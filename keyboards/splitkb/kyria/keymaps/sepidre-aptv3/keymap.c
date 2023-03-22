#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"
#include "oled.c"
#include "logics.c"
#define DE_UE DE_UDIA // Ü
#define DE_OE DE_ODIA // Ö
#define DE_AE DE_ADIA // Ä

#define K_RCTL MT(MOD_LCTL, DE_R)
#define K_HSFT MT(MOD_LSFT, DE_H)
#define K_SALT MT(MOD_LALT, DE_S)
#define K_TGUI MT(MOD_LGUI, DE_T)
#define K_ICTL MT(MOD_RCTL, DE_I)
#define K_NSFT MT(MOD_RSFT, DE_N)
#define K_AALT MT(MOD_RALT, DE_A)
#define K_EGUI MT(MOD_RGUI, DE_E)

#define K_DOTHYPR MT(MOD_HYPR, DE_DOT)
#define K_COMMMEH MT(MOD_MEH, DE_COMM)
#include "combo.c"
//DE_DEG

// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	  [_NEO] = LAYOUT(
      KC_ESC,         DE_X,   DE_V,   DE_L,   DE_C,   DE_W,                   /*|*/                  DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_SS,
      LSFT_T(KC_TAB), DE_U,   DE_I,   DE_A,   DE_E,   DE_O,                   /*|*/                  DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTL ,       DE_UE,  DE_OE,  DE_AE,  DE_P,   DE_Z, KC_MPRV, KC_MNXT, /*|*/ KC_MPLY, KC_NO,DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                                 KC_LGUI, MO(_SYM),KC_LALT, KC_SPC, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), KC_LALT, MO(_NUM), KC_NO
    ),
      [_NEOS] = LAYOUT(
      KC_NO, DE_X,  DE_V,  DE_L,  DE_C, DE_W,               /*|*/               DE_K, DE_H, DE_G, DE_F,  DE_Q, KC_NO,
      KC_NO, DE_U,  DE_I,  DE_A,  DE_E, DE_O,               /*|*/               DE_S, DE_N, DE_R, DE_T,  DE_D, KC_NO,
      KC_NO, DE_UE, DE_OE, DE_AE, DE_P, DE_Z, KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, DE_B, DE_M, DE_Y, DE_SS, DE_J, KC_NO,
                 KC_NO, K_COMMMEH, KC_SPC, MO(_NAV), KC_NO, /*|*/ KC_NO, MO(_SYMN), KC_ENT, K_DOTHYPR, KC_NO
    ),
      [_APTv3] = LAYOUT(
      KC_NO, DE_W,   DE_G,   DE_D,   DE_F,   DE_B,               /*|*/               DE_Q, DE_L,   DE_U,   DE_O,   DE_Y,   KC_NO,
      KC_NO, K_RCTL, K_SALT, K_TGUI, K_HSFT, DE_K,               /*|*/               DE_J, K_NSFT, K_EGUI, K_AALT, K_ICTL, KC_NO,
      KC_NO, DE_X,   DE_C,   DE_M,   DE_P,   DE_V, KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, DE_Z, DE_UE,  DE_OE,  DE_AE,  DE_SS,  KC_NO,
                      KC_NO, K_COMMMEH, KC_SPC, MO(_NAV), KC_NO, /*|*/ KC_NO, MO(_SYMN), KC_ENT, K_DOTHYPR, KC_NO
    ),
      [_NUM] = LAYOUT(
      _______,    KC_PGUP,  KC_BSPC,   KC_UP,    KC_DEL,   KC_PGDN,                   /*|*/                  KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_PEQL,
      KC_ENT,     KC_HOME,  KC_LEFT,   KC_DOWN,  KC_RIGHT, KC_END,                    /*|*/                  KC_PSLS, KC_4, KC_5, KC_6, KC_PPLS, KC_NO,
      LALT(KC_S), KC_AGAIN, LCA(DE_R), S(KC_F5), KC_F12,   KC_PGUP, _______, _______, /*|*/ _______, _______,KC_0,    KC_1, KC_2, KC_3, KC_NO, KC_NO,
                                           _______, _______,_______,_______, _______, /*|*/ _______, _______, _______, KC_PDOT, KC_PCMM
    ),
      [_SYM] = LAYOUT(
      _______, DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                  /*|*/                  DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
      _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                  /*|*/                  DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_EURO,
      _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV, _______, _______, /*|*/ _______, _______,DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_NO,
                                _______, _______, _______, _______, _______, /*|*/ _______, _______, _______, _______, _______
    ),
      [_NAV] = LAYOUT(
      KC_NO, KC_ESC,  KC_BSPC, KC_UP,   KC_DEL,   KC_LCTL,               /*|*/               KC_F11, KC_F12, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,
      KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,               /*|*/               KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_NO,
      KC_NO, KC_END,  KC_LSFT, KC_LALT, KC_TAB,   KC_PGDN, KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_NO,
                                KC_NO, K_COMMMEH, KC_SPC, MO(_NAV), KC_NO, /*|*/ KC_NO, MO(_SYM), KC_ENT, KC_LSFT, KC_NO
    ),

      [_SYMN] = LAYOUT(
      KC_NO, DE_SECT, DE_AMPR, DE_DLR,  DE_EXLM, DE_GRV,                /*|*/               DE_SLSH, KC_7, KC_8, KC_9, DE_MINS, KC_NO,
      KC_NO, DE_TILD, DE_PIPE, DE_LPRN, DE_RPRN, DE_QUES,               /*|*/               DE_ASTR, KC_4, KC_5, KC_6, DE_PLUS, KC_NO,
      KC_NO, DE_PERC, DE_EURO, DE_SCLN, DE_COLN, DE_MINS, KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, KC_0,    KC_1, KC_2, KC_3, DE_EQL,  KC_NO,
                             KC_NO, K_COMMMEH, KC_SPC, MO(_NUM), KC_NO, /*|*/ KC_NO, MO(_SYM), KC_ENT, DE_DOT, KC_NO
    ),
      [_ADJ] = LAYOUT(
      KC_NO, KC_ESC, LCTL(LGUI(DE_D)), KC_NO,       KC_NO,               KC_NO,              /*|*/               CW_TOGG,    TG(_NEO),             TG(_NEOS),    TG(_APTv3), KC_NO, KC_NO,
      KC_NO, KC_NO,  KC_NO,            LCA(KC_TAB), LSA(KC_TAB),         KC_F5,              /*|*/               RCS(KC_F5), LALT(KC_TAB),         LCTL(KC_TAB), RGB_VAD,    KC_NO, QK_COMBO_ON,
      KC_NO, KC_NO,  KC_NO,            KC_NO,       LCTL(LGUI(KC_LEFT)), KC_NO,KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, KC_NO,      LCTL(LGUI(KC_RIGHT)), KC_NO,        KC_NO,      KC_NO, QK_COMBO_OFF,
                                                      KC_NO, EE_CLR, KC_SPC, _______, KC_NO, /*|*/ KC_NO, _______, KC_ENT, QK_BOOT,   KC_NO
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
