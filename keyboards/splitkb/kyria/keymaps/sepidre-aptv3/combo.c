#include QMK_KEYBOARD_H

enum combo_events {
  _BRC,
  _CBR,
  _PRN,
  _ABK,
  _AT,
  _DQUO,
  _QUO,
  _UNDER,
  _MINUS,
  _CIRC,
  _SLSH,
  _BSLS,
  _TABL,
  _TABR,
  _HASH,
  _CAPS,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
// Leg end
// []   BRC
// {}   CBR
// ()   PRN
// <>   ABK
// @    at
// "    dquo
// '    quo
// _    under
// -    minus
// ^    CIRC
// /    SLSH
// \/   BLS
// TABL TABL
// TABR TABR
// #    HASH
// CAPS CAPS

const uint16_t PROGMEM brc_combo[] = {DE_D, DE_F, COMBO_END};
const uint16_t PROGMEM cbr_combo[] = {DE_M, DE_P, COMBO_END};
const uint16_t PROGMEM prn_combo[] = {DE_UE, DE_OE, COMBO_END};
const uint16_t PROGMEM abk_combo[] = {DE_L, DE_U, COMBO_END};
const uint16_t PROGMEM at_combo[] = {DE_S, DE_T, COMBO_END};
const uint16_t PROGMEM dquo_combo[] = {DE_G, DE_D, COMBO_END};
const uint16_t PROGMEM quo_combo[] = {DE_U, DE_O, COMBO_END};
const uint16_t PROGMEM under_combo[] = {DE_F, DE_B, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {DE_Q, DE_L, COMBO_END};
const uint16_t PROGMEM circ_combo[] = {DE_H, DE_K, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {DE_C, DE_M, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {DE_OE, DE_AE, COMBO_END};
const uint16_t PROGMEM tabl_combo[] = {DE_T, DE_H, COMBO_END};
const uint16_t PROGMEM tabr_combo[] = {DE_N, DE_E, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {DE_E, DE_A, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {DE_H, DE_N, COMBO_END};

combo_t key_combos[] = {
  [_BRC] = COMBO_ACTION(brc_combo),
  [_CBR] = COMBO_ACTION(cbr_combo),
  [_PRN] = COMBO_ACTION(prn_combo),
  [_ABK] = COMBO_ACTION(abk_combo),
  [_AT] = COMBO_ACTION(at_combo),
  [_DQUO] = COMBO_ACTION(dquo_combo),
  [_QUO] = COMBO_ACTION(quo_combo),
  [_UNDER] = COMBO_ACTION(under_combo),
  [_MINUS] = COMBO_ACTION(minus_combo),
  [_CIRC] = COMBO_ACTION(circ_combo),
  [_SLSH] = COMBO_ACTION(slsh_combo),
  [_BSLS] = COMBO_ACTION(bsls_combo),
  [_TABL] = COMBO_ACTION(tabl_combo),
  [_TABR] = COMBO_ACTION(tabr_combo),
  [_HASH] = COMBO_ACTION(hash_combo),
  [_CAPS] = COMBO_ACTION(caps_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case _BRC:
      if (pressed) {
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
      }
      break;
    case _CBR:
      if (pressed) {
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
      }
      break;
    case _PRN:
      if (pressed) {
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
      }
      break;
    case _ABK:
      if (pressed) {
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
      }
      break;
    case _AT:
      if (pressed) {
        tap_code16(DE_AT);
      }
      break;
    case _DQUO:
      if (pressed) {
        tap_code16(DE_DQUO);
      }
      break;
    case _QUO:
      if (pressed) {
        tap_code16(DE_QUOT);
      }
      break;
    case _UNDER:
      if (pressed) {
        tap_code16(DE_UNDS);
      }
      break;
    case _MINUS:
      if (pressed) {
        tap_code16(DE_MINS);
      }
      break;
    case _CIRC:
      if (pressed) {
        tap_code16(DE_CIRC);
      }
      break;
    case _SLSH:
      if (pressed) {
        tap_code16(DE_SLSH);
      }
      break;
    case _BSLS:
      if (pressed) {
        tap_code16(DE_BSLS);
      }
      break;
    case _TABL:
    case _TABR:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case _HASH:
      if (pressed) {
        tap_code16(DE_HASH);
      }
      break;
    case _CAPS:
      if (pressed) {
        tap_code16(CW_TOGG);
      }
      break;
  }
}
