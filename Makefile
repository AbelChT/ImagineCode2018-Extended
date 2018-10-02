DEVICE = atmega328p
MCU = atmega328p
AVRDUDE_DEVICE = m328p
DEVICE ?= atmega168
MCU ?= atmega168
AVRDUDE_DEVICE ?= m168

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os -std=c++11
CC=avr-g++
OBJ2HEX=avr-objcopy 
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax

PORT ?= /dev/ttyACM0
AVRDUDE=avrdude

TARGET=result
SOURCE_FILES= main.cpp modes/activity.h modes/dance/dance.cpp modes/dance/dance.h modes/power/power.cpp modes/power/power.h modes/race/race.h modes/race/race.cpp modes/dance/choreography_step.cpp modes/dance/choreography_step.h modes/race/race_type.h modes/race/between_lines/race_between_lines.h modes/race/between_lines/race_between_lines.cpp modes/race/black_line/race_black_line.h modes/race/black_line/race_black_line.cpp
all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

result.hex: result.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

result.obj: $(SOURCE_FILES)
	$(CC) $(CFLAGS) $(SOURCE_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c avrisp2 -P $(PORT) -U flash:w:$(TARGET).hex
