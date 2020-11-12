#include "function.h"

extern u8 alarmclock[5] = {
0x00,0x00,0x00,0x00,0
};   //��������ʱ��
extern u8 timeregulation[8] ={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};   //ʱ����Ļ���,�롢�֡�ʱ���ա��¡��ܡ���
extern u8 pass = 0;  //ͨ��֤��������ʾ��������
extern bit alarmflag = 0;    //���Ӹ�������

char mod = 0;   //������־����


void KeyAction(u8 keymap)
{
	u8 i; //�������㸨������
	
	if((alarmflag == 1)&&(keymap == 0x1B))
	{
		alarmflag = 0;
		for(i = 0;i<4;i++)
			alarmclock[i] = 0x00;
	}
	if(keymap == 0x26)
		mod++;
	else if(keymap == 0x28)
		mod--;
	if(mod == 4)        //��־λ�������
	{	
		mod = 0;
		pass = 0;
	}
	if((mod != 0)&&(keymap==0x0D)||(pass != 0))
	{
		if(mod ==1)
		{
			pass = 1;
			AlarmClock(keymap);
		}
		else if(mod == 2)
		{
			pass = 2;
			TimeRegulation(keymap);
		}
		else if(mod == 3)
		{
			LcdInit();
			pass = 3;
			if(keymap == 0x1B)
			{
				mod = 0;
				pass = 0;
			}
		}
//			    case 3:
//				pass = 3;
//				StopWatch(keymap);
//				break; //�����ƣ�����ܽ���
//			default:
//				break;
	}
}

void AlarmClock(u8 keymap)
{
	static u8 keybuff = 0; //ִ�д�������
	u8 i;      //�����������
	
	if(keybuff == 7)  //ִ������ж��Լ�������������
	{
		mod = 0;
		keybuff = 0;
		pass = 0;
		alarmflag = 1;
	}
	else if(keybuff == 0)
		LcdInit();
	
	if((keymap>='0'&&keymap<='9')||keymap==0x25||keymap==0x27)   //����Ч���ж�
	{
		if(keymap>='0'&&keymap<='9')
		{
			switch(keybuff)  //������ִ����ӦЧ��
			{
				case 0:
					alarmclock[0] = keymap - '0' << 4;
					break;
				case 1:
					alarmclock[0] |= keymap - '0';
					break;
				case 2:
					alarmclock[1] = keymap - '0' << 4;
					break;
				case 3:
					alarmclock[1] |= keymap - '0';
					break;
				case 4:
					alarmclock[2] = keymap - '0' << 4;
					break;
				case 5:
					alarmclock[2] |= keymap - '0';
					break;
				case 6:
					alarmclock[3] |= keymap - '0';  //��
					break;
				default:
					break;	
			}
			keybuff++;
		}
		else if(keymap==0x25||keymap==0x27)   //��ֵ��<����>��,�л���������һ������
		{
			switch(keybuff)
			{
				case 0:
					break;
				case 1:
				{
					alarmclock[0] = 0x00;
					keybuff = 0;
				}
					break;
				case 2:
				{
					alarmclock[0] = 0x00;
					keybuff = 0;
				}
					break;
				case 3:
				{
					alarmclock[1] = 0x00;
					keybuff = 2;
				}
					break;
				case 4:
				{
					alarmclock[1] = 0x00;
					keybuff = 2;
				}
					break;
				case 5:
				{
					alarmclock[2] = 0x00;
					keybuff = 4;
				}
					break;
				case 7:
				{
					alarmclock[2] = 0x00;
					keybuff = 4;
				}
					break;
				default:
					break;	
			}
		}
	}
	else if(keymap == 0x1B)
		{
			keybuff = 0;
			pass = 0;
			for(i = 0;i<4;i++)
			alarmclock[i] = 0x00;
			mod = 0;
		}
}
void TimeRegulation(u8 keymap)
{
	static u8 keybuff = 0; //ִ�д�������
	
	if(keybuff == 0) //����һ�ν���ʱ����ȡ����ʱ�䣬���ڵ���
	{
		LcdInit();
		DS1302BurstRead(timeregulation);
	}
	
	if(keymap == 0x0D)  //���»س�����ʾȷ�ϸ���
	{
		keybuff = 0;
		pass = 0;
		DS1302BurstWrite(timeregulation);
	}
	if((keymap>='0'&&keymap<='9')||keymap==0x25||keymap==0x27)
	{
		if(keymap==0x27) //��ֵ��<����>��
			keybuff++;
		else if(keymap == 0x25)
		{
			if(keybuff != 0)
				keybuff --;
		}
		if(keymap>='0'&&keymap<='9')
		{
			switch(keybuff)  //������ִ����ӦЧ��
			{
				case 0:
					timeregulation[0] = keymap - '0' << 4;
					break;
				case 1:
					timeregulation[0] |= keymap - '0';
					break;
				case 2:
					timeregulation[1] = keymap - '0' << 4;
					break;
				case 3:
					timeregulation[1] |= keymap - '0';
					break;
				case 4:
					timeregulation[2] = keymap - '0' << 4;
					break;
				case 5:
					timeregulation[2] |= keymap - '0';
					break;
				case 6:
					timeregulation[3] = keymap - '0' << 4;
					break;
				case 7:
					timeregulation[3] |= keymap - '0';
					break;
				case 8:
					timeregulation[4] = keymap - '0' << 4;
					break;
				case 9:
					timeregulation[4] |= keymap - '0';
					break;
				case 10:
					timeregulation[5] = keymap - '0';
					break;
				case 11:
					timeregulation[6] |= keymap - '0' << 4;
					break;
				case 12:
					timeregulation[6] |= keymap - '0';
					break;
				default:
					break;	
			}
			keybuff++;
		}
	}
	else if(keymap == 0x1B)
	{
		pass = 0;
		keybuff = 0;
		mod = 0;
	}
}
//void StopWatch(u8 keymap)
//{
//	if(keymap == 0x0D)
//	{	
//			keybuff++;
//	}
//}
//�����ƣ������




