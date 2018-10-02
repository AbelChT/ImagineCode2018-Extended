#pragma once

#include "../../../core/platform_includes.h"
#include "../race_type.h"

class RaceBetween : public RaceType {
private:
    const int kMaxSpeed = 255;
    Pololu3pi *device;
    int integral_;
    int last_proportional_;

public:
    RaceBetween(Pololu3pi *device);

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
