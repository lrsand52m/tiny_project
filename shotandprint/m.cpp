#define _CRT_SECURE_NO_WARNINGS
#include "Prints.h"
int main(int argc,char* argv[])
{
	int x1, x2, y1, y2;
	system("mode con cols=30 lines=15");
	system("md c:\\VS2008");
	Pos(0, 9);
	printf("按下F1快速截取全屏\n");
	Pos(0, 0);
	printf("按下空格选取截图起点\n");
	printpos(&x1, &y1, 1);
	Sleep(300);
	printf("按下空格选取截图终点\n");
	printpos(&x2, &y2, 3);
	//x2 -= (x2 - x1) % 4;
	CaptureScreen(x1, y1, x2, y2);
	return 0;
	//system("start /b C:/Windows/system32/mspaint.exe");
	////_T是一个宏，作用是让你的程序支持Unicode编码.
	//HWND hwnd_notepad = FindWindow(_T("notepad++"), 0);
	////#define DECLARE_HANDLE(name)
	////struct name##__{int unused;};
	////typedef struct name##__ *name
	/////DECLARE_HANDLE        (HWND);
	//if (hwnd_notepad == 0)
	//{
	//	MessageBox(0, _T("dont run notepad"), _T("error"), MB_OK);
	//	return 0;
	//}
	////获取窗口大写
	//RECT rect;
	//GetWindowRect(hwnd_notepad, &rect);
	//LONG height = rect.bottom - rect.top;
	//LONG width = rect.right - rect.left;
	////输出窗口大小信息
	//TCHAR tzbuf[256] = { 0 };
	//wsprintf(tzbuf, _T("%s%d\n%s%d"), _T("height="), height, _T("width="), width);
	////弹出消息栏
	//MessageBox(0, tzbuf, _T("notepad window size"), MB_OK);
	//printf("%s\n", tzbuf);
	//system("pause");
	//prints(argv[1],0);
}

