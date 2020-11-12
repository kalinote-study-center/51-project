#ifndef __PCF8591_H
#define __PCF8591_H
#include "IIC.h"

#ifndef u8
#define u8 unsigned char
#endif

u8 GetADCValue(u8 chn);       //读取当前的ADC转换值，chn-ADC通道号0~3
void ValueToString(u8 *str,u8 val);   
// ADC转换值转为实际电压值的字符串形式，str字符串指针，valAD转换值

#endif