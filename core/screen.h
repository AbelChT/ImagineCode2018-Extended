#pragma once

#include "screen_content.h"

class Screen {
private:
    const char title[];
    ScreenContentType type;
    ScreenContent screenContent;
public:
    Screen(const char *title, const ScreenContent &screenContent, ScreenContentType type);
};
