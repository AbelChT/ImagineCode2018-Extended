#include "main.h"

/**
 * Entry point of your program
 * @param device Pololu3pi controller device
 * @return main screen
 */
Screen entryPoint(Pololu3pi *device){
    const char msg_select_mode[] = "select\nmode";
    const char msg_race_mode[] = "race\nmode";
    const char msg_dance_mode[] = "dance\nmode";
    const char msg_power_mode[] = "power\nmode";

    Screen danceScreen = Screen(msg_dance_mode, Dance(), ScreenContentType::ACTIVITY);
    Screen raceScreen = Screen(msg_race_mode, Race(device), ScreenContentType::ACTIVITY);
    Screen powerScreen = Screen(msg_power_mode, Power(), ScreenContentType::ACTIVITY);

    Screen screens[3] = {danceScreen, raceScreen, powerScreen};

    ScreenSubcategory subcategory = ScreenSubcategory(screens, 3);

    Screen mainScreen = Screen(msg_select_mode, subcategory, ScreenContentType::SUBCATEGORY);

    return mainScreen;
}
