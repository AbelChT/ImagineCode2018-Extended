#include "race_between_lines.h"

RaceBetween::RaceBetween(Pololu3pi *device) : device(device), integral_(0), last_proportional_(0) {}

/**
* Function executed when mode is stopped and relaunch.
* If OnSetup is executed, then this will be executed
*/
void RaceBetween::OnStart() {
    // Set properly calibration for this mode
    unsigned int *maximum = device->getLineSensorsCalibratedMaximumOn();
    maximum[0] = 2000;
    maximum[1] = 1950;
    maximum[2] = 1850;
    maximum[3] = 1950;
    maximum[4] = 2000;

    unsigned int *minimum = device->getLineSensorsCalibratedMinimumOn();
    minimum[0] = 350;
    minimum[1] = 300;
    minimum[2] = 250;
    minimum[3] = 300;
    minimum[4] = 350;
}

/**
* Function executed when mode is paused an resume ( When someone press the mode assigned key ).
* If OnStart is executed, then this will be executed
*/
void RaceBetween::OnResume() {
    // Nothing to do
}

/**
* Function executed when mode is paused ( When someone press the mode assigned key )
*/
void RaceBetween::OnPause() {
    set_motors(0, 0);
}

/**
* Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
* OnPause.
*/
void RaceBetween::OnStop() {
    // Nothing to do
}

/**
* Main loop of the mode
*/
void RaceBetween::OnLoop() {
    unsigned int sensors[5]; // an array to hold sensor values

    unsigned int position = device->readLine(sensors, IR_EMITTERS_ON);

    int proportional;

    if (position >= 0 && position < 2000) proportional = position;
    else if (position > 2000 && position <= 4000) proportional = position - 4000;
    else {
        position = device->readLine(sensors, IR_EMITTERS_ON);
        if (position >= 0 && position < 2000) proportional = 2000;
        else proportional = -2000;
    }
    int derivative = proportional - this->last_proportional_;
    this->integral_ += proportional;
    this->last_proportional_ = proportional;
    int power_difference = proportional * 1 / 8 + this->integral_ / 10000 + derivative * 25 / 10;

    if (power_difference > this->kMaxSpeed)
        power_difference = this->kMaxSpeed;

    if (power_difference < -this->kMaxSpeed)
        power_difference = -this->kMaxSpeed;

    if (power_difference < 0)
        OrangutanMotors::setSpeeds(this->kMaxSpeed + power_difference, this->kMaxSpeed);

    else
        OrangutanMotors::setSpeeds(this->kMaxSpeed, this->kMaxSpeed - power_difference);
}

