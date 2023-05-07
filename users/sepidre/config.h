#pragma once

#define COMBO_COUNT 15
#define COMBO_TERM 75

#define TAP_CODE_DELAY 25

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define FP_LAYER_LIGHTING_HUE_2 FP_HSV_MINT
#define FP_LAYER_LIGHTING_HUE_3 FP_HSV_LAVENDER
#define FP_LAYER_LIGHTING_HUE_4 FP_HSV_LEMON
#define FP_LAYER_LIGHTING_HUE_5 FP_HSV_MELON

// These are the colors I used on my ffkb low pro ks-27 with the xvx horizon purple and green keycaps
// #define FP_LAYER_LIGHTING_HUE_2 HSV_GREEN
// #define FP_LAYER_LIGHTING_HUE_3 HSV_ORANGE
// #define FP_LAYER_LIGHTING_HUE_4 HSV_YELLOW
// #define FP_LAYER_LIGHTING_HUE_5 HSV_CYAN
// #define FP_LAYER_LIGHTING_HUE_6 HSV_WHITE

#define RGBLIGHT_LAYERS_RETAIN_VAL

// To enable this, just pass RGB_MATRIX_REACTIVE_LAYERS=yes at the command line when building
// Also, you must make sure that RGB_MATRIX_SOLID_REACTIVE_SIMPLE is enabled
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_REACTIVE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_3 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_4 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_5 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

// To enable this, just pass RGBLIGHT_SNAKE_LAYERS=yes at the command line when building
// Also, you must make sure that RGBLIGHT_MODE_SNAKE is enabled
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SNAKE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_3 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_4 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_5 RGBLIGHT_MODE_SNAKE+1
#endif

// To enable this, just pass RGBLIGHT_TWINKLE_LAYERS=yes at the command line when building
// Also, you must make sure that RGBLIGHT_MODE_TWINKLE is enabled
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_TWINKLE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_3 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_4 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_5 RGBLIGHT_MODE_TWINKLE+1
#endif

// To enable this, just pass RGB_LED_RING=yes at the command line when building
#if defined(RGBLIGHT_ENABLE) && defined(RGB_LED_RING)
#undef RGBLED_NUM
#define RGBLED_NUM 12
#endif

// To enable this, just pass RGB_MATRIX_BAND_VAL_LAYERS=yes at the command line when building
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_BAND_VAL_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_3 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_4 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_5 RGB_MATRIX_BAND_VAL
#endif


#ifdef RGB_MATRIX_ENABLE
  #undef RGB_MATRIX_LED_COUNT
  #define RGB_MATRIX_LED_COUNT 36
  #define RGB_MATRIX_CENTER {100, 32}
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 112  /* The maximum brightness level for RGB_MATRIX */
  #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_KEYREACTIVE_ENABLED
  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  #define ENABLE_RGB_MATRIX_BAND_VAL
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define ENABLE_RGB_MATRIX_DUAL_BEACON
  #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_RAINDROPS
  #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #define ENABLE_RGB_MATRIX_SPLASH
  #define ENABLE_RGB_MATRIX_MULTISPLASH
  #define ENABLE_RGB_MATRIX_SOLID_SPLASH
  #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
