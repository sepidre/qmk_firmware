#include "sepidre.h"
#include "casemodes.h"

 // for alternating between 45 degree angle routing and free angle routing with one key
bool kicad_free_angle_routing = false;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in sadekbaroudi.h file
// Then runs the _keymap's record handler if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!IS_MOD(keycode) && record->event.pressed) {
		if(keycode == QK_MAGIC_SWAP_CTL_GUI) {
			current_os =_MAC;
		}
        if(keycode == QK_MAGIC_UNSWAP_CTL_GUI) {
            current_os = _WIN;
        }
	}



    #ifdef CASEMODES_ENABLE
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    // If console is enabled, it will print the matrix position and status of each key pressed
    #endif
    return true;
}
