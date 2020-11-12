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

void LcdWaitReady();    //等待
void LcdWriteCmd(u8 cmd);   //写命令
void LcdWriteDat(u8 dat);   //写数据
void LcdSetCursor(u8 x,u8 y);   //设置起始位置
void LcdShowStr(u8 x,u8 y,u8 *str);   //串显示
void LcdInit();   //初始化

#endif