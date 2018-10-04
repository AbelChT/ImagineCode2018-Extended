#pragma once

#include "core/platform_includes.h"
#include "core/screen_subcategory.h"
#include "modes/dance/dance.h"
#include "modes/race/race.h"
#include "modes/power/power.h"


/**
 * Entry point of your program
 * @param device Pololu3pi controller device
 * @return main screen
 */
Screen entryPoint(Pololu3pi *device);