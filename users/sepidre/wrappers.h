#pragma once
#include "sepidre.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

// Since ffkbhw uses the name LAYOUT_ffkbhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkbhw))
#    define LAYOUT LAYOUT_ffkbhw
#endif

// Since ffkbhw uses the name LAYOUT_ffkb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkb))
#    define LAYOUT LAYOUT_ffkb
#endif

// Since fpm101 uses the name LAYOUT_fpm101 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_fpm101))
#    define LAYOUT LAYOUT_fpm101
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)        LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_pteron38_wrapper(...)         LAYOUT_pteron38(__VA_ARGS__)
#define LAYOUT_ffkbhw_wrapper(...)           LAYOUT_ffkbhw(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define DE_UE DE_UDIA // Ü
#define DE_OE DE_ODIA // Ö
#define DE_AE DE_ADIA // Ä

// Thumbs
#define K_DOTHYPR MT(MOD_HYPR, DE_DOT)
#define K_COMMMEH MT(MOD_MEH, DE_COMM)

#define __ALPHA_THUMB_L1__ K_COMMMEH
#define __ALPHA_THUMB_L2__ KC_SPC
#define __ALPHA_THUMB_L3__ MO(_NAVIGATION)
#define __ALPHA_THUMB_R1__ MO(_SYMBOLS)
#define __ALPHA_THUMB_R2__ KC_ENT
#define __ALPHA_THUMB_R3__ K_DOTHYPR

//           Spac  NAV   | SYM  Ent
#define __ALPHA_THUMBS_LEFT_2__                             __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__
#define __ALPHA_THUMBS_RIGHT_2__                            __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__
// MEH/,     Spac  NAV   | SYM  Ent  HYP/.
#define __ALPHA_THUMBS_LEFT_3__                             __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__, __ALPHA_THUMB_L3__
#define __ALPHA_THUMBS_RIGHT_3__                            __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__

#define ______ALT_THUMB_L1____ __ALPHA_THUMB_L1__
#define ______ALT_THUMB_L2____ __ALPHA_THUMB_L2__
#define ______ALT_THUMB_L3____ __ALPHA_THUMB_L3__
#define ______ALT_THUMB_R1____ __ALPHA_THUMB_R1__
#define ______ALT_THUMB_R2____ __ALPHA_THUMB_R2__
#define ______ALT_THUMB_R3____ KC_LSFT

//           Spac  NAV   | SYM  Ent
#define __ALPHA_ALT_THUMBS_LEFT_2__                         __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_2__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__
// MEH/,     Spac  NAV   | SYM  Ent  Shift
#define __ALPHA_ALT_THUMBS_LEFT_3__                         __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_3__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__

/*   APTv3
w    g     d     f     b     | q    l    u     o    y
r    s     t     h     k     | j    n    e     a    i
x    c     m     p     v     | z    ü    ö     ä    ß
*/
// HomeRows
// Left
#define K_RCTL MT(MOD_LCTL, DE_R)
#define K_SALT MT(MOD_LALT, DE_S)
#define K_TGUI MT(MOD_LGUI, DE_T)
#define K_HSFT MT(MOD_LSFT, DE_H)
// Right
#define K_NSFT MT(MOD_RSFT, DE_N)
#define K_EGUI MT(MOD_RGUI, DE_E)
#define K_AALT MT(MOD_RALT, DE_A)
#define K_ICTL MT(MOD_RCTL, DE_I)

#define __________________APTv3_L1____________________			DE_W,    DE_G,    DE_D,    DE_F,    DE_B
#define __________________APTv3_L2____________________			K_RCTL,  K_SALT,  K_TGUI,  K_HSFT,  DE_K
#define __________________APTv3_L3____________________			DE_X,    DE_C,    DE_M,    DE_P,    DE_V

#define __________________APTv3_R1____________________			DE_Q,    DE_L,    DE_U,    DE_O,    DE_Y
#define __________________APTv3_R2____________________			DE_J,    K_NSFT,  K_EGUI,  K_AALT,  K_ICTL
#define __________________APTv3_R3____________________			DE_Z,    DE_UE,   DE_OE,   DE_AE,   DE_SS


#define __ALPHA_L1_K1__ KC_Q
#define __ALPHA_L1_K2__ KC_W
#define __ALPHA_L1_K3__ KC_F
#define __ALPHA_L1_K4__ KC_P
#define __ALPHA_L1_K5__ KC_B

#define __ALPHA_R1_K1__ KC_J
#define __ALPHA_R1_K2__ KC_L
#define __ALPHA_R1_K3__ KC_U
#define __ALPHA_R1_K4__ KC_Y
#define __ALPHA_R1_K5__ KC_SCLN

/*   NEO2
x    v     l     c     w     | k    h    g     f    q
u    i     a     e     o     | s    n    r     t    d
ü    ö     ä     p     z     | b    m    y     ß    j
*/
// HomeRow
// Left

#define K_UCTL MT(MOD_LCTL, DE_U)
#define K_IALT MT(MOD_LALT, DE_I)
#define K_AGUI MT(MOD_LGUI, DE_A)
#define K_ESFT MT(MOD_LSFT, DE_E)
// Right
#define K_NSFT MT(MOD_RSFT, DE_N)
#define K_RGUI MT(MOD_RGUI, DE_R)
#define K_TALT MT(MOD_RALT, DE_T)
#define K_DCTL MT(MOD_RCTL, DE_D)
#define ____________________NEO2_L1___________________			DE_X,    DE_V,    DE_L,    DE_C,    DE_W
#define ____________________NEO2_L2___________________			K_UCTL,  K_IALT,  K_AGUI,  K_ESFT,  DE_O
#define ____________________NEO2_L3___________________			DE_UE,   DE_OE,   DE_AE,   DE_P,    DE_Z
#define ____________________NEO2_R1___________________			DE_K,    DE_H,    DE_G,    DE_F,    DE_Q
#define ____________________NEO2_R2___________________			DE_S,    K_NSFT,  K_RGUI,  K_TALT,  K_DCTL
#define ____________________NEO2_R3___________________			DE_B,    DE_M,    DE_Y,    DE_SS,   DE_J

#define ____________________GAME_L2___________________			DE_U,  DE_I,  DE_A,  DE_E,  DE_O
#define ____________________GAME_L3___________________			DE_COMM, DE_DOT, DE_COLN, DE_P,  DE_Z
#define ____________________GAME_R2___________________			DE_S,  DE_N,  DE_R,  DE_T,  DE_D

#define ________________WEAPON_1_______________			DE_K, KC_BSPC, KC_UP,   KC_DEL,  KC_LCTL
#define ________________WEAPON_2_______________			DE_Q, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP
#define ________________WEAPON_3_______________			DE_B, KC_LSFT, DE_J,    DE_T,    KC_PGDN

// BLANK FULL LINE
#define ___________________BLANK___________________			_______, _______, _______, _______, _______

/* NAVIGATION
ESC  Back  UP    DEL   CTRL
HOME Left  Down  Right PUp
END  Shift ALT   Next  PDown
*/
#define ________________NAVIGATION_1_______________			KC_ESC,  KC_BSPC, KC_UP,   KC_DEL,  KC_LCTL
#define ________________NAVIGATION_2_______________			KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP
#define ________________NAVIGATION_3_______________			KC_END,  KC_LSFT, KC_LALT, KC_TAB,  KC_PGDN

/* NUMPAD
/    7    8     9    -
*    4    5     6    +
0    1    2     3    =
*/
#define _________________NUMPAD_1__________________			DE_SLSH, KC_7, KC_8, KC_9, DE_MINS
#define _________________NUMPAD_2__________________			DE_ASTR, KC_4, KC_5, KC_6, DE_PLUS
#define _________________NUMPAD_3__________________			KC_0,    KC_1, KC_2, KC_3, DE_EQL

/* SYMBOLS
§    &     $     !     `
~    |     (     )     ?
%    €     ;     :     -
*/
#define _________________SYMBOLS_1_________________			DE_SECT, DE_AMPR, DE_DLR,  DE_EXLM, DE_GRV
#define _________________SYMBOLS_2_________________			DE_TILD, ALGR(KC_NUBS), DE_LPRN, DE_RPRN, DE_QUES
#define _________________SYMBOLS_3_________________			DE_PERC, DE_EURO, DE_SCLN, DE_COLN, DE_MINS

/* FUNCTION
F11  F12  Prev  Play Next
F6   F7   F8    F9   F10
F1   F2   F3    F4   F5
*/
#define _________________FKEYS_1___________________			KC_F11, KC_F12, KC_MPRV, KC_MPLY, KC_MNXT
#define _________________FKEYS_2___________________			KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10
#define _________________FKEYS_3___________________			KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5

/* ADJUST
ESC  NWD               CAE   | CAPS NEO  NEOS   APTv3 GME
           BTABP TABP  F5    | CSF5 TABN BTABN       Deact Combo
AF4              WTP         |      WTN              Act Combo
           Reset Spac        |      Ent  Boot
*/
#define ________________ADJUST_L1_________________			RGB_TOG, RGB_MODE_REVERSE, RGB_MODE_FORWARD, _______, TG(_APTv3)
#define ________________ADJUST_L2_________________			_______, RGB_HUI, RGB_SAI, RGB_VAI, TG(_NEO2)
#define ________________ADJUST_L3_________________			_______, RGB_HUD, RGB_SAD, RGB_VAD, TG(_GME)

#define ________________ADJUST_R1_________________			RGB_TOG, RGB_MODE_REVERSE, RGB_MODE_FORWARD, _______, TG(_APTv3)
#define ________________ADJUST_R2_________________			QK_MAGIC_SWAP_CTL_GUI, RGB_HUI, RGB_SAI, RGB_VAI, TG(_NEO2)
#define ________________ADJUST_R3_________________			QK_MAGIC_TOGGLE_CTL_GUI, RGB_HUD, RGB_SAD, RGB_VAD, TG(_GME)

// MOUSE LAYER

#define __MOUSE_1_K1__ _______
#define __MOUSE_1_K2__ KC_MS_WH_UP
#define __MOUSE_1_K3__ KC_MS_UP
#define __MOUSE_1_K4__ KC_MS_WH_DOWN
#define __MOUSE_1_K5__ _______

#define __MOUSE_2_K1__ KC_MS_WH_LEFT
#define __MOUSE_2_K2__ KC_MS_LEFT
#define __MOUSE_2_K3__ KC_MS_DOWN
#define __MOUSE_2_K4__ KC_MS_RIGHT
#define __MOUSE_2_K5__ KC_MS_WH_RIGHT

#define __MOUSE_3_K1__ _______
#define __MOUSE_3_K2__ KC_MS_WH_UP
#define __MOUSE_3_K3__ KC_MS_WH_DOWN
#define __MOUSE_3_K4__ KC_MS_ACCEL1
#define __MOUSE_3_K5__ KC_MS_ACCEL2

#define __________________MOUSE_1__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_2__________________     __MOUSE_2_K1__, __MOUSE_2_K2__, __MOUSE_2_K3__, __MOUSE_2_K4__, __MOUSE_2_K5__
#define __________________MOUSE_3__________________     __MOUSE_3_K1__, __MOUSE_3_K2__, __MOUSE_3_K3__, __MOUSE_3_K4__, __MOUSE_3_K5__

// clang-format on
