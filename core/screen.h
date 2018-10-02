#pragma once

#include "screen_content.h"

class Screen {
private:
    char title[];
    ScreenContentType type;
    ScreenContent screenContent;
public:
    Screen(char *title, const ScreenContent &screenContent, ScreenContentType type);
};
