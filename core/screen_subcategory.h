#pragma once

#include "screen_content.h"
#include "screen.h"

class ScreenSubcategory : ScreenContent {
private:
    Screen screens [];
    unsigned int size;
public:
    ScreenSubcategory(Screen *screens, unsigned int size);
};
