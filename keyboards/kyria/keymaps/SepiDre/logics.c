#include "keymap_german.h"
#include "led.c"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
   case HIBER:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(" "));
            SEND_STRING("hibernate");
            register_code(KC_ENT);
            return false;
        }
        break;
    default:
    // Use process_record_keymap to reset timer on all other keypresses to awaken from idle.
        if (record->event.pressed) {
            #ifdef OLED_DRIVER_ENABLE
                oled_timer = timer_read32();
            #endif
        }
  }
  return true;
}


LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // for single key sequences
        // register_code(KC_LGUI);
        // register_code(KC_S);
        // unregister_code(KC_S);
        // unregister_code(KC_LGUI);
        SEQ_ONE_KEY(KC_W) {
            register_code(KC_LGUI);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING(SS_LCTL("c"));
        }
        SEQ_ONE_KEY(KC_V) {
            SEND_STRING(SS_LCTL("v"));
        }
        SEQ_ONE_KEY(KC_X) {
            SEND_STRING(SS_LCTL("x"));
        }
        SEQ_ONE_KEY(KC_L) {
            SEND_STRING(SS_LGUI("l"));
        }
        SEQ_ONE_KEY(KC_E) {
            SEND_STRING(SS_LGUI("e"));
        }
        SEQ_ONE_KEY(KC_DOT) {
            SEND_STRING(SS_LGUI("."));
        }
        SEQ_ONE_KEY(KC_TAB) {
            register_code(KC_LALT);
            register_code(KC_TAB);
            unregister_code(KC_LALT);
            unregister_code(KC_TAB);
        }

        // for two-key sequences
        SEQ_TWO_KEYS(KC_C, KC_A) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }
        SEQ_TWO_KEYS(KC_T, KC_O) {
            // Start Toggle
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(DE_AE);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(DE_AE);
        }
        SEQ_TWO_KEYS(KC_L, KC_O) {
            // Start STRG ALT DEL
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_DEL);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_DEL);
        }
        SEQ_TWO_KEYS(KC_P, KC_S) {
            // Start Taskmgmnr
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_ESC);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_ESC);
        }
        SEQ_TWO_KEYS(KC_C, KC_S) {
            // Start Greenshot
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_C);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_C);
        }
        SEQ_TWO_KEYS(KC_E, KC_E) {
            // Start Enpass
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(DE_Z);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(DE_Z);
        }
        SEQ_TWO_KEYS(KC_E, KC_U) {
            // Copy User Enpass
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_U);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_U);
        }
        SEQ_TWO_KEYS(KC_E, KC_P) {
            // Copy PWD Enpass
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_P);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_P);
        }
        SEQ_TWO_KEYS(KC_E, KC_T) {
            // Copy Token Enpass
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_T);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_T);
        }

        // for three-key sequences
        //SEQ_THREE_KEYS(KC_XXXX, KC_YYYY, KC_ZZZZ) {
            // INSERT CODE HERE: anything you can do in a macro
        //}

        // ..., the rest of your Leader Key definitions.
    }
}
