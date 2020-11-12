#include "PCF8591.h"

u8 GetADCValue(u8 chn)
{
    u8 val;
    
    IIC_Start();
    if (!IIC_SendByte(0x48<<1))  //寻址PCF8591，如未应答，则停止操作并返回0
    {
        IIC_Stop();
        return 0;
    }
    IIC_SendByte(0x40|chn);        //写入控制字节，选择转换通道
    IIC_Start();
    IIC_SendByte((0x48<<1)|0x01);  //寻址PCF8591，指定后续为读操作
    IIC_ReadACK();       //先读取一空字节
    val =IIC_ReadNAK();        //读取刚刚转换完的值
    IIC_Stop();
    
    return val;
}

void ValueToString(u8 *str,u8 val)
{
    val = (val*50) / 255;
    str[0] = (val/10) + '0';
    str[1] = '.'; 
    str[2] = (val%10) + '0'; 
    str[3] = 'V';
    str[4] = '\0'; 
}
