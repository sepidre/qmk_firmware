/* Copyright 2021 Seth Bonner <fl3tching101@gmail.com>
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

#include "keycode_lookup.h"
#include "print.h"
#include "via.h"

#define num_keycodes (sizeof(lookup_table)/sizeof(lookup_table[0]))
static char UNKNOWN_KEYCODE[] = "UNKNOWN";

int cmp(const void *v1, const void *v2)
{
    const lookup_table_t *c1 = v1;
    const lookup_table_t *c2 = v2;

    return (c1->keycode - c2->keycode);
}

/*
    Returns a pointer to a string containing the string describing the keycode, such as those found here:
    https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes

    Will return a string that says "UNKNOWN" if the keycode cannot be found.
*/
char* translate_keycode_to_string(uint16_t code)
{
    lookup_table_t * result = NULL;
    lookup_table_t target = {.key_string = "", .keycode = code};
    char * return_p;

    result = bsearch(&target, lookup_table, num_keycodes, sizeof(lookup_table_t), cmp);

    if(result != NULL)
    {
        return_p = result->key_string;
    }
    else
    {
        return_p = UNKNOWN_KEYCODE;
    }

    return (return_p);
}

lookup_table_t lookup_table[334] =
{
 {"KC_NO", KC_NO},
 {"KC_TRNS", KC_TRNS},
 {"KC_A", KC_A},
 {"KC_B", KC_B},
 {"KC_C", KC_C},
 {"KC_D", KC_D},
 {"KC_E", KC_E},
 {"KC_F", KC_F},
 {"KC_G", KC_G},
 {"KC_H", KC_H},
 {"KC_I", KC_I},
 {"KC_J", KC_J},
 {"KC_K", KC_K},
 {"KC_L", KC_L},
 {"KC_M", KC_M},
 {"KC_N", KC_N},
 {"KC_O", KC_O},
 {"KC_P", KC_P},
 {"KC_Q", KC_Q},
 {"KC_R", KC_R},
 {"KC_S", KC_S},
 {"KC_T", KC_T},
 {"KC_U", KC_U},
 {"KC_V", KC_V},
 {"KC_W", KC_W},
 {"KC_X", KC_X},
 {"KC_Y", KC_Y},
 {"KC_Z", KC_Z},
 {"KC_1", KC_1},
 {"KC_2", KC_2},
 {"KC_3", KC_3},
 {"KC_4", KC_4},
 {"KC_5", KC_5},
 {"KC_6", KC_6},
 {"KC_7", KC_7},
 {"KC_8", KC_8},
 {"KC_9", KC_9},
 {"KC_0", KC_0},
 {"KC_ENT", KC_ENT},
 {"KC_ESC", KC_ESC},
 {"KC_BSPC", KC_BSPC},
 {"KC_TAB", KC_TAB},
 {"KC_SPC", KC_SPC},
 {"KC_MINS", KC_MINS},
 {"KC_EQL", KC_EQL},
 {"KC_LBRC", KC_LBRC},
 {"KC_RBRC", KC_RBRC},
 {"KC_BSLS", KC_BSLS},
 {"KC_NUHS", KC_NUHS},
 {"KC_SCLN", KC_SCLN},
 {"KC_QUOT", KC_QUOT},
 {"KC_GRV", KC_GRV},
 {"KC_ZKHK", KC_ZKHK},
 {"KC_COMM", KC_COMM},
 {"KC_DOT", KC_DOT},
 {"KC_SLSH", KC_SLSH},
 {"KC_CAPS", KC_CAPS},
 {"KC_F1", KC_F1},
 {"KC_F2", KC_F2},
 {"KC_F3", KC_F3},
 {"KC_F4", KC_F4},
 {"KC_F5", KC_F5},
 {"KC_F6", KC_F6},
 {"KC_F7", KC_F7},
 {"KC_F8", KC_F8},
 {"KC_F9", KC_F9},
 {"KC_F10", KC_F10},
 {"KC_F11", KC_F11},
 {"KC_F12", KC_F12},
 {"KC_PSCR", KC_PSCR},
 {"KC_SLCK", KC_SLCK},
 {"KC_PAUS", KC_PAUS},
 {"KC_INS", KC_INS},
 {"KC_HOME", KC_HOME},
 {"KC_PGUP", KC_PGUP},
 {"KC_DEL", KC_DEL},
 {"KC_END", KC_END},
 {"KC_PGDN", KC_PGDN},
 {"KC_RGHT", KC_RGHT},
 {"KC_LEFT", KC_LEFT},
 {"KC_DOWN", KC_DOWN},
 {"KC_UP", KC_UP},
 {"KC_NLCK", KC_NLCK},
 {"KC_PSLS", KC_PSLS},
 {"KC_PAST", KC_PAST},
 {"KC_PMNS", KC_PMNS},
 {"KC_PPLS", KC_PPLS},
 {"KC_PENT", KC_PENT},
 {"KC_P1", KC_P1},
 {"KC_P2", KC_P2},
 {"KC_P3", KC_P3},
 {"KC_P4", KC_P4},
 {"KC_P5", KC_P5},
 {"KC_P6", KC_P6},
 {"KC_P7", KC_P7},
 {"KC_P8", KC_P8},
 {"KC_P9", KC_P9},
 {"KC_P0", KC_P0},
 {"KC_PDOT", KC_PDOT},
 {"KC_NUBS", KC_NUBS},
 {"KC_APP", KC_APP},
 {"KC_POWER", KC_POWER},
 {"KC_PEQL", KC_PEQL},
 {"KC_F13", KC_F13},
 {"KC_F14", KC_F14},
 {"KC_F15", KC_F15},
 {"KC_F16", KC_F16},
 {"KC_F17", KC_F17},
 {"KC_F18", KC_F18},
 {"KC_F19", KC_F19},
 {"KC_F20", KC_F20},
 {"KC_F21", KC_F21},
 {"KC_F22", KC_F22},
 {"KC_F23", KC_F23},
 {"KC_F24", KC_F24},
 {"KC_EXECUTE", KC_EXECUTE},
 {"KC_HELP", KC_HELP},
 {"KC_MENU", KC_MENU},
 {"KC_SELECT", KC_SELECT},
 {"KC_STOP", KC_STOP},
 {"KC_AGAIN", KC_AGAIN},
 {"KC_UNDO", KC_UNDO},
 {"KC_CUT", KC_CUT},
 {"KC_COPY", KC_COPY},
 {"KC_PASTE", KC_PASTE},
 {"KC_FIND", KC_FIND},
 {"KC_LCAP", KC_LCAP},
 {"KC_LNUM", KC_LNUM},
 {"KC_LSCR", KC_LSCR},
 {"KC_PCMM", KC_PCMM},
 {"KC_KP_EQUAL_AS400", KC_KP_EQUAL_AS400},
 {"KC_RO", KC_RO},
 {"KC_KANA", KC_KANA},
 {"KC_JYEN", KC_JYEN},
 {"KC_HENK", KC_HENK},
 {"KC_MHEN", KC_MHEN},
 {"KC_INT6", KC_INT6},
 {"KC_INT7", KC_INT7},
 {"KC_INT8", KC_INT8},
 {"KC_INT9", KC_INT9},
 {"KC_HAEN", KC_HAEN},
 {"KC_HANJ", KC_HANJ},
 {"KC_LANG3", KC_LANG3},
 {"KC_LANG4", KC_LANG4},
 {"KC_LANG5", KC_LANG5},
 {"KC_LANG6", KC_LANG6},
 {"KC_LANG7", KC_LANG7},
 {"KC_LANG8", KC_LANG8},
 {"KC_LANG9", KC_LANG9},
 {"KC_ERAS", KC_ERAS},
 {"KC_SYSREQ", KC_SYSREQ},
 {"KC_CANCEL", KC_CANCEL},
 {"KC_CLR", KC_CLR},
 {"KC_CLEAR", KC_CLEAR},
 {"KC_PRIOR", KC_PRIOR},
 {"KC_OUT", KC_OUT},
 {"KC_OPER", KC_OPER},
 {"KC_CLEAR_AGAIN", KC_CLEAR_AGAIN},
 {"KC_CRSEL", KC_CRSEL},
 {"KC_EXSEL", KC_EXSEL},
 {"KC_PWR", KC_PWR},
 {"KC_SLEP", KC_SLEP},
 {"KC_WAKE", KC_WAKE},
 {"KC_MUTE", KC_MUTE},
 {"KC_VOLU", KC_VOLU},
 {"KC_VOLD", KC_VOLD},
 {"KC_MNXT", KC_MNXT},
 {"KC_MPRV", KC_MPRV},
 {"KC_MSTP", KC_MSTP},
 {"KC_MPLY", KC_MPLY},
 {"KC_MSEL", KC_MSEL},
 {"KC_EJCT", KC_EJCT},
 {"KC_MAIL", KC_MAIL},
 {"KC_CALC", KC_CALC},
 {"KC_MYCM", KC_MYCM},
 {"KC_WWW_SEARCH", KC_WWW_SEARCH},
 {"KC_WWW_HOME", KC_WWW_HOME},
 {"KC_WWW_BACK", KC_WWW_BACK},
 {"KC_WWW_FORWARD", KC_WWW_FORWARD},
 {"KC_WWW_STOP", KC_WWW_STOP},
 {"KC_WWW_REFRESH", KC_WWW_REFRESH},
 {"KC_WWW_FAVORITES", KC_WWW_FAVORITES},
 {"KC_MFFD", KC_MFFD},
 {"KC_MRWD", KC_MRWD},
 {"KC_BRIU", KC_BRIU},
 {"KC_BRID", KC_BRID},
 {"KC_LCTL", KC_LCTL},
 {"KC_LSFT", KC_LSFT},
 {"KC_LALT", KC_LALT},
 {"KC_LGUI", KC_LGUI},
 {"KC_RCTL", KC_RCTL},
 {"KC_RSFT", KC_RSFT},
 {"KC_RALT", KC_RALT},
 {"KC_RGUI", KC_RGUI},
 {"KC_MS_UP", KC_MS_UP},
 {"KC_MS_DOWN", KC_MS_DOWN},
 {"KC_MS_LEFT", KC_MS_LEFT},
 {"KC_MS_RIGHT", KC_MS_RIGHT},
 {"KC_MS_BTN1", KC_MS_BTN1},
 {"KC_MS_BTN2", KC_MS_BTN2},
 {"KC_MS_BTN3", KC_MS_BTN3},
 {"KC_MS_BTN4", KC_MS_BTN4},
 {"KC_MS_BTN5", KC_MS_BTN5},
 {"KC_MS_WH_UP", KC_MS_WH_UP},
 {"KC_MS_WH_DOWN", KC_MS_WH_DOWN},
 {"KC_MS_WH_LEFT", KC_MS_WH_LEFT},
 {"KC_MS_WH_RIGHT", KC_MS_WH_RIGHT},
 {"KC_MS_ACCEL0", KC_MS_ACCEL0},
 {"KC_MS_ACCEL1", KC_MS_ACCEL1},
 {"KC_MS_ACCEL2", KC_MS_ACCEL2},
 {"KC_EXLM", KC_EXLM},
 {"KC_AT", KC_AT},
 {"KC_HASH", KC_HASH},
 {"KC_DLR", KC_DLR},
 {"KC_PERC", KC_PERC},
 {"KC_CIRC", KC_CIRC},
 {"KC_AMPR", KC_AMPR},
 {"KC_ASTR", KC_ASTR},
 {"KC_LPRN", KC_LPRN},
 {"KC_RPRN", KC_RPRN},
 {"KC_UNDS", KC_UNDS},
 {"KC_PLUS", KC_PLUS},
 {"KC_LCBR", KC_LCBR},
 {"KC_RCBR", KC_RCBR},
 {"KC_PIPE", KC_PIPE},
 {"KC_COLN", KC_COLN},
 {"KC_DQUO", KC_DQUO},
 {"KC_TILD", KC_TILD},
 {"KC_LT", KC_LT},
 {"KC_GT", KC_GT},
 {"KC_QUES", KC_QUES},
 {"RESET", QK_BOOT},
 {"DEBUG", DEBUG},
 {"MAGIC_TOGGLE_NKRO", MAGIC_TOGGLE_NKRO},
 {"KC_GESC", KC_GESC},
 {"AU_ON", AU_ON},
 {"AU_OFF", AU_OFF},
 {"AU_TOG", AU_TOG},
 {"CLICKY_TOGGLE", CLICKY_TOGGLE},
 {"CLICKY_ENABLE", CLICKY_ENABLE},
 {"CLICKY_DISABLE", CLICKY_DISABLE},
 {"CLICKY_UP", CLICKY_UP},
 {"CLICKY_DOWN", CLICKY_DOWN},
 {"CLICKY_RESET", CLICKY_RESET},
 {"MU_ON", MU_ON},
 {"MU_OFF", MU_OFF},
 {"MU_TOG", MU_TOG},
 {"MU_MOD", MU_MOD},
 {"BL_ON", BL_ON},
 {"BL_OFF", BL_OFF},
 {"BL_DEC", BL_DEC},
 {"BL_INC", BL_INC},
 {"BL_TOGG", BL_TOGG},
 {"BL_STEP", BL_STEP},
 {"BL_BRTG", BL_BRTG},
 {"RGB_TOG", RGB_TOG},
 {"RGB_MOD", RGB_MOD},
 {"RGB_RMOD", RGB_RMOD},
 {"RGB_HUI", RGB_HUI},
 {"RGB_HUD", RGB_HUD},
 {"RGB_SAI", RGB_SAI},
 {"RGB_SAD", RGB_SAD},
 {"RGB_VAI", RGB_VAI},
 {"RGB_VAD", RGB_VAD},
 {"RGB_SPI", RGB_SPI},
 {"RGB_SPD", RGB_SPD},
 {"RGB_M_P", RGB_M_P},
 {"RGB_M_B", RGB_M_B},
 {"RGB_M_R", RGB_M_R},
 {"RGB_M_SW", RGB_M_SW},
 {"RGB_M_SN", RGB_M_SN},
 {"RGB_M_K", RGB_M_K},
 {"RGB_M_X", RGB_M_X},
 {"RGB_M_G", RGB_M_G},
 {"KC_LSPO", KC_LSPO},
 {"KC_RSPC", KC_RSPC},
 {"KC_SFTENT", KC_SFTENT},
 {"KC_LCPO", KC_LCPO},
 {"KC_RCPC", KC_RCPC},
 {"KC_LAPO", KC_LAPO},
 {"KC_RAPC", KC_RAPC},
 {"FN_MO13", FN_MO13},
 {"FN_MO23", FN_MO23},
 {"MACRO00", MACRO00},
 {"MACRO01", MACRO01},
 {"MACRO02", MACRO02},
 {"MACRO03", MACRO03},
 {"MACRO04", MACRO04},
 {"MACRO05", MACRO05},
 {"MACRO06", MACRO06},
 {"MACRO07", MACRO07},
 {"MACRO08", MACRO08},
 {"MACRO09", MACRO09},
 {"MACRO10", MACRO10},
 {"MACRO11", MACRO11},
 {"MACRO12", MACRO12},
 {"MACRO13", MACRO13},
 {"MACRO14", MACRO14},
 {"MACRO15", MACRO15},
 {"USER00", USER00},
 {"USER01", USER01},
 {"USER02", USER02},
 {"USER03", USER03},
 {"USER04", USER04},
 {"USER05", USER05},
 {"USER06", USER06},
 {"USER07", USER07},
 {"USER08", USER08},
 {"USER09", USER09},
 {"USER10", USER10},
 {"USER11", USER11},
 {"USER12", USER12},
 {"USER13", USER13},
 {"USER14", USER14},
 {"USER15", USER15}
};
