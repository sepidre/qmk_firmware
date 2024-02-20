#pragma once
#include "sepidre.h"

#if defined(KEYBOARD_fingerpunch_arachnophobe) \
    || defined(KEYBOARD_fingerpunch_ffkb_atmega_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v2) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v3) \
    || defined(KEYBOARD_fingerpunch_ffkb_lite_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_rp_v0) \
    || defined(KEYBOARD_fingerpunch_ffkb_rp_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_rp_v3) \
    || defined(KEYBOARD_fingerpunch_fflx)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#elif defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    KC_RGB_T = PLACEHOLDER_SAFE_RANGE, // Toggles RGB Layer Indication mode
    KC_RGB_BLT,                        // Toggles RGB Base Layer Override mode
    RGB_IDL,                           // RGB Idling animations
    M_KI_R_SWAP,
    M_KI_R_ANGLE,
    M_KI_R_FREE,
    L_GREP,
    L_FIND,
    L_GITCOMMIT,
    N_DEL_LINE,
    N_SEL_LINE,
    S_ALT_TAB,
    P_ANGBRKT,
    P_PAREN,
    P_CURLY,
    P_BRKT,
    P_ARROW,
    E_ROBOT,
    E_CAT,
    C_CAPSWORD,
    C_HYPHENCASE,
    C_UNDERSCORECASE,
    C_ANYCASE,
    U_KVM_SWITCH,
    G_GOD_ON,
    G_GOD_OFF,
    G_PULLING,
    G_PUSH,
    NEW_SAFE_RANGE,
    SS_SEC1,
    TD_SECT_SEC1,
    SS_SEC2,
    TD_AMPR_SEC2,
    SS_SEC3,
    TD_DLR_SEC3,
    SS_SEC4,
    TD_EXLM_SEC4,
    SS_SEC5,
    TD_GRV_SEC5
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);


#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define KC_RESET RESET
#define KC_RST   KC_RESET
