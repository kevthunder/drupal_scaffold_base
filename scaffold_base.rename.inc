<?php 
  use ICanBoogie\Inflector;
      
  class ScaffoldBaseRenameOptions extends RenameOptions{
    
    var $checks = array(
      '/\.(php|inc|module|install)$/' => 'replace_model_name',
    );
    var $checkRendered = true;
    
    function model_name(){
      return $this->process->prompt(array('prompt'=>'Model name','default'=>$this->process->dest_module),'model_name');
    }
    
    var $types = array(
      'char' => array(
        'alias' => 'c'
      ),
      'varchar' => array(
        'alias' => 'v',
        'schema' => array(
          'length' => 256,
        )
      ),
      'text' => array(
        'alias' => 't'
      ),
      'blob' => array(
        'alias' => 'b'
      ),
      'int' => array(
        'alias' => 'i'
      ),
      'float' => array(
        'alias' => 'f'
      ),
      'numeric' => array(
        'alias' => 'n'
      ),
      'serial' => array(
        'alias' => 's'
      ),
    );
    
    function typeByAlias($alias){
      if(!empty($alias)){
        if(array_key_exists($alias,$this->types)) return array_merge(array('type'=>$alias),$this->types[$alias]);
        foreach ($this->types as $key => $val) {
          if($val['alias'] == $alias) return array_merge(array('type'=>$key),$this->types[$alias]);
        }
      }
    }
    
    function parseFieldType($str){
      list($type, $null) = explode(':',$str,2);
      list($null, $opt) = explode(' ',$str,2);
      $type = $this->typeByAlias($type);
      if($type){
        $field = array(
          'schema' => array(
            'type' => $type['type']
          ),
          'form' => array(
            '#type' => 'textfield', 
          )
        );
        $field = array_merge_recursive($field,$type);
        $field['schema']['not null'] = ($null != 'null');
        
        if($opt){
          $opt = json_decode($opt, true);
          if($opt) $field['schema'] = array_merge($field['schema'],$opt);
        }
        return $field;
      }
    }
    
    function fields(){
      if(empty($this->process->choices['fields'])){
        $this->process->choices['fields'] = array();
        $inflector = Inflector::get();
        while($field = $this->process->prompt(array('prompt'=>'Choose a field to add or leave blank to continue'))) {
          if($field == ''){ break; }
          list($field, $type) = explode(':',$field,2);
          $type = $this->parseFieldType($type);
          while(!$type){
            $this->process->output('Possible types :');
            foreach($this->types as $name => $opt){
              $this->process->output(' - '.$name.(!empty($opt['alias'])?' ('.$opt['alias'].')':''));
            }
            $type = $this->process->prompt(array('prompt'=>'Field '.$field.' type or "q" to cancel','default'=>'varchar'));
            if($type == 'q'){ break 2; }
            $type = $this->parseFieldType($type);
          }
          if(empty($type['schema']['description'])) $type['schema']['description'] = $inflector->humanize($field);
          $this->process->choices['fields'][$field] = $type;
        }
      }
      return $this->process->choices['fields'];
    }
    
    function model_replacements(){
      if(!empty($this->_model_replacements)) return $this->_model_replacements;
      $inflector = Inflector::get();
      $model_name = $this->model_name();
      $replacements = array(
        'model_name_human_plural' => $inflector->pluralize($inflector->humanize($model_name)),
        'model-name-plural' => str_replace('_','-',$inflector->pluralize($model_name)),
        'model-name' => str_replace('_','-',$model_name),
        'model_name_human' => $inflector->humanize($model_name),
        'model_name_plural' => $inflector->pluralize($model_name),
        'ModelName' => $inflector->camelize($model_name),
        'model_name' => $model_name
      );
      // drush_print_r($replacements);
      $this->_model_replacements = $replacements;
      return $replacements;
    }
    
    function file_new_name($file){
      $replacements = $this->model_replacements();
      $dir = dirname($file);
      $name = basename($file);
      return $dir .'/'. str_replace(array_keys($replacements), array_values($replacements),$name);
    }
    
    function replace_model_name($file){
      $model_name = $this->model_name();
      $replacements = $this->model_replacements();
      
      $str=file_get_contents($file);
      $str=str_replace(array_keys($replacements), array_values($replacements),$str);
      
      $str=$this->process->replace_promp('primary_key_field', array('prompt'=>'Primary key for you model','default'=>$model_name[0].'id'),$str,true);
      file_put_contents($file, $str);
    }
  }
 ?>