#include <1602.h>

void LcdWaitReady()
{
	u8 buff;
	LCD1602_DB = 0xFF;
	LCD1602_RS = 0;
	LCD1602_RW = 1;
	do
	{
		LCD1602_E = 1;
		buff = LCD1602_DB;
		LCD1602_E = 0;
	}while(buff & 0x80);
}

void LcdWriteCmd(u8 cmd)
{
	LcdWaitReady();
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_DB = cmd;
	LCD1602_E = 1;
	LCD1602_E = 0;
}

void LcdWriteDat(u8 dat)
{
	LcdWaitReady();
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_DB = dat;
	LCD1602_E = 1;
	LCD1602_E = 0;
}

void LcdSetCursor(u8 x,u8 y)
{
	u8 addr = x;
	if(y == 1)
		addr += 0x40;
	LcdWriteCmd(addr | 0x80);
}

void LcdShowStr(u8 x,u8 y,u8 *str)
{
	LcdSetCursor(x,y);
	while(*str != 0)
	{
		LcdWriteDat(*str);
		str++;
	}
}

void LcdInit()
{
	LcdWriteCmd(0x38);
	LcdWriteCmd(0x0c);
	LcdWriteCmd(0x06);
	LcdWriteCmd(0x01);
}



