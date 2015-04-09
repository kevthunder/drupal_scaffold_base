<?php 
  use ICanBoogie\Inflector;
      
  class ScaffoldBaseRenameOptions {
    
    var $checks = array(
      '/\.(php|inc|module)$/' => 'replace_model_name',
    );
    
    function __construct($process) {
      $this->process = $process;
    }
    
    function model_name(){
      return $this->process->prompt(array('prompt'=>'Model name','default'=>$this->process->dest_module),'model_name');
    }
    
    var $_model_replacements;
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
      drush_print_r($replacements);
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
      file_put_contents($file, $str);
    }
  }
 ?>