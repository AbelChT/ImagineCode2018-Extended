cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(ImagineCode_C__port)

include_directories(/usr/lib/avr/include)

add_executable(
        executabl main.cpp modes/activity.h modes/dance/dance.cpp modes/dance/dance.h modes/power/power.cpp
        modes/power/power.h modes/race/race.h modes/race/race.cpp modes/dance/choreography_step.cpp
        modes/dance/choreography_step.h modes/race/race_type.h modes/race/between_lines/race_between_lines.h
        modes/race/between_lines/race_between_lines.cpp modes/race/black_line/race_black_line.h
        modes/race/black_line/race_black_line.cpp)