<?php
	$form['number'] = array(
    '#type' => 'textfield', 
    '#title' => t('Number'), 
    '#default_value' => $model_name->number,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
?>