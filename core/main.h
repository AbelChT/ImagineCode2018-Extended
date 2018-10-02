#pragma once

#include <pololu/Pololu3pi.h>
#include "screen.h"

/**
 * Init the system and return the device object
 */
Pololu3pi* init();

/**
 * Launch the system
 * @return 0 if everything go OK
 */
int launch(Screen screen);