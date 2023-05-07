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
 */

// clang-format off
#define LAYOUT_ffkb_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
         K32, K33, K34, K35, K36, K37, K38, K39 \
  )\
  LAYOUT_wrapper( \
        KC_BSLS,      K01,            K02,            K03,            LT(_FUNCTION, K04),     K05,                      K06,                   LT(_FUNCTION, K07),    K08,              K09,            K0A,          KC_BSLS, \
        LCTL(KC_C),      LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),            K15,                      K16,       RSFT_T(K17),           RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A),  LCTL(KC_V), \
        TG(_NAVIGATION), K21,            K22,            K23,            K24,                    K25,                      K26,                   K27,                   K28,              K29,            K2A,          KC_BSLS, \
                                 KC_MUTE,                K33,            LT(_NAVIGATION,K34),    LT(_FUNCTION,K35),        K36,        LT(_SYMBOLS,K37),      K38,              LCTL(KC_BSPC), \
                                                                                                           KC_BSPC \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ffkb_base_wrapper(...)       LAYOUT_ffkb_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NEO2] = LAYOUT_ffkb_base_wrapper(
        ____________________NEO2_L1___________________, ____________________NEO2_R1___________________,
        ____________________NEO2_L2___________________, ____________________NEO2_R2___________________,
        ____________________NEO2_L3___________________, ____________________NEO2_R3___________________,
                      KC_MUTE, __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__, LCTL(KC_BSPC)
    ),

    [_APTv3] = LAYOUT_ffkb_base_wrapper(
        __________________APTv3_L1____________________, __________________APTv3_R1____________________,
        __________________APTv3_L2____________________, __________________APTv3_R2____________________,
        __________________APTv3_L3____________________, __________________APTv3_R3____________________,
                      _______, __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__, _______
    ),

    [_NAVIGATION] = LAYOUT_ffkb_base_wrapper(
        ________________NAVIGATION_1_______________, _________________FKEYS_1___________________,
        ________________NAVIGATION_2_______________, _________________FKEYS_2___________________,
        ________________NAVIGATION_3_______________, _________________FKEYS_3___________________,
          _______, __ALPHA_THUMBS_LEFT_2__, _______, MO(_FUNCTION), __ALPHA_THUMBS_RIGHT_2__, _______
    ),

    [_SYMBOLS] = LAYOUT_ffkb_base_wrapper(
        _________________SYMBOLS_1_________________, _________________NUMPAD_1__________________,
        _________________SYMBOLS_2_________________, _________________NUMPAD_2__________________,
        _________________SYMBOLS_3_________________, _________________NUMPAD_3__________________,
    _______, __ALPHA_THUMBS_LEFT_2__, MO(_FUNCTION), _______, __ALPHA_THUMBS_RIGHT_2__, _______
    ),

    [_FUNCTION] = LAYOUT_ffkb_base_wrapper(
        ________________ADJUST_L1_________________, ________________ADJUST_R1_________________,
        ________________ADJUST_L2_________________, ________________ADJUST_R2_________________,
        ________________ADJUST_L3_________________, ________________ADJUST_R3_________________,
         _______, __ALPHA_THUMBS_LEFT_2__, _______, _______, __ALPHA_THUMBS_RIGHT_2__, _______
    )
};

