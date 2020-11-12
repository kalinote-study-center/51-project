#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "reg52.h"
#include "function.h"

#define u8 unsigned char

sbit KEY_IN_1  = P2^4;
sbit KEY_IN_2  = P2^5;
sbit KEY_IN_3  = P2^6;
sbit KEY_IN_4  = P2^7;
sbit KEY_OUT_1 = P2^3;
sbit KEY_OUT_2 = P2^2;
sbit KEY_OUT_3 = P2^1;
sbit KEY_OUT_4 = P2^0;

void KeyScan();
void KeyDriver();

#endif