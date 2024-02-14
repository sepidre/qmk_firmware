uSRC += sepidre.c \
#      process_records.c

COMMAND_ENABLE   			= no  # Commands for debug and configuration
CONSOLE_ENABLE 				= no  # Console for debug
UNICODE_ENABLE   			= no  # Unicode
SWAP_HANDS_ENABLE			= no  # Allow swapping hands of keyboard
BACKLIGHT_ENABLE 			= no
NKRO_ENABLE      			= yes
RAW_ENABLE       			= yes
CASEMODES_ENABLE 			= no
COMBO_ENABLE     			= yes
LTO_ENABLE       			= no
RGB_MATRIX_ENABLE			= yes
FP_EVQ_UNDER_PALMS			= yes
ENCODER_ENABLE				= yes
OLED_ENABLE					= yes
# UNCOMMENT TO DISABLE MACROS
EXTRAFLAGS     				=
# UNCOMMENT TO DISABLE MACROS

SPACE_CADET_ENABLE    		= no
GRAVE_ESC_ENABLE      		= no

RGB_MATRIX_REACTIVE_LAYERS := no
ifeq ($(strip $(RGB_MATRIX_REACTIVE_LAYERS)), yes)
    OPT_DEFS += -DRGB_MATRIX_REACTIVE_LAYERS
endif

ifeq ($(strip $(RGBLIGHT_SNAKE_LAYERS)), yes)
    OPT_DEFS += -DRGBLIGHT_SNAKE_LAYERS
endif

RGBLIGHT_TWINKLE_LAYERS := no
ifeq ($(strip $(RGBLIGHT_TWINKLE_LAYERS)), yes)
    OPT_DEFS += -DRGBLIGHT_TWINKLE_LAYERS
endif

RGB_LED_RING := no
ifeq ($(strip $(RGB_LED_RING)), yes)
    OPT_DEFS += -DRGB_LED_RING
endif

RGB_MATRIX_BAND_VAL_LAYERS := no
ifeq ($(strip $(RGB_MATRIX_BAND_VAL_LAYERS)), yes)
    OPT_DEFS += -DRGB_MATRIX_BAND_VAL_LAYERS
endif

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

ifeq ($(strip $(USERSPACE_RGBLIGHT_ENABLE)), yes)
    SRC += rgb_stuff.c
    OPT_DEFS += -DUSERSPACE_RGBLIGHT_ENABLE
endif

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifeq ($(strip $(RAW_ENABLE)), yes)
    SRC += hid.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += encoder_stuff.c
endif

ifeq ($(strip $(CASEMODES_ENABLE)), yes)
    SRC += casemodes.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += combos.c
endif

IMORONI_TRACKBALL_ENABLE = no
HAPTIC_ENABLE = no
POINTING_DEVICE_ENABLE = no
