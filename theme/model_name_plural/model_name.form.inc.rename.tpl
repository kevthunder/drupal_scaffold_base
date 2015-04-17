<!--?php
<?php foreach ($this->config->fields() as $name => $opt) { ?>
	$form['<?php echo $name ?>'] = array(
  <?php echo $this->indent($this->arrayKeysExport($opt['form']),1) ?>

    '#title' => t('<?php echo $inflector->humanize($name) ?>'), 
    '#default_value' => $model_name-><?php echo $name ?>,
  );
<?php } ?>
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
?-->