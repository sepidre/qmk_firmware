/* Copyright 2021 Sadek Baroudi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sepidre.h"
#include QMK_KEYBOARD_H

/*
 * The `LAYOUT_ffkb_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 * make fingerpunch/ffkb/rp/v1:sepidre RGB_MATRIX_ENABLE=yes FP_EVQ=yes FP_TRACKBALL_ENABLE=yes HAPTIC_ENABLE=yes AUDIO_ENABLE=yes
 */

// clang-format off
#define LAYOUT_ffkb_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
        KC_MS_BTN3,      K01,            K02,            K03,            K04,                    K05,                      K06,                   K07,                   K08,              K09,            K0A,          KC_MS_BTN3, \
        KC_MS_BTN1,      LALT_T(K11),    LGUI_T(K12),    LGUI_T(K13),    LSFT_T(K14),            K15,                      LT(_MOUSE, K16),       RSFT_T(K17),           RGUI_T(K18),      RALT_T(K19),    RCTL_T(K1A),  KC_MS_BTN1, \
        KC_MS_BTN2,      K21,            K22,            K23,            K24,                    K25,                      K26,                   K27,                   K28,              K29,            K2A,          KC_MS_BTN2, \
                                 KC_MUTE,                K33,            K34,                    LT(_NAVIGATION,K35),      LT(_SYMBOLS,K36),      K37,                   K38,              KC_BSPC \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ffkb_base_wrapper(...)       LAYOUT_ffkb_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NEO2] = LAYOUT_ffkb_base_wrapper(
        ____________________NEO2_L1___________________, ____________________NEO2_R1___________________,
        ____________________NEO2_L2___________________, ____________________NEO2_R2___________________,
        ____________________NEO2_L3___________________, ____________________NEO2_R3___________________,
                      KC_MUTE, __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__, KC_LSFT
    ),

    [_APTv3] = LAYOUT_ffkb_base_wrapper(
        __________________APTv3_L1____________________, __________________APTv3_R1____________________,
        __________________APTv3_L2____________________, __________________APTv3_R2____________________,
        __________________APTv3_L3____________________, __________________APTv3_R3____________________,
                      _______, __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__, _______
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        _______, ________________NAVIGATION_1_______________, _________________FKEYS_1___________________, _______,
        _______, ________________NAVIGATION_2_______________, _________________FKEYS_2___________________, _______,
        _______, ________________NAVIGATION_3_______________, _________________FKEYS_3___________________, _______,
                   _______, __ALPHA_THUMBS_LEFT_2__, _______, MO(_FUNCTION), __ALPHA_THUMBS_RIGHT_2__, _______,
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        _______, _________________SYMBOLS_1_________________, _________________NUMPAD_1__________________, _______,
        _______, _________________SYMBOLS_2_________________, _________________NUMPAD_2__________________, _______,
        _______, _________________SYMBOLS_3_________________, _________________NUMPAD_3__________________, _______,
             _______, __ALPHA_THUMBS_LEFT_2__, MO(_FUNCTION), _______, __ALPHA_THUMBS_RIGHT_2__, RGB_TOG,
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______, ________________ADJUST_L1_________________, ________________ADJUST_R1_________________, _______,
        _______, ________________ADJUST_L2_________________, ________________ADJUST_R2_________________, _______,
        _______, ________________ADJUST_L3_________________, ________________ADJUST_R3_________________, _______,
                  _______, __ALPHA_THUMBS_LEFT_2__, _______, _______, KC_ENT, TG(_GME), _______,
    ),

    [_GME] = LAYOUT_ffkb_base_wrapper(
        ____________________NEO2_L1___________________, ____________________NEO2_R1___________________,
        ____________________GAME_L2___________________, ____________________GAME_R2___________________,
        ____________________GAME_L3___________________, ____________________NEO2_R3___________________,
                     _______, KC_TAB, KC_SPC, MO(_WPN), KC_LALT, __ALPHA_THUMBS_RIGHT_2__, KC_LSFT
    ),

    [_WPN] = LAYOUT_wrapper(
        _______, ________________WEAPON_1_______________, _________________FKEYS_1___________________, _______,
        _______, ________________WEAPON_2_______________, _________________FKEYS_2___________________, _______,
        _______, ________________WEAPON_3_______________, _________________FKEYS_3___________________, _______,
                        _______, KC_TAB, KC_SPC, _______, KC_ESC, KC_ENT, TG(_GME), MO(_FUNCTION),
    )
    [_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_1__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_2__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_3__________________, ___________________BLANK___________________, _______,
                 _______, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _______
    )
};

