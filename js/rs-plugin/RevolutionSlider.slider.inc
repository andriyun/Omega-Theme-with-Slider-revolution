<?php
$arrStyles        = array(
    "tp-caption Default_text_large" => "Default large title",
    "tp-caption Default_text_medium" => "Default medium title",
    "tp-caption Default_text_small" => "Default small title",
    "tp-caption big_white" => "big_white",
    "tp-caption big_orange" => "big_orange",
    "tp-caption big_black" => "big_black",
    "tp-caption big_white" => "big_white",
    "tp-caption medium_grey" => "medium_grey",
    "tp-caption small_text" => "small_text",
    "tp-caption medium_text" => "medium_text",
    "tp-caption large_text" => "large_text",
    "tp-caption large_black_text" => "large_black_text",
    "tp-caption very_large_text" => "very_large_text",
    "tp-caption very_large_black_text" => "very_large_black_text",
    "tp-caption bold_red_text" => "bold_red_text",
    "tp-caption bold_brown_text" => "bold_brown_text",
    "tp-caption bold_green_text" => "bold_green_text",
    "tp-caption very_big_white" => "very_big_white",
    "tp-caption very_big_black" => "very_big_black",
    "tp-caption green_title_text" => "Title (Green)",
	"tp-caption orange_title_text" => "Title (Orange) large"



);
$arrEasing        = array(
    "easeOutBack" => "easeOutBack",
    "easeInQuad" => "easeInQuad",
    "easeOutQuad" => "easeOutQuad",
    "easeInOutQuad" => "easeInOutQuad",
    "easeInCubic" => "easeInCubic",
    "easeOutCubic" => "easeOutCubic",
    "easeInOutCubic" => "easeInOutCubic",
    "easeInQuart" => "easeInQuart",
    "easeOutQuart" => "easeOutQuart",
    "easeInOutQuart" => "easeInOutQuart",
    "easeInQuint" => "easeInQuint",
    "easeOutQuint" => "easeOutQuint",
    "easeInOutQuint" => "easeInOutQuint",
    "easeInSine" => "easeInSine",
    "easeOutSine" => "easeOutSine",
    "easeInOutSine" => "easeInOutSine",
    "easeInExpo" => "easeInExpo",
    "easeOutExpo" => "easeOutExpo",
    "easeInOutExpo" => "easeInOutExpo",
    "easeInCirc" => "easeInCirc",
    "easeOutCirc" => "easeOutCirc",
    "easeInOutCirc" => "easeInOutCirc",
    "easeInElastic" => "easeInElastic",
    "easeOutElastic" => "easeOutElastic",
    "easeInOutElastic" => "easeInOutElastic",
    "easeInBack" => "easeInBack",
    "easeOutBack" => "easeOutBack",
    "easeInOutBack" => "easeInOutBack",
    "easeInBounce" => "easeInBounce",
    "easeOutBounce" => "easeOutBounce",
    "easeInOutBounce" => "easeInOutBounce"
);
$arrAnimations    = array(
    "fade" => "Fade",
    "sft" => "Short from Top",
    "sfb" => "Short from Bottom",
    "sfr" => "Short from Right",
    "sfl" => "Short from Left",
    "lft" => "Long from Top",
    "lfb" => "Long from Bottom",
    "lfr" => "Long from Right",
    "lfl" => "Long from Left",
    "randomrotate" => "Random Rotate"
);
$arrEndAnimations = array(
    "auto" => "Choose Automatic",
    "fadeout" => "Fade Out",
    "stt" => "Short to Top",
    "stb" => "Short to Bottom",
    "stl" => "Short to Left",
    "str" => "Short to Right",
    "ltt" => "Long to Top",
    "ltb" => "Long to Bottom",
    "ltl" => "Long to Left",
    "ltr" => "Long to Right",
    "randomrotateout" => "Random Rotate Out"
);
$arrTransitions   = array(
    "random" => "Random",
    "fade" => "Fade",
    "slidehorizontal" => "Slide Horizontal",
    "slidevertical" => "Slide Vertical",
    "boxslide" => "Box Slide",
    "boxfade" => "Box Fade",
    "slotzoom-horizontal" => "SlotZoom Horizontal",
    "slotslide-horizontal" => "SlotSlide Horizontal",
    "slotfade-horizontal" => "SlotFade Horizontal",
    "slotzoom-vertical" => "SlotZoom Vertical",
    "slotslide-vertical" => "SlotSlide Vertical",
    "slotfade-vertical" => "SlotFade Vertical",
    "curtain-1" => "Curtain 1",
    "curtain-2" => "Curtain 2",
    "curtain-3" => "Curtain 3",
    "slideleft" => "Slide Left",
    "slideright" => "Slide Right",
    "slideup" => "Slide Up",
    "slidedown" => "Slide Down",
    "papercut" => "Premium - Paper Cut",
    "3dcurtain-horizontal" => "Premium - 3D Curtain Horizontal",
    "3dcurtain-vertical" => "Premium - 3D Curtain Vertical",
    "flyin" => "Premium - Fly In",
    "turnoff" => "Premium - Turn Off",
    "cubic" => "Premium - Cubic"
);
for ($i = 0; $i <= 50; $i++) {
    $options['weight'][$i] = $i;
}
    if (theme_get_setting('slider-show', 'omega_sr')) {
        $form['slider']                      = array(
            '#type' => 'fieldset',
          	   '#title' => "<div class='rev-image'><img src=" .base_path(). drupal_get_path('theme', 'omega_sr') . "/images/rev-logo.png" . " /></div>",
            '#collapsible' => FALSE,
            '#collapsed' => FALSE,
            '#group' => 'settings',
            '#tree' => TRUE,
            '#weight' => -10,
            '#prefix' => '<div id="layers">',
            '#suffix' => '</div>',
        );
        $form['slider']['buttons']           = array(
            '#type' => 'fieldset',
            '#collapsible' => FALSE,
            '#collapsed' => FALSE,
            '#tree' => TRUE,
            '#weight' => -111
        );
        $form['slider']['buttons']['add']    = array(
            '#type' => 'submit',
            '#value' => t('New Slide'),
            '#name' => 'create',
            '#submit' => array(
                'omega_sr_slide_iupd'
            ),
            '#attributes' => array(
                'class' => array(
                    'add-slider'
                )
            ),
            '#weight' => -80001,
            '#prefix' => '<div id="slider-buttons">',
            '#suffix' => '<div id="slider-settings-button" class="slider-settings">General Settings</div></div>'
        );
        $form['slider']['width']             = array(
            '#type' => 'textfield',
            '#title' => t('Width'),
            '#field_suffix' => t('px'),
            '#description' => t('Slider width'),
            '#size' => 10,
            '#required' => TRUE,
            '#default_value' => isset($settings['slider']['width']) ? $settings['slider']['width'] : 1005,
            '#prefix' => '<div id="revolution-slider-settings-inspiro"><table width="1005" border="0" cellpadding="0" cellspacing="0"><tr><td width="400" align="left" valign="top"><h2>' . t("Appearance") . '</h2>' . '<div id="slider-width">',
            '#suffix' => '</div>',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            )
        );
        $form['slider']['height']            = array(
            '#type' => 'textfield',
            '#title' => t('Height'),
            '#field_suffix' => t('px'),
            '#description' => t('Slider height'),
            '#size' => 10,
            '#required' => TRUE,
            '#default_value' => isset($settings['slider']['height']) ? $settings['slider']['height'] : 420,
            '#prefix' => '<div id="slider-height">',
            '#suffix' => '</div></div>',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            )
        );
        $form['slider']['show_timerbar']     = array(
            '#type' => 'radios',
            '#title' => t('Show Timer Line'),
            '#description' => t('Show the top running timer line'),
            '#default_value' => isset($settings['slider']['show_timerbar']) ? $settings['slider']['show_timerbar'] : "<div class='tp-bannertimer tp-bottom'></div>",
            '#prefix' => '<div id="slider-stop_on_hover">',
            '#options' => array(
                "<div class='tp-bannertimer tp-bottom'></div>" => t("Show"),
                "" => t("Hide")
            ),
            '#suffix' => '</div>'
        );
        $form['slider']['delay']             = array(
            '#type' => 'textfield',
            '#title' => t('Delay'),
            '#field_suffix' => t('px'),
            '#description' => t('The time one slide stays on the screen in Milliseconds'),
            '#size' => 10,
            '#required' => TRUE,
            '#default_value' => isset($settings['slider']['delay']) ? $settings['slider']['delay'] : 9000,
            '#prefix' => '<div id="slider-revolution-settings"><div id="slider-delay">',
            '#suffix' => '</div></td><td width="50"></td>',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            )
        );
        $form['slider']['touchenabled']      = array(
            '#type' => 'radios',
            '#title' => t('Touch Enabled'),
            '#description' => t('Enable Swipe Function on touch devices'),
            '#default_value' => isset($settings['slider']['touchenabled']) ? $settings['slider']['touchenabled'] : "on",
            '#prefix' => '<td width="500" align="left" valign="top"><h2>' . t("General Settings") . '</h2>' . '<div id="slider-touchenabled">',
            '#options' => array(
                "on" => t("On"),
                "off" => t("Off")
            ),
            '#suffix' => '</div>'
        );
        $form['slider']['stop_on_hover']     = array(
            '#type' => 'radios',
            '#title' => t('Stop On Hover'),
            '#description' => t('Stop the Timer when hovering the slider'),
            '#default_value' => isset($settings['slider']['stop_on_hover']) ? $settings['slider']['stop_on_hover'] : "on",
            '#prefix' => '<div id="slider-stop_on_hover">',
            '#options' => array(
                "on" => t("On"),
                "off" => t("Off")
            ),
            '#suffix' => '</div>'
        );
        $form['slider']['lazyload']           = array(
            '#type' => 'radios',
            '#title' => t('Lazy Load'),
            '#description' => t('The lazy load means that the images will be loaded by demand, it speeds the loading of the slider.'),
            '#default_value' => isset($settings['slider']['lazyload']) ? $settings['slider']['lazyload'] : "off",
            '#prefix' => '<div id="slider-lazyload">',
            '#options' => array(
                "on" => t("On"),
                "off" => t("Off")
            ),
            '#suffix' => '</div>'
        );
        $form['slider']['shuffle']           = array(
            '#type' => 'radios',
            '#title' => t('Shuffle Mode'),
            '#description' => t('Turn Shuffle Mode on and off! Will be randomized only once at the start.'),
            '#default_value' => isset($settings['slider']['shuffle']) ? $settings['slider']['shuffle'] : "off",
            '#prefix' => '<div id="slider-shuffle">',
            '#options' => array(
                "on" => t("On"),
                "off" => t("Off")
            ),
            '#suffix' => '</div></div></td></tr></table></div>'
        );
        $form['slider']['layers']['sorting'] = array(
            '#type' => 'container',
            '#prefix' => '<div id="revolution-slider-sorting">',
            '#suffix' => '</div>'
        );
        if (isset($settings['slider']['layers'])) {
            foreach ($settings['slider']['layers'] as $SlideId => $Slide) {
                $form['slider']['layers'][$SlideId]                                 = array(
                    '#type' => 'fieldset',
                    '#title' => isset($Slide['title']) ? $Slide['title'] : t('Slide @number', array(
                        '@number' => $SlideId + 1
                    )),
                    '#group' => 'layers',
                    '#attributes' => array(
                        'class' => array(
                            'layer-fieldset layer-identity'
                        )
                    )
                );
                $dragAreaTop = '<div id="slider-buttons"><div id="slider-change-' . $SlideId . '-background-button" class="slider-change-background">Change Background</div><div id="slider-change-' . $SlideId . '-settings-button" class="slider-change-settings">Slide Settings</div><div id="slider-close-' . $SlideId . '-button" class="slider-close-button slider-change-settings" parent_id="edit-slider-layers-' . $SlideId . '">Close</div></div>';
                $form['slider']['layers'][$SlideId]['create_sublayer']['text-html'] = array(
                    '#type' => 'submit',
                    '#value' => t('Add Layer: Text/HTML'),
                    '#name' => "create-sublayer-" . $SlideId,
                    '#submit' => array(
                        'omega_sr_sublayer_create'
                    ),
                    '#attributes' => array(
                        'class' => array(
                            'add-layer'
                        )
                    ),
                    '#prefix' => '<div id="slider-buttons">'
                );
                $form['slider']['layers'][$SlideId]['create_sublayer']['image']     = array(
                    '#type' => 'submit',
                    '#value' => t('Add Layer: Image'),
                    '#name' => "create-sublayer-" . $SlideId,
                    '#submit' => array(
                        'omega_sr_sublayer_create'
                    ),
                    '#attributes' => array(
                        'class' => array(
                            'add-layer'
                        )
                    )
                );
                $form['slider']['layers'][$SlideId]['create_sublayer']['video']     = array(
                    '#type' => 'submit',
                    '#value' => t('Add Layer: Video'),
                    '#name' => "create-sublayer-" . $SlideId,
                    '#submit' => array(
                        'omega_sr_sublayer_create'
                    ),
                    '#attributes' => array(
                        'class' => array(
                            'add-layer'
                        )
                    ),
                    '#suffix' => '<div id="delete-layer-' . $SlideId . '-button" class="layer-delete">Delete Layer </div></div>' . $dragAreaTop
                );
                $form['slider']['layers'][$SlideId]['delete']                       = array(
                    '#type' => 'submit',
                    '#name' => "delete-" . $SlideId,
                    '#default_value' => t('Delete Slide'),
                    '#submit' => array(
                        'omega_sr_slide_iupd'
                    ),
                    '#attributes' => array(
                        'class' => array(
                            'layer-delete-all'
                        )
                    ),
                    '#prefix' => '<div class="slider-buttons-sort" id="slider-delete-button-' . $SlideId . '">',
                    '#suffix' => '</div>'
                );


        		 $form['slider']['layers'][$SlideId]['background_upload'] = array(
                '#type' => 'container',
                '#attributes' => array('class' => array('upload')),
              );

         $form['slider']['layers'][$SlideId]['background_upload']['file']    = array(
                    '#type' => 'file',
                    '#name' => "files[backgrounds-" . $SlideId . "]",
                    '#title' => t('Upload background'),
                    '#description' => t("Attention: Min/Max height 500px;"),
                    '#prefix' => '<div id="upload-layer-' . $SlideId . '-background-image" class="upload-layer-background-image">',

                );

              $form['slider']['layers'][$SlideId]['background_upload']['submit'] = array(
                '#type' => 'submit',
                '#value' => t('Upload'),
        		'#name' => "Slide-{$SlideId}-bg-upload",
        		'#attributes' => array(
                        'class' => array(
                            'upload-button'
                        )
                    ),
              );

              $form['slider']['layers'][$SlideId]['background_upload']['cancel'] = array(
        		'#markup' => '<input id="reset" type="reset" value="reset" class="cancel-button" />',
        		'#weight' => 1000,
        		'#suffix' => '</div>'
              );

                $form['slider']['layers'][$SlideId]['background']                   = array(
                    '#type' => 'hidden',
                    '#value' => isset($Slide['background']) ? $Slide['background'] : ''
                );
                $form['slider']['layers'][$SlideId]['settings']                     = array(
                    '#type' => 'container',
                    '#prefix' => '<div id="slider-change-' . $SlideId . '-settings" class="slider-change-settings-container">',
                    '#suffix' => '</div>',
                    '#tree' => TRUE
                );
                $form['slider']['layers'][$SlideId]['settings']['transition']       = array(
                    '#type' => 'select',
                    '#title' => t("Transition"),
                    '#options' => $arrTransitions,
                    '#default_value' => isset($Slide['settings']['transition']) ? $Slide['settings']['transition'] : 'random',
                    '#description' => t("The appearance transition of this slide."),
                    '#prefix' => '<div id="transition-select">',
                    '#suffix' => '</div>'
                );
                $form['slider']['layers'][$SlideId]['settings']['slot']             = array(
                    '#title' => t("Slot Amount"),
                    '#description' => t("The number of slots or boxes the slide is divided into. If you use boxfade, over 7 slots can be juggy."),
                    '#type' => 'textfield',
                    '#attributes' => array(
                        'class' => array(
                            'shortfield'
                        )
                    ),
                    '#default_value' => isset($Slide['settings']['slot']) ? $Slide['settings']['slot'] : '7'
                );
                $form['slider']['layers'][$SlideId]['settings']['slide_id']             = array(
                    '#title' => t("Slide id attribute"),
                    '#description' => t("The slide id html attribute."),
                    '#type' => 'textfield',
                    '#default_value' => isset($Slide['settings']['slide_id']) ? $Slide['settings']['slide_id'] : 'slide-'.$SlideId
                );
                $form['slider']['layers'][$SlideId]['settings']['transition_speed'] = array(
                    '#title' => t("Transition Duration"),
                    '#description' => t("The duration of the transition (Default:300, min: 100 max 2000). "),
                    '#type' => 'textfield',
                    '#attributes' => array(
                        'class' => array(
                            'shortfield'
                        )
                    ),
                    '#default_value' => isset($Slide['settings']['transition_speed']) ? $Slide['settings']['transition_speed'] : '300'
                );
                $form['slider']['layers'][$SlideId]['settings']['weight']           = array(
                    '#type' => 'select',
                    '#options' => $options['weight'],
                    '#attributes' => array(
                        'class' => array(
                            'hide'
                        )
                    ),
                    '#default_value' => isset($Slide['settings']['weight']) ? $Slide['settings']['weight'] : ''
                );
                $form['slider']['layers'][$SlideId]['sliderArea']                   = array(
                    '#type' => 'container',
                    '#attributes' => array(
                        'class' => array(
                            'sliderArea'
                        ),
                        'style' => "position:relative;height:".$settings['slider']['height']."px;width:".$settings['slider']['width']."px;clear:both;"
                    ),
                    '#suffix' => '<table width="1005" border="0" cellpadding="0" cellspacing="0"><tr><td width="600" align="left" valign="top"><h2>' . t("Layer Parameters") . '</h2>'
                );
                if (isset($Slide['background']) && !empty($Slide['background'])) {
                    $backgroundimgGetInfo                                                    = image_get_info($Slide['background']);
                    $ml                                                                      = -$backgroundimgGetInfo['width'] / 2;
                    $mt                                                                      = -$backgroundimgGetInfo['height'] / 2;

        			$default_img_height = $settings['slider']['height'];
        			$default_img_width = $settings['slider']['width'];

        			$img_height = $backgroundimgGetInfo['height'];
        			$img_width = $backgroundimgGetInfo['width'];

        			$new_img_height = $img_height;
        			$new_img_width = $img_width;


        			if( $img_height >= $default_img_height && $img_width >= $default_img_width )
        			{
        				$img_ratio = $default_img_height / $img_height;

        				$new_img_height = $default_img_height;
        				$new_img_width = $img_ratio * $img_width;

        				$ml = -( $new_img_width - $default_img_width ) / 2;
        				$mt = 0;

        				if( $new_img_width < $default_img_width )
        				{
        					$new_img_width = $default_img_width+50;
        					$new_img_height = ( $new_img_width / $img_width ) * $img_height;
        					$ml = -25;
        					$mt = 0;
        				}
        			}
        			else if( $img_height > $default_img_height )
        			{


        				$img_ratio = $default_img_height / $img_height;
        				$new_img_height = $img_ratio * $img_height;
        				$new_img_width = $img_ratio * $img_width;
        				$ml = $img_ratio * $ml;
        				$mt = $img_ratio * $mt;

        				if( $new_img_width < $default_img_width )
        				{
        					$new_img_width = $default_img_width;
        					$new_img_height = ( $new_img_width / $img_width ) * $img_height;
        					$ml = -25;
        					$mt = 0;
        				}

        			}
        			else
        			{
        				if( $new_img_width < $default_img_width )
        				{
        					$new_img_width = $default_img_width;
        					$new_img_height = ( $new_img_width / $img_width ) * $img_height;
        					$ml = -25;
        					$mt = 0;
        				}
        			}

                    $form['slider']['layers'][$SlideId]['sliderArea']['background']['layer'] = array(
                        '#markup' => theme_image(array(
                            'path' => file_create_url($Slide['background']),
                            'attributes' => array(
                                'class' => array(
                                    'background'
                                ),
                                'style' => "position:absolute;margin-top:" . $mt . "px;margin-left:" . $ml . "px; height: ".$new_img_height."px; width:".$new_img_width."px;"
                            )
                        ))
                    );
                }
                if (isset($Slide['sublayers'])) {
                    $form['slider']['layers'][$SlideId]['sublayers'] = array(
                        '#type' => 'container',
                        '#attributes' => array(
                            'class' => array(
                                'slider-layer-properties'
                            )
                        )
                    );
                    foreach ($Slide['sublayers'] as $LayerId => $sublayer) {
                        $id_class = "element-" . $SlideId . "-" . $LayerId;
                        $type     = @$sublayer['type'];
                        $slx      = $sublayer['x'];
                        $sly      = $sublayer['y'];
                        $slw      = $sublayer['weight'];
                        switch ($type) {
                            case 'text-html':
                                $form['slider']['layers'][$SlideId]['sublayers'][$LayerId] = _omega_sr_slider_text_html_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly, $arrStyles);
                                break;
                            case 'image':
                                $form['slider']['layers'][$SlideId]['sublayers'][$LayerId] = _omega_sr_slider_image_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly);
                                break;
                            case 'video':
                                $form['slider']['layers'][$SlideId]['sublayers'][$LayerId] = _omega_sr_slider_video_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly, $arrStyles);
                                break;
                        }
                        $content               = '<div style="position:absolute;left:' . $slx . 'px;top:' . $sly . 'px;z-index:' . $slw . '" id="' . $id_class . '" class="sublayer">';
                        $text_html_div_content = isset($sublayer['text-html']) ? $sublayer['text-html'] : 'Caption text ' . $LayerId;
                        $text_html_div_style   = isset($sublayer['text-style']) ? $sublayer['text-style'] : 'tp-caption Default_text_medium';
                        switch ($type) {
                            case 'text-html':
                                $content .= "<div id='element-" . $SlideId . "-" . $LayerId . "-text' class='" . $text_html_div_style . "'>" . $text_html_div_content . "</div>";
                                break;
                            case 'image':
                                if (isset($sublayer['image']['path'])) {
                                    $path = file_create_url($sublayer['image']['path']);
                                    $content .= "<img src='{$path}' />";
                                }
                                break;
                            case 'video':
                                if (isset($sublayer['video-code'])) {
                                    $videoID     = $sublayer['video-code'];
                                    $videoType   = is_numeric($videoID) ? "vimeo" : "youtube";
                                    $videoWidth  = $sublayer['video-width'];
                                    $videoHeight = $sublayer['video-height'];
                                    if ($videoType == "youtube"):
                                        $content .= '<div class="caption"><iframe src="http://www.youtube.com/embed/' . $videoID . '?hd=1&amp;wmode=opaque&amp;controls=1&amp;showinfo=0" width="' . $videoWidth . '" height="' . $videoHeight . '" style="width:' . $videoWidth . 'px;height:' . $videoHeight . 'px;"></iframe></div>';
                                    else:
                                        $content .= '<div class="caption" data-autoplay="false"><iframe src="http://player.vimeo.com/video/' . $videoID . '?title=0&amp;byline=0&amp;portrait=0" width="' . $videoWidth . '" height="' . $videoHeight . '"></iframe></div>';
                                    endif;
                                }
                                break;
                        }
                        $content .= '<div class="drag-layer"></div></div>';
                        $form['slider']['layers'][$SlideId]['sliderArea'][$LayerId] = array(
                            '#markup' => $content
                        );
                    }
                }
                $form['slider']['layers'][$SlideId]['wrap'] = array(
                    '#type' => 'markup',
                    '#suffix' => '</td><td width="30"></td><td width="330" align="left" valign="top"><h2>' . t("Layers Sorting") . '<div style="width:60px; float:right; text-align:center;">' . t("Delay") . '</div></h2><div id="edit-slider-layers-' . $SlideId . '-sort" class="layer-sorting-box"><div></td></tr></table>'
                );
            }
    }
}
function _omega_sr_slider_type($sublayer)
{
    $type_form = array(
        '#type' => 'hidden',
        '#default_value' => $sublayer['type']
    );
    return $type_form;
}
function _omega_sr_slider_action_container($SlideId, $LayerId)
{
    $action_container_form = array(
        '#type' => 'container',
        '#attributes' => array(
            'class' => array(
                'hide'
            )
        ),
        'delete' => _omega_sr_slider_action_container_delete($SlideId, $LayerId)
    );
    return $action_container_form;
}
function _omega_sr_slider_action_container_delete($SlideId, $LayerId)
{
    $delete_form = array(
        '#type' => 'submit',
        '#id' => 'delete-layer-' . $SlideId . '-button',
        '#name' => "delete-" . $SlideId . "-" . $LayerId,
        '#default_value' => t('Delete Layer'),
        '#attributes' => array(
            'class' => array(
                'layer-delete-all'
            )
        ),
        '#submit' => array(
            'omega_sr_sublayer_delete'
        )
    );
    return $delete_form;
}
function _omega_sr_slider_x($slx, $id_class)
{
    $x_form = array(
        '#type' => 'hidden',
        '#default_value' => isset($slx) ? $slx : '50',
        '#attributes' => array(
            'class' => array(
                'x-pos',
                $id_class
            )
        )
    );
    return $x_form;
}
function _omega_sr_slider_y($sly, $id_class)
{
    $y_form = array(
        '#type' => 'hidden',
        '#default_value' => isset($sly) ? $sly : '50',
        '#attributes' => array(
            'class' => array(
                'y-pos',
                $id_class
            )
        )
    );
    return $y_form;
}
function _omega_sr_slider_weight($options, $sublayer)
{
    $weight_form = array(
        '#type' => 'select',
        '#options' => $options['weight'],
        '#attributes' => array(
            'class' => array(
                'hide'
            )
        ),
        '#default_value' => isset($sublayer['weight']) ? $sublayer['weight'] : '0'
    );
    return $weight_form;
}
function _omega_sr_slider_video_code($sublayer)
{
    $video_code_form = array(
        '#type' => 'textfield',
        '#title' => t('Video ID'),
        '#default_value' => isset($sublayer['video-code']) ? $sublayer['video-code'] : '',
        '#attributes' => array(
            'class' => array(
                'video-code-set'
            )
        )
    );
    return $video_code_form;
}
function _omega_sr_slider_video_width($sublayer)
{
    $video_width_form = array(
        '#type' => 'textfield',
        '#title' => t('Width'),
        '#default_value' => isset($sublayer['video-width']) ? $sublayer['video-width'] : '',
        '#attributes' => array(
            'class' => array(
                'shortfield'
            )
        ),
        '#prefix' => '<div id="video-width">',
        '#suffix' => '</div>'
    );
    return $video_width_form;
}
function _omega_sr_slider_video_height($sublayer)
{
    $video_height_form = array(
        '#type' => 'textfield',
        '#title' => t('Height'),
        '#default_value' => isset($sublayer['video-height']) ? $sublayer['video-height'] : '',
        '#attributes' => array(
            'class' => array(
                'shortfield'
            )
        ),
        '#prefix' => '<div id="video-height">',
        '#suffix' => '</div>'
    );
    return $video_height_form;
}
function _omega_sr_slider_text_html($sublayer, $LayerId)
{
    $text_html_form = array(
        '#type' => 'textarea',
        '#title' => t('HTML/Text'),
        '#default_value' => isset($sublayer['text-html']) ? $sublayer['text-html'] : t('Caption text@sid', array(
            '@sid' => $LayerId
        )),
        '#cols' => 20,
        '#rows' => 5,
        '#resizable' => false,
        '#attributes' => array(
            'class' => array(
                'text-html-text-set'
            ),
            'style' => array(
                'height:160px;'
            )
        )
    );
    return $text_html_form;
}
function _omega_sr_slider_title($sublayer)
{
    $title_form = array(
        '#type' => 'textfield',
        '#title' => t('Layer name'),
        '#default_value' => $sublayer['title']
    );
    return $title_form;
}
function _omega_sr_slider_text_styles($arrStyles, $sublayer)
{
    $styles_form = array(
        '#title' => t("Font style"),
        '#type' => 'select',
        '#options' => $arrStyles,
        '#default_value' => isset($sublayer['text-style']) ? $sublayer['text-style'] : '',
        '#attributes' => array(
            'class' => array(
                'text-html-style-set'
            ),
            'style' => array(
                'clear:both; overflow:hidden;display:block;'
            )
        )
    );
    return $styles_form;
}
function _omega_sr_slider_image_upload_form($SlideId, $LayerId)
{
    $upload_image_form = array(
        '#type' => 'file',
        '#name' => "files[sublayers-" . $SlideId . "-" . $LayerId . "]",
        '#title' => t('Upload/Update layer image')
    );
    return $upload_image_form;
}
function _omega_sr_slider_properties($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations)
{
    $properties_form = array(
        'animation' => array(
            '#title' => t("Animation"),
            '#type' => 'select',
            '#options' => $arrAnimations,
            '#default_value' => isset($sublayer['properties']['animation']) ? $sublayer['properties']['animation'] : '',
            '#prefix' => '<div id="animation-select">',
            '#suffix' => '</div>'
        ),
        'easingin' => array(
            '#type' => 'select',
            '#title' => t("Easing"),
            '#options' => $arrEasing,
            '#default_value' => isset($sublayer['properties']['easingin']) ? $sublayer['properties']['easingin'] : '',
            '#empty_option' => t('Select easing effect'),
            '#prefix' => '<div id="easing-select">',
            '#suffix' => '</div>'
        ),
        'speed' => array(
            '#title' => t("Speed"),
            '#type' => 'textfield',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            ),
            '#default_value' => isset($sublayer['properties']['speed']) ? $sublayer['properties']['speed'] : ''
        ),
        'delay' => array(
            '#type' => 'textfield',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            ),
            '#default_value' => isset($sublayer['properties']['delay']) ? $sublayer['properties']['delay'] : '0',
            '#prefix' => '<div id="edit-slider-layers-' . $SlideId . '-sublayers-' . $LayerId . '-properties-delay">',
            '#suffix' => '</div>'
        ),
        'revslider-end-transition' => array(
            '#type' => 'radios',
            '#title' => t('End transition (Optional)'),
            '#options' => array(
                'yes' => t("Show param"),
                'no' => t("Hide param")
            ),
            '#default_value' => isset($sublayer['properties']['revslider-end-transition']) ? $sublayer['properties']['revslider-end-transition'] : 'no',
            '#prefix' => '<div id="revslider-end-transition-checkbox">',
            '#suffix' => '</div><div id="revslider-end-transition-' . $SlideId . '-' . $LayerId . '">'
        ),
        'endspeed' => array(
            '#title' => t("End Speed"),
            '#type' => 'textfield',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            ),
            '#default_value' => isset($sublayer['properties']['endspeed']) ? $sublayer['properties']['endspeed'] : '',
            '#prefix' => "<div id='revslider-end-transition'><div id='endspeed-input'>",
            '#suffix' => '</div>'
        ),
        'enddelay' => array(
            '#title' => t("End Time"),
            '#type' => 'textfield',
            '#attributes' => array(
                'class' => array(
                    'shortfield'
                )
            ),
            '#default_value' => isset($sublayer['properties']['enddelay']) ? $sublayer['properties']['enddelay'] : '0',
            '#prefix' => '<div id="enddelay-input">',
            '#suffix' => '</div>'
        ),
        'endanimation' => array(
            '#title' => t("End Animation"),
            '#type' => 'select',
            '#options' => $arrEndAnimations,
            '#default_value' => isset($sublayer['properties']['endanimation']) ? $sublayer['properties']['endanimation'] : '',
            '#prefix' => '<div id="endanimation-select">',
            '#suffix' => '</div>'
        ),
        'endeasingin' => array(
            '#type' => 'select',
            '#title' => t("Easing"),
            '#options' => $arrEasing,
            '#default_value' => isset($sublayer['properties']['endeasingin']) ? $sublayer['properties']['endeasingin'] : '',
            '#empty_option' => t('Select easing effect'),
            '#prefix' => '<div id="endeasing-select">',
            '#suffix' => '</div>'
        )
    );
    return $properties_form;
}
function _omega_sr_slider_image($sublayer)
{
    $img_form = array();
    if (isset($sublayer['image']['path'])) {
        $url              = file_create_url($sublayer['image']['path']);
        $img_form['path'] = array(
            '#type' => 'hidden',
            '#default_value' => $sublayer['image']['path']
        );
    }
    return $img_form;
}
function _omega_sr_slider_text_html_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly, $arrStyles)
{
    $complete_form = array(
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#attributes' => array(
            'class' => array(
                $id_class
            )
        ),
        '#prefix' => '<div id="slider-' . $SlideId . '-layer-' . $LayerId . '-properties" class="layer-properties">',
        '#suffix' => '</div>',
        'title' => _omega_sr_slider_title($sublayer),
        'text-style' => _omega_sr_slider_text_styles($arrStyles, $sublayer),
        'text-html' => _omega_sr_slider_text_html($sublayer, $LayerId),
        'x' => _omega_sr_slider_x($slx, $id_class),
        'y' => _omega_sr_slider_y($sly, $id_class),
        'weight' => _omega_sr_slider_weight($options, $sublayer),
        'properties' => _omega_sr_slider_properties($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations),
        'action_container' => _omega_sr_slider_action_container($SlideId, $LayerId),
        'type' => _omega_sr_slider_type($sublayer)
    );
    return $complete_form;
}
function _omega_sr_slider_image_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly)
{
    $complete_form = array(
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#attributes' => array(
            'class' => array(
                $id_class
            )
        ),
        '#prefix' => '<div id="slider-' . $SlideId . '-layer-' . $LayerId . '-properties" class="layer-properties">',
        '#suffix' => '</div>',
        'title' => _omega_sr_slider_title($sublayer),
        'x' => _omega_sr_slider_x($slx, $id_class),
        'y' => _omega_sr_slider_y($sly, $id_class),
        'weight' => _omega_sr_slider_weight($options, $sublayer),
        'properties-image' => _omega_sr_slider_image_upload_form($SlideId, $LayerId),
        'properties' => _omega_sr_slider_properties($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations),
        'image' => _omega_sr_slider_image($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly),
        'action_container' => _omega_sr_slider_action_container($SlideId, $LayerId),
        'type' => _omega_sr_slider_type($sublayer)
    );
    return $complete_form;
}
function _omega_sr_slider_video_form($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations, $id_class, $options, $slx, $sly)
{
    $complete_form = array(
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#attributes' => array(
            'class' => array(
                $id_class
            )
        ),
        '#prefix' => '<div id="slider-' . $SlideId . '-layer-' . $LayerId . '-properties" class="layer-properties">',
        '#suffix' => '</div>',
        'title' => _omega_sr_slider_title($sublayer),
        'video-code' => _omega_sr_slider_video_code($sublayer),
        'video-width' => _omega_sr_slider_video_width($sublayer),
        'video-height' => _omega_sr_slider_video_height($sublayer),
        'x' => _omega_sr_slider_x($slx, $id_class),
        'y' => _omega_sr_slider_y($sly, $id_class),
        'weight' => _omega_sr_slider_weight($options, $sublayer),
        'properties' => _omega_sr_slider_properties($sublayer, $SlideId, $LayerId, $arrAnimations, $arrEasing, $arrEndAnimations),
        'action_container' => _omega_sr_slider_action_container($SlideId, $LayerId),
        'type' => _omega_sr_slider_type($sublayer)
    );
    return $complete_form;
}
