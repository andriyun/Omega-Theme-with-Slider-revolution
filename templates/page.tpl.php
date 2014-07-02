<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<div<?php print $attributes; ?>>
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>
  <?php if(drupal_is_front_page()): ?>
    <?php if (theme_get_setting('slider-show', 'omega_sr') == "rev"): ?>
    <?php print render($page['revslider']); ?>
    <?php endif; ?>
  <?php endif; ?>
  <?php if (isset($page['content'])) : ?>
    <?php print render($page['content']); ?>
  <?php endif; ?>

  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>
