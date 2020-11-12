#include "show.h"


u8 TIME0[8]; //缓存实时时间
extern u8 alarmclock[5];
extern u8 timeregulation[8];
extern u8 pass;

void ShowBasic()
{
	u8 str1[17] = {"2000-00-00 Week0"},str2[17] = {"00:00:00Timeshow"};
	DS1302BurstRead(TIME0);
	
	str1[2] = (TIME0[6]/16)+'0';
	str1[3] = (TIME0[6]&0x0F)+'0';
	str1[5] = (TIME0[4]/16)+'0';
	str1[6] = (TIME0[4]&0x0F)+'0';				
	str1[8] = (TIME0[3]/16)+'0';
	str1[9] = (TIME0[3]&0x0F)+'0';
	str1[15] = (TIME0[5]&0x0F)+'0';
	str1[17] = '\0';
	LcdShowStr(0,0,str1);
				
	str2[0] = (TIME0[2]/16)+'0';
	str2[1] = (TIME0[2]&0x0F)+'0';
	str2[3] = (TIME0[1]/16)+'0';
	str2[4] = (TIME0[1]&0x0F)+'0';				
	str2[6] = (TIME0[0]/16)+'0';
	str2[7] = (TIME0[0]&0x0F)+'0';
	str2[17] = '\0';
	LcdShowStr(0,1,str2);
}

void ShowAlarmClock(u8 *TIME)
{
	u8 str1[17] = {"Alarm setting:"},str2[17] = {"00:00:00  week0"};
	
	str1[14] = '\0';
	LcdShowStr(0,0,str1);
	
	str2[0] = (TIME[2]/16)+'0';     //时
	str2[1] = (TIME[2]&0x0F)+'0';
	str2[3] = (TIME[1]/16)+'0';    //分
	str2[4] = (TIME[1]&0x0F)+'0';
	str2[6] = (TIME[0]/16)+'0';     //秒
	str2[7] = (TIME[0]&0x0F)+'0';	
	str2[14] = (TIME[3]&0x0F)+'0';   //周
	str2[15] = '\0';
    LcdShowStr(0,1,str2);
}

void ShowTimeRegulation(u8 *TIME)
{
	u8 str1[17] = {"Adapt:2000-00-00"},str2[17] = {"00:00:00  Week0"};
	
	str1[8] = (TIME[6]/16)+'0';
	str1[9] = (TIME[6]&0x0F)+'0';     //年
	str1[11] = (TIME[4]/16)+'0';
	str1[12] = (TIME[4]&0x0F)+'0';   //月
	str1[14] = (TIME[3]/16)+'0';
	str1[15] = (TIME[3]&0x0F)+'0';   //日
	str1[16] = '\0';
	LcdShowStr(0,0,str1);

	str2[0] = (TIME[2]/16)+'0';     //时
	str2[1] = (TIME[2]&0x0F)+'0';
	str2[3] = (TIME[1]/16)+'0';    //分
	str2[4] = (TIME[1]&0x0F)+'0';
	str2[6] = (TIME[0]/16)+'0';     //秒
	str2[7] = (TIME[0]&0x0F)+'0';	
	str2[14] = (TIME[5]&0x0F)+'0';   //周
	str2[15] = '\0';
    LcdShowStr(0,1,str2);	
}

void ShowParameters()
{
	static float vbuff1 = 0.6,vbuff2 = 0;
	int ppm;
	u8 str1[17] ={"Gas:0000ppm"},str2[17] = {"TMP:000 RH:00%"},val;
	
	val = GetADCValue(1);
	vbuff2 = (val*50) / 2550.0;
	ppm = (vbuff2 - vbuff1)*2000;
	str1[5] = (ppm % 1000)/100 +'0';
	str1[4] = ppm / 1000 + '0';
	LcdShowStr(0,0,str1);
	
	LcdShowStr(0,1,str2);
}

void ShowJudg(u8 jdg)
{
	switch(jdg)
	{
		case 0:
			ShowBasic();
			break;
		case 1:
			ShowAlarmClock(alarmclock);
			break;
		case 2:
			ShowTimeRegulation(timeregulation);
			break;
		case 3:
			ShowParameters();
			break;
		default:
			break;
	}
}


