// Copyright 2026 Anthony Wilson

#pragma once

// Namespace/identifier (first bit of every report) for custom HID messages
#define CUSTOM_HID_PREFIX 0xFF

// Define custom HID handler function
void handle_custom_hid(uint8_t *data, uint8_t length);
