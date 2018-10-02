#include "race_black_line.h"

RaceBlack::RaceBlack(Pololu3pi *device) : device(device), integral_(0), last_proportional_(0) {}

/**
    * Function executed when mode is stopped and relaunch.
    * If OnSetup is executed, then this will be executed
    */
void RaceBlack::OnStart() {
    // Set properly calibration for this mode
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
}

/**
* Function executed when mode is paused an resume ( When someone press the mode assigned key ).
* If OnStart is executed, then this will be executed
*/
void RaceBlack::OnResume() {
    // Nothing to do
}

/**
* Function executed when mode is paused ( When someone press the mode assigned key )
*/
void RaceBlack::OnPause() {
    set_motors(0, 0);
}

/**
* Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
* OnPause.
*/
void RaceBlack::OnStop() {
    // Nothing to do
}

/**
* Main loop of the mode
*/
void RaceBlack::OnLoop() {
    unsigned int sensors[5]; // an array to hold sensor values

    unsigned int position = device->readLine(sensors, IR_EMITTERS_ON);

    int proportional = ((int) position) - 2000;
    int derivative = proportional - this->last_proportional_;
    this->integral_ += proportional;
    this->last_proportional_ = proportional;
    int power_difference = proportional / 20 + this->integral_ / 10000 + derivative * 5 / 2;

    if (power_difference > this->kMaxSpeed)
        power_difference = this->kMaxSpeed;

    if (power_difference < -this->kMaxSpeed)
        power_difference = -this->kMaxSpeed;

    if (power_difference < 0)
        OrangutanMotors::setSpeeds(this->kMaxSpeed + power_difference, this->kMaxSpeed);

    else
        OrangutanMotors::setSpeeds(this->kMaxSpeed, this->kMaxSpeed - power_difference);
}


