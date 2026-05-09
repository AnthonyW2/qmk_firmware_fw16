// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#define LAYOUT( \
    H1,    H2,    H3,    H4, \
   K90,   K95,  K100,  K105, \
   K91,   K96,  K101,  K107, \
   K92,   K97,  K102,  K106, \
   K93,   K98,  K103,  K109, \
   K99,  K110,  K104,  K108  \
) \
{ \
  {   K90,   K91,   K92,   K93,   K95,   K96,   K97,   K98 }, \
  {   K99,  K100,  K101,  K102,  K103,  K104,  K105,  K106 }, \
  {  K108,    H1,    H2, KC_NO,    H4,  K107,  K109,  K110 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO,    H3, KC_NO, KC_NO, KC_NO }, \
}

enum _layers {
  // Just a numpad (except for the numlock key and the top row)
  _NUMPAD,
  
  // My custom quick-access & navigation layouts
  _MACRO0,
  _MACRO1,
  
  // Live system stats
  _MONITOR,
  
  // Just send key codes, and let the daemon and applications deal with them
  _APPLICATION,
  
  // Just letters on all keys
  _FACTORY,
};
