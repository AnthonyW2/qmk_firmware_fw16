// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(RGB_MATRIX_ENABLE)
const is31_led g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |   R location
 *   |   |         G location
 *   |   |         |         B location
 *   |   |         |         | */
    // Re-arranged in LED ID order so it matches with the physical location array
    {0,  CS3_SW1,  CS2_SW1,  CS1_SW1}, // LED 0
    {0,  CS3_SW2,  CS2_SW2,  CS1_SW2}, // LED 1
    {0,  CS3_SW3,  CS2_SW3,  CS1_SW3}, // LED 2
    {0,  CS3_SW4,  CS2_SW4,  CS1_SW4}, // LED 3

    {0,  CS6_SW1,  CS5_SW1,  CS4_SW1}, // LED 4
    {0,  CS6_SW3,  CS5_SW3,  CS4_SW3}, // LED 5
    {0,  CS6_SW4,  CS5_SW4,  CS4_SW4}, // LED 6
    {0,  CS6_SW2,  CS5_SW2,  CS4_SW2}, // LED 7

    {0,  CS9_SW1,  CS8_SW1,  CS7_SW1}, // LED 8
    {0,  CS9_SW2,  CS8_SW2,  CS7_SW2}, // LED 9
    {0,  CS9_SW3,  CS8_SW3,  CS7_SW3}, // LED 10
    {0,  CS9_SW4,  CS8_SW4,  CS7_SW4}, // LED 11

    {0, CS12_SW1, CS11_SW1, CS10_SW1}, // LED 12
    {0, CS12_SW2, CS11_SW2, CS10_SW2}, // LED 13
    {0, CS12_SW3, CS11_SW3, CS10_SW3}, // LED 14
    {0, CS12_SW4, CS11_SW4, CS10_SW4}, // LED 15

    {0, CS15_SW2, CS14_SW2, CS13_SW2}, // LED 16
    {0, CS15_SW3, CS14_SW3, CS13_SW3}, // LED 17
    {0, CS15_SW1, CS14_SW1, CS13_SW1}, // LED 18
    {0, CS15_SW4, CS14_SW4, CS13_SW4}, // LED 19

    {0, CS18_SW1, CS17_SW1, CS16_SW1}, // LED 20
    {0, CS18_SW2, CS17_SW2, CS16_SW2}, // LED 21
    {0, CS18_SW3, CS17_SW3, CS16_SW3}, // LED 22
    {0, CS18_SW4, CS17_SW4, CS16_SW4}, // LED 23
};

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {     4,      7,      6,      9,      0,      1,      3,     11, },
    {     8,     20,     21,     23,     15,     14,     18,     19, },
    {    12,      5,      2, NO_LED,     17,     16,     13,     10, },
    {NO_LED, NO_LED, NO_LED, NO_LED,     22, NO_LED, NO_LED, NO_LED, },
}, {
    /*  Macropad key location to LED Index
     *         ┌────┬────┬────┬────┐
     *  row 1  │  5 │  2 │ 22 │ 17 │
     *         ├────┼────┼────┼────┤
     *  row 2  │  4 │  0 │ 20 │ 18 │
     *         ├────┼────┼────┼────┤
     *  row 3  │  7 │  1 │ 21 │ 16 │
     *         ├────┼────┼────┼────┤
     *  row 4  │  6 │  3 │ 23 │ 19 │
     *         ├────┼────┼────┼────┤
     *  row 5  │  9 │ 11 │ 15 │ 13 │
     *         ├────┼────┼────┼────┤
     *  row 6  │  8 │ 10 │ 14 │ 12 │
     *         └────┴────┴────┴────┘
     *        24 keys and LEDs total
     */
    // LED Index to Physical Position
    {  73,  10 }, // LED 0
    {  73,  24 }, // LED 1
    {  73,   0 }, // LED 2
    {  73,  37 }, // LED 3
    {   0,  10 }, // LED 4
    {   0,   0 }, // LED 5
    {   0,  37 }, // LED 6
    {   0,  24 }, // LED 7
    {   0,  64 }, // LED 8
    {   0,  50 }, // LED 9
    {  73,  64 }, // LED 10
    {  73,  50 }, // LED 11
    { 223,  64 }, // LED 12
    { 223,  50 }, // LED 13
    { 150,  64 }, // LED 14
    { 150,  50 }, // LED 15
    { 223,  24 }, // LED 16
    { 223,   0 }, // LED 17
    { 223,  10 }, // LED 18
    { 223,  37 }, // LED 19
    { 150,  10 }, // LED 20
    { 150,  24 }, // LED 21
    { 150,   0 }, // LED 22
    { 150,  37 }, // LED 23
}, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4
} };
#endif
