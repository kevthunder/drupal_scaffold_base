<?php
  $schema = array(
      'description' => 'The base table for model_name_human.',
      'fields' => array(
        'lid' => array(
          'description' => 'The primary identifier for a model_name_human.',
          'type' => 'serial',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'number' => array(
          'description' => 'The model_name_human Number.',
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'default' => '',
        ),
      ),
      'primary key' => array('lid'),
    );
  }
?>