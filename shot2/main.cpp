#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <graphics.h>			// 绘图库头文件，绘图语句需要
#include <conio.h>
#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<atlimage.h>
#include<wtypes.h>

char path[260] = "c:/shots/";
char name[100] = { 0 };
void shot()
{
	system("title shot");
	int x, y;
	x = GetSystemMetrics(SM_CXSCREEN);//屏幕宽度
	y = GetSystemMetrics(SM_CYSCREEN);//屏幕高度
	//std::cout << x << " " << y << std::endl;
	system("pause");
	ShowWindow(FindWindow(NULL, _T("shot")), SW_MINIMIZE);
	Sleep(300);
	//system("mode con cols=80 lines=40");
	HWND h = ::GetDesktopWindow();
	HDC hdc = GetDC(h);
	RECT re;
	::GetClientRect(h, &re);
	HDC hdcm = ::CreateCompatibleDC(hdc);
	HBITMAP hn = ::CreateCompatibleBitmap(hdc, 1920, 1080);
	HBITMAP ho = (HBITMAP)::SelectObject(hdcm, hn);
	::BitBlt(hdcm, 0, 0, 1920, 1080, hdc, 0, 0, SRCCOPY);

	//getchar();
	if (OpenClipboard(NULL) && EmptyClipboard())
	{
		SetClipboardData(CF_BITMAP, hn);
	}
	CloseClipboard();
}
char* shot2(char* name)
{
	ShowWindow(FindWindow(NULL, _T("G:\\VS2008\\TEST\\paint\\Debug\\paint.exe")), SW_MINIMIZE);
	Sleep(300);
	//char *name = "c:/qeiourasdhgkd.bmp";
	//获得桌面窗口句柄
	HWND hDesktopWnd = GetDesktopWindow();
	//获得桌面窗口设备环境
	HDC hDesktopDC = GetDC(hDesktopWnd);
	//产生全屏幕窗口设备描述表的兼容设备环境
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	//产生全屏幕窗口设备描述表的兼容位图
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, 1920, 1080);
	//printf("\n宽度:%d\n高度:%d\n", x2 - x1, y2 - y1);
	//system("pause");
	//将兼容位图选入兼容设备环境
	SelectObject(hCaptureDC, hCaptureBitmap);
	//将全屏幕窗口位图的象素数据拷贝到兼容设备描述表
	BitBlt(hCaptureDC, 0, 0, 1920, 1080, hDesktopDC, 0, 0, SRCCOPY);
	BITMAPINFO    bi;
	void *pBits = NULL;
	ZeroMemory(&bi, sizeof(bi));
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biHeight = (1080);
	bi.bmiHeader.biWidth = (1920);
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 24;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 3 * (1080)*(1920);
	//产生位图兼容设备描述表
	//DECLARE_HANDLE(HDC);
	HDC        hBmpFileDC = CreateCompatibleDC(hDesktopDC);
	//产生位图兼容位图  
	HBITMAP    hBmpFileBitmap = CreateDIBSection(hDesktopDC, &bi, DIB_RGB_COLORS, &pBits, NULL, 0);
	//将兼容位图选入兼设备描述表容设备描述表
	SelectObject(hBmpFileDC, hBmpFileBitmap);
	//将捕获的位图的象素拷贝到位图设备环境
	BitBlt(hBmpFileDC, 0, 0, 1920, 1080, hCaptureDC, 0, 0, SRCCOPY);
	//创建文件    typedef void *HANDLE;
	HANDLE    hFile = CreateFile(name, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
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
		//写入剪切板
		if (OpenClipboard(NULL) && EmptyClipboard())
		{
			SetClipboardData(CF_BITMAP, hFile);
		}
		CloseClipboard();
		CloseHandle(hFile);
	}

	DeleteDC(hBmpFileDC);
	DeleteObject(hBmpFileBitmap);
	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
	return name;
}
void CIrcle()
{
	CImage image;
	HWND h = ::GetDesktopWindow();
	image.Load("C:/1.jpg");
	ShowWindow(FindWindow(NULL, _T("shot")), SW_MINIMIZE);
	Sleep(1000);
	int j = 0;
	while (j < 1000)
	{
		image.Draw(GetDC(h), CRect(0,0,1920,1080));
		Sleep(10);
		j++;
	}
	Sleep(10000);
	system("pause");
	initgraph(640, 480);
	int i = 1;
	while (1)
	{
		setlinecolor(RGB(i, 0, 0));
		circle(320, 240, 255 - i);
		i++;
		Sleep(90);
		if (i == 256)break;
	}
	Sleep(1000);
	closegraph();
}
void Lines()
{
	initgraph(520, 520);
	int color[8] = { RGB(233,0,0), RGB(250, 150, 50), YELLOW, GREEN, CYAN, BLUE, RGB(210, 0, 230),WHITE };
	int r = 250;
	setfillcolor(WHITE);
	solidrectangle(0, 0, 519, 519);
	for (int i = 0; i < 8; i++)
	{
		setfillcolor(color[i]);
		solidcircle(260, 260, r);
		r -= 10;
	}
	setfillcolor(WHITE);
	solidrectangle(0, 260, 519, 519);
	getchar();
	closegraph();
}

void LRS()
{
	initgraph(640, 480);
	int stx = 130;
	int sty = 150;
	POINT a[6] = { { stx + 150, sty + 115 }, { stx + 150, sty + 180 },
	{ stx + 235, sty + 180 }, { stx + 160, sty + 100 },
	{ stx + 250, sty + 100 }, { stx + 250, sty + 170 } };
	while (1)
	{
		setfillcolor(BLACK);
		solidrectangle(0, 0, 639, 479);
		setlinecolor(BLACK);
		setfillcolor(RED);
		solidrectangle(stx, sty, stx + 120, sty + 180);
		setfillcolor(GREEN);
		Sleep(500);
		solidrectangle(stx + 130, sty, stx + 250, sty + 180);
		setfillcolor(BLUE);
		Sleep(500);
		solidrectangle(stx + 260, sty, stx + 380, sty + 180);
		setfillcolor(BLACK);
		Sleep(500);
		solidrectangle(stx + 20, sty, stx + 120, sty + 160);
		Sleep(500);
		solidrectangle(stx + 150, sty + 20, stx + 230, sty + 80);
		Sleep(500);
		fillpolygon(a, 3);
		Sleep(500);
		fillpolygon(a + 3, 3);
		Sleep(500);
		solidrectangle(stx + 280, sty + 20, stx + 380, sty + 80);
		Sleep(500);
		solidrectangle(stx + 260, sty + 100, stx + 360, sty + 160);
		Sleep(2000);
	}
	closegraph();
}
void painter()
{
	initgraph(640, 480);		// 初始化640x480的绘图屏幕
	MOUSEMSG m;
	int flag = 0;
	int prex = 0;
	int prey = 0;
	int first = 1;
	long t1 = 0;
	long t2 = 0;
	//setwritemode(R2_XORPEN);
	setlinestyle(PS_SOLID, 6);
	while (1)
	{
		m = GetMouseMsg();
		t2 = clock();
		if (t2 - t1 > 20)
			first = 1;
		t1 = clock();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			//line(m.x-1, m.y-1, m.x, m.y);
			if (first)
			{
				prex = m.x;
				prey = m.y;
				first = 0;
			}
			if (flag)
			{
				line(m.x, m.y, prex, prey);
				prex = m.x;
				prey = m.y;
				//Sleep(100);
			}
		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			setlinecolor(RED);
			setfillcolor(RED);
			flag = 1;
			solidcircle(m.x, m.y, 3);
		}
		if (m.uMsg == WM_RBUTTONDOWN)
		{
			setlinecolor(WHITE);
			setfillcolor(WHITE);
			flag = 1;
			solidcircle(m.x, m.y, 3);
		}
		if (m.uMsg == WM_LBUTTONUP)
		{
			setlinecolor(RED);
			flag = 0;
			//solidcircle(m.x, m.y, 5);
		}
		if (m.uMsg == WM_RBUTTONUP)
		{
			setlinecolor(WHITE);
			flag = 0;
			//solidcircle(m.x, m.y, 5);
		}
		if (m.uMsg == WM_MBUTTONDOWN)
		{
			int c = getfillcolor();
			setfillcolor(BLACK);
			solidrectangle(0, 0, 640, 480);
			setfillcolor(c);
		}
		if (_kbhit())
		{
			setlinecolor(RGB(_getch() * 2, rand() % 256, rand() % 256));
		}
	}
	getchar();
	closegraph();				// 关闭绘图屏幕
}
void RECS()
{
	MOUSEMSG m;
	//initgraph(640, 480);
	setlinestyle(PS_SOLID, 4);
	setlinecolor(BLUE);
	setfillcolor(BLUE);
	int stx = 0;
	int sty = 0;
	int prex = 0;
	int prey = 0;
	setwritemode(R2_XORPEN);
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			//putpixel(m.x,m.y,BLUE);
			stx = m.x;
			sty = m.y;
			prex = m.x;
			prey = m.y;
			break;
		case WM_LBUTTONUP:
			break;
		case WM_MOUSEMOVE:
			if (m.mkLButton)
			{
				rectangle(stx, sty, prex, prey);
				rectangle(stx, sty, m.x, m.y);
				prex = m.x;
				prey = m.y;
			}
			break;
		}
	}
	//closegraph();
}
void load(char* name)
{
	IMAGE img;	// 定义 IMAGE 对象
	loadimage(&img, name);	// 读取图片到 img 对象中
	int y = img.getheight(), x = img.getwidth();
	initgraph(x, y);//根据图片尺寸初始化绘图窗口
	//setaspectratio(1600 / 1980.0, 845 / 1080.0);
	ShowWindow(FindWindow(NULL, _T("paint")), SW_MAXIMIZE);//窗口最大化
	//setorigin(1600-1980, 845-1080);
	putimage(0, 0, &img);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
	RECS();
	getchar();
	closegraph();
}
char* setname(char* p)
{
	//strcat(p, "-");
	//strcat(p, __DATE__); 
	char * ret = p;
	while (*p)
	{
		if (*p == ':' || *p == ' ' || *p == '\n')*p = '-';
		p++;
	}
	*(p - 1) = 0;
	strcat(ret, ".bmp");
	return ret;
}
char* init()
{
	//system("md c:/shot/");
	//system("pause");
	time_t lt = time(NULL);
	char p[100] = { 0 };
	int t = 0;
	strcpy(p, ctime(&lt));
	setname(p);
	sprintf(name, "%s%s", path, p);
	return name;
}
void begins()
{
	load(shot2(init()));
}
int main()
{
	begins();
	//system("title shot");
	//srand((unsigned)time(NULL));
	//system("title LRS");
	////system("mode con cols = 80 lines = 45");
	//initgraph(640, 480);		// 初始化640x480的绘图屏幕
	//ShowWindow(FindWindow(NULL, _T("paint")), SW_MAXIMIZE);
	//RECS();
	//shot();
	//CIrcle();
	//painter();
	//LRS();
	//Lines();
	//system("pause");
	//load();
	return 0;
}
