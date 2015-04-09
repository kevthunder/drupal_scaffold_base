<?php
/**
 * Implements hook_theme().
 */
function scaffold_base_theme($existing, $type, $theme, $path) {
    $items = array();
    $path = drupal_get_path('module', 'scaffold_base');
    $items['model_name_plural_index'] = array(
      'path' => $path . '/theme/model_name_plural',
      'template' => 'model-name-plural-index'
    );
    $items['model_name_plural_add'] = array(
      'render element' => 'form',
      'path' => $path . '/theme/model_name_plural',
      'template' => 'model-name-add'
    );
    $items['model_name_plural_view'] = array(
      'path' => $path . '/theme/model_name_plural',
      'template' => 'model-name-view'
    );
    $items['model_name_plural_edit'] = array(
      'render element' => 'form',
      'path' => $path . '/theme/model_name_plural',
      'template' => 'model-name-edit'
    );
    $items['model_name_plural_delete'] = array(
      'path' => $path . '/theme/model_name_plural',
      'template' => 'model-name-delete'
    );

    return $items;
}
