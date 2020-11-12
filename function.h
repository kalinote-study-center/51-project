#ifndef __FUNCTION_H
#define __FUNCTION_H
#include "DS1302.h"
#include "1602.h"
#include "show.h"

#ifndef u8
#define u8 unsigned char
#endif

void KeyAction(u8 keymap);
void AlarmClock(u8 keymap);
void TimeRegulation(u8 keymap);
//void StopWatch(u8 keymap);  //√Î±Ì

#endif