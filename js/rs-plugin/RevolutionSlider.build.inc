<?php
		$settings['slider'] = theme_get_setting('slider', 'omega_sr');

		if( !empty( $settings['slider']['layers']))
		{
        $settings['slider'] = theme_get_setting('slider', 'omega_sr');



		//omega_sr Slider variables
        $Slider             = $settings['slider']['layers'];
        @usort($Slider, 'compareWeight');
        $variables['page']['revslider']['slider_container'] = array(
            '#type' => 'markup',
            '#prefix' => '<div class="fullwidthbanner-container"><div class="fullwidthbanner"><ul>',
            '#suffix' => '</ul>' . $settings['slider']['show_timerbar'] . '</div></div>'
        );
        if (!empty($Slider)){
            foreach ($Slider as $sliderId => $SliderItem) {
                if (!empty($SliderItem)) {
                    // Set slider param
                    $not_param = array(
                        'weight',
                        'title',
                        'background',
                        'sublayers'
                    );
                    $param     = array();
                    foreach ($SliderItem as $property => $value) {
                        if (!in_array($property, $not_param) && !empty($value)) {
                            @$param[$property] = "{$property}: {$value};";
                        }
                    }
                    $slideTransition                                                         = isset($SliderItem['settings']['transition']) ? $SliderItem['settings']['transition'] : 'random';
                    $slideSlot                                                               = isset($SliderItem['settings']['slot']) ? $SliderItem['settings']['slot'] : '7';
                    $slideSpeed                                                              = isset($SliderItem['settings']['transition_speed']) ? $SliderItem['settings']['transition_speed'] : '';
                    $slideDelay                                                              = isset($SliderItem['settings']['delay']) ? $SliderItem['settings']['delay'] : '';
                    $variables['page']['revslider']['slider_container']['slider'][$sliderId] = array(
                        '#type' => 'markup',
                        '#prefix' => '<li '.(isset($SliderItem['settings']['slide_id']) ? 'id="'.$SliderItem['settings']['slide_id'].'"' : '').' data-transition="' . $slideTransition . '" data-slotamount="' . $slideSlot . '" data-masterspeed="' . $slideSpeed . '" >',
                        '#suffix' => '</li>'
                    );

					if($settings['slider']['lazyload'] == 'on') {
						$SliderItemBackgroundMarkup = "<img src='" . base_path() . drupal_get_path('theme', 'omega_sr') . "/js/rs-plugin/images/dummy.png' data-lazyload='" . file_create_url($SliderItem['background']) . "'/>";
					}else {
						$SliderItemBackgroundMarkup = "<img src='" . @file_create_url($SliderItem['background']) . "'/>";
					}

                    if (!empty($SliderItem['background'])) {
                        $variables['page']['revslider']['slider_container']['slider'][$sliderId]['bg'] = array(
                            '#type' => 'markup',
                            '#markup' => $SliderItemBackgroundMarkup,
                        );
                    }

                    if (!empty($SliderItem['sublayers'])) {
                        $i = 2;
                        foreach ($SliderItem['sublayers'] as $layerId => $layer) {
                            $layerAnimation    = isset($layer["properties"]["animation"]) ? $layer["properties"]["animation"] : '';
                            $layerDelay        = isset($layer["properties"]["delay"]) ? $layer["properties"]["delay"] : '';
                            $layerEasingin     = isset($layer["properties"]["easingin"]) ? $layer["properties"]["easingin"] : '';
                            $layerSpeed        = isset($layer["properties"]["speed"]) ? $layer["properties"]["speed"] : '';
                            $layerEndSpeed     = isset($layer["properties"]["endspeed"]) ? $layer["properties"]["endspeed"] : '';
                            $layerEndDelay     = isset($layer["properties"]["enddelay"]) ? $layer["properties"]["enddelay"] : '';
                            $layerEndEasingin  = isset($layer["properties"]["endeasingin"]) ? $layer["properties"]["endeasingin"] : '';
                            $layerEndAnimation = isset($layer["properties"]["endanimation"]) ? $layer["properties"]["endanimation"] : '';
							$revsliderendtransition = isset($layer["properties"]["revslider-end-transition"]) ? $layer["properties"]["revslider-end-transition"] : 'no';

                            $videoCode     = isset($layer['video-code']) ? $layer['video-code'] : '';
							$videoWidth    = isset($layer['video-width']) ? $layer['video-width'] : '320';
							$videoHeight   = isset($layer['video-height']) ? $layer['video-height'] : '220';

						if(is_array(@$layer['properties'])){
							foreach (@$layer['properties'] as $property => $value) {
                                $param[$property] = "{$property}: {$value};";
                            }
}
                            if ($revsliderendtransition == "yes") {
                                $optional_param = ' data-end="' . $layerEndDelay . '" data-endspeed="' . $layerEndSpeed . '" data-endeasing="' . $layerEndEasingin . '"';
                            } else {
                                $optional_param = "";
                            }
                            $htmlParams = 'data-x="' . $layer["x"] . '" data-y="' . $layer["y"] . '" data-speed="' . $layerSpeed . '" data-start="' . $layerDelay . '" data-easing="' . $layerEasingin . '" style="z-index:' . $layer["weight"] . '"';
                            $htmlParams = $htmlParams . " " . $optional_param;
                            $content    = "";
                            switch (@$layer['type']) {
                                case 'text-html':
                                    if (isset($layer['text-html'])) {
                                        $list = explode("\n", $layer['text-html']);
                                        //kpr($list);
                                        if (count($list)){
                                            $items = array();
                                            foreach ($list as $key => $item) {
                                                $items[] = array(
                                                    'data' => t(strip_tags($item)),
                                                    'class' => array('line-'.$key),

                                                    );
                                            }
                                            $text_html = theme('item_list', array('items' => $items,'attributes'=>array('class'=>array('slide-'.$sliderId))));
                                            //kpr($text_html_);
                                        } else $text_html = t($layer['text-html']);
                                        $content .= '<div class="caption ' . $layer["text-style"] . ' ' . $layerAnimation . ' ' . $layerEndAnimation . ' " ' . $htmlParams . ' >' . $text_html . '</div>';
                                    }
                                    break;
                                case 'image':
                                    if (isset($layer['image']['path'])) {
                                        $content .= '<div class="caption ' . $layerAnimation . ' ' . $layerEndAnimation . ' " ' . $htmlParams . ' ><img src="' . file_create_url($layer['image']['path']) . '" /></div>';
                                    }
                                    break;
                                case 'video':
                                    $videoID = $videoCode;
                                    if ($videoID != "") {
                                        $videoType   = is_numeric($videoID) ? "vimeo" : "youtube";

                                        if ($videoType == "youtube"): //youtube
                                            $content .= '<div class="caption ' . $layerAnimation . ' ' . $layerEndAnimation . ' " ' . $htmlParams . ' ><iframe src="http://www.youtube.com/embed/' . $videoID . '?

hd=1&amp;wmode=opaque&amp;controls=1&amp;showinfo=0" width="' . $videoWidth . '" height="' . $videoHeight . '"

style="width:' . $videoWidth . 'px;height:' . $videoHeight . 'px;"></iframe></div>';
                                        else: //vimeo
                                            $content .= '<div class="caption ' . $layerAnimation . ' ' . $layerEndAnimation . ' " ' . $htmlParams . ' ><iframe src="http://player.vimeo.com/video/' . $videoID . '?

title=0&amp;byline=0&amp;portrait=0;api=1" width="' . $videoWidth . '" height="' . $videoHeight . '"></iframe></div>';
                                        endif;
                                    }
                                    break;
                            }
                            $variables['page']['revslider']['slider_container']['slider'][$sliderId][$layerId] = array(
                                '#type' => 'markup',
                                '#markup' => $content
                            );
                            $i++;
                        }
                    }
                }
            }
        }


    }


    $build_slider_settings = "
	var tpj=jQuery;
	tpj.noConflict();
	tpj(document).ready(function() {
	if (tpj.fn.cssOriginal!=undefined)
		tpj.fn.css = tpj.fn.cssOriginal;
		tpj('.fullwidthbanner').revolution(
			{

				startheight:" . $settings['slider']['height'] . ",
				onHoverStop:'" . $settings['slider']['stop_on_hover'] . "',
				delay:" . $settings['slider']['delay'] . ",
				shuffle:'" . $settings['slider']['shuffle'] . "',
				touchenabled:'" . $settings['slider']['touchenabled'] . "',
				navigationType:'none',
				fullWidth:'on',
				fullScreen:'off',
				lazyLoad:'" . $settings['slider']['lazyload'] . "',
				shadow:0


			});
});";
    drupal_add_js($build_slider_settings, array('type' => 'inline'));
	drupal_add_css('.fullwidthbanner-container{width:100% !important; max-height:'. $settings['slider']['height'] . 'px !important; }', array('group' => CSS_THEME, 'type' => 'inline'));


