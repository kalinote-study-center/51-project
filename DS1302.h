#ifndef __DS1302_H
#define __DS1302_H
#include "reg52.h"
#ifndef u8
#define u8 unsigned char
#endif

sbit DS1302_CK = P3^5;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P1^7;

void DS1302ByteWrite(u8 dat);   //��/дһλ��DS1302
u8 DS1302ByteRead();
void DS1302SingleWrite(u8 reg,u8 single);   //�ɼĴ�����/д��regΪ�Ĵ�����ַ
u8 DS1302SingleRead(u8 reg);
void DS1302BurstRead(u8 *dat);  //����ģʽ��8λ��/д
void DS1302BurstWrite(u8 *dat);
void DS1302_Inite();          //��ʼ��

#endif
