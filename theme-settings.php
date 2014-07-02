<?php

function omega_sr_form_system_theme_settings_alter(&$form, &$form_state)
{
	include_once 'template.php';
    drupal_add_js(drupal_get_path('theme', 'omega_sr') . '/js/theme.js');
    drupal_add_css(drupal_get_path('theme', 'omega_sr') . '/css/theme.css');
    drupal_add_css(drupal_get_path('theme', 'omega_sr') . '/js/rs-plugin/css/font-style.css');
    drupal_add_library('system', 'ui');
    drupal_add_library('system', 'farbtastic');
    drupal_add_library('system', 'ui.sortable');
    drupal_add_library('system', 'ui.draggable');
    drupal_add_library('system', 'ui.dialog');


    $form_state['build_info']['files'][]                          = drupal_get_path('theme', 'omega_sr') . '/theme-settings.php';
    $form['#validate'][]                                          = 'omega_sr_settings_validate';
    $form['#submit'][]                                            = 'omega_sr_settings_submit';
    $settings['slider']                                           = theme_get_setting('slider', 'omega_sr');


    $form['theme_settings']['#collapsible'] = TRUE;
    $form['theme_settings']['#collapsed']   = TRUE;
    $form['logo']['#collapsible']           = TRUE;
    $form['logo']['#collapsed']             = TRUE;
    $form['favicon']['#collapsible']        = TRUE;
    $form['favicon']['#collapsed']          = TRUE;


    $form['alpha_settings']['general-settings']                       = array(
        '#type' => 'fieldset',
        '#title' => t('General'),
        '#weight' => -11,
    );
    // Breadcrumb elements
    $form['alpha_settings']['general-settings']['slider-show']        = array(
        '#type' => 'select',
        '#title' => t('Select default slider'),
        '#description' => t('Select front page slider'),
        '#options' => array(
            "rev" => t('Revolution Slider'),
            "pan" => t('Panel Slider'),
            "ref" => t('Refine Slider'),
            "none" => t('None'),
        ),
        '#default_value' => theme_get_setting('slider-show', 'omega_sr')
    );
    include_once(drupal_get_path('theme', 'omega_sr') . '/js/rs-plugin/RevolutionSlider.slider.inc');

    foreach ($form['alpha_settings'] as $key => $value) {
        if (!is_array($value)) continue;
        switch($key){
/*            case 'general-settings':
                $form['alpha_settings'][$key]['#access'] = user_access('slider revolution settings');
                break;*/
            default:
                $form['alpha_settings'][$key]['#access'] = user_access('theme settings');
        }
    }
    $form['favicon']['#access'] = user_access('theme settings');
    $form['logo']['#access'] = user_access('theme settings');
    $form['theme_settings']['#access'] = user_access('theme settings');
}
/* Settings form Validator */
function omega_sr_settings_validate($form, &$form_state)
{
    $settings['slider'] = theme_get_setting('slider', 'omega_sr');
    $BuildSettingTheme  = $form_state['build_info']['args'][0];
    $validateFile       = array(
        'file_validate_is_image' => array()
    );
    // Validate Layer
    if (!empty($form_state['values']['slider']['layers'])) {
        foreach ($form_state['values']['slider']['layers'] as $SlideId => &$Slide) {
            if (is_array($Slide)) {
                $UploadedFile = file_save_upload("backgrounds-" . $SlideId, $validateFile);
                //Upload new slide background
                if (isset($UploadedFile)) {
                    if ($UploadedFile) {
                        $Slide['background'] = $UploadedFile;
                        if (isset($Slide['background'])) {
                            @drupal_unlink($Slide['background']);
                        }
                    } else {
                        form_set_error("backgrounds-" . $SlideId, t('The background could not be uploaded.'));
                    }
                }
                // Process Validate Layer
                if (isset($Slide['sublayers'])) {
                    foreach ($Slide['sublayers'] as $LayerId => &$sublayer) {
                        foreach ($sublayer['properties'] as $key => &$property) {
                            if (empty($property) || $property == '_none') {
                                unset($sublayer['properties'][$key]);
                            }
                            unset($property);
                        }
                        $UploadedFile = file_save_upload("sublayers-" . $SlideId . "-" . $LayerId, $validateFile);
                        if (isset($UploadedFile)) {
                            if ($UploadedFile) {
                                $Slide['sublayers'][$LayerId]['image']['file'] = $UploadedFile;
                                @drupal_unlink($sublayer['image']['path']);
                            } else {
                                form_set_error("sublayers-" . $SlideId . "-" . $LayerId, t('The sublayer could not be uploaded.'));
                            }
                        }
                        unset($sublayer);
                    }
                }
                unset($Slide['delete']);
                unset($Slide['background_upload']);
                unset($Slide['create_sublayer']);
            }
            unset($Slide);
        }
    }
}
/* Submit form Settings form */
function omega_sr_settings_submit($form, &$form_state)
{
	if(!empty($form_state['values']['slider']['layers'])){
    foreach ($form_state['values']['slider']['layers'] as $SlideId => &$Slide) {
        if (isset($Slide['background']) && is_object($Slide['background'])) {
            $UploadedFile        = $Slide['background'];
            $Slide['background'] = file_unmanaged_copy($UploadedFile->uri, 'public://omega_sr/' . $UploadedFile->filename);
        }
        if (isset($Slide['sublayers'])) {
            foreach ($Slide['sublayers'] as $LayerId => &$sublayer) {
                // If the user uploaded a new sublayer image, save it to a permanent location.
                if (isset($sublayer['image']['file']) && is_object($sublayer['image']['file'])) {
                    $UploadedFile              = $sublayer['image']['file'];
                    $sublayer['image']['path'] = file_unmanaged_copy($UploadedFile->uri, 'public://omega_sr/' . $UploadedFile->filename);
                    // Unset unnecessary data
                    unset($form_state['values']['slider']['layers'][$SlideId]['sublayers'][$LayerId]['image']['file']);
                    unset($form_state['values']['slider']['layers'][$SlideId]['sublayers'][$LayerId]['image']['upload']);
                }
            }
        }
    }
    $BuildSettingTheme = $form_state['build_info']['args'][0];
    $path              = variable_get('theme_' . $BuildSettingTheme . '_files_directory');
    @file_unmanaged_delete_recursive($path);
    // Prepare target location for generated files.
    $id   = $BuildSettingTheme . '-' . substr(hash('sha256', serialize($BuildSettingTheme) . microtime()), 0, 8);
    $path = 'public://omega_sr/' . $id;
    file_prepare_directory($path, FILE_CREATE_DIRECTORY);
    variable_set('theme_' . $BuildSettingTheme . '_files_directory', $path);
	}
}
function omega_sr_slide_iupd($form, &$form_state)
{
    $action        = $form_state['triggering_element']['#name'];
    $exploded_name = explode('-', $form_state['triggering_element']['#name']);
    $action        = isset($exploded_name[1]) ? $exploded_name[0] : $action;
    switch ($action) {
        case 'create':
            $Slide_count                                = isset($form_state['values']['slider']['layers']) ? count($form_state['values']['slider']['layers']) : 0;
            $form_state['values']['slider']['layers'][] = array(
                'sublayers' => array()
            );
            break;
        case 'delete':
            $SlideId = $form_state['clicked_button']['#parents'][2];
            @$Slide = $form_state['values']['slider']['layers'][$SlideId];
            @drupal_unlink($Slide['background']);
            // Delete layer image and itself
            if (isset($Slide['sublayers'])) {
                foreach ($Slide['sublayers'] as $sublayer) {
                    @drupal_unlink($sublayer['image']['path']);
                }
            }
            unset($form_state['values']['slider']['layers'][$SlideId]);
            break;
    }
    end($form_state['values']['slider']['layers']);
    $form_state['lid'] = key($form_state['values']['slider']['layers']);
    variable_set($form_state['values']['var'], $form_state['values']);
}
/* Add Layer to slide */
function omega_sr_sublayer_create($form, &$form_state)
{
    $SlideId        = $form_state['triggering_element']['#parents'][2];
    $type           = $form_state['triggering_element']['#parents'][4];
    $sublayer_count = 0;
    if (isset($form_state['values']['slider']['layers'][$SlideId]['sublayers'])) {
        $sublayer_count = count($form_state['values']['slider']['layers'][$SlideId]['sublayers']);
    }
    if ($type == "text-html") {
        $layerName = "Caption ";
    }
    if ($type == "image") {
        $layerName = "Image ";
    }
    if ($type == "video") {
        $layerName = "Video ";
    }
    $form_state['values']['slider']['layers'][$SlideId]['sublayers'][] = array(
        'title' => t($layerName . '@number', array(
            '@number' => $sublayer_count
        )),
        'x' => 50,
        'y' => 50,
        'weight' => 0,
        'form'
    );
    drupal_set_message("New layer " . $layerName . " is created successfuly!");
    $LayerId                                                                           = count($form_state['values']['slider']['layers'][$SlideId]['sublayers']) - 1;
    $LayerId2                                                                          = count($form_state['values']['slider']['layers'][$SlideId]['sublayers']) + 1;
    $form_state['values']['slider']['layers'][$SlideId]['sublayers'][$LayerId]['type'] = $type;
    variable_set($form_state['values']['var'], $form_state['values']);
}
/* Delete Layer from slide */
function omega_sr_sublayer_delete($form, &$form_state)
{
    $SlideId = $form_state['triggering_element']['#parents'][2];
    $LayerId = $form_state['triggering_element']['#parents'][4];
    @drupal_unlink($form_state['values']['slider']['layers'][$SlideId]['sublayers'][$LayerId]['image']['path']);
    unset($form_state['values']['slider']['layers'][$SlideId]['sublayers'][$LayerId]);
    variable_set($form_state['values']['var'], $form_state['values']);
    drupal_set_message(t('Layer deleted.'));
}
function site_bg_validate($element, &$form_state)
{
    global $base_url;
    $validateFile = array(
        'file_validate_is_image' => array()
    );
    $UploadedFile = file_save_upload('site_bg_image', $validateFile, "public://", FILE_EXISTS_REPLACE);
    if ($form_state['values']['delete_site_bg_image'] == TRUE) {
        // Delete layer file
        file_unmanaged_delete($form_state['values']['site_bg_preview']);
        $form_state['values']['site_bg_preview'] = NULL;
    }
    if ($UploadedFile) {
        // change file's status from temporary to permanent and update file database
        $UploadedFile->status = FILE_STATUS_PERMANENT;
        file_save($UploadedFile);
        $file_url                                = file_create_url($UploadedFile->uri);
        $file_url                                = str_ireplace($base_url, '', $file_url);
        // set to form
        $form_state['values']['site_bg_preview'] = $file_url;
    }
}

