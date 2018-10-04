//
// Created by abel on 3/10/18.
//

#include "screen.h"

Screen::Screen(const char *title, const ScreenContent &screenContent, ScreenContentType type) : title(title), type(type),
                                                                                          screenContent(
                                                                                                  screenContent) {}
