#ifndef __DS1302_H
#define __DS1302_H
#include "reg52.h"
#ifndef u8
#define u8 unsigned char
#endif

sbit DS1302_CK = P3^5;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P1^7;

void DS1302ByteWrite(u8 dat);   //读/写一位到DS1302
u8 DS1302ByteRead();
void DS1302SingleWrite(u8 reg,u8 single);   //由寄存器读/写，reg为寄存器地址
u8 DS1302SingleRead(u8 reg);
void DS1302BurstRead(u8 *dat);  //爆发模式，8位读/写
void DS1302BurstWrite(u8 *dat);
void DS1302_Inite();          //初始化

#endif
