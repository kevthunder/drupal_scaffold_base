<?php
	
  class ModelName {
    static function schema(){
      require 'model_name.schema.inc'
      return $schema;
    }
    static function all(){
      $results = db_select('model_name_plural')
        ->fields('model_name_plural')
        ->execute();
      $model_name_plural = array();
      while($res = $results->fetchAssoc()){
      // foreach($results as $res){
        $model_name_plural[] = new ModelName($res);
      }
      return $model_name_plural;
    }
    static function find($id){
      $result = db_select('model_name_plural')
      ->fields('model_name_plural')
      ->condition('lid', $id,'=')
      ->execute()
      ->fetchAssoc();
      return new ModelName($result);
    }
    
    function __construct($data = array()) {
      foreach (ModelName::schema()['fields'] as $key => $val) {
        $this->{$key} = isset($data[$key]) ? $data[$key] : (isset($val['default'])? $val['default'] : null);
      }
    }
    
    function data(){
      $data = array();
      foreach (ModelName::schema()['fields'] as $key => $val) {
        $data[$key] = $this->{$key};
      }
      return $data;
    }
    
    function set($arg1,$arg2 = null){
      if(is_array($arg1)){
        $data = $arg1;
        foreach ($data as $key => $val) {
          if(array_key_exists($key,ModelName::schema()['fields'])) $this->{$key} = $val;
        }
      }else{
        $key = $arg1;
        $val = $arg2;
        $this->{$key} = $val;
      }
    }
    
    function save(){
      if(empty($this->lid)){
        $this->lid = db_insert('model_name_plural') 
          ->fields($this->data())
          ->execute();
      }else{
        $num_updated = db_update('model_name_plural') 
          ->fields($this->data())
          ->condition('lid', $this->lid)
          ->execute();
      }
    }
    
    function delete(){
      if(!empty($this->lid)){
        return db_delete('model_name_plural')
          ->condition('lid', $this->lid)
          ->execute();
      }
    }
  }
 
?>