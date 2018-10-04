#pragma once

#include "screen_content.h"

/**
 * This interface represent a mode of execution that can be used.
 */
class Activity : ScreenContent {
public:
    /**
    * Function executed only first time mode is executed
    */
    virtual void OnSetup() = 0;

    /**
    * Function executed when mode is stopped and relaunch.
    * If OnSetup is executed, then this will be executed
    */
    virtual void OnStart();

    /**
    * Function executed when mode is paused an resume ( When someone press the mode assigned key ).
    * If OnStart is executed, then this will be executed
    */
    virtual void OnResume() = 0;

    /**
    * Function executed when mode is paused ( When someone press the mode assigned key )
    */
    virtual void OnPause() = 0;

    /**
    * Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
    * OnPause.
    */
    virtual void OnStop() = 0;

    /**
    * Main loop of the mode
    */
    virtual void OnLoop() = 0;

    /**
     * Check if Activity is finished
     */
    bool IsFinished();

    /**
     * Function executed when Button B is pressed
     */
    virtual void OnButtonPressedB() = 0;

    /**
    * Function executed when Button C is pressed
    */
    virtual void OnButtonPressedC()= 0;

private:
    bool finished = true;

    /**
    * Finish the actual activity
    */
    void Finish();
};
