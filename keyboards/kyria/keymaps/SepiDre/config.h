/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
docker container exec --workdir /qmk_firmware qmk qmk compile -kb kyria -km SepiDre
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 300000
  #define OLED_FONT_END 127
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD 3
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_HUE_STEP 1
  #define RGBLIGHT_SAT_STEP 1
  #define RGBLIGHT_VAL_STEP 1
  #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 0
  #define RGBLIGHT_EFFECT_KNIGHT_LENGTH 2
  #define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 6
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
  //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.
#endif

// Fix for Elite C rev3
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK
#define RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 0
// Speed up slave half startup
#define SPLIT_USB_TIMEOUT 1000

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
//#define ENCODER_RESOLUTION 2

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define MASTER_LEFT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#undef PRODUCT
#define PRODUCT CRKBD Loose Transistor Ed.

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

// The Leader key allows to flexibly assign macros to key sequences.
#define NO_ACTION_MACRO
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 950

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10
// Custom Font path
#define OLED_FONT_H "keyboards/kyria/keymaps/SepiDre/glcdfont.c"
#define OLED_DISABLE_TIMEOUT
