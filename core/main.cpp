/*
 * This code will follow a black path between two black lines, using a
 * very simple algorithm.  It demonstrates auto-calibration and use of
 * the 3pi IR sensors, motor control, bar graphs using custom
 * characters, and music playback, making it a good starting point for
 * developing your own more competitive line follower.
 */

// The 3pi include file must be at the beginning of any program that
// uses the Pololu AVR library and 3pi.
#include <pololu/Pololu3pi.h>

// This include file allows data to be stored in program space.  The
// ATmega168 has 16k of program space compared to 1k of RAM, so large
// pieces of static data should be stored in program space.
#include <avr/pgmspace.h>

// Diferent modules
#include "../modes/power/power.h"
#include "../modes/dance/dance.h"
#include "../modes/race/race.h"

// Introductory messages.  The "PROGMEM" identifier causes the data to
// go into program space.
const char msg_panteras[]
PROGMEM = "Panteras";
const char msg_manila[]
PROGMEM = "Manila";
const char msg_select[]
PROGMEM = "select";
const char msg_mode[]
PROGMEM = "mode";
const char msg_race[]
PROGMEM = "race";
const char msg_dance[]
PROGMEM = "dance";
const char msg_power[]
PROGMEM = "power";
const char msg_paused[]
PROGMEM = "Paused";
const char msg_go[]
PROGMEM = "Go!";
const char msg_dancing[]
PROGMEM = "Dancing";

// BUTTONS FOR MODES
#define MODE_RACE_BUTTON BUTTON_A
#define MODE_DANCE_BUTTON BUTTON_B
#define MODE_POWER_BUTTON BUTTON_C


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

// Initializes the 3pi, displays a welcome message, calibrates, and
// plays the initial music.
void initialize(Pololu3pi& device) {
    // This must be called at the beginning of 3pi code, to set up the
    // sensors.  We use a value of 2000 for the timeout, which
    // corresponds to 2000*0.4 us = 0.8 ms on our 20 MHz processor.
    Pololu3pi::init(2000);
    load_custom_characters(); // load the custom characters

    // This function is required because it map in memory sensors
    device.calibrateLineSensors(IR_EMITTERS_ON);
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

Pololu3pi* init(){
    //TODO:
}


// This is the main function, where the code starts.  All C programs
// must have a main() function defined somewhere.
int launch(Screen screen) {
    Pololu3pi device;
    // set up the 3pi
    initialize(device);

    // Diferent modes
    Dance DanceMode;
    Power PowerMode;
    Race RaceMode = Race(&device);


    DanceMode.OnSetup();
    RaceMode.OnSetup();
    PowerMode.OnSetup();

    // muestra mensaje "Panteras Manila"
    display_message(msg_panteras, msg_manila);
    OrangutanTime::delayMilliseconds(1000);

    // muestra el mensaje select mode
    display_message(msg_select, msg_mode);
    unsigned char button_pressed = OrangutanPushbuttons::waitForButton(BUTTON_A | BUTTON_B | BUTTON_C);

    // Modulo de juego seleccionado
    unsigned char selected_game_mode;

    while (1) {
        // Seteamos el modo de juego
        selected_game_mode = button_pressed;

        // Segun el modo de juego mostramos cosas diferentes en la pantalla
        switch (selected_game_mode) {
            case MODE_RACE_BUTTON:
                display_message(msg_race, msg_mode);
                break;
            case MODE_DANCE_BUTTON:
                display_message(msg_dance, msg_mode);
                break;
            case MODE_POWER_BUTTON:
                display_message(msg_power, msg_mode);
                break;
        }

        // Esperamos hasta la confirmaci�n de modo de juego
        button_pressed = OrangutanPushbuttons::waitForButton(BUTTON_A | BUTTON_B | BUTTON_C);

        // Si el boton no es el de confirmaci�n, se cambia de modo de juego
        if (button_pressed != selected_game_mode) {
            continue; // Cambiamos de modo de juego
        }

        // On Start Activity
        switch (selected_game_mode) {
            case MODE_RACE_BUTTON:
                RaceMode.OnStart();
                break;
            case MODE_DANCE_BUTTON:
                DanceMode.OnStart();
                break;
            case MODE_POWER_BUTTON:
                PowerMode.OnStart();
                break;
        }

        GAME_MODE_LOOP_START:
        // On Resume Activity
        switch (selected_game_mode) {
            case MODE_RACE_BUTTON:
                RaceMode.OnResume();
                display_message_centred(msg_go);
                break;
            case MODE_DANCE_BUTTON:
                DanceMode.OnResume();
                display_message_centred(msg_dancing);
                break;
            case MODE_POWER_BUTTON:
                PowerMode.OnResume();
                // El power mode ya lleva su propia imagen para el lcd
                break;
        }

        // On Main loop
        // WARNING: If is too slow change switch with while
        while (!(button_pressed = OrangutanPushbuttons::isPressed(BUTTON_A | BUTTON_B | BUTTON_C))) {
            switch (selected_game_mode) {
                case MODE_RACE_BUTTON:
                    RaceMode.OnLoop();
                    break;
                case MODE_DANCE_BUTTON:
                    DanceMode.OnLoop();
                    break;
                case MODE_POWER_BUTTON:
                    PowerMode.OnLoop();
                    break;
            }
        }
        OrangutanPushbuttons::waitForRelease(button_pressed);

        // On Pause Activity
        if (button_pressed == selected_game_mode) {
            display_message_centred(msg_paused);
            switch (selected_game_mode) {
                case MODE_RACE_BUTTON:
                    RaceMode.OnPause();
                    break;
                case MODE_DANCE_BUTTON:
                    DanceMode.OnPause();
                    break;
                case MODE_POWER_BUTTON:
                    PowerMode.OnPause();
                    break;
            }
        } else {
            // On Stop Activity
            switch (selected_game_mode) {
                case MODE_RACE_BUTTON:
                    RaceMode.OnPause();
                    RaceMode.OnStop();
                    break;
                case MODE_DANCE_BUTTON:
                    DanceMode.OnPause();
                    DanceMode.OnStop();
                    break;
                case MODE_POWER_BUTTON:
                    PowerMode.OnPause();
                    PowerMode.OnStop();
                    break;
            }
            continue;
        }

        button_pressed = OrangutanPushbuttons::waitForButton(BUTTON_A | BUTTON_B | BUTTON_C);

        if (button_pressed != selected_game_mode) {
            // On Stop Activity
            switch (selected_game_mode) {
                case MODE_RACE_BUTTON:
                    RaceMode.OnStop();
                    break;
                case MODE_DANCE_BUTTON:
                    DanceMode.OnStop();
                    break;
                case MODE_POWER_BUTTON:
                    PowerMode.OnStop();
                    break;
            }
            continue; // Cambiamos de modo de juego
        } else {
            goto GAME_MODE_LOOP_START;
        }
    }
}


