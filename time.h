#ifndef __TIME_H
#define __TIME_H
#include "reg52.h"
#include "DS1302.h"

sbit BUZZ = P1^6;

void AlarmClockJudg();

#endif