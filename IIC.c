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

    for (mask=0x80; mask!=0; mask>>=1) //从高位到低位依次进行
    {
        if ((mask&dat) == 0)  //该位的值输出到SDA上
            SDA = 0;
        else
            SDA = 1;
        IIC_Delay10us();
        SCL = 1;          //拉高SCL
        IIC_Delay10us();
        SCL = 0;          //再拉低SCL，完成一个位周期
    }
    SDA = 1;   //8位数据发送完后，主机释放SDA，以检测从机应答
    IIC_Delay10us();
    SCL = 1; 
    ack = SDA;
    IIC_Delay10us();
    SCL = 0; 

    return (~ack);   //0=不存在或忙或写入失败，1=存在且空闲或写入成功		
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


