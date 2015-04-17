<!--?php
  $schema = array(
      'description' => 'The base table for model_name_human.',
      'fields' => array(
        'primary_key_field' => array(
          'description' => 'The primary identifier for a model_name_human.',
          'type' => 'serial',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
<?php     foreach ($this->config->fields() as $name => $opt) { ?>
        '<?php echo $name ?>' => <?php echo $this->indent(var_export($opt['schema'],true),4) ?>,
<?php     } ?>
      ),
      'primary key' => array('primary_key_field'),
    );
?-->