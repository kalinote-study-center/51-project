#ifndef __IIC_H
#define __IIC_H

#include "reg52.h"

#ifndef u8
#define u8 unsigned char
#endif

sbit SCL = P3^1;
sbit SDA = P3^0;

void IIC_Delay10us();   //IIC��������ʱ10us(ԭ����>4.7us����)
void IIC_Start();     //��ʼλ
void IIC_Stop();      //����λ
bit IIC_SendByte(u8 dat);     //�����߷���һ�ֽ�����,���سɹ����
u8 IIC_ReadACK();    //��һ�ֽ����ݣ�����Ӧ���ź�
u8 IIC_ReadNAK();      //��һ���ֽڣ���������Ӧ���ź�

#endif