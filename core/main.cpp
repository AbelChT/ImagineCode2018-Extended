/**
* Core of the scheduler
*/

/**
 * Module that specify the end user
 */
#include "../main.h"

/**
 * Other includes
 */
#include "core_utils.h"
#include "platform_includes.h"

/**
 * Splash screen
 */
const char msg_splash_screen[] = "Panteras\nManila";

/**
 * Paused message
 */
const char msg_paused[] = "Paused";

/**
 * Selection menu buttons mapping
 * This buttons are used during the selection of the mode
 */
#define BUTTON_MENU_GO_BACK BUTTON_A
#define BUTTON_MENU_NEXT_MODE BUTTON_B
#define BUTTON_MENU_SELECT_MODE BUTTON_C

/**
 * In-Mode buttons mapping
 * This buttons are used during the mode execution
 */
#define BUTTON_IN_MODE_PAUSE BUTTON_A
#define BUTTON_IN_MODE_BUTTON_B BUTTON_B
#define BUTTON_IN_MODE_BUTTON_C BUTTON_C

/**
 * Pause buttons mapping
 * This buttons are used during the pause mode
 */
#define BUTTON_PAUSE_RESUME BUTTON_A
#define BUTTON_PAUSE_REESTART BUTTON_B
#define BUTTON_PAUSE_MAIN_MENU BUTTON_C

// Initializes the 3pi, displays a welcome message, calibrates, and
// plays the initial music.
void initialize(Pololu3pi &device) {
    // This must be called at the beginning of 3pi code, to set up the
    // sensors.  We use a value of 2000 for the timeout, which
    // corresponds to 2000*0.4 us = 0.8 ms on our 20 MHz processor.
    Pololu3pi::init(2000);
    load_custom_characters(); // load the custom characters

    // This function is required because it map in memory sensors
    device.calibrateLineSensors(IR_EMITTERS_ON);
}

Activity selectMode(const Screen &modes) {
    // TODO:
}

/**
 * Manage the mode selected with all the events associated
 * @param activity
 */
void inMode(Activity &activity) {
    activity.OnStart();
    bool endMode = false;
    while (!endMode) {
        activity.OnResume();
        // WARNING: If button is pressed it will freeze the mode since it is released
        // in a first analysis this is not a usability problem
        while (!OrangutanPushbuttons::isPressed(BUTTON_IN_MODE_PAUSE)) {
            if (OrangutanPushbuttons::isPressed(BUTTON_IN_MODE_BUTTON_B)) {
                activity.OnButtonPressedB();
                OrangutanPushbuttons::waitForRelease(BUTTON_IN_MODE_BUTTON_B);
            }

            if (OrangutanPushbuttons::isPressed(BUTTON_IN_MODE_BUTTON_C)) {
                activity.OnButtonPressedC();
                OrangutanPushbuttons::waitForRelease(BUTTON_IN_MODE_BUTTON_C);
            }

            activity.OnLoop();
        }

        OrangutanPushbuttons::waitForRelease(BUTTON_IN_MODE_PAUSE);

        activity.OnPause();

        // Manage buttons click on pause mode
        unsigned char pause_button_pressed = OrangutanPushbuttons::waitForButton(
                BUTTON_PAUSE_RESUME | BUTTON_PAUSE_REESTART | BUTTON_PAUSE_MAIN_MENU);
        if (pause_button_pressed == BUTTON_PAUSE_REESTART) {
            // Reestart process
            activity.OnStop();
            activity.OnStart();
        } else if (pause_button_pressed == BUTTON_PAUSE_MAIN_MENU) {
            endMode = true;
        }
    }
    activity.OnStop();
}


// This is the main function, where the code starts.  All C programs
// must have a main() function defined somewhere.
int main() {
    Pololu3pi device;
    // set up the 3pi
    initialize(device);

    Screen main_screen = entryPoint(&device);

    for (;;) {
        Activity actual = selectMode(main_screen);
        inMode(actual);
    }
}


