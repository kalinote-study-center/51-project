#include "PCF8591.h"

u8 GetADCValue(u8 chn)
{
    u8 val;
    
    IIC_Start();
    if (!IIC_SendByte(0x48<<1))  //ѰַPCF8591����δӦ����ֹͣ����������0
    {
        IIC_Stop();
        return 0;
    }
    IIC_SendByte(0x40|chn);        //д������ֽڣ�ѡ��ת��ͨ��
    IIC_Start();
    IIC_SendByte((0x48<<1)|0x01);  //ѰַPCF8591��ָ������Ϊ������
    IIC_ReadACK();       //�ȶ�ȡһ���ֽ�
    val =IIC_ReadNAK();        //��ȡ�ո�ת�����ֵ
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
