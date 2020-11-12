#include "time.h"

extern bit alarmflag;
extern u8 alarmclock[5];
u8 time1[8];

void AlarmClockJudg()
{
	if(alarmflag == 1)
	{
		DS1302BurstRead(time1);
		if((alarmclock[2] == time1[2])&&(alarmclock[1] == time1[1])&&(alarmclock[3] == time1[5]))
			{
				BUZZ = 0;
			}
	}
	if(alarmflag == 0)
	{
		BUZZ = 1;
	}
}