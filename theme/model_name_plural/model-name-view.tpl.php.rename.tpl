<h1><!--?php echo $model_name->number ?--></h1>

<div class="primary_key_field">
  <h2><!--?php echo t('Id') ?--></h2>
  <p><!--?php echo $model_name->primary_key_field ?--></p>
</div>
<?php foreach ($this->config->fields() as $name => $opt) { ?>
<div class="number">
  <h2><!--?php echo t('<?php echo $inflector->humanize($name) ?>') ?--></h2>
  <p><!--?php echo $model_name-><?php echo $name ?> ?--></p>
</div>
<?php } ?>
<ul class="actions">
  <li><!--?php echo l('Back','model_name_plural'); ?--></li>
  <li><!--?php echo l('Edit','model_name_plural/'.$model_name->primary_key_field.'/edit'); ?--></li>
  <li><!--?php echo l('Delete','model_name_plural/'.$model_name->primary_key_field.'/delete'); ?--></li>
</ul>


