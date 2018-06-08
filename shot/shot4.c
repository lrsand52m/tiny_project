#include <stdio.h>
#include <stdlib.h>
#include <wtypes.h>
#include <tchar.h>
#include<math.h>
#include<time.h>
//设置打印位置
void CaptureScreen(int x1, int y1, int x2, int y2)
{
	int t = 0;
	if (x2 < x1)
	{
		t = x2; x2 = x1; x1 = t;
	}
	if (y2 < y1)
	{
		t = y2; y2 = y1; y1 = t;
	}
	//获得桌面窗口句柄
	HWND hDesktopWnd = GetDesktopWindow();
	//获得桌面窗口设备环境
	HDC hDesktopDC = GetDC(hDesktopWnd);
	//产生全屏幕窗口设备描述表的兼容设备环境
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	//产生全屏幕窗口设备描述表的兼容位图
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, x2, y2);
	printf("%d\n%d\n", x2 - x1, y2 - y1);
	//system("pause");
	//将兼容位图选入兼容设备环境
	SelectObject(hCaptureDC, hCaptureBitmap);
	//将全屏幕窗口位图的象素数据拷贝到兼容设备描述表
	BitBlt(hCaptureDC,  0, 0, x2-x1, y2-y1, hDesktopDC, x1, y1, SRCCOPY);
	BITMAPINFO    bi;
	void *pBits = NULL;
	ZeroMemory(&bi, sizeof(bi));
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biHeight = (y2 - y1);
	bi.bmiHeader.biWidth = (x2 - x1);
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 24;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 3 * (y2 - y1)*(x2 - x1);
	//产生位图兼容设备描述表
	//DECLARE_HANDLE(HDC);
	HDC        hBmpFileDC = CreateCompatibleDC(hDesktopDC);
	//产生位图兼容位图  
	HBITMAP    hBmpFileBitmap = CreateDIBSection(hDesktopDC, &bi, DIB_RGB_COLORS, &pBits, NULL, 0);
	//将兼容位图选入兼设备描述表容设备描述表
	SelectObject(hBmpFileDC, hBmpFileBitmap);
	//将捕获的位图的象素拷贝到位图设备环境
	BitBlt(hBmpFileDC, 0, 0, x2 - x1, y2 - y1, hCaptureDC, 0, 0, SRCCOPY);
	//创建文件    typedef void *HANDLE;
	HANDLE    hFile = CreateFile("g:/VS2008/666.bmp", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//保存位图文件
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwRet = 0;
		BITMAPFILEHEADER bmfHeader;
		ZeroMemory(&bmfHeader, sizeof(bmfHeader));
		bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
		bmfHeader.bfSize = bi.bmiHeader.biSizeImage + bmfHeader.bfOffBits;
		bmfHeader.bfType = 'MB';
		//写入位图信息头
		WriteFile(hFile, &bmfHeader, sizeof(bmfHeader), &dwRet, NULL);
		//写入位图尺寸颜色表等信息
		WriteFile(hFile, &bi.bmiHeader, sizeof(bi.bmiHeader), &dwRet, NULL);
		//写入位图数据块
		WriteFile(hFile, pBits, bi.bmiHeader.biSizeImage, &dwRet, NULL);
		CloseHandle(hFile);
	}
	DeleteDC(hBmpFileDC);
	DeleteObject(hBmpFileBitmap);
	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
}
void Pos(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void printpos(int *x, int* y,int z)
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
			Pos(0, z);
			printf("x=%4d,y=%4d\n", xy->x*1920/1536, xy->y*1080/864);
			zx = xy->x;
			zy = xy->y;
		}
		if (GetAsyncKeyState(VK_F1))
		{
			
			CaptureScreen(0, 0, 1920, 1080);
			exit(0);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			*x = xy->x*1920/1536;
			*y = xy->y*1080/864;
			break;
		}
	}
}

int main()
{
	int x1, x2, y1, y2;
	system("mode con cols=20 lines=10");
	Pos(0, 9);
	printf("按下F1快速截取全屏\n");
	Pos(0, 0);
	printf("按下空格选取截图起点\n");
	printpos(&x1, &y1, 1);
	Sleep(300);
	printf("按下空格选取截图终点\n");
	printpos(&x2, &y2, 3);
	CaptureScreen(x1,y1,x2,y2);
	return 0;
}