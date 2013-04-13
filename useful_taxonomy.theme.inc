<?php


/**
 * Display taxonomy nested tree as list
 * vars['tree'] : tree to display
 * vars['view_modes'] : array to define view mode by levels. Also available : label (default), link.
 * if string is used instead of array, all terms will be rendered with this default
 * @param $vars
 * @return bool|string
 */
function theme_useful_taxonomy_taxonomy_tree_list($vars) {
  $tree = $vars['tree'];
  $view_modes = (isset($vars['view_modes'])) ? $vars['view_modes'] : 'label';

  $items = array();

  if (!empty($tree)) {
    // Edit taxonomy tree as items theme list ready
    $items = _taxonomy_nested_tree_as_list($tree, $view_modes);
  }

  $list = array(
    '#theme' => 'item_list',
    '#items' => $items,
  );

  return render($list);
}