#ifndef __1602_H
#define __1602_H
#include <reg52.h>
#ifndef u8
#define u8 unsigned char
#endif
#define LCD1602_DB P0

sbit LCD1602_RS = P1^0;
sbit LCD1602_RW = P1^1;
sbit LCD1602_E = P1^5;

void LcdWaitReady();    //�ȴ�
void LcdWriteCmd(u8 cmd);   //д����
void LcdWriteDat(u8 dat);   //д����
void LcdSetCursor(u8 x,u8 y);   //������ʼλ��
void LcdShowStr(u8 x,u8 y,u8 *str);   //����ʾ
void LcdInit();   //��ʼ��

#endif