#pragma once
#include <tchar.h>
#include<stdio.h>
//#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <afxwin.h>
#define clt CLK_TCK
//#define _AFXDLL
void Pos(int x,int y);
int prints(char*, int);
int getMapArray(char *mapname, unsigned char *maparray, int* mapwidth, int* mapheight);
unsigned int printimg(char* argv);
int move(int x, int y);
int click(int type, int double_click);
int clicks(int type, int double_click, int time, int count, int px, int py);
void printpos(int *x,int *y);