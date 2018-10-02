#pragma once

/**
 * This interface represent a mode of execution that can be used.
 */ 
class Activity
{
  public:
    /**
    * Function executed only first time mode is executed
    */
    virtual void OnSetup() = 0;

    /**
    * Function executed when mode is stopped and relaunch.
    * If OnSetup is executed, then this will be executed
    */
    virtual void OnStart() = 0;

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
};
