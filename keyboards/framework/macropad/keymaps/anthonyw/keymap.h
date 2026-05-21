// Copyright 2026 Anthony Wilson

#pragma once

/**
 * Update the state of the numlock LED
 */
void set_numlock_led(bool numlock_state);

/**
 * This function is executed when the daemon is first heard from (since macropad init)
 */
void on_daemon_first_connect(void);
