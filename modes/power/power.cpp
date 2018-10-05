#include "power.h"

/**
 * Function executed when mode is stopped and relaunch.
 * If on_mode_create is executed, then this will be executed
 */
void Power::OnStart() {
    // Nothing to do
}

/**
 * Function executed when mode is paused an resume ( When someone press the mode assigned key ).
 * If on_mode_start is executed, then this will be executed
 */
void Power::OnResume() {
    this->last_execution_timestamp_ = 0;
}

/**
 * Function executed when mode is paused ( When someone press the mode assigned key )
 */
void Power::OnPause() {
    // Nothing to do
}

/**
 * Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
 * on_mode_pause.
 */
void Power::OnStop() {
    // Nothing to do
}

/**
 * Main loop of the mode
 */
void Power::OnLoop() {
    if (OrangutanTime::ms() - this->last_execution_timestamp_ > 500) {
        this->last_execution_timestamp_ = get_ms();
        OrangutanLCD::clear();
        OrangutanLCD::print(OrangutanAnalog::readBatteryMillivolts());
        OrangutanLCD::print("mV");
    }
}

void Power::OnButtonPressedB() {

}

void Power::OnButtonPressedC() {

}
