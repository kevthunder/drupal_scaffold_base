<h1><?php echo $model_name->number ?></h1>

<div class="lid">
  <h2><?php echo t('Id') ?></h2>
  <p><?php echo $model_name->lid ?></p>
</div>
<div class="number">
  <h2><?php echo t('Number') ?></h2>
  <p><?php echo $model_name->number ?></p>
</div>

<ul class="actions">
  <li><?php echo l('Back','model_name_plural'); ?></li>
  <li><?php echo l('Edit','model_name_plural/'.$model_name->lid.'/edit'); ?></li>
  <li><?php echo l('Delete','model_name_plural/'.$model_name->lid.'/delete'); ?></li>
</ul>


