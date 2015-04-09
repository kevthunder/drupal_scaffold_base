<h1><?php echo t('model_name_human_plural') ?></h1>

<table>
  <tr>
    <th><?php echo t('Id') ?></th>
    <th><?php echo t('Number') ?></th>
    <th></th>
  </tr>
  <?php foreach ($model_name_plural as $model_name) { ?>
    <tr>
      <td><?php echo $model_name->lid ?></td>
      <td><?php echo $model_name->number ?></td>
      <td class="actions">
        <?php echo l('View','model_name_plural/'.$model_name->lid); ?>
        <?php echo l('Edit','model_name_plural/'.$model_name->lid.'/edit'); ?>
        <?php echo l('Delete','model_name_plural/'.$model_name->lid.'/delete'); ?>
      </td>
    </tr>
  <?php } ?>
</table>

<ul class="actions">
  <li><?php echo l('Add model_name_human','model_name_plural/add'); ?></li>
</ul>