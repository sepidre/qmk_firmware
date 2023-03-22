#include "keymap_german.h"
#include "led.c"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _ADJ);
}

// [Post Init] --------------------------------------------------------------//
void keyboard_post_init_user(void) {
    // Set RGB to known state
    rgblight_disable_noeeprom();
    rgblight_setrgb(RGB_GREEN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    user_led_enabled = true;
}
// [Process User Input] ------------------------------------------------------//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
    // Handle RGB Changes sans eeprom - necessary due to the layer dependent RGB color
    // changes in marrix_scan_user
    case RGB_TOG:
        if (record->event.pressed) {
            // Toggle matrix on key press
            user_led_enabled ? rgblight_disable_noeeprom() : rgblight_enable_noeeprom();
            // Toggle boolean flag
            user_led_enabled = !user_led_enabled;
        }
        return false;
    default:
    // Use process_record_keymap to reset timer on all other keypresses to awaken from idle.
        if (record->event.pressed) {
            #ifdef OLED_DRIVER_ENABLE
                oled_timer = timer_read32();
            #endif
            // Restore LEDs if they are enabled by user
            if (user_led_enabled) {
                rgblight_disable_noeeprom();
            }
        }
  }
  return true;
}
