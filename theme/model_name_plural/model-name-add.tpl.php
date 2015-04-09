<h1><?php echo t('Create model_name_human') ?></h1>

<?php
  unset($form['#theme']);
	echo render($form);
?>

<ul class="actions">
  <li><?php echo l('Back','model_name_plural'); ?></li>
</ul>



