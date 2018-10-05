#pragma once

#include "platform_includes.h"

// This function loads custom characters into the LCD.  Up to 8
// characters can be loaded; we use them for 7 levels of a bar graph.
void load_custom_characters();

/**
 * Muestra un mensaje de dos lineas en la pantalla
 */
void display_message(const char line1[], const char line2[]);

/**
 * Muestra un mensaje de dos lineas en la pantalla
 */
void display_message_centred(const char line1[]);
