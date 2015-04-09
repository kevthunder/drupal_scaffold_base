<?php

/**
 * @file
 * File defining the menus(routes).
 */

/**
 * Implementation of hook_menu().
 */
 function scaffold_base_menu() {
    $items['model_name_plural'] = array(
      'page callback' => 'model_name_plural_index',
      'access callback' => true,
      'file' => 'controllers/model_name.pages.inc'
    );
    $items['model_name_plural/add'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array('model_name_plural_add'),
      'access callback' => true,
      'file' => 'controllers/model_name.pages.inc'
    );
    $items['model_name_plural/%'] = array(
      'page callback' => 'model_name_plural_view',
      'page arguments' => array(1),
      'access callback' => true,
      'file' => 'controllers/model_name.pages.inc'
    );
    $items['model_name_plural/%/edit'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array('model_name_plural_edit',1),
      'access callback' => true,
      'file' => 'controllers/model_name.pages.inc'
    );
    $items['model_name_plural/%/delete'] = array(
      'page callback' => 'model_name_plural_delete',
      'page arguments' => array(1),
      'access callback' => true,
      'file' => 'controllers/model_name.pages.inc'
    );
    return $items;
  }