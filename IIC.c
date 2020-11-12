#include "IIC.h"

void IIC_Delay10us()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);
}

void IIC_Start()
{
	SDA = 1;
	SCL = 1;
	IIC_Delay10us();
	SDA = 0;
	IIC_Delay10us();
	SCL = 0;
}

void IIC_Stop()
{
	SCL = 0;
	SDA = 0;
	IIC_Delay10us();
	SCL = 1;
	IIC_Delay10us();
	SDA = 1;
	IIC_Delay10us();
}

bit IIC_SendByte(u8 dat)
{
    bit ack;
    u8 mask;

    for (mask=0x80; mask!=0; mask>>=1) //�Ӹ�λ����λ���ν���
    {
        if ((mask&dat) == 0)  //��λ��ֵ�����SDA��
            SDA = 0;
        else
            SDA = 1;
        IIC_Delay10us();
        SCL = 1;          //����SCL
        IIC_Delay10us();
        SCL = 0;          //������SCL�����һ��λ����
    }
    SDA = 1;   //8λ���ݷ�����������ͷ�SDA���Լ��ӻ�Ӧ��
    IIC_Delay10us();
    SCL = 1; 
    ack = SDA;
    IIC_Delay10us();
    SCL = 0; 

    return (~ack);   //0=�����ڻ�æ��д��ʧ�ܣ�1=�����ҿ��л�д��ɹ�		
}

u8 IIC_ReadACK()
{
	u8 dat = 0,readbuff;
	
	SDA = 1;
	IIC_Delay10us();
	for(readbuff = 0;readbuff < 8;readbuff++)
	{
		SCL = 1;
		IIC_Delay10us();
		dat <<= 1;
		dat |= SDA;
		IIC_Delay10us();
		SCL = 0;
		IIC_Delay10us();
	}
	SDA = 0;
    IIC_Delay10us();
    SCL = 1;
    IIC_Delay10us();
    SCL = 0; 
	
	return dat;
}

u8 IIC_ReadNAK()
{
	u8 dat = 0,readbuff;
	
	SDA = 1;
	IIC_Delay10us();
	for(readbuff = 0;readbuff < 8;readbuff++)
	{
		SCL = 1;
		IIC_Delay10us();
		dat <<= 1;
		dat |= SDA;
		IIC_Delay10us();
		SCL = 0;
		IIC_Delay10us();
	}
	SDA = 1;
    IIC_Delay10us();
    SCL = 1;
    IIC_Delay10us();
    SCL = 0; 
	
	return dat;
}


