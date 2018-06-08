#define _CRT_SECURE_NO_WARNINGS 
#include "click.h"
//const int MOUSEEVENTF_MOVE = 0x0001;      //移动鼠标
//const int MOUSEEVENTF_LEFTDOWN = 0x0002;  //模拟鼠标左键按下
//const int MOUSEEVENTF_LEFTUP = 0x0004;    //模拟鼠标左键抬起
//const int MOUSEEVENTF_RIGHTDOWN = 0x0008; //模拟鼠标右键按下
//const int MOUSEEVENTF_RIGHTUP = 0x0010;   //模拟鼠标右键抬起
//const int MOUSEEVENTF_MIDDLEDOWN = 0x0020;//模拟鼠标中键按下
//const int MOUSEEVENTF_MIDDLEUP = 0x0040;  //模拟鼠标中键抬起
//const int MOUSEEVENTF_ABSOLUTE = 0x8000;  //标示是否采用绝对坐标
/** mouse move
* x -- int, x-coordinate
* y -- int, y-coordinate
*/
//打印坐标
void printpos(int *x, int* y)
{
	long zx = -1;
	long zy = -1;
	POINT ptB = { 0, 0 };
	/*
	typedef struct tagPOINT
	{
	LONG  x;
	LONG  y;
	} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;
	*/
	while (1)
	{
		LPPOINT xy = &ptB;  //位置变量
		GetCursorPos(xy);   //获取鼠标当前位置
		//如果鼠标移动，（即当前的坐标改变则打印出坐标）打印出做坐标。
		if ((zx != xy->x) || (zy != xy->y))
		{
			Pos(0, 2);
			printf("x=%4d,y=%4d\n", xy->x, xy->y);
			zx = xy->x;
			zy = xy->y;
			
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			*x = xy->x;
			*y = xy->y;
			break;
		}
	}
}
//设置打印位置
void Pos(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

//鼠标移动
int move(int x, int y)
{
	typedef BOOL(WINAPI *Fun1)(int x, int y);
	//#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
	//DECLARE_HANDLE(HINSTANCE);
	HINSTANCE hDll;
	hDll = LoadLibrary("user32.dll");
	if (NULL == hDll)
	{
		fprintf(stderr, "load dll 'user32.dll' fail.");
		return -1;
	}
	Fun1 SetCursorPos = (Fun1)GetProcAddress(hDll, "SetCursorPos");
	if (NULL == SetCursorPos)
	{
		fprintf(stderr, "call function 'SetCursorPos' fail.");
		FreeLibrary(hDll);
		return -1;
	}
	SetCursorPos(x, y);
	FreeLibrary(hDll);
	return 0;
}

/** mouse click
* type          -- int, 0:left click;1:right click
* double_click  -- bool, true:double click; false: single click
*/
//鼠标点击
int clicks(int type, int double_click, int time, int count, int px, int py)
{
	int t = 0;
	while (1)
	{
		move(px, py);
		Sleep(time);
		click(type, double_click);
		count--;
		t++;
		if (!count)break;
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
	}
	return t;
}
int click(int type, int double_click)
{
	int left_click = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
	int right_click = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
	int clicktype;
	HINSTANCE hDll;
	typedef void(WINAPI*Fun2)
		(
		//typedef unsigned long       DWORD;
		DWORD dwFlags,        // motion and click options  
		DWORD dx,             // horizontal position or change  
		DWORD dy,             // vertical position or change  
		DWORD dwData,         // wheel movement  
		//typedef unsigned long _win64 *ULONG_PTR
		ULONG_PTR dwExtraInfo // application-defined information  
		);

	hDll = LoadLibrary("user32.dll");
	if (NULL == hDll)
	{
		fprintf(stderr, "load dll 'user32.dll' fail.");
		return -1;
	}

	Fun2 mouse_event = (Fun2)GetProcAddress(hDll, "mouse_event");
	if (NULL == mouse_event)
	{
		fprintf(stderr, "call function 'mouse_event' fail.");
		FreeLibrary(hDll);
		return -1;
	}
	if (type == 0)
		clicktype = left_click;
	else
		clicktype = right_click;
	mouse_event(clicktype, 0, 0, 0, 0);
	FreeLibrary(hDll);
	if (double_click)
		click(type, 0);
	return 0;
}