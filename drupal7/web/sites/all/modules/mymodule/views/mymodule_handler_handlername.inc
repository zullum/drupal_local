<?php

// This file must be at mymodule/views directory.

/**
 * @file
 * Definition of mymodule_handler_handlername.
 */

/**
 * Description of what my handler does.
 */
class mymodule_handler_handlername extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['field_testtextfield'] = array(
      'table' => 'field_data_field_testtextfield',
      'field' => 'field_testtextfield_value',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['option_a'] = array('default' => '');
    $options['option_b'] = array('default' => '');

    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['option_a'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $this->options['option_a'],
      '#description' => t('Some description.'),
      '#weight' => -10,
    );

    $form['option_b'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $this->options['option_b'],
      '#description' => t('Some description.'),
      '#weight' => -9,
    );
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    // This ensures that even if Views changes the field name within the query, the handler will still work.
    // Inspect the $this->aliases array to find the key of the field that you need.
    $value = $this->get_value($values, 'field_testtextfield');

    dsm($value);

    return format_string('<div class="@option_a" data-tag="@field_testtextfield" data-follow_name="@option_b"></div>', array(
      '@field_testtextfield' => $value,
      '@option_a' => $this->options['option_a'],
      '@option_b' => $this->options['option_b'],
    ));
  }
}



// /**
//  * @file
//  * Definition of views_handler_field_node_path.
//  */

// /**
//  * Field handler to present the path to the node.
//  *
//  * @ingroup views_field_handlers
//  */
// class mymodule_handler_handlername extends views_handler_field {

//     /**
//      * {@inheritdoc}
//      */
//     public function option_definition() {
//       $options = parent::option_definition();
//       //$options['absolute'] = array('default' => FALSE, 'bool' => TRUE);

//       return $options;
//     }

//     /**
//      * {@inheritdoc}
//      */
//     public function construct() {
//       parent::construct();
//       $this->additional_fields['nid'] = 'nid';
//     }

//     /**
//      * {@inheritdoc}
//      */
//     public function options_form(&$form, &$form_state) {
//       parent::options_form($form, $form_state);
//     //   $form['absolute'] = array(
//     //     '#type' => 'checkbox',
//     //     '#title' => t('Use absolute link (begins with "http://")'),
//     //     '#default_value' => $this->options['absolute'],
//     //     '#description' => t('Enable this option to output an absolute link. Required if you want to use the path as a link destination (as in "output this field as a link" above).'),
//     //     '#fieldset' => 'alter',
//     //   );
//     }

//     /**
//      * {@inheritdoc}
//      */
//     public function query() {
//       $this->ensure_my_table();
//       $this->add_additional_fields();
//     }

//     /**
//      * {@inheritdoc}
//      */
//     public function render($values) {
//       $nid = $this->get_value($values, 'nid');
//       // return url("node/$nid", array('absolute' => $this->options['absolute']));
//       return url("node/$nid", array('absolute' => TRUE));
//     }

// }
