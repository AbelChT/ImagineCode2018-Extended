#include "activity.h"

/**
* Function executed when mode is stopped and relaunch.
* If OnSetup is executed, then this will be executed
*/
virtual void Activity::OnStart() {
    this->finished = false;
}

/**
* Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
* OnPause.
*/
virtual void Activity::OnStop() {
    this->finished = true;
};

/**
 * Check if Activity is finished
 */
bool Activity::IsFinished() {
    return this->finished;
}

void Activity::Finish() {
    this->finished = true;
}
