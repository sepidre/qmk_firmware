#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"
#include "oled.c"
#include "logics.c"
// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	  [_NEO] = LAYOUT(
      LT(_MULTI, KC_ESC), DE_X,   DE_V,   DE_L,   DE_C,   DE_W,       /*|*/       DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_SS,
      LSFT_T(KC_TAB),     DE_U,   DE_I,   DE_A,   DE_E,   DE_O,       /*|*/       DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTRL,           DE_UE,  DE_OE,  DE_AE,  DE_P,   DE_Z,       /*|*/       DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                                           KC_LEAD, KC_SPC, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), LALT_T(KC_LGUI)
    ),
	  [_NEOMAC] = LAYOUT(
      LT(_MULTI, KC_ESC), DE_X,   DE_V,   DE_L,   DE_C,   DE_W,       /*|*/       DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_SS,
      LSFT_T(KC_TAB),     DE_U,   DE_I,   DE_A,   DE_E,   DE_O,       /*|*/       DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTRL,           DE_UE,  DE_OE,  DE_AE,  DE_P,   DE_Z,       /*|*/       DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                                           KC_LGUI, KC_SPC, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), KC_LALT
    ),
      [_NUM] = LAYOUT(
      KC_ESC,     KC_HOME,  KC_BSPC,   KC_UP,    KC_DEL,   KC_END,          /*|*/       KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_PEQL,
      KC_ENT,     KC_UNDO,  KC_LEFT,   KC_DOWN,  KC_RIGHT, KC_PGUP,         /*|*/       KC_PSLS, KC_4, KC_5, KC_6, KC_PPLS, DE_Y,
      LCTL(KC_S), KC_AGAIN, LCA(DE_R), S(KC_F5), KC_F12,   KC_PGDOWN,       /*|*/       KC_0,    KC_1, KC_2, KC_3, KC_PDOT, KC_PCMM,
                                                   KC_F2, KC_SPC, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), LALT_T(KC_PGDN)
    ),
      [_SYM] = LAYOUT(
      KC_ESC,     DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,       /*|*/       DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
      LCTL(KC_Z), DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,       /*|*/       DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_EURO,
      LCTL(KC_S), DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,        /*|*/       DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, TG(_GAME),
                                   LCA_T(KC_DEL), _______, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), LALT_T(KC_PGDN)
    ),
	  [_MULTI] = LAYOUT(
      _______, KC_LGUI, _______, KC_1, KC_2, KC_3,       /*|*/       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,       KC_F6,
      KC_TAB,  _______, _______, KC_4, KC_5, KC_6,       /*|*/       KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,      KC_F12,
      KC_MSEL, _______, KC_0,    KC_7, KC_8, KC_9,       /*|*/       KC_PGUP, KC_PGDN, _______, TG(_NEO), TG(_NEOMAC), TG(_GAME),
                              KC_MPRV, KC_MPLY, KC_MNXT, /*|*/ _______, _______, EEP_RST
    ),
	  [_GAME] = LAYOUT(
      KC_ESC,  DE_X,    DE_V,   DE_L,    DE_C,   DE_W,       /*|*/       DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_SS,
      KC_LSFT, DE_U,    DE_I,   DE_A,    DE_E,   DE_O,       /*|*/       DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTL, DE_COMM, DE_DOT, DE_MINS, DE_P,   DE_Z,       /*|*/       DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                                KC_TAB, KC_SPC, MO(_WEAPON), /*|*/ MO(_SYM), KC_ENT, KC_LALT
    ),
	  [_WEAPON] = LAYOUT(
      _______, DE_K, DE_H,    KC_UP,   DE_S,     DE_R,       /*|*/       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      _______, DE_Q, KC_LEFT, KC_DOWN, KC_RIGHT, DE_T,       /*|*/       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, DE_B, DE_M,    DE_N,    DE_Y,     DE_J,       /*|*/       _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, /*|*/ KC_ENT, KC_SPC, KC_LALT
    ),
      [_ADJ] = LAYOUT(
      KC_F1,          KC_F2,    KC_F3,    KC_F4,   KC_F5,     KC_F6,         /*|*/       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  HIBER,
      KC_F7,          KC_F8,    KC_F9,    KC_F10,  KC_F11,    KC_F12,        /*|*/       _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, _______,
      KC_SYSTEM_WAKE, _______,  _______,  KC_SLCK, _______,   _______,       /*|*/       _______, _______, DE_COMM, DE_DOT,  _______,  _______,
                                          LGUI_T(KC_PGUP), KC_SPC, MO(_NUM), /*|*/ MO(_SYM), KC_ENT, LALT_T(KC_PGDN)
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                ,-------------------------------------------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                |      |      |      |      |      |        |
//  * `-----------------------------+------+------+------.  ,------+------+------+------+----------------------'
//  *                               |      |      |      |  |      |      |      |
//  *                               |      |      |      |  |      |      |      |
//  *                               `--------------------'  `--------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//                                           _______, _______, _______, _______, _______, _______
//     ),
};
