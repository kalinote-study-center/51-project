#include "DS1302.h"
u8 code NowTime[8] = {
0x00,0x30,0x12,0x09,0x11,0x01,0x20,0x00 
};                      //分别按寄存器对应位排列8位，用于掉电后初始化,BCD码形式

void DS1302ByteWrite(u8 dat)
{
	u8 buff;
	for(buff = 0x01;buff != 0;buff <<= 1)
	{
		if(dat&buff)
			DS1302_IO = 1;
		else
			DS1302_IO = 0;
		DS1302_CK = 1;
		DS1302_CK = 0;
	}
	DS1302_IO = 1;
}

u8 DS1302ByteRead()
{
	u8 buff,dat=0;
	for(buff = 0x01;buff != 0;buff <<= 1)
	{
		if(DS1302_IO != 0)
			dat |= buff;
		DS1302_CK = 1;
		DS1302_CK = 0;
	}
	return dat;
}

void DS1302BurstRead(u8 *dat)
{
	u8 i;
	DS1302_CE = 1;
	DS1302ByteWrite(0xBF);
	for(i = 0;i < 8;i++)
	dat[i] = DS1302ByteRead();
	DS1302_CE = 0;
}

void DS1302BurstWrite(u8 *dat)
{
  u8 i;
	DS1302_CE = 1;
	DS1302ByteWrite(0xBE);
	for(i = 0;i < 8;i++)
	DS1302ByteWrite(dat[i]);
	DS1302_CE = 0;
}

void DS1302SingleWrite(u8 reg,u8 single)
{
	DS1302_CE = 1;
	DS1302ByteWrite((reg << 1)|0x80);
	DS1302ByteWrite(single);
	DS1302_CE = 0;
}

u8 DS1302SingleRead(u8 reg)
{
	u8 dat;
	DS1302_CE = 1;
	DS1302ByteWrite((reg << 1)|0x81);
	dat = DS1302ByteRead();
	DS1302_CE = 0;
	return dat;
}

void DS1302_Inite()
{
	u8 dat;
	DS1302_CE = 0;
	DS1302_CK = 0;
	dat = DS1302SingleRead(0);
	if((dat&0x80) != 0)
	{
		DS1302SingleWrite(7,0x00);
		DS1302BurstWrite(NowTime);
	}
}




