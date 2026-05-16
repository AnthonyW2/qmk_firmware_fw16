// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"
#include "raw_hid.h"
#if defined(RGB_MATRIX_ENABLE)
#include "rgb_matrix.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Just a numpad (except for the top row)
     *         ┌────┬────┬────┬────┐
     *  4 keys │ L++|    │MUTE│MICM│
     *         ├────┼────┼────┼────┤
     *  4 keys │ Num│ /  │ *  │ -  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 7  │ 8  │ 9  │ +  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ 4  │ 5  │ 6  │ +  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 1  │ 2  │ 3  │Entr│
     *         ├────┼────┼────┼────┤
     *  3 keys │ 0  │ 0  │ .  │Entr│
     *         └────┴────┴────┴────┘
     * 21 total
     */
    [_NUMPAD] = LAYOUT(
        TO(_MACRO0), KC_NO,   KC_MUTE, G(KC_MUTE),
        KC_NUM,      KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,       KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,       KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,       KC_P2,   KC_P3,   KC_PENT,
        KC_P0,       KC_P0,   KC_PDOT, KC_PENT
    ),
    
    // My custom quick-access & navigation layouts
    [_MACRO0] = LAYOUT(
        TO(_MACRO1),  KC_TRNS,      KC_TRNS,      KC_TRNS,
        C(S(KC_F17)), C(S(KC_F18)), C(S(KC_F19)), C(S(KC_F20)),
        C(S(KC_F21)), C(S(KC_F22)), C(S(KC_F23)), C(S(KC_F24)),
        C(KC_F13),    C(KC_F14),    C(KC_F15),    C(KC_F16),
        C(KC_F17),    C(KC_F18),    C(KC_F19),    C(KC_F20),
        C(KC_F21),    C(KC_F22),    C(KC_F23),    C(KC_F24)
    ),
    [_MACRO1] = LAYOUT(
        TO(_MONITOR), KC_TRNS,     KC_TRNS,     KC_TRNS,
        C(S(KC_F17)), C(S(KC_F18)), C(S(KC_F19)), C(S(KC_F20)),
        C(S(KC_F21)), C(S(KC_F22)), C(S(KC_F23)), C(S(KC_F24)),
        C(KC_F13),    C(KC_F14),    C(KC_F15),    C(KC_F16),
        C(KC_F17),    C(KC_F18),    C(KC_F19),    C(KC_F20),
        C(KC_F21),    C(KC_F22),    C(KC_F23),    C(KC_F24)
    ),
    
    // Live system stats (just pass the keys through to the numpad layer)
    [_MONITOR] = LAYOUT(
        TO(_APPLICATION), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // Just send key codes, and let the daemon and applications deal with them
    [_APPLICATION] = LAYOUT(
        TO(_NUMPAD), KC_TRNS,   KC_TRNS,   KC_TRNS,
        S(KC_F17),   S(KC_F18), S(KC_F19), S(KC_F20),
        S(KC_F21),   S(KC_F22), S(KC_F23), S(KC_F24),
        KC_F13,      KC_F14,    KC_F15,    KC_F16,
        KC_F17,      KC_F18,    KC_F19,    KC_F20,
        KC_F21,      KC_F22,    KC_F23,    KC_F24
    ),
    
    /* Alphabet
     *         ┌────┬────┬────┬────┐
     *  4 keys │ A  │ B  │ C  │ D  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ E  │ F  │ G  │ H  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ I  │ J  │ K  │ L  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ M  │ N  │ O  │ P  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ Q  │ R  │ S  │ T  │
     *         ├────┼────┼────┼────┤
     *  4 keys │ U  │ V  │ W  │ X  │
     *         └────┴────┴────┴────┘
     * 24 total
     */
    [_FACTORY] = LAYOUT(
        KC_A,    KC_B,    KC_C,    KC_D,
        KC_E,    KC_F,    KC_G,    KC_H,
        KC_I,    KC_J,    KC_K,    KC_L,
        KC_M,    KC_N,    KC_O,    KC_P,
        KC_Q,    KC_R,    KC_S,    KC_T,
        KC_U,    KC_V,    KC_W,    KC_X
    ),
    
    
     /*
     *         ┌───────┬───────┬───────┬───────┐
     *  4 keys │ RGB   │ RGB + │ RGB + │ RGB + │
     *         │Toggle │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │Numlock│ RGB - │ RGB - │ RGB - │
     *         |       │ Speed │ Hue   │ Sat   │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys │ Home  |   ↑   | Page  |RGB Nxt│
     *         |       |       | Up    |Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys |  ←    |       |   →   |RGB Prv│
     *         |       |       |       |Effect │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys | End   |  ↓    | Page  │ BL    │
     *         |       |       | Down  │ Step  │
     *         ├───────┼───────┼───────┼───────┤
     *  4 keys | Insert| Insert| Delete│ BL    │
     *         |       |       |       │ Step  │
     *         └───────┴───────┴───────┴───────┘
     * 24 total
     */
    //[_FN] = LAYOUT(
    //    RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI,
    //    _______, RGB_SPD, RGB_HUD, RGB_SAD,
    //    _______, _______, _______, RGB_MOD,
    //    _______, _______, _______, RGB_RMOD,
    //    _______, _______, _______, BL_STEP,
    //    _______, _______, _______, BL_STEP
    //),
    
};

/**
 * Store the state of all RGB LEDs
 */
static RGB rgb_states[RGB_MATRIX_LED_COUNT];

/**
 * Run code just after keyboard initialisation
 */
void keyboard_post_init_user(void) {
    // Sync initial numlock state from the host
    if (host_keyboard_led_state().num_lock) {
        rgb_states[4] = (RGB){255,255,255};
    } else {
        rgb_states[4] = (RGB){0,0,0};
    }
    
    // [future] Wait for a connection to the daemon, which will sync audio, layer, and LED state
}

/**
 * Run code upon LED state change (like capslock & numlock)
 */
bool led_update_user(led_t led_state) {
    // Change RGB state if numlock state changes, either triggered by OS or
    // by numlock key on this keyboard
    if (led_state.num_lock) {
        rgb_states[4] = (RGB){255,255,255};
    } else {
        rgb_states[4] = (RGB){0,0,0};
    }
    return true;
}

/**
 * Run code on layer change
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NUMPAD:
            rgb_states[5] = (RGB){0,0,0};
            break;
        case _MACRO0:
            rgb_states[5] = (RGB){255,0,0};
            break;
        case _MACRO1:
            rgb_states[5] = (RGB){0,255,0};
            break;
        case _MONITOR:
            rgb_states[5] = (RGB){0,0,255};
            break;
        case _APPLICATION:
            rgb_states[5] = (RGB){255,0,255};
            break;
        default:
            rgb_states[5] = (RGB){255,255,255};
            break;
    }
  return state;
}

/**
 * Override the handle_custom_hid function defined in /keyboards/framework/factory.c.
 * This function defines what the macropad should do when it receives
 * messages from the daemon running on the OS.
 */
void handle_custom_hid(uint8_t *data, uint8_t length) {
    uint8_t command_id = data[0];
    uint8_t *command_data = &(data[1]);
    
    uint8_t response[length];
    memset(response, 0, length);
    
    // Our custom communication namespace is 0xFF
    response[0] = 0xFF;
    
    // Start by identifying the type of command received
    switch(command_id) {
        case 0:
            // Set layer
            if (command_data[0] >= _NUMPAD && command_data[0] <= _APPLICATION) {
                layer_move(command_data[0]);
            }
            response[1] = 0;
            response[2] = command_data[0];
            break;
        case 1:
            // Set RGB LED
            uint8_t index = command_data[0];
            
            if (index >= RGB_MATRIX_LED_COUNT) {
                return;
            }
            
            rgb_states[index] = (RGB){command_data[1], command_data[2], command_data[3]};
            
            response[1] = 1;
            response[2] = rgb_states[index].r;
            response[3] = rgb_states[index].g;
            response[4] = rgb_states[index].b;
            break;
        case 2:
            // Set brightness
            response[1] = 'C';
            break;
        default:
            response[1] = 'Z';
    }
    
    raw_hid_send(response, length);
}

/**
 * Customised RGB matrix control function.
 * We're using custom indicators instead of effects because we need more control.
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(
            i,
            rgb_states[i].r,
            rgb_states[i].g,
            rgb_states[i].b
        );
    }

    return false;
}

/**
 * Function defined by Framework (not customised).
 */
void enable_factory_mode(bool enable) {
    if (enable)
        layer_on(_FACTORY);
    else
        layer_off(_FACTORY);
}
