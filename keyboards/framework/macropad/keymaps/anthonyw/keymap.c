// Copyright 2026 Anthony Wilson

// Original Macropad firmware by Framework Computer (Copyright 2022)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"
#include "raw_hid.h"
#include "custom.h"
#if defined(RGB_MATRIX_ENABLE)
#include "rgb_matrix.h"
#endif
#include "keymap.h"

// Define custom keycodes
enum keycodes {
    // Ask the system for its status
    KC_STATUS_REQ = QK_USER,
};

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
     */
    [_NUMPAD] = LAYOUT(
        TO(_MACRO0), KC_STATUS_REQ, KC_MUTE, G(KC_MUTE),
        KC_NUM,      KC_PSLS,       KC_PAST, KC_PMNS,
        KC_P7,       KC_P8,         KC_P9,   KC_PPLS,
        KC_P4,       KC_P5,         KC_P6,   KC_PPLS,
        KC_P1,       KC_P2,         KC_P3,   KC_PENT,
        KC_P0,       KC_P0,         KC_PDOT, KC_PENT
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
        TO(_MONITOR), KC_TRNS,      KC_TRNS,      KC_TRNS,
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
    
    /* Just send key codes, and let the daemon and applications deal with them
     *         ┌────┬────┬────┬────┐
     *  4 keys │ L++|    │MUTE│MICM│
     *         ├────┼────┼────┼────┤
     *  4 keys │SF17│SF18│SF19│SF20│
     *         ├────┼────┼────┼────┤
     *  3 keys │SF21│SF22│SF23│SF24│
     *         ├────┼────┼────┼────┤
     *  4 keys │ F13│ F14│ F15│ F16│
     *         ├────┼────┼────┼────┤
     *  4 keys │ F17│ F18│ F19│ F20│
     *         ├────┼────┼────┼────┤
     *  3 keys │ F21│ F22│ F23│ F24│
     *         └────┴────┴────┴────┘
     */
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
     */
    [_FACTORY] = LAYOUT(
        KC_A,    KC_B,    KC_C,    KC_D,
        KC_E,    KC_F,    KC_G,    KC_H,
        KC_I,    KC_J,    KC_K,    KC_L,
        KC_M,    KC_N,    KC_O,    KC_P,
        KC_Q,    KC_R,    KC_S,    KC_T,
        KC_U,    KC_V,    KC_W,    KC_X
    ),
    
};

/**
 * Define the codes for the custom RAW HID commands
 */
enum custom_hid_commands {
    // Send/receive a ping
    hid_cmd_ping       = 0x00,
    // Acknowledge a ping
    hid_cmd_ack        = 0x01,
    
    // Send/receive new layer
    hid_cmd_set_layer  = 0x02, // [layer]
    
    // Receive a new RGB value for a key
    hid_cmd_set_rgb    = 0x03, // [key id, r, g, b]
    // Receive a new overall brightness level
    hid_cmd_set_bright = 0x04, // [brightness divisor]
    // RGB matrix enable/disable & set mode
    hid_cmd_rgb_matrix = 0x05, // [new state, new mode]
    
    // Send a key downpress event
    hid_cmd_key_down   = 0x06, // [key id]
    // Send a key release event
    hid_cmd_key_up     = 0x07, // [key id]
    
    // Ask the daemon for host system status
    hid_cmd_status_req = 0x08,
    // Receive host system status response
    hid_cmd_status_res = 0x09, // [mem, cpu, gpu, gui, crashes, kernel]
};

/**
 * Create our own rgb_state_t struct, because this version of QMK doesn't have rgb_t,
 * and the byte order of the RGB struct isn't necessarily red-green-blue.
 */
typedef struct {
    uint8_t r, g, b;
} rgb_state_t;

/**
 * Store the state of all RGB LEDs
 */
static rgb_state_t rgb_states[RGB_MATRIX_LED_COUNT] = {0};

/**
 * How many times to halve RGB components to reduce brightness.
 * A value of 0 is full brightness, 1 is half, etc.
 * 7 is the lowest brightness, reducing 0xFF to 0x01.
 */
static uint8_t rgb_brightness_shift = 3;

/**
 * True if the daemon has ever been heard from since boot.
 */
static bool daemon_hid_initialised = false;
/**
 * True if the daemon is currently available.
 * False if it hasn't been heard from in a while.
 * 
 * NOTE: Currently this is not automatically updated (no heartbeat pings).
 */
static bool daemon_hid_available = false;

/**
 * Store the current layer (updated by layer_state_set_user).
 */
static uint8_t current_layer = _NUMPAD;
/**
 * If this is true, then a RAW HID message needs to be sent to the daemon to inform it that the keyboard has switched layers.
 */
static bool pending_layer_update = false;

/**
 * Store current daemon status request, response, and display states
 */
static bool pending_daemon_status_req = false;
static bool pending_daemon_status_res = false;
static bool showing_daemon_status = false;

/**
 * Which RGB LEDs are used to indicate requested host system status
 */
const uint8_t system_stat_led_ids[4] = {4, 0, 20, 18};

/**
 * Run code just after keyboard initialisation
 */
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    
    // Sync initial numlock state from the host
    //set_numlock_led(host_keyboard_led_state().num_lock);
    
    // Set the color of the top second-left RGB LED to red, indicating that the daemon has not established connection yet
    rgb_states[2] = (rgb_state_t){255,0,0};
    
    // Tell the daemon that the macropad is available
    uint8_t message[RAW_EPSIZE] = {0};
    message[0] = CUSTOM_HID_PREFIX;
    message[1] = hid_cmd_ping;
    raw_hid_send(message, RAW_EPSIZE);
}

/**
 * This function is executed when the daemon is first heard from (since macropad init)
 */
void on_daemon_first_connect() {
    // Turn off the no-communication indicator
    rgb_states[2] = (rgb_state_t){0,0,0};
    // Sync initial numlock state from the host
    set_numlock_led(host_keyboard_led_state().num_lock);
}

/**
 * Handle custom keycode actions
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_STATUS_REQ:
            if (record->event.pressed) {
                // Enable the RGB LEDs if they were disabled
                rgb_matrix_enable_noeeprom();
                if (showing_daemon_status) {
                    // Reset status LEDs
                    rgb_states[system_stat_led_ids[0]] = (rgb_state_t){0, 0, 0};
                    rgb_states[system_stat_led_ids[1]] = (rgb_state_t){0, 0, 0};
                    rgb_states[system_stat_led_ids[2]] = (rgb_state_t){0, 0, 0};
                    rgb_states[system_stat_led_ids[3]] = (rgb_state_t){0, 0, 0};
                    set_numlock_led(host_keyboard_led_state().num_lock);
                    showing_daemon_status = false;
                } else {
                    // Send a status request to the daemon on the host
                    pending_daemon_status_req = true;
                    // Show all red status LEDs while awaiting response
                    rgb_states[system_stat_led_ids[0]] = (rgb_state_t){255, 0, 0};
                    rgb_states[system_stat_led_ids[1]] = (rgb_state_t){255, 0, 0};
                    rgb_states[system_stat_led_ids[2]] = (rgb_state_t){255, 0, 0};
                    rgb_states[system_stat_led_ids[3]] = (rgb_state_t){255, 0, 0};
                    showing_daemon_status = true;
                }
            }
            return false;
        
        default:
            // Process other keycodes normally
            return true;
    }
}

/**
 * Run code upon LED state change (like capslock & numlock)
 */
bool led_update_user(led_t led_state) {
    // Change RGB state if numlock state changes, either triggered by OS or
    // by numlock key on this keyboard
    set_numlock_led(led_state.num_lock);
    return true;
}

/**
 * Run code on layer change
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer = get_highest_layer(state);
    pending_layer_update = true;
    
    // Update RGB state according to the new layer
    switch (current_layer) {
        case _NUMPAD:
            rgb_states[5] = (rgb_state_t){127,63,63};
            set_numlock_led(host_keyboard_led_state().num_lock);
            break;
        case _MACRO0:
            rgb_states[5] = (rgb_state_t){0,0,0};
            set_numlock_led(false);
            break;
        case _MACRO1:
            rgb_states[5] = (rgb_state_t){63,127,63};
            break;
        case _MONITOR:
            rgb_states[5] = (rgb_state_t){63,63,127};
            break;
        case _APPLICATION:
            rgb_states[5] = (rgb_state_t){127,63,127};
            break;
        default:
            rgb_states[5] = (rgb_state_t){127,127,127};
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
    
    // Update daemon availability and execute on_daemon_first_connect
    if (!daemon_hid_initialised) {
        on_daemon_first_connect();
    }
    daemon_hid_initialised = true;
    daemon_hid_available = true;
    
    // Our custom communication namespace is CUSTOM_RAW_HID_PREFIX
    uint8_t response[RAW_EPSIZE] = {0};
    response[0] = CUSTOM_HID_PREFIX;
    
    // Start by identifying the type of command received
    switch(command_id) {
        case hid_cmd_ping:
            // Ping received
            // Acknowledge the ping
            response[1] = hid_cmd_ack;
            break;
        
        //case hid_cmd_ack:
        //    // Ping acknowledged
        //    return;
        
        case hid_cmd_set_layer:
            // Set layer
            if (command_data[0] >= _NUMPAD && command_data[0] <= _APPLICATION) {
                layer_move(command_data[0]);
            }
            //response[1] = hid_cmd_set_layer;
            //response[2] = command_data[0];
            return;
        
        case hid_cmd_set_rgb:
            // Set RGB LED
            if (command_data[0] < RGB_MATRIX_LED_COUNT) {
                rgb_states[command_data[0]] = (rgb_state_t){command_data[1], command_data[2], command_data[3]};
            }
            //response[1] = hid_cmd_set_rgb;
            //response[2] = rgb_states[index].r;
            //response[3] = rgb_states[index].g;
            //response[4] = rgb_states[index].b;
            return;
        
        case hid_cmd_set_bright:
            // Set brightness
            if (command_data[0] < 8) {
                rgb_brightness_shift = command_data[0];
            } else {
                rgb_brightness_shift = 7;
            }
            //response[1] = hid_cmd_set_bright;
            //response[2] = 255 >> rgb_brightness_shift;
            return;
        
        case hid_cmd_rgb_matrix:
            // Enable/disable RGB matrix
            switch (command_data[0]) {
                case 0:
                    rgb_matrix_disable_noeeprom();
                    break;
                case 1:
                    rgb_matrix_enable_noeeprom();
                    break;
                case 2:
                    rgb_matrix_disable();
                    break;
                case 3:
                    rgb_matrix_enable();
                    break;
            }
            // Set RGB matrix mode
            switch (command_data[1]) {
                case 0:
                    rgb_matrix_mode_noeeprom(0);
                    break;
                case 1:
                    rgb_matrix_mode_noeeprom(1);
                    break;
                case 2:
                    rgb_matrix_mode(0);
                    break;
                case 3:
                    rgb_matrix_mode(1);
                    break;
            }
            //response[1] = hid_cmd_rgb_matrix;
            //response[2] = rgb_matrix_is_enabled();
            //response[3] = rgb_matrix_get_mode();
            //response[4] = rgb_matrix_get_suspend_state();
            return;
        
        case hid_cmd_status_res:
            // Parse host system status response
            // [mem, cpu, gpu, gui, crashes, kernel]
            rgb_states[system_stat_led_ids[0]] = (rgb_state_t){command_data[0], command_data[1], command_data[2]};
            rgb_states[system_stat_led_ids[1]] = (rgb_state_t){command_data[3], 0, 0};
            rgb_states[system_stat_led_ids[2]] = (rgb_state_t){command_data[4], 0, 0};
            rgb_states[system_stat_led_ids[3]] = (rgb_state_t){command_data[5], 0, 0};
            showing_daemon_status = true;
            pending_daemon_status_res = false;
            return;
        
        default:
            // Not a known command
            response[1] = 0xFF;
    }
    
    raw_hid_send(response, RAW_EPSIZE);
}

/**
 * Customised RGB matrix control function.
 * We're using custom indicators instead of effects because we need more control.
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(
            i,
            rgb_states[i].r >> rgb_brightness_shift,
            rgb_states[i].g >> rgb_brightness_shift,
            rgb_states[i].b >> rgb_brightness_shift
        );
    }

    return false;
}

/**
 * Clean up after QMK processing.
 */
void housekeeping_task_user(void) {
    if (pending_daemon_status_req) {
        // Send a RAW HID message to ask the daemon for its status
        uint8_t message[RAW_EPSIZE] = {0};
        message[0] = CUSTOM_HID_PREFIX;
        message[1] = hid_cmd_status_req;
        raw_hid_send(message, RAW_EPSIZE);
        
        pending_daemon_status_req = false;
        
        // Now awaiting response
        pending_daemon_status_res = true;
    }
    
    if (pending_layer_update && daemon_hid_available) {
        // Send a RAW HID message to update the daemon about the new layer
        uint8_t message[RAW_EPSIZE] = {0};
        message[0] = CUSTOM_HID_PREFIX;
        message[1] = hid_cmd_set_layer;
        message[2] = current_layer;
        raw_hid_send(message, RAW_EPSIZE);
        
        pending_layer_update = false;
    }
}

/**
 * Update the state of the numlock LED
 */
void set_numlock_led(bool numlock_state) {
    if (numlock_state || current_layer != _NUMPAD) {
        rgb_states[4] = (rgb_state_t){0,0,0};
    } else {
        rgb_states[4] = (rgb_state_t){255,255,255};
    }
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
