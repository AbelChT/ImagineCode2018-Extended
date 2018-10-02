#include "dance.h"
/*
* buzzer1: for the Orangutan LV/SV-xx8
*
* Uses the OrangutanBuzzer library to play a series of notes on the
* Orangutan's buzzer.  It also uses the OrangutanLCD library to
* display the notes its playing, and it uses the OrangutanPushbuttons
* library to allow the user to stop/reset the melody with the top
* pushbutton.
*
* http://www.pololu.com/docs/0J20/6.d
* http://www.pololu.com
* http://forum.pololu.com
*/

#define MELODY_LENGTH 203
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

/*
* Music that sounds on background
*/
// These arrays take up a total of 285 bytes of RAM (out of a 1k limit)
const unsigned int note[MELODY_LENGTH] =
        {
                NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
                NOTE_A4, NOTE_G4, NOTE_A4, 0,

                NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
                NOTE_A4, NOTE_G4, NOTE_A4, 0,

                NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
                NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
                NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
                NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_D5, NOTE_E5, NOTE_A4, 0,
                NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
                NOTE_C5, NOTE_A4, NOTE_B4, 0,

                NOTE_A4, NOTE_A4,
                //Repeat of first part
                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
                NOTE_A4, NOTE_G4, NOTE_A4, 0,

                NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
                NOTE_A4, NOTE_G4, NOTE_A4, 0,

                NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
                NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
                NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
                NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

                NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
                NOTE_D5, NOTE_E5, NOTE_A4, 0,
                NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
                NOTE_C5, NOTE_A4, NOTE_B4, 0,
                //End of Repeat

                NOTE_E5, 0, 0, NOTE_F5, 0, 0,
                NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
                NOTE_D5, 0, 0, NOTE_C5, 0, 0,
                NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

                NOTE_E5, 0, 0, NOTE_F5, 0, 0,
                NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
                NOTE_D5, 0, 0, NOTE_C5, 0, 0,
                NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
        };

const unsigned int duration[MELODY_LENGTH] =
        {
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 125,

                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 125,

                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 125, 250, 125,

                125, 125, 250, 125, 125,
                250, 125, 250, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 375,

                250, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 125,

                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 125,

                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 250, 125, 125,
                125, 125, 125, 250, 125,

                125, 125, 250, 125, 125,
                250, 125, 250, 125,
                125, 125, 250, 125, 125,
                125, 125, 375, 375,
                //End of Repeat

                250, 125, 375, 250, 125, 375,
                125, 125, 125, 125, 125, 125, 125, 125, 375,
                250, 125, 375, 250, 125, 375,
                125, 125, 125, 125, 125, 500,

                250, 125, 375, 250, 125, 375,
                125, 125, 125, 125, 125, 125, 125, 125, 375,
                250, 125, 375, 250, 125, 375,
                125, 125, 125, 125, 125, 500
        };

/*
* Choreography that our bug dance
*/
#define choreography_size 6
const int choreography[choreography_size][choreography_size] = {
        {40,  40,  1000},
        {20,  50,  500},
        {-20, 20,  700},
        {20,  -20, 700},
        {-20, -50, 500},
        {-40, -40, 1000}
};

/**
* Function executed only one time to setup before any one
*/
void Dance::OnSetup() {
    // Nothing to do
}

/**
* Function executed when mode is stopped and relaunch.
* If on_mode_create is executed, then this will be executed
*/
void Dance::OnStart() {
    this->currentIdx_ = 0;
    this->current_choreography_step_ = 5;
}

/**
* Function executed when mode is paused an resume ( When someone press the mode assigned key ).
* If on_mode_start is executed, then this will be executed
*/
void Dance::OnResume() {
    OrangutanMotors::setSpeeds(0, 0);
    this->last_execution_timestamp_ = 0;
}

/**
* Function executed when mode is paused ( When someone press the mode assigned key )
*/
void Dance::OnPause() {
    OrangutanMotors::setSpeeds(0, 0);
    if (OrangutanBuzzer::isPlaying()) OrangutanBuzzer::stopPlaying();
}

/**
* Function executed when mode is stopped ( When someone press a different mode assigned key ). Its always be executed after
* on_mode_pause.
*/
void Dance::OnStop() {}

/**
* Main loop of the mode
*/
void Dance::OnLoop() {
    // if we haven't finished playing the song and
    // the buzzer is ready for the next note, play the next note
    if (this->currentIdx_ < MELODY_LENGTH && !OrangutanBuzzer::isPlaying()) {
        // play note at max volume
        OrangutanBuzzer::playFrequency(note[this->currentIdx_], duration[this->currentIdx_] * 2, 15);
        this->currentIdx_++;
    }
        //If the song is finished, restart the song.
    else if (this->currentIdx_ == MELODY_LENGTH) {
        this->currentIdx_ = 0;
    }

    if (OrangutanTime::ms() - this->last_execution_timestamp_ > choreography[this->current_choreography_step_][2]) {
        this->last_execution_timestamp_ = OrangutanTime::ms();
        this->current_choreography_step_ = (this->current_choreography_step_ + 1) % choreography_size;
        OrangutanMotors::setSpeeds(choreography[this->current_choreography_step_][0],
                                   choreography[this->current_choreography_step_][1]);
    }
}
