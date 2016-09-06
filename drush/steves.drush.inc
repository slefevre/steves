<?php

function steves_drush_command() {
  $commands['registry-rebuild-cache-clear'] = array(
    'description' => 'Rebuilds registry and clears all caches',
    'callback' => 'steves_drush_registry_rebuild_cache_clear',
    'arguments' => array(),
    'aliases' => array('rrcc', 'ccrr'),
    'examples' => array(
      'drush rrcc' => 'Rebuilds registry and clears all caches',
    ),
  );
  $commands['pm-reinstall'] = array(
    'description' => 'Disables, uninstalls, then installs a module',
    'callback' => 'steves_drush_pm_reinstall',
    'arguments' => array(
      'module_name' => 'The name of the module',
    ),
    'aliases' => array('rein', 'reinstall'),
    'examples' => array(
      'drush pm-reinstall views' => 'Disables, uninstalle, and installs views',
    ),
  );
  $commands['pm-remove'] = array(
    'description' => 'Disables and uninstalls a module',
    'callback' => 'steves_drush_pm_removed',
    'arguments' => array(
      'module_name' => 'The name of the module',
    ),
    'aliases' => array('rm', 'remove'),
    'examples' => array(
      'drush pm-remove views' => 'Disables and uninstalls views',
    ),
  );
  return $commands;
}

function steves_drush_registry_rebuild_cache_clear() {
  cache_clear_all();
  registry_rebuild();
}

function steves_drush_pm_reinstall($module_name) {
  $module = array($module_name);
  drupal_disable($module);
  drupal_uninstall_modules($module_name);
  drupal_enable($module);
}

function steves_drush_pm_remove($module_name) {
  $module = array($module_name);
  drupal_disable($module);
  drupal_uninstall_modules($module_name);
}
