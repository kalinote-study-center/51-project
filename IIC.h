#ifndef __IIC_H
#define __IIC_H

#include "reg52.h"

#ifndef u8
#define u8 unsigned char
#endif

sbit SCL = P3^1;
sbit SDA = P3^0;

void IIC_Delay10us();   //IIC总线用延时10us(原则上>4.7us即可)
void IIC_Start();     //开始位
void IIC_Stop();      //结束位
bit IIC_SendByte(u8 dat);     //向总线发送一字节数据,返回成功与否
u8 IIC_ReadACK();    //读一字节数据，发送应答信号
u8 IIC_ReadNAK();      //读一个字节，但发出非应答信号

#endif