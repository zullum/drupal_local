<?php

/**
 * @file
 * Contains \Drupal\mymodule\Controller\CustomPageController.
 */
namespace Drupal\mymodule\Controller;

use Drupal\Core\Controller\ControllerBase;
use Symfony\Component\HttpFoundation\JsonResponse;

class CustomPageController extends ControllerBase {
  public function customData() {
    $return = array('custom_data'=>'my test string');
    // Create key/value array.
    return new JsonResponse($return);
  }
}