<h1><?php echo t('Create model_name_human') ?></h1>

<?php
  unset($form['#theme']);
	echo render($form);
?>

<ul class="actions">
  <li><?php echo l('Back','model_name_plural'); ?></li>
  <li><?php echo l('View','model_name_plural/'.$model_name->lid); ?></li>
  <li><?php echo l('Delete','model_name_plural/'.$model_name->lid.'/delete'); ?></li>
</ul>


