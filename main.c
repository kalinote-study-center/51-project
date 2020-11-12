#include "1602.h"
#include "DS1302.h"
#include "keyboard.h"
#include "show.h"
#include "reg52.h"
#include "time.h"

extern u8 pass;
void Init_Timer0();


void main()
{
    EA = 1;
	Init_Timer0();
	DS1302_Inite();
	LcdInit();
	
    while (1)
    {
		KeyDriver();      //ִ�а����ж�
	}
}

void Init_Timer0()
{
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TH0 = 0xFC;     //����T0����ֵ
    TL0 = 0x67;
    ET0 = 1;
    TR0 = 1;
}

void InterruptTimer0() interrupt 1
{
    TH0 = 0xd8;
    TL0 = 0xf0;
    KeyScan();   //ִ�а���ɨ��
	ShowJudg(pass);  //��ʾģʽ�ж�
	AlarmClockJudg();     //�����ж�
}



