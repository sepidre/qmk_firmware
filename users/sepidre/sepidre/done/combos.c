
#include "combos.h"

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

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
/*
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
*/
const uint16_t PROGMEM brc_combo[] = {DE_L, DE_C, COMBO_END};
const uint16_t PROGMEM cbr_combo[] = {DE_AE, DE_P, COMBO_END};
const uint16_t PROGMEM prn_combo[] = {DE_M, DE_Y, COMBO_END};
const uint16_t PROGMEM abk_combo[] = {DE_H, DE_G, COMBO_END};
const uint16_t PROGMEM at_combo[] = {K_IALT, K_AGUI, COMBO_END};
const uint16_t PROGMEM dquo_combo[] = {DE_V, DE_L, COMBO_END};
const uint16_t PROGMEM quo_combo[] = {DE_G, DE_F, COMBO_END};
const uint16_t PROGMEM under_combo[] = {DE_C, DE_W, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {DE_K, DE_H, COMBO_END};
const uint16_t PROGMEM circ_combo[] = {K_ESFT, DE_O, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {DE_OE, DE_AE, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {DE_Y, DE_SS, COMBO_END};
const uint16_t PROGMEM tabl_combo[] = {K_AGUI, K_ESFT, COMBO_END};
const uint16_t PROGMEM tabr_combo[] = {K_NSFT, K_RGUI, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {K_RGUI, K_TALT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {K_ESFT, K_NSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
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
  //[_CAPS] = COMBO_ACTION(caps_combo)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case _BRC:
      if (pressed) {
        tap_code16(DE_LBRC);
        tap_code16(DE_RBRC);
        tap_code16(KC_LEFT);
      }
      break;
    case _CBR:
      if (pressed) {
        tap_code16(DE_LCBR);
        tap_code16(DE_RCBR);
        tap_code16(KC_LEFT);
      }
      break;
    case _PRN:
      if (pressed) {
        tap_code16(DE_LPRN);
        tap_code16(DE_RPRN);
        tap_code16(KC_LEFT);
      }
      break;
    case _ABK:
      if (pressed) {
        tap_code16(KC_NUBS);
        tap_code16(LSFT(KC_NUBS));
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
    /*case _CAPS:
      if (pressed) {
        tap_code16(CW_TOGG);
      }
      break;*/
  }
}

// END COMBOS
