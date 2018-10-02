#include "race.h"

Race::Race(Pololu3pi *device) : device(device), raceBlack(RaceBlack(device)), raceBetween(RaceBetween(device)) {}

/**
 * Function executed only first time mode is executed
 */
void Race::OnSetup() {
    // Nothing to do
}

/**
 * Function executed when mode is stopped and relaunch.
 * If on_mode_create is executed, then this will be executed
 */
void Race::OnStart() {
    // Calibrate the sensors to detect the zone
    unsigned int *maximum = device->getLineSensorsCalibratedMaximumOn();
    maximum[0] = 2000;
    maximum[1] = 1896;
    maximum[2] = 1801;
    maximum[3] = 2000;
    maximum[4] = 2000;

    unsigned int *minimum = device->getLineSensorsCalibratedMinimumOn();
    minimum[0] = 421;
    minimum[1] = 310;
    minimum[2] = 268;
    minimum[3] = 330;
    minimum[4] = 467;

    unsigned int sensors[5];
    unsigned int position = read_line(sensors, IR_EMITTERS_ON);

    if (position == 0 || position == 4000)
        this->selectedRaceMode = &raceBetween;
    else
        this->selectedRaceMode = &raceBlack;

}

/**
 * Function executed when mode is paused an resume ( When someone press the mode assigned key ).
 * If on_mode_start is executed, then this will be executed
 */
void Race::OnResume() {
    this->selectedRaceMode->OnResume();
}

/**
 * Function executed when mode is paused ( When someone press the mode assigned key )
 */
void Race::OnPause() {
    this->selectedRaceMode->OnPause();
}

/**
 * Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
 * on_mode_pause.
 */
void Race::OnStop() {
    this->selectedRaceMode->OnStop();
}

/**
 * Main loop of the mode
 */
void Race::OnLoop() {
    this->selectedRaceMode->OnLoop();

}