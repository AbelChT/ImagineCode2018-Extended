#pragma once

#include <pololu/Pololu3pi.h>
#include "../activity.h"

class Power : public Activity {
private:
    /**
    * Timestamp of the last loop execution
    */
    unsigned long last_execution_timestamp_ = 0;

public:
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
