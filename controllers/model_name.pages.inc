<?php

  module_load_include('inc', 'scaffold_base', 'models/model_name');
  
  /*** index ***/
	function model_name_plural_index(){
    $model_name_plural = ModelName::all();
    return theme('model_name_plural_index', array('model_name_plural' => $model_name_plural));
  }
  
  /*** add ***/
	function model_name_plural_add($form, &$form_state){
    $model_name = $form_state['model_name'] = new ModelName();
    $file = DRUPAL_ROOT . '/' . drupal_get_path('module', 'scaffold_base') . "/theme/model_name_plural/model_name.form.inc";
    require $file;
    return $form;
  }
	function model_name_plural_add_submit(&$form, &$form_state){
    $form_state['redirect'] = 'model_name_plural';
    $form_state['model_name']->set($form_state['values']);
    $form_state['model_name']->save();
  }
  
  /*** view ***/
	function model_name_plural_view($id){
    $model_name = ModelName::find($id);
    return theme('model_name_plural_view', array('model_name' => $model_name));
  }
  
  /*** edit ***/
	function model_name_plural_edit($form, &$form_state,$id){
    $model_name = $form_state['model_name'] = ModelName::find($id);
    $file = DRUPAL_ROOT . '/' . drupal_get_path('module', 'scaffold_base') . "/theme/model_name_plural/model_name.form.inc";
    require $file;
    return $form;
  }
	function model_name_plural_edit_submit(&$form, &$form_state){
    $form_state['redirect'] = 'model_name_plural';
    $form_state['model_name']->set($form_state['values']);
    $form_state['model_name']->save();
  }
  
  /*** delete ***/
	function model_name_plural_delete($id){
    $model_name = ModelName::find($id);
    if(!empty($_POST['confirm'])){
      $model_name->delete();
      drupal_goto('model_name_plural');
    }else{
      return theme('model_name_plural_delete', array('model_name' => $model_name));
    }
  }
?>