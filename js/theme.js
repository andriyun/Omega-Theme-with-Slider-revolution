
// Document ready
(function ($) {

  $(document).ready(function(){

   $('#selected-image-boxed').click(function() {
       $('#selected-image-boxed').addClass("selected-image");
     $('#selected-image-wide').removeClass("selected-image");
    });

   $('#selected-image-wide').click(function() {
       $('#selected-image-wide').addClass("selected-image");
     $('#selected-image-boxed').removeClass("selected-image");
    });

  //Sidebars
  $('#selected-sidebar-left').click(function() {
       $('#selected-sidebar-left').addClass("selected-image");
     $('#selected-sidebar-right').removeClass("selected-image");
     $('#selected-full-width').removeClass("selected-image");
    });

   $('#selected-sidebar-right').click(function() {
       $('#selected-sidebar-left').removeClass("selected-image");
     $('#selected-sidebar-right').addClass("selected-image");
     $('#selected-full-width').removeClass("selected-image");
    });

     $('#selected-full-width').click(function() {
        $('#selected-sidebar-left').removeClass("selected-image");
     $('#selected-sidebar-right').removeClass("selected-image");
     $('#selected-full-width').addClass("selected-image");
    });


  //Background type
  $('#selected-layout-color').click(function() {
       $('#selected-layout-color').addClass("selected-image");
     $('#selected-layout-pattern').removeClass("selected-image");
     $('#selected-layout-image').removeClass("selected-image");
    });

   $('#selected-layout-pattern').click(function() {
       $('#selected-layout-color').removeClass("selected-image");
     $('#selected-layout-pattern').addClass("selected-image");
     $('#selected-layout-image').removeClass("selected-image");
    });

     $('#selected-layout-image').click(function() {
       $('#selected-layout-color').removeClass("selected-image");
     $('#selected-layout-pattern').removeClass("selected-image");
     $('#selected-layout-image').addClass("selected-image");
    });


  if($("input[name='layout_mode']:checked").val() == 'boxed'){
    $('#selected-image-boxed').addClass("selected-image");
  }
  else{
    $('#selected-image-wide').addClass("selected-image");
  }

  if($("input[name='layout_background']:checked").val() == 'layout_color'){
    $('#selected-layout-color').addClass("selected-image");
  }

  if($("input[name='layout_background']:checked").val() == 'layout_image'){
    $('#selected-layout-image').addClass("selected-image");
  }
  if($("input[name='layout_background']:checked").val() == 'layout_pattern'){
    $('#selected-layout-pattern').addClass("selected-image");
  }

  if($("input[name='layout_background_pattern']:checked")){
    $('#selected-layout-' + $("input[name=\'layout_background_pattern\']:checked").val()).addClass("selected-image-pattern");
  }

  $("#layout_background_pattern_div label.option img").click(function(e) {
        $('.selected-image-pattern').removeClass('selected-image-pattern');
    $(this).addClass('selected-image-pattern');
    });



  //Color Header line Image or Color function
    var default_header_line_bg = $('#edit-header-line-bg').val();
  if(default_header_line_bg != 'color'){$('.form-item-header-line-bg-color').hide();}
    if(default_header_line_bg == 'color'){$('.form-item-header-line-bg-color').show();}
    $('#edit-header-line-bg').change(function(){$item_header_line_bg = $(this);if($item_header_line_bg.val() == 'color'){$('.form-item-header-line-bg-color').show();}else{$('.form-item-header-line-bg-color').hide();}});
    $('.color').after(('<div class="ls-colorpicker" />'));

    //Color Header line Image or Color function default_header_line_bg  form-item-header-line-bg-color
    var default_layout_mode = $("input[name='layout_mode']:checked").val();
  if(default_layout_mode != 'boxed'){$('#layout_background_div').hide();}
    if(default_layout_mode == 'boxed'){$('#layout_background_div').show();}

    $('#edit-layout-mode').change(function(){
    $default_layout_mode = $(this);
      if($("input[name='layout_mode']:checked").val() == 'boxed'){
          $('#layout_background_div').show();
        }
        else{
          $('#layout_background_div').hide();
          }
  });


  //Background
    var default_layout_background = $("input[name='layout_background']:checked").val();

  if(default_layout_background == 'layout_image'){$('#site_bg_preview_div').show();}else{$('#site_bg_preview_div').hide();}
  if(default_layout_background == 'layout_pattern'){$('#layout_background_pattern_div').show();}else{$('#layout_background_pattern_div').hide();}
  if(default_layout_background == 'layout_color'){$('#layout_background_color_div').show();}else{$('#layout_background_color_div').hide();}


    $('#edit-layout-background').change(function(){
    $default_layout_background = $(this);
      if($("input[name='layout_background']:checked").val() == 'layout_image'){
          $('#site_bg_preview_div').show();
        }
        else{
          $('#site_bg_preview_div').hide();
          }
    if($("input[name='layout_background']:checked").val() == 'layout_pattern'){
          $('#layout_background_pattern_div').show();
        }
        else{
          $('#layout_background_pattern_div').hide();
          }
    if($("input[name='layout_background']:checked").val() == 'layout_color'){
          $('#layout_background_color_div').show();
        }
        else{
          $('#layout_background_color_div').hide();
          }
  });


   var default_site_bg_color = $('#edit-site-bg-color').val();


    $('#edit-header-line-bg').change(function(){$item_header_line_bg = $(this);
    if($item_header_line_bg.val() == 'boxed'){$('.form-item-header-line-bg-color').show();}else{$('.form-item-site-bg-color').hide();}});
    $('.color').after(('<div class="ls-colorpicker" />'));


  jQuery('.ls-colorpicker').each(function() {
      var $item = $(this);
      $item.farbtastic( function(color) {
        $item.parent('.form-item.form-type-textfield').find('.color').val(color);
        $item.parent('.form-item.form-type-textfield').find('.color').css('background-color', color);
      }).hide();
    });
      jQuery('.color').focus(function() {jQuery(this).next().slideDown();});
      jQuery('.color').blur(function() {jQuery(this).next().slideUp();});

   });


})(jQuery);


(function ($) {


  Drupal.behaviors.omega_sr = {
        attach: function (context, settings) {

      // Revolution Slider draggable place
      $('.sublayer').draggable({containment: 'parent', scroll: false,
        stop: function(event, ui) {
          var id = $(this).attr('id');
          var pos = $(this).position();
          $('input.x-pos.' + id).val(pos.left);
          $('input.y-pos.' + id).val(pos.top);
        },
      });


        $('.sliderArea .sublayer').click(function() {

    var id=$(this).attr('id');
    var id_arr = id.split('-');
    var layer = id_arr[1];
    var sublayer = id_arr[2];


        $('.sublayer.active').removeClass('active');
    $(this).addClass('active');

    $('.layer-sorting-li').css('border-color', '#D3D3D3');
    $('li#layer-sorting-'+layer+'-'+sublayer).css('border-color', '#C9D411');

    $('.slider-layer-properties .layer-properties').hide();
    $("#slider-"+layer+"-layer-"+sublayer+'-properties').show();

    $('#layer-buttons .layer-delete').addClass('layer-delete-active');
    $('#edit-slider-layers-'+layer+'-delete-layer').attr('name', 'delete-'+layer+'-'+sublayer).addClass('layer-delete-active');
    $('#edit-slider-layers-'+layer+'-delete-layer').attr('id','edit-slider-layers-'+layer+'-sublayers-'+sublayer+'-action-container-delete');
    $('#edit-slider-layers-'+layer+'-sublayers-'+sublayer+'-action-container').hide();
    $('#delete-layer-'+layer+'-button').replaceWith($('#edit-slider-layers-'+layer+'-sublayers-'+sublayer+'-action-container').html());

    $('#edit-slider-layers-'+layer+'-sublayers-'+sublayer).show();

      });

  $('.layer-sorting-box').on('click', '.layer-sorting-li', function(e) {
        var elm_attr = $(this).attr('elm');
    var elm_arr = elm_attr.split('-');
    //var elm = +'-'+elm_arr[1];
    var layer = elm_arr[0];
    var sublayer = elm_arr[1];

    $('#delete-layer-'+layer+'-button').replaceWith($('#edit-slider-layers-'+layer+'-sublayers-'+sublayer+'-action-container').html());
    });

    $('.sliderArea').click(function(e) {



      if (!$(e.target).hasClass('drag-layer'))
      {
        $('.sublayer.active').removeClass('active');

        $('.layer-delete-active').removeClass('layer-delete-active');

        var id=$(this).attr('id');
        var id_arr = id.split('-');
        var layer = id_arr[3];
        var sublayer = id_arr[5];
        console.log(layer);

        $('#edit-slider-layers-'+layer+'-sublayers').find('fieldset').hide();

        $('.layer-sorting-li').css('border-color', '#D3D3D3');


        $('.slider-layer-properties .layer-properties').hide();
        $('#delete-layer-'+layer+'-button').replaceWith('<div id="delete-layer-'+layer+'-button" class="layer-delete">Delete Layer</div>');
      }
    $('#edit-slider-layers-'+layer+'-sublayers-'+sublayer).show();
      });

  $('.layer-change-image').click(function(e) {
    var id = $(this).attr('id');
    $('#'+id+'-upload').dialog({ modal: true, width: 500});
  });

  $(document).ready(function(e) {

    $(".add-layer.form-submit").click( function(e) {

      var id = $(this).attr('id');
      id = id.split('-');
      id = id[3];

      var bg_upload_id = "edit-slider-layers-"+id+"-background-upload-file";
      if(document.getElementById(bg_upload_id).files.length >= 1)
      {
        e.preventDefault();
        alert("Please submit changed background first");
      }

    });

    $(".slider-close-button").click( function(e) {



    });


    $('#revolution-slider-settings-inspiro').hide();
    $('#slider-settings-button').removeClass("clicked-once");

    $('#slider-settings-button').click(function() {
      if ($(this).hasClass("clicked-once")) {

        $('#revolution-slider-settings-inspiro').hide();
        $('#slider-settings-button').removeClass("clicked-once");

      }
      else {

        $('#revolution-slider-settings-inspiro').show();
        $('#slider-settings-button').addClass("clicked-once");

      }
     }
    );


    $(".slider-layer-properties .layer-properties").hide();


    $(".layer-identity").each(function(index, element) {
      var layer_id = $(this).attr('id');
      var sublayers_ul = '<ul id="'+layer_id+'-ardis_sublayers">';
      $(this).find(".form-wrapper fieldset").each(function(index, element) {
        var sublayer_id = $(this).attr('id');

        var sublayer_weight = $("#"+sublayer_id+"-weight").val();
        var sublayer_type = $("#"+sublayer_id+"-type").val();

        var elm_arr = sublayer_id.split('-');
        var elm = elm_arr[3]+'-'+elm_arr[5];
        var sublayer_legend = $('#edit-slider-layers-'+elm_arr[3]+'-sublayers-'+elm_arr[5]+'-title').val();


        sublayers_ul += '<li id="layer-sorting-'+elm_arr[3]+'-'+elm_arr[5]+'" class="ui-state-default layer-sorting-li" sublayer_weight="'+sublayer_id+'-weight" weight="'+sublayer_weight+'" elm="'+elm+'"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span>'+sublayer_legend+'<span style="float: right; margin-top: -2px; position: relative; right: 0;">'+$("#edit-slider-layers-"+elm_arr[3]+"-sublayers-"+elm_arr[5]+"-properties-delay").html()+'</span></li>';
        $(".form-item-slider-layers-"+elm_arr[3]+"-sublayers-"+elm_arr[5]+"-properties-delay").hide();
      });
      sublayers_ul += '</ul>';

      $("#"+layer_id+"-sort").append( sublayers_ul ).find('#'+layer_id+'-ardis_sublayers').sortable();
      var list = $('#'+layer_id+'-ardis_sublayers');
      var listItems = list.find('li').sort(function(a,b){ return $(b).attr('weight') - $(a).attr('weight'); });
      list.find('li').remove();
      list.append(listItems);

      var index_positions = Array();
      $("#"+layer_id+"-sort").find('#'+layer_id+'-ardis_sublayers').sortable({
        start: function(event, ui)
        {
          var i = 0;

          $('#'+layer_id+'-ardis_sublayers li').each(function(index, element) {
            var weight = $(this).attr('weight');
            if( weight != 'undefined' && weight != null )
            {
              index_positions[i] = $(this).attr('weight');
              i++;
            }
          });
        },
        update: function(event, ui) {

          $('#'+layer_id+'-ardis_sublayers li').each(function(index, element) {
            var pos = index_positions.length - index - 1;
            $(this).attr('weight', pos);
            var sublayer_weight = $(this).attr('sublayer_weight');
            $("#"+sublayer_weight).val(pos);
            var elm = $(this).attr('elm');
            $('#element-'+elm).css('z-index', pos);
          });

        }
      });

    });


    $('.layer-sorting-box ul li').click(function(e) {
      $('.layer-sorting-box ul li').css('border-color', '#D3D3D3')
            $(this).css('border-color', '#C9D411');

      var elm_attr = $(this).attr('elm');
      var elm_arr = elm_attr.split('-');

      var elm = elm_arr[0]+'-'+elm_arr[1];

      $('.sliderArea .active').removeClass('active');
      $("#element-"+elm_arr[0]+"-"+elm_arr[1]).addClass('active');
      $('.slider-layer-properties .layer-properties').hide();
      $("#slider-"+elm_arr[0]+"-layer-"+elm_arr[1]+'-properties').show();

      if($('input[name="slider\\[layers\\]\\['+elm_arr[0]+'\\]\\[sublayers\\]\\['+elm_arr[1]+'\\]\\[properties\\]\\[revslider-end-transition\\]"]:checked').val() != "yes"){

        $('#revslider-end-transition-'+elm_arr[0]+'-'+elm_arr[1]+'').addClass('hide');
      };

      $('#edit-slider-layers-'+elm_arr[0]+'-sublayers-'+elm_arr[1]+'-properties-revslider-end-transition-yes').click(function() {
        $('#revslider-end-transition-'+elm_arr[0]+'-'+elm_arr[1]+'').removeClass('hide');

      });

      $('#edit-slider-layers-'+elm_arr[0]+'-sublayers-'+elm_arr[1]+'-properties-revslider-end-transition-no').click(function() {
        $('#revslider-end-transition-'+elm_arr[0]+'-'+elm_arr[1]+'').addClass('hide');

      });


        });

  //Slide List
    $('.layer-identity').hide();
    var layers_ul = '<ul id="layers_list">';

    $("#edit-slider .layer-identity").each(function(index, element) {
      var fieldset_id = $(this).attr('id');

      var fieldset_id_arr = fieldset_id.split('-');
      var lid = fieldset_id_arr[3];
      var layer_weight = 'edit-slider-layers-'+lid+'-settings-weight';
      var weight = $('#'+layer_weight).val();
            var legend = $(this).find('legend').find('span').html();
      var bg_img = $('#'+fieldset_id).find('img.background').attr('src');
      var bg_img_div = '<div class="bg_img_small"><img src="'+bg_img+'" height="80" /></div>';
      var delete_button_wrapper = '<div class="delete_button_wrapper">'+$('#slider-delete-button-'+lid).html()+'</div>';
      var layers_ul_li = '<li class="layers_list_item" listens="'+fieldset_id+'" layer_weight="'+layer_weight+'" weight="'+weight+'"><table><tr><td class="td_legend">'+legend+'</td><td class="td_bg_img">'+bg_img_div+'</td><td class="td_delete_button">'+delete_button_wrapper+'</td></tr></table></li>';
      $('#edit-slider-layers-'+lid+' #edit-slider-layers-'+lid+'-delete').remove();
      layers_ul += layers_ul_li;


        });
    layers_ul += '</ul>';
    $('#revolution-slider-sorting').html( layers_ul );
    $('#layers_list').sortable();
    $('#revolution-slider-layers .layer-fieldset').css('height', '50px').sortable();

    var list = $('#layers_list');
    var listItems = list.find('li').sort(function(a,b){ return $(b).attr('weight') - $(a).attr('weight'); });
    list.find('li').remove();
    list.append(listItems);

    var index_positions = Array();
    $("#revolution-slider-sorting").find('#layers_list').sortable({
      start: function(event, ui)
      {
        var i = 0;

        $('#layers_list li').each(function(index, element) {
          var weight = $(this).attr('weight');
          if( weight != 'undefined' && weight != null )
          {
            index_positions[i] = $(this).attr('weight');
            i++;
          }
        });
      },
      update: function(event, ui) {

        list.find('li').each(function(index, element) {
          var pos = index_positions.length - index - 1;
          $(this).attr('weight', pos);
          var layer_weight = $(this).attr('layer_weight');
          $("#"+layer_weight).val(pos);
        });

      }
    });




    $('#edit-slider').on('click', '.layers_list_item', function(e) {
      if (!$(e.target).hasClass('delete_button_wrapper') && !$(e.target).hasClass('layer-delete-all'))
      {
        $('.slider-change-settings-container').hide();
        $(this).parent('ul').hide();
        var id = $(this).attr('listens');
        $('#'+id).show();
        localStorage.setItem("InspiroLastDiv", 'y#'+id);
      }
        });
    $('.slider-close-button').click(function(e) {

      var id = $(this).attr('id');
      id = id.split('-');
      id = id[2];

      var bg_upload_id = "edit-slider-layers-"+id+"-background-upload-file";
      if(document.getElementById(bg_upload_id).files.length >= 1)
      {
        e.preventDefault();
        //alert("Please submit changed background first");
      }
      else
      {
        var parent_id=$(this).attr('parent_id');
        $('#'+parent_id).hide();
        $('#layers_list').show();
        localStorage.setItem("InspiroLastDiv", 'n#'+parent_id);
      }
        });

    var last = localStorage.getItem("InspiroLastDiv");

    if(last != "" && last != null)
    {
      var check = last.substring(1,0);
      var sbstr = last.substring(1);

      if(check == "y"){

        if(sbstr.length > 0)
        {
          $(sbstr).show();
          $('#layers_list').hide();
        }else{
          $('#layers_list').show();
        }
      }else if(check == "n"){
        $(sbstr).hide();
        $('#layers_list').show();
      }
    }


    $('.upload-layer-background-image').hide();
    $('.slider-change-background').click(function(e) {
      var btn_id = $(this).attr('id');
      var btn_id_arr = btn_id.split('-');
      var layer = btn_id_arr[2];

      $('#slider-change-'+layer+'-settings').slideUp();
      $('#upload-layer-'+layer+'-background-image').slideToggle();
      $(this).toggleClass('clicked');
      $('.slider-change-settings').removeClass('clicked');
    });
    $('.slider-change-settings-container').hide();
    $('.slider-change-settings').click(function(e) {
            var btn_id = $(this).attr('id');
      var btn_id_arr = btn_id.split('-');
      var layer = btn_id_arr[2];

      var bg_upload_id = "edit-slider-layers-"+layer+"-background-upload-file";
      if(document.getElementById(bg_upload_id).files.length >= 1)
      {
        e.preventDefault();
        alert("Please submit changed background first");
      }
      else
      {
        $('#upload-layer-'+layer+'-background-image').slideUp();
        $('#slider-change-'+layer+'-settings').slideToggle();
        $(this).toggleClass('clicked');
        $('.slider-change-background').removeClass('clicked');
      }
    });

    $(".text-html-text-set").keyup(function(e) {
            var id = $(this).attr('id');
      var id_arr = id.split('-');
      $("#element-"+id_arr[3]+'-'+id_arr[5]+"-text").html( $(this).val() );
    });

    $(".text-html-style-set").change(function(e) {
            var id = $(this).attr('id');
      var id_arr = id.split('-');
      $("#element-"+id_arr[3]+'-'+id_arr[5]+"-text").attr('class', '').addClass( $(this).val() );
        });
  });
  }
};

function stopRKey(evt) {
  var evt = (evt) ? evt : ((event) ? event : null);
  var node = (evt.target) ? evt.target : ((evt.srcElement) ? evt.srcElement : null);
  if ((evt.keyCode == 13) && (node.type=="text"))  {return false;}
}

document.onkeypress = stopRKey;

})(jQuery);
