<h1><!--?php echo t('model_name_human_plural') ?--></h1>

<table>
  <tr>
    <th><!--?php echo t('Id') ?--></th>
<?php foreach ($this->config->fields() as $name => $opt) { ?>
    <th><!--?php echo t('<?php echo $inflector->humanize($name) ?>') ?--></th>
<?php } ?>
    <th></th>
  </tr>
  <!--?php foreach ($model_name_plural as $model_name) { ?-->
    <tr>
      <td><!--?php echo $model_name->primary_key_field ?--></td>
<?php foreach ($this->config->fields() as $name => $opt) { ?>
      <td><!--?php echo $model_name-><?php echo $name ?> ?--></td>
<?php } ?>
      <td class="actions">
        <!--?php echo l('View','model_name_plural/'.$model_name->primary_key_field); ?-->
        <!--?php echo l('Edit','model_name_plural/'.$model_name->primary_key_field.'/edit'); ?-->
        <!--?php echo l('Delete','model_name_plural/'.$model_name->primary_key_field.'/delete'); ?-->
      </td>
    </tr>
  <!--?php } ?-->
</table>

<ul class="actions">
  <li><!--?php echo l('Add model_name_human','model_name_plural/add'); ?--></li>
</ul>