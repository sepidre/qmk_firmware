//#include QMK_KEYBOARD_H
//#include <stdio.h>
#include logo_reader.c

// Oled timer similar to Drashna's
static uint32_t oled_timer = 0;
// Boolean to store the master LED clear so it only runs once.
bool master_oled_cleared = false;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

// Das Display kann 11 Zeichen
// {OLED helpers} -----------------------------------------------//
// Render Logo
void render_logo(void) {
    oled_write_P(read_logo(), false);
}

// Master OLED Screen (Left Hand )
void render_master_oled(void) {
    // Switch display based on Layer
    switch (get_highest_layer(layer_state)){
        case _GAME:
            render_separator();
            render_separator();
            render_layer_state();
            render_separator();
            render_separator();
            render_separator();
            break;
        case _WEAPON:
            render_separator();
            render_separator();
            render_separator();
            render_layer_state();
            render_separator();
            render_separator();
            break;
        default:
            render_separator();
            render_separator();
            render_layer_state();
            render_separator();
            render_separator();
    }
}

// Slave OLED scren (Right Hand)
void render_slave_oled(void) {
    render_logo();
}

void oled_task_user(void) {

    if (timer_elapsed32(oled_timer) > 100000 && timer_elapsed32(oled_timer) < 479999) {
        // Render logo on both halves before full timeout
        if (is_keyboard_master() && !master_oled_cleared) {
            // Clear master OLED once so the logo renders properly
            oled_clear();
            master_oled_cleared = true;
        }
        render_logo();
        return;
    }
    // Drashna style timeout for LED and OLED Roughly 8mins
    else if (timer_elapsed32(oled_timer) > 480000) {
        oled_off();
        rgblight_disable_noeeprom();
        return;
    }
    else {
        oled_on();
        // Reset OLED Clear flag
        master_oled_cleared = false;
        // Show logo when USB dormant
        if (is_keyboard_master()) {
            render_master_oled();
        } else {
            render_slave_oled();
        }
    }
}
