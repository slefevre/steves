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
    'aliases' => array('rein', 'reinstall', 're-install'),
    'examples' => array(
      'drush pm-reinstall views' => 'Disables, uninstalls, and installs the `views` module',
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
      'drush pm-remove views' => 'Disables and uninstalls the `views` module',
    ),
  );
  return $commands;
}

function steves_drush_registry_rebuild_cache_clear() {

  $message = dt('Rebulding registry.');
  drush_log($message);
  drush_print($message);
  registry_rebuild();

  $message = dt('Clearing all caches.');
  drush_log($message);
  drush_print($message);
  cache_clear_all();
}

function steves_drush_pm_reinstall($module_name) {

  $module = array($module_name);

  steves_drush_pm_remove($module_name);

  $message = dt('Enabling module.');
  drush_log($message);
  drush_print($message);
  module_enable($module);
}

function steves_drush_pm_remove($module_name) {
  $module = array($module_name);

  $message = dt('Disabling module.');
  drush_log($message);
  drush_print($message);
  module_disable($module);

  $message = dt('Uninstalling module.');
  drush_log($message);
  drush_print($message);
  drupal_uninstall_modules($module_name);
}
