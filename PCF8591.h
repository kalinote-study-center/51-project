#ifndef __PCF8591_H
#define __PCF8591_H
#include "IIC.h"

#ifndef u8
#define u8 unsigned char
#endif

u8 GetADCValue(u8 chn);       //��ȡ��ǰ��ADCת��ֵ��chn-ADCͨ����0~3
void ValueToString(u8 *str,u8 val);   
// ADCת��ֵתΪʵ�ʵ�ѹֵ���ַ�����ʽ��str�ַ���ָ�룬valADת��ֵ

#endif