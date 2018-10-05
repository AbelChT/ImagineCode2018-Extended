//
// Created by abel on 5/10/18.
//

#include "core_utils.h"

// Data for generating the characters used in load_custom_characters
// and display_readings.  By reading levels[] starting at various
// offsets, we can generate all of the 7 extra characters needed for a
// bargraph.  This is also stored in program space.
const char levels[]
PROGMEM = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
};

// This function loads custom characters into the LCD.  Up to 8
// characters can be loaded; we use them for 7 levels of a bar graph.
void load_custom_characters() {
    OrangutanLCD::loadCustomCharacter(levels + 0, 0); // no offset, e.g. one bar
    OrangutanLCD::loadCustomCharacter(levels + 1, 1); // two bars
    OrangutanLCD::loadCustomCharacter(levels + 2, 2); // etc...
    OrangutanLCD::loadCustomCharacter(levels + 3, 3);
    OrangutanLCD::loadCustomCharacter(levels + 4, 4);
    OrangutanLCD::loadCustomCharacter(levels + 5, 5);
    OrangutanLCD::loadCustomCharacter(levels + 6, 6);
    OrangutanLCD::clear(); // the LCD must be cleared for the characters to take effect
}

/**
 * Muestra un mensaje de dos lineas en la pantalla
 */
void display_message(const char line1[], const char line2[]) {
    OrangutanLCD::clear();
    OrangutanLCD::gotoXY(0, 0);
    OrangutanLCD::printFromProgramSpace(line1);
    OrangutanLCD::gotoXY(0, 1);
    OrangutanLCD::printFromProgramSpace(line2);
}

/**
 * Muestra un mensaje de dos lineas en la pantalla
 */
void display_message_centred(const char line1[]) {
    OrangutanLCD::clear();
    OrangutanLCD::printFromProgramSpace(line1);
}