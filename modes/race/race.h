#pragma once

#include <pololu/3pi.h>
#include "../activity.h"
#include "race_type.h"
#include "between_lines/race_between_lines.h"
#include "black_line/race_black_line.h"

class Race : public Activity {
private:
    RaceType *selectedRaceMode;
    Pololu3pi *device;

    RaceBlack raceBlack;
    RaceBetween raceBetween;

public:

    Race(Pololu3pi *device);

    /**
    * Function executed only first time mode is executed
    */
    void OnSetup() override;

    /**
    * Function executed when mode is stopped and relaunch.
    * If OnSetup is executed, then this will be executed
    */
    void OnStart() override;

    /**
    * Function executed when mode is paused an resume ( When someone press the mode assigned key ).
    * If OnStart is executed, then this will be executed
    */
    void OnResume() override;

    /**
    * Function executed when mode is paused ( When someone press the mode assigned key )
    */
    void OnPause() override;

    /**
    * Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
    * OnPause.
    */
    void OnStop() override;

    /**
    * Main loop of the mode
    */
    void OnLoop() override;
};
