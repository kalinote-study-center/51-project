#ifndef __SHOW_H
#define __SHOW_H
#include "1602.h"
#include "DS1302.h"
#include "PCF8591.h"

#ifndef u8
#define u8 unsigned char
#endif

void ShowBasic();
void ShowAlarmClock(u8 *TIME);
void ShowTimeRegulation(u8 *TIME);
void ShowParameters();
void ShowJudg(u8 jdg);

#endif