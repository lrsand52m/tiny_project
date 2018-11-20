#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>			// 绘图库头文件，绘图语句需要
#include <conio.h>				// 控制台输入输出头文件，system("pause")语句需要
#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdio.h>
//void main()
//{
//	initgraph(640, 480);		// 初始化640x480的绘图屏幕
//	line(200, 240, 440, 240);	// 画线(200,240) - (440,240)
//	line(320, 120, 320, 360);	// 画线(320,120) - (320,360)
//	system("pause");
//	closegraph();				// 关闭绘图屏幕
//}
//
//#include <graphics.h>
//#include <conio.h>
//#include <math.h>
//
//#define PI 3.14
//
//void main()
//{
//	initgraph(640, 480);
//	int c;
//	double a;
//	int x, y, r = 200;
//	for (a = 0; a < PI * 2; a += 0.0001)
//	{
//		x = (int)(r * cos(a) + 320 + 0.5);
//		y = (int)(r * sin(a) + 240 + 0.5);
//		c = (int)(a * 255 / (2 * PI) + 0.5);
//		setlinecolor(RGB(c, 0, 0));
//		line(320, 240, x, y);
//	}
//	system("pause");
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	initgraph(640, 480);
//
//	for (int x = 100; x<540; x += 20)
//	{
//		// 绘制黄线、绿色填充的圆
//		setlinecolor(YELLOW);
//		setfillcolor(GREEN);
//		fillcircle(x, 100, 20);
//
//		// 延时
//		Sleep(500);
//
//		// 绘制黑线、黑色填充的圆
//		setlinecolor(BLACK);
//		setfillcolor(BLACK);
//		fillcircle(x, 100, 20);
//	}
//
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>

//void main()
//{
//	initgraph(640, 480);
//
//	int x = 320;
//
//	// 画初始图形
//	setlinecolor(YELLOW);
//	setfillcolor(GREEN);
//	fillcircle(x, 240, 20);
//
//	char c = 0;
//	while (c != 27)
//	{
//		// 获取按键
//		c = getc(stdin);
//
//		// 先擦掉上次显示的旧图形
//		setlinecolor(BLACK);
//		setfillcolor(BLACK);
//		fillcircle(x, 240, 20);
//
//		// 根据输入，计算新的坐标
//		switch (c)
//		{
//		case 'a': x -= 2; break;
//		case 'd': x += 2; break;
//		case 27: break;
//		}
//
//		// 绘制新的图形
//		setlinecolor(YELLOW);
//		setfillcolor(GREEN);
//		fillcircle(x, 240, 20);
//
//		// 延时
//		Sleep(10);
//	}
//
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>

//void sanjiaoxing(int x, int y, int color)
//{
//	setlinecolor(color);
//
//	line(x, y, x + 10, y);
//	line(x, y, x, y + 10);
//	line(x + 10, y, x, y + 10);
//}
//
//void main()
//{
//	initgraph(640, 480);	
//
//	for (int x = 0; x<640; x += 10)
//	for (int y = 0; y<480; y += 10)
//		sanjiaoxing(x, y, RGB(x * 255 / 640, y * 255 / 480, 0));
//
//	getc(stdin);				
//	closegraph();		
//}
//#include <graphics.h>
//#include <conio.h>
//#include <math.h>
//
//#define PI 3.14159265359
//
//void Draw(int hour, int minute, int second)
//{
//	double a_hour, a_min, a_sec;					// 时、分、秒针的弧度值
//	int x_hour, y_hour, x_min, y_min, x_sec, y_sec;	// 时、分、秒针的末端位置
//
//	// 计算时、分、秒针的弧度值
//	a_sec = second * 2 * PI / 60;
//	a_min = minute * 2 * PI / 60 + a_sec / 60;
//	a_hour = hour * 2 * PI / 12 + a_min / 12;
//
//	// 计算时、分、秒针的末端位置
//	x_sec = 320 + (int)(120 * sin(a_sec));
//	y_sec = 240 - (int)(120 * cos(a_sec));
//	x_min = 320 + (int)(100 * sin(a_min));
//	y_min = 240 - (int)(100 * cos(a_min));
//	x_hour = 320 + (int)(70 * sin(a_hour));
//	y_hour = 240 - (int)(70 * cos(a_hour));
//
//	// 画时针
//	setlinestyle(PS_SOLID, 10, NULL);
//	setlinecolor(WHITE);
//	line(320, 240, x_hour, y_hour);
//
//	// 画分针
//	setlinestyle(PS_SOLID, 6, NULL);
//	setlinecolor(LIGHTGRAY);
//	line(320, 240, x_min, y_min);
//
//	// 画秒针
//	setlinestyle(PS_SOLID, 2, NULL);
//	setlinecolor(RED);
//	line(320, 240, x_sec, y_sec);
//}
//
//void main()
//{
//	initgraph(640, 480);		// 初始化 640 x 480 的绘图窗口
//
//	// 绘制一个简单的表盘
//	circle(320, 240, 2);
//	circle(320, 240, 60);
//	circle(320, 240, 160);
//	outtextxy(296, 310, _T("BestAns"));
//
//	// 设置 XOR 绘图模式
//	setwritemode(R2_XORPEN);	// 设置 XOR 绘图模式
//
//	// 绘制表针
//	SYSTEMTIME ti;				// 定义变量保存当前时间
//	while (!_kbhit())				// 按任意键退出钟表程序
//	{
//		GetLocalTime(&ti);		// 获取当前时间
//		Draw(ti.wHour, ti.wMinute, ti.wSecond);	// 画表针
//		Sleep(1000);							// 延时 1 秒
//		Draw(ti.wHour, ti.wMinute, ti.wSecond);	// 擦表针（擦表针和画表针的过程是一样的）
//	}
//
//	closegraph();				// 关闭绘图窗口
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	// 初始化图形窗口
//	initgraph(640, 480);
//	MOUSEMSG m;						// 定义鼠标消息
//	while (true)
//	{
//		// 获取一条鼠标消息
//		m = GetMouseMsg();
//
//		switch (m.uMsg)
//		{
//		case WM_MOUSEMOVE:		// 鼠标移动的时候画红色的小点
//			putpixel(m.x, m.y, RED);
//			break;
//
//		case WM_LBUTTONDOWN:	// 如果点左键的同时按下了 Ctrl 键
//			if (m.mkCtrl)		// 画一个大方块
//				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
//			else				// 画一个小方块
//				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
//			break;
//
//		case WM_RBUTTONUP:
//			return;				// 按鼠标右键退出程序
//		}
//	}
//	 //关闭图形窗口
//	closegraph();
//}
//#include <graphics.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <time.h>
//
//void main()
//{
//	srand((unsigned)time(NULL));
//
//	initgraph(640, 480);
//
//	int x, y, c;
//	while (!_kbhit())
//	{
//		x = rand() % 640;
//		y = rand() % 480;
//		c = RGB(rand() % 256, rand() % 256, rand() % 256);
//		putpixel(x, y, c);
//	}
//
//	closegraph();
//}
//#include <graphics.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <stdio.h>
//#include <time.h>
//
//void main()
//{
//	int x, y;
//	char num[4];
//
//	srand((unsigned)time(NULL));
//
//	initgraph(640, 480);
//
//	// 画格子
//	for (x = 0; x <= 480; x += 30)
//	for (y = 0; y <= 240; y += 30)
//	{
//		line(x, 0, x, 240);
//		line(0, y, 480, y);
//	}
//
//	// 定义二维数组
//	bool cell[16][8];
//	// 初始化二维数组
//	for (x = 0; x<16; x++)
//	for (y = 0; y<8; y++)
//		cell[x][y] = false;
//
//	// 在每个格子上写数字
//	for (int i = 1; i <= 128; i++)
//	{
//		// 找到一个没有写数字的随机格子
//		do
//		{
//			x = rand() % 16;
//			y = rand() % 8;
//		} while (cell[x][y] == true);
//
//		// 标记该格子已用
//		cell[x][y] = true;
//
//		// 在格子上写数字
//		sprintf(num, "%d", i);
//		outtextxy(x * 30, y * 30, num);
//	}
//
//	getchar();
//	closegraph();
//}
//#include <graphics.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <time.h>
//
//void main()
//{
//	srand((unsigned)time(NULL));
//
//	initgraph(640, 480);
//
//	// 定义点的坐标数组
//	int x[100];            // 点的 x 坐标
//	int y[100];            // 点的 y 坐标
//	int i;
//
//	// 初始化点的初始坐标
//	for (i = 0; i<100; i++)
//	{
//		x[i] = rand() % 640;
//		y[i] = rand() % 480;
//	}
//
//	while (!_kbhit())
//	{
//		for (i = 0; i<100; i++)
//		{
//			// 擦掉前一个点
//			putpixel(x[i], y[i], BLACK);
//			// 计算新坐标
//			y[i] += 3;
//			if (y[i] >= 480) y[i] = 0;
//			// 绘制新点
//			putpixel(x[i], y[i], WHITE);
//		}
//
//		Sleep(10);
//	}
//
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	initgraph(640, 480);
//
//	// 定义 IMAGE 对象
//	IMAGE img;
//
//	// 绘制内容
//	circle(100, 100, 20);
//	line(70, 100, 130, 100);
//	line(100, 70, 100, 130);
//
//	// 保存区域至 img 对象
//	getimage(&img, 70, 70, 60, 60);
//
//	// 将 img 对对象显示在屏幕的某个位置
//	putimage(200, 200, &img);
//
//	getchar();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	initgraph(640, 480);
//
//	IMAGE img;	// 定义 IMAGE 对象
//	loadimage(&img, "G:/VS2008/c.bmp");	// 读取图片到 img 对象中
//	putimage(200, 200, &img);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
//
//	getchar();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	initgraph(640, 480);
//
//	// 获取窗口句柄
//	HWND hwnd = GetHWnd();
//	// 设置窗口标题文字
//	SetWindowText(hwnd, "Hello World!");
//
//	getchar();
//	closegraph();
//}

//#include <graphics.h>
//#include <conio.h>
//
//#define PI 3.14159265
//
//// 主函数
//void main()
//{
//	// 创建大小为 800 * 600 的绘图窗口
//	initgraph(800, 600);
//
//	// 设置原点 (0, 0) 为屏幕中央（Y轴默认向下为正）
//	setorigin(400, 300);
//
//	// 使用白色填充背景
//	setbkcolor(WHITE);
//	cleardevice();
//
//
//	// 画脸
//	setfillcolor(RGB(7, 190, 234));						// 头
//	setlinecolor(BLACK);
//	fillroundrect(-135, -206, 135, 54, 248, 248);
//
//	setfillcolor(WHITE);								// 脸
//	fillellipse(-115, -144, 115, 46);
//
//	fillroundrect(-63, -169, 0, -95, 56, 56);			// 右眼
//	fillroundrect(0, -169, 63, -95, 56, 56);			// 左眼
//
//	setfillcolor(BLACK);
//	solidcircle(-16, -116, 6);							// 右眼球
//	solidcircle(16, -116, 6);							// 左眼球
//
//	setfillcolor(RGB(201, 62, 0));						// 鼻子
//	fillcircle(0, -92, 15);
//
//	line(0, -77, 0, -4);								// 人中
//	arc(-108, -220, 108, -4, PI * 5 / 4, PI * 7 / 4);	// 嘴
//
//	line(-42, -73, -90, -91);							// 胡子
//	line(42, -73, 90, -91);
//	line(-41, -65, -92, -65);
//	line(41, -65, 92, -65);
//	line(-42, -57, -90, -39);
//	line(42, -57, 90, -39);
//
//
//	// 画身体
//	line(-81, 32, -138, 72);					// 手臂(上)
//	line(81, 32, 138, 72);
//	line(-96, 96, -116, 110);					// 手臂(下)
//	line(96, 96, 116, 110);
//
//	line(-96, 85, -96, 178);					// 腿外侧
//	line(96, 85, 96, 178);
//	arc(-10, 168, 10, 188, 0, PI);				// 腿内侧
//
//	setfillcolor(WHITE);						// 手
//	fillcircle(-140, 99, 27);
//	fillcircle(140, 99, 27);
//	fillroundrect(-2, 178, -112, 205, 24, 24);	// 脚
//	fillroundrect(2, 178, 112, 205, 24, 24);
//
//	setfillcolor(RGB(7, 190, 234));				// 身体填充蓝色
//	floodfill(0, 100, BLACK);
//
//	setfillcolor(WHITE);						// 肚皮
//	fillcircle(0, 81, 75);
//	solidrectangle(-60, 4, 60, 24);				// 用白色矩形擦掉多余的肚皮
//
//	pie(-58, 23, 58, 139, PI, 0);				// 口袋
//
//
//	// 画铃铛
//	setfillcolor(RGB(169, 38, 0));				// 绳子
//	fillroundrect(-100, 23, 100, 42, 12, 12);
//
//	setfillcolor(RGB(245, 237, 38));			// 铃铛外形
//	fillcircle(0, 49, 19);
//
//	setfillcolor(BLACK);						// 铃铛上的洞
//	solidellipse(-4, 50, 4, 57);
//	setlinestyle(PS_SOLID, 3);
//	line(0, 57, 0, 68);
//
//	setlinestyle(PS_SOLID, 1);					// 铃铛上的纹路
//	line(-16, 40, 16, 40);
//	line(-18, 44, 18, 44);
//
//
//	// 按任意键退出
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//
//// 定义回调
//void(*callback)(int x, int y);
//
//
//// 画方块上的小方块
//void DrawSmallBox(int x, int y, bool lt, bool rt, bool lb, bool rb)
//{
//	int nx = x * 26 - 13;
//	int ny = y * 26 - 13;
//	if (lt) solidrectangle(nx + 1, ny + 1, nx + 1 + 6, ny + 1 + 6);
//	if (rt) solidrectangle(nx + 24, ny + 1, nx + 24 - 6, ny + 1 + 6);
//	if (lb) solidrectangle(nx + 1, ny + 24, nx + 1 + 6, ny + 24 - 6);
//	if (rb) solidrectangle(nx + 24, ny + 24, nx + 24 - 6, ny + 24 - 6);
//}
//
//
//// 圆中的每个点(回调函数)
//void CirclePoints(int x, int y)
//{
//	if (x == 0 && y < 0)
//		DrawSmallBox(x, y, false, false, true, true);
//	else if (x == 0 && y > 0)
//		DrawSmallBox(x, y, true, true, false, false);
//	else if (x < 0 && y == 0)
//		DrawSmallBox(x, y, false, true, false, true);
//	else if (x > 0 && y == 0)
//		DrawSmallBox(x, y, true, false, true, false);
//	else if (x == 0 && y == 0)
//		;
//	else if ((x < 0 && y < 0) || (x > 0 && y > 0))
//		DrawSmallBox(x, y, false, true, true, false);
//	else
//		DrawSmallBox(x, y, true, false, false, true);
//}
//
//
//// 基于 Bresenham 算法画填充圆
//void FillCircle_Bresenham(int x, int y, int r)
//{
//	int tx = 0, ty = r, d = 3 - 2 * r, i;
//
//	while (tx < ty)
//	{
//		// 画水平两点连线(<45度)
//		for (i = x - ty; i <= x + ty; i++)
//		{
//			CirclePoints(i, y - tx);
//			if (tx != 0)	// 防止水平线重复绘制
//				CirclePoints(i, y + tx);
//		}
//
//		if (d < 0)			// 取上面的点
//			d += 4 * tx + 6;
//		else				// 取下面的点
//		{
//			// 画水平两点连线(>45度)
//			for (i = x - tx; i <= x + tx; i++)
//			{
//				CirclePoints(i, y - ty);
//				CirclePoints(i, y + ty);
//			}
//
//			d += 4 * (tx - ty) + 10, ty--;
//		}
//
//		tx++;
//	}
//
//	if (tx == ty)			// 画水平两点连线(=45度)
//	for (i = x - ty; i <= x + ty; i++)
//	{
//		CirclePoints(i, y - tx);
//		CirclePoints(i, y + tx);
//	}
//}
//
//
//// 主函数
//void main()
//{
//	// 创建绘图窗口
//	initgraph(640, 480);
//	setbkcolor(LIGHTGRAY);
//	cleardevice();
//	setorigin(320, 240);
//
//	// 画 15 x 15 的间隔黑白块，每块 26 x 26，共 390 x 390
//	setlinecolor(BLACK);
//	setfillcolor(WHITE);
//	fillrectangle(-210, -210, 209, 209);
//	COLORREF fc = WHITE;
//	for (int x = -195; x < 195; x += 26)
//	for (int y = -195; y < 195; y += 26)
//	{
//		fc = (~fc) & 0xffffff;
//		setfillcolor(fc);
//		solidrectangle(x, y, x + 25, y + 25);
//	}
//
//	// 在填充圆内的方块内画小方块
//	setrop2(R2_XORPEN);
//	setfillcolor(WHITE);
//	FillCircle_Bresenham(0, 0, 6);
//
//	// 按任意键退出
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//void main()
//{
//	srand((unsigned)time(NULL));						// 设置随机种子
//	POINT P[3] = { { 320, 50 }, { 120, 400 }, { 520, 400 } };	// 设定三角形的三个顶点
//	POINT p = { rand() % 640, rand() % 480 };				// 随机产生当前点
//
//	// 初始化图形模式
//	initgraph(640, 480);
//
//	// 绘制三万个点
//	int n;
//	for (int i = 0; i <= 30000; i++)
//	{
//		n = rand() % 3;
//		p.x = (p.x + P[n].x) / 2;
//		p.y = (p.y + P[n].y) / 2;
//		putpixel(p.x, p.y, GREEN);
//	}
//
//	// 按任意键退出
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//// 定义常量
//#define ITERATIONS 1000		// 迭代次数，越高，图像越精细
//#define MAXCOLOR 64			// 颜色数
//
//
///////////////////////////////////////////////////
//// 定义复数及乘、加运算
///////////////////////////////////////////////////
//
//// 定义复数
//struct COMPLEX
//{
//	double re;
//	double im;
//};
//
//// 定义复数“乘”运算
//COMPLEX operator * (COMPLEX a, COMPLEX b)
//{
//	COMPLEX c;
//	c.re = a.re * b.re - a.im * b.im;
//	c.im = a.im * b.re + a.re * b.im;
//	return c;
//}
//
//// 定义复数“加”运算
//COMPLEX operator + (COMPLEX a, COMPLEX b)
//{
//	COMPLEX c;
//	c.re = a.re + b.re;
//	c.im = a.im + b.im;
//	return c;
//}
//
//
///////////////////////////////////////////////////
//// 定义颜色及初始化颜色
///////////////////////////////////////////////////
//
//// 定义颜色
//int Color[MAXCOLOR];
//
//// 初始化颜色
//void InitColor()
//{
//	// 使用 HSL 颜色模式产生角度 h1 到 h2 的渐变色
//	int h1 = 240, h2 = 30;
//	for (int i = 0; i<MAXCOLOR / 2; i++)
//	{
//		Color[i] = HSLtoRGB((float)h1, 1.0f, i * 2.0f / MAXCOLOR);
//		Color[MAXCOLOR - 1 - i] = HSLtoRGB((float)h2, 1.0f, i * 2.0f / MAXCOLOR);
//	}
//}
//
//
///////////////////////////////////////////////////
//// 绘制 Mandelbrot Set (曼德布洛特集)
///////////////////////////////////////////////////
//void Draw(double fromx, double fromy, double tox, double toy)
//{
//	COMPLEX z, c;
//	int x, y, k;	// 定义循环变量
//	for (x = 0; x < 640; x++)
//	{
//		c.re = fromx + (tox - fromx) * (x / 640.0);
//		for (y = 0; y < 480; y++)
//		{
//			c.im = fromy + (toy - fromy) * (y / 480.0);
//			z.re = z.im = 0;
//			for (k = 0; k < ITERATIONS; k++)
//			{
//				if (z.re * z.re + z.im * z.im > 4.0)	break;
//				z = z * z + c;
//			}
//			putpixel(x, y, (k >= ITERATIONS) ? 0 : Color[k % MAXCOLOR]);
//		}
//	}
//}
//
//
///////////////////////////////////////////////////
//// 主函数
///////////////////////////////////////////////////
//void main()
//{
//	// 初始化绘图窗口及颜色
//	initgraph(640, 480);
//	InitColor();
//
//
//	// 初始化 Mandelbrot Set(曼德布洛特集)坐标系
//	double fromx, fromy, tox, toy;
//	fromx = -2.1; tox = 1.1;
//	fromy = -1.2; toy = 1.2;
//	Draw(fromx, fromy, tox, toy);
//
//
//	// 捕获鼠标操作，实现放大鼠标选中区域
//	MOUSEMSG m;
//	bool isLDown = false;
//	int selfx, selfy, seltx, selty;	// 定义选区
//
//	while (!_kbhit())
//	{
//		m = GetMouseMsg();			// 获取一条鼠标消息
//
//		switch (m.uMsg)
//		{
//			// 按鼠标中键恢复原图形坐标系
//		case WM_MBUTTONUP:
//			fromx = -2.1; tox = 1.1;
//			fromy = -1.2; toy = 1.2;
//			Draw(fromx, fromy, tox, toy);
//			break;
//
//			// 按鼠标左键并拖动，选择区域
//		case WM_MOUSEMOVE:
//			if (isLDown)
//			{
//				rectangle(selfx, selfy, seltx, selty);
//				seltx = m.x;
//				selty = m.y;
//				rectangle(selfx, selfy, seltx, selty);
//			}
//			break;
//
//			// 按鼠标左键并拖动，选择区域
//		case WM_LBUTTONDOWN:
//			setcolor(WHITE);
//			setwritemode(R2_XORPEN);
//			isLDown = true;
//			selfx = seltx = m.x;
//			selfy = selty = m.y;
//			rectangle(selfx, selfy, seltx, selty);
//
//			break;
//
//			// 按鼠标左键并拖动，选择区域
//		case WM_LBUTTONUP:
//			rectangle(selfx, selfy, seltx, selty);
//			setwritemode(R2_COPYPEN);
//			isLDown = false;
//			seltx = m.x;
//			selty = m.y;
//
//			if (selfx == seltx || selfy == selty)	break;
//
//			// 修正选区为 4:3
//			int tmp;
//			if (selfx > seltx)	{ tmp = selfx; selfx = seltx; seltx = tmp; }
//			if (selfy > selty)	{ tmp = selfy; selfy = selty; selty = tmp; }
//
//			if ((seltx - selfx) * 0.75 < (selty - selfy))
//			{
//				selty += (3 - (selty - selfy) % 3);
//				selfx -= (selty - selfy) / 3 * 4 / 2 - (seltx - selfx) / 2;
//				seltx = selfx + (selty - selfy) / 3 * 4;
//			}
//			else
//			{
//				seltx += (4 - (seltx - selfx) % 4);
//				selfy -= (seltx - selfx) * 3 / 4 / 2 - (selty - selfy) / 2;
//				selty = selfy + (seltx - selfx) * 3 / 4;
//			}
//
//			// 更新坐标系
//			double f, t;
//			f = fromx + (tox - fromx) * selfx / 640;
//			t = fromx + (tox - fromx) * seltx / 640;
//			fromx = f;
//			tox = t;
//			f = fromy + (toy - fromy) * selfy / 480;
//			t = fromy + (toy - fromy) * selty / 480;
//			fromy = f;
//			toy = t;
//
//			// 画图形
//			Draw(fromx, fromy, tox, toy);
//
//			break;
//		}
//	}
//
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <math.h>
//#include <time.h>
//
//
//#define WIDTH		1024		// 屏幕宽
//#define HEIGHT		576			// 屏幕高
//#define NUM_MOVERS	600			// 小球数量
//#define	FRICTION	0.96f		// 摩擦力
//
//
//// 定义小球结构
//struct Mover
//{
//	COLORREF	color;			// 颜色
//	float		x, y;			// 坐标
//	float		vX, vY;			// 速度
//};
//
//
//// 定义全局变量
//Mover	movers[NUM_MOVERS];			// 小球数组
//int		mouseX, mouseY;			// 当前鼠标坐标
//int		mouseVX, mouseVY;		// 鼠标速度
//int		prevMouseX, prevMouseY;		// 上次鼠标坐标
//bool	isMouseDown;				// 鼠标左键是否按下
//DWORD*	pBuffer;					// 显存指针
//
//
//// 初始化
//void init()
//{
//	// 初始化小球数组
//	for (int i = 0; i < NUM_MOVERS; i++)
//	{
//		movers[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
//		movers[i].x = WIDTH * 0.5;
//		movers[i].y = HEIGHT * 0.5;
//		movers[i].vX = float(cos(float(i))) * (rand() % 34);
//		movers[i].vY = float(sin(float(i))) * (rand() % 34);
//	}
//
//	// 初始化鼠标变量
//	mouseX = prevMouseX = WIDTH / 2;
//	mouseY = prevMouseY = HEIGHT / 2;
//
//	// 设置随机种子
//	srand((unsigned int)time(NULL));
//
//	// 获取显存指针
//	pBuffer = GetImageBuffer(NULL);
//}
//
//
//// 全屏变暗 50%
//void darken()
//{
//	for (int i = WIDTH * HEIGHT - 1; i >= 0; i--)
//	if (pBuffer[i] != 0)
//		pBuffer[i] = RGB(GetRValue(pBuffer[i]) >> 1, GetGValue(pBuffer[i]) >> 1, GetBValue(pBuffer[i]) >> 1);
//}
//
//
//// 绝对延时
//void delay(DWORD ms)
//{
//	static DWORD oldtime = GetTickCount();
//
//	while (GetTickCount() - oldtime < ms)
//		Sleep(1);
//
//	oldtime = GetTickCount();
//}
//
//
//// 绘制动画(一帧)
//void run()
//{
//	darken();	// 全屏变暗
//
//	mouseVX = mouseX - prevMouseX;
//	mouseVY = mouseY - prevMouseY;
//	prevMouseX = mouseX;
//	prevMouseY = mouseY;
//
//	float toDist = WIDTH * 0.86f;
//	float stirDist = WIDTH * 0.125f;
//	float blowDist = WIDTH * 0.5f;
//
//	for (int i = 0; i < NUM_MOVERS; i++)
//	{
//		float x = movers[i].x;
//		float y = movers[i].y;
//		float vX = movers[i].vX;
//		float vY = movers[i].vY;
//
//		float dX = x - mouseX;
//		float dY = y - mouseY;
//		float d = (float)sqrt(dX * dX + dY * dY);
//		dX = d ? dX / d : 0;
//		dY = d ? dY / d : 0;
//
//		if (isMouseDown && d < blowDist)
//		{
//			float blowAcc = (1 - (d / blowDist)) * 14;
//			vX += dX * blowAcc + 0.5f - float(rand()) / RAND_MAX;
//			vY += dY * blowAcc + 0.5f - float(rand()) / RAND_MAX;
//		}
//
//		if (d < toDist)
//		{
//			float toAcc = (1 - (d / toDist)) * WIDTH * 0.0014f;
//			vX -= dX * toAcc;
//			vY -= dY * toAcc;
//		}
//
//		if (d < stirDist)
//		{
//			float mAcc = (1 - (d / stirDist)) * WIDTH * 0.00026f;
//			vX += mouseVX * mAcc;
//			vY += mouseVY * mAcc;
//		}
//
//		vX *= FRICTION;
//		vY *= FRICTION;
//
//		float avgVX = (float)fabs(vX);
//		float avgVY = (float)fabs(vY);
//		float avgV = (avgVX + avgVY) * 0.5f;
//
//		if (avgVX < 0.1) vX *= float(rand()) / RAND_MAX * 3;
//		if (avgVY < 0.1) vY *= float(rand()) / RAND_MAX * 3;
//
//		float sc = avgV * 0.45f;
//		sc = max(min(sc, 3.5f), 0.4f);
//
//		float nextX = x + vX;
//		float nextY = y + vY;
//
//		if (nextX > WIDTH)	{ nextX = WIDTH;	vX *= -1; }
//		else if (nextX < 0)		{ nextX = 0;		vX *= -1; }
//		if (nextY > HEIGHT){ nextY = HEIGHT;	vY *= -1; }
//		else if (nextY < 0)		{ nextY = 0;		vY *= -1; }
//
//		movers[i].vX = vX;
//		movers[i].vY = vY;
//		movers[i].x = nextX;
//		movers[i].y = nextY;
//
//		// 画小球
//		setcolor(movers[i].color);
//		setfillstyle(movers[i].color);
//		fillcircle(int(nextX + 0.5), int(nextY + 0.5), int(sc + 0.5));
//	}
//}
//
//
//// 主函数
//void main()
//{
//	// 创建绘图窗口
//	initgraph(WIDTH, HEIGHT);
//	// 启用批绘图模式
//	BeginBatchDraw();
//
//	// 初始化
//	init();
//
//	// 鼠标消息变量
//	MOUSEMSG m;
//
//	while (true)
//	{
//		// 处理鼠标消息
//		while (MouseHit())
//		{
//			m = GetMouseMsg();
//
//			switch (m.uMsg)
//			{
//			case WM_MOUSEMOVE:		mouseX = m.x;	mouseY = m.y;	break;
//			case WM_LBUTTONDOWN:	isMouseDown = true;				break;
//			case WM_LBUTTONUP:		isMouseDown = false;			break;
//			}
//		}
//
//		// 绘制动画
//		run();
//
//		// 显示缓存的绘制内容
//		FlushBatchDraw();
//
//		// 延时 20 毫秒
//		delay(20);
//	}
//
//	// 关闭
//	EndBatchDraw();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//// 宏常量
//#define	WIDTH		640
//#define HEIGHT		480
//#define FIREWIDTH	320
//#define	FIREHEIGHT	180
//
//// 全局变量
//COLORREF	g_Colors[193];						// 火焰色系中使用的全部颜色
//BYTE		g_Fire[FIREWIDTH];					// 火焰数据
//BYTE		g_Bits[FIREHEIGHT * FIREWIDTH];		// 火焰数据
//
//// 火焰属性
//int m_nDecay = 5;			// 衰减度，范围 [1, 100]，默认 5
//int m_nFlammability = 385;	// 易燃性，范围 [1, 399]，默认 385
//int m_nMaxHeat = 192;		// 最高热度，范围 [0, 192]，默认 192
//int m_nSpreadRate = 20;		// 传播速率，范围 [1, 100]，默认 20
//int m_nSize = 160;			// 火源宽度，范围 [40, FIREWIDTH]，默认 160
//int m_nSmoothness = 1;		// 平滑度，范围 [0, 5]，默认 1
//int m_nDistribution = 1;	// 分布，范围 [0, 10]，默认 1
//int m_nChaos = 50;			// 混沌，范围 [1, 100]，默认 50
//
//
//
//// 初始化火焰
//void InitFire()
//{
//	// 初始化颜色
//	int r, g, b;
//
//	// 默认红色火焰。根据注释选择不同的火焰效果
//	b = 256 + 256 + 255;	g = 256 + 255;	r = 255;	// 红色火焰
//	 r = 256+256+255;	g = 256+255;	b = 255;	// 蓝色火焰
//	 g = 256+256+255;	b = 256+255;	r = 255;	// 绿色火焰
//
//	// 生成火焰色系
//	for (int i = 192; i >= 0; i--)
//	{
//		g_Colors[i] = RGB((r > 255) ? 255 : r, (g > 255) ? 255 : g, (b > 255) ? 255 : b);
//		r = (r > 3) ? (r - 4) : 0;
//		g = (g > 3) ? (g - 4) : 0;
//		b = (b > 3) ? (b - 4) : 0;
//	}
//
//	// 置空火焰数组
//	memset(g_Fire, 0, FIREWIDTH);
//	memset(g_Bits, 0, FIREWIDTH * FIREHEIGHT);
//}
//
//
//
//// 画色系
//void DrawColorScheme()
//{
//	POINT s[8] = { { 0, 450 }, { 580, 450 }, { 580, 420 }, { 610, 420 },
//	{ 610, 0 }, { 639, 0 }, { 639, 479 }, { 0, 479 } };
//
//	HRGN rgn1 = CreatePolygonRgn(s, 8, WINDING);
//	HRGN rgn2 = CreateEllipticRgn(550, 390, 611, 451);
//	CombineRgn(rgn1, rgn1, rgn2, RGN_DIFF);
//
//	// 定义裁剪区域
//	setcliprgn(rgn1);			// 设置区域 rgn 为裁剪区
//	DeleteObject(rgn1);
//	DeleteObject(rgn2);
//
//	// 画色系
//	int c, x, y;
//	for (int i = 0; i < 1120; i++)
//	{
//		c = int(i / 5.8);
//		x = (i <= 479 ? 639 : 639 - i + 479);
//		y = (i <= 479 ? i : 479);
//		setcolor(BGR(g_Colors[c]));
//		line(0, 0, x, y);
//	}
//
//	// 取消裁剪区域
//	setcliprgn(NULL);
//}
//
//
//
//// 计算火焰的每个点
//inline void BurnPoint(BYTE* pRow, BYTE* pNextRow)
//{
//	BYTE* pTarget;
//
//	int off = rand() % (m_nDistribution + 1);
//
//	int val = m_nDecay + 1;
//	val = rand() % val;
//	val = *pNextRow - val;
//
//	pTarget = (rand() & 1) ? pRow + off : pRow - off;
//	*pTarget = (val > 0) ? (BYTE)val : 0;
//}
//
//
//
//// 计算火焰
//void RenderFlame()
//{
//	int xStart, xEnd, x, y;
//	BYTE* pRow;
//	BYTE* pNextRow;
//
//	xStart = (FIREWIDTH - m_nSize) / 2;
//	xEnd = xStart + m_nSize + 1;
//
//	pRow = g_Bits;
//	for (x = 0; x < FIREWIDTH; x++)
//	{
//		if (x < (xStart + m_nDistribution) || x >= (xEnd - m_nDistribution))
//			g_Fire[x] = 0;
//		*pRow++ = g_Fire[x];
//	}
//
//	for (y = FIREHEIGHT - 1; y > 0; y--)	// y = 0 火焰最大；y++ 火焰变小
//	{
//		pRow = (g_Bits + FIREWIDTH * y);
//		pNextRow = (g_Bits + FIREWIDTH * (y - 1));
//
//		if (rand() & 1)
//		{
//			for (x = 0; x < FIREWIDTH; x++)
//			{
//				BurnPoint(pRow, pNextRow);
//				pRow++;
//				pNextRow++;
//			}
//		}
//		else
//		{
//			pRow += FIREWIDTH - 1;
//			pNextRow += FIREWIDTH - 1;
//			for (x = 0; x < FIREWIDTH; x++)
//			{
//				BurnPoint(pRow, pNextRow);
//				pRow--;
//				pNextRow--;
//			}
//		}
//	}
//
//	if (rand() % (400 - m_nFlammability) == 0)
//	{
//		int off = m_nSize - 5;
//		off = rand() % off;
//		off += xStart;
//
//		for (x = off; x < off + 5; x++)
//			g_Fire[x] = 239;
//	}
//
//	for (x = xStart; x < xEnd; x++)
//	{
//		if (g_Fire[x] < m_nMaxHeat)
//		{
//			int val = rand() % m_nChaos + 1;
//			val -= m_nChaos / 2;
//			val += m_nSpreadRate;
//			val += g_Fire[x];
//
//			if (val > m_nMaxHeat)
//				g_Fire[x] = m_nMaxHeat;
//			else if (val < 0)
//				g_Fire[x] = 0;
//			else
//				g_Fire[x] = val;
//		}
//		else
//			g_Fire[x] = m_nMaxHeat;
//	}
//
//	if (m_nSmoothness > 0)
//	{
//		xStart += m_nSmoothness;
//		xEnd -= m_nSmoothness;
//		for (x = xStart; x < xEnd; x++)
//		{
//			int val = 0;
//			for (y = x - m_nSmoothness; y < x + 1 + m_nSmoothness; y++)
//				val += g_Fire[y];
//
//			g_Fire[x] = val / (2 * m_nSmoothness + 1);
//		}
//	}
//}
//
//
//
//// 显示火焰
//void PaintFlame(int offset_x, int offset_y)
//{
//	DWORD* pDst = GetImageBuffer();	// 获取显存指针
//
//	for (int y = 0; y < FIREHEIGHT; y++)
//	for (int x = 0; x < FIREWIDTH; x++)
//	{
//		COLORREF c = g_Colors[g_Bits[y * FIREWIDTH + x]];
//		pDst[(offset_y - y) * WIDTH + offset_x + x] = c;
//	}
//
//	FlushBatchDraw();				// 使显存操作生效
//}
//
//
//
//// 主函数
//void main()
//{
//	initgraph(WIDTH, HEIGHT);		// 创建绘图窗口
//	srand((unsigned)time(NULL));	// 设置随机种子
//
//	InitFire();						// 初始化火焰
//	DrawColorScheme();				// 绘制色系图
//
//	while (!_kbhit())					// 按任意键退出
//	{
//		RenderFlame();				// 渲染火焰
//		PaintFlame(145, 320);		// 显示火焰
//		Sleep(33);					// 延时
//	}
//
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <math.h>
//
//#define	WIDTH	640
//#define	HEIGHT	480
//#define	PI		3.1415926535
//
//HPALETTE	g_hPal, g_hOldPal;	// 调色板句柄
//LOGPALETTE*	g_pLOGPAL;			// 调色板信息结构体
//HDC			g_hDC;				// EasyX 窗口的 DC 句柄
//
//
//// 初始化
//void Init()
//{
//	initgraph(WIDTH, HEIGHT);	// 创建绘图窗口
//	g_hDC = GetImageHDC();		// 获取绘图窗口的句柄
//
//	// 设定动画色系
//	int r = 216;
//	int g = 0;
//	int b = 0;
//
//	///////////////////
//	// 初始化调色板
//
//	// 为调色板结构体分配内存(该调色板含有 32 种颜色)
//	// 比实际多四个字节是增加了 palVersion 和 palNumEntries 两个成员，
//	// 详见 MSDN 中 LOGPALETTE 的定义
//	g_pLOGPAL = (LOGPALETTE*)new PALETTEENTRY[33];
//	g_pLOGPAL->palVersion = 0x300;
//	g_pLOGPAL->palNumEntries = 32;
//
//	for (int i = 0; i < 32; i++)
//	{
//		g_pLOGPAL->palPalEntry[i].peRed = BYTE(r * sin(PI * i / 32));
//		g_pLOGPAL->palPalEntry[i].peGreen = BYTE(g * sin(PI * i / 32));
//		g_pLOGPAL->palPalEntry[i].peBlue = BYTE(b * sin(PI * i / 32));
//		g_pLOGPAL->palPalEntry[i].peFlags = PC_RESERVED;
//	}
//
//	g_hPal = CreatePalette(g_pLOGPAL);					// 创建调色板
//	g_hOldPal = SelectPalette(g_hDC, g_hPal, false);	// 选入调色板
//}
//
//
//// 改变调色板
//void ChangePal()
//{
//	// 使调色板的颜色循环更换
//	PALETTEENTRY t = g_pLOGPAL->palPalEntry[0];
//	for (int i = 0; i < 31; i++)
//		g_pLOGPAL->palPalEntry[i] = g_pLOGPAL->palPalEntry[i + 1];
//	g_pLOGPAL->palPalEntry[31] = t;
//
//	// 使调色板的修改生效
//	AnimatePalette(g_hPal, 0, 32, g_pLOGPAL->palPalEntry);
//	RealizePalette(g_hDC);
//}
//
//
//// 画图案
//void Draw()
//{
//	HBRUSH hBrush;
//	int x1, y1;
//	COLORREF c;
//
//	for (int y = 0; y < 64; y++)
//	for (int x = 0; x < 64; x++)
//	{
//		RECT rt = { x * WIDTH / 64 + 1,
//			y * HEIGHT / 64 + 1,
//			(x + 1) * WIDTH / 64,
//			(y + 1) * HEIGHT / 64 };
//
//		x1 = x > 31 ? 63 - x : x;
//		y1 = y > 31 ? 63 - y : y;
//		c = PALETTEINDEX(min(x1, y1));
//
//		hBrush = CreateSolidBrush(c);
//		FillRect(g_hDC, &rt, hBrush);
//		DeleteObject(hBrush);
//	}
//}
//
//
//// 退出
//void Quit()
//{
//	SelectPalette(g_hDC, g_hOldPal, false);
//	DeleteObject(g_hPal);
//
//	delete[] g_pLOGPAL;
//
//	closegraph();
//}
//
//
//// 主函数
//void main()
//{
//	Init();					// 初始化
//
//	while (!_kbhit())		// 按任意键退出
//	{
//		ChangePal();		// 改变调色板
//		Draw();				// 画图案(每次画的都一样，动态图像是因为调色板的改变)
//		FlushBatchDraw();	// 使 GDI 绘图函数生效
//		Sleep(33);			// 延时
//	}
//
//	Quit();					// 退出
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//#define	WIDTH	1280
//#define	HEIGHT	720
//#define	MAXSTEP	9
//
//
//
//// 节点（多个连续的节点环，组成一个顶点）
//struct POINTNODE
//{
//	POINT		pos;	// 位置
//	POINTNODE*	next;	// 指向下一个节点的指针
//};
//
//
//
//// 顶点（四个顶点，组成一个多边形）
//class VERTEX
//{
//public:
//	POINTNODE*	m_head;		// 头结点的指针
//	POINT		m_step;		// 移动步长
//
//	// 构造函数
//	VERTEX()
//	{
//		m_head = NULL;
//	}
//
//	// 析构函数
//	~VERTEX()
//	{
//		if (m_head != NULL)
//			delete[] m_head;
//	}
//
//	// 初始化环链
//	void Init(int count)
//	{
//		// 初始化前进方向
//		m_step.x = ((rand() % 2) * 2 - 1) * (rand() % MAXSTEP + 1);
//		m_step.y = ((rand() % 2) * 2 - 1) * (rand() % MAXSTEP + 1);
//
//		// 初始化节点环
//		m_head = new POINTNODE[count];
//		m_head[0].pos.x = rand() % WIDTH;
//		m_head[0].pos.y = rand() % HEIGHT;
//		m_head[0].next = &m_head[count - 1];
//		for (int i = 1; i <= count; i++)
//		{
//			m_head[i].pos.x = m_head[i - 1].pos.x - m_step.x;
//			m_head[i].pos.y = m_head[i - 1].pos.y - m_step.y;
//			m_head[i].next = &m_head[i - 1];
//		}
//	}
//
//	// 获取头部节点坐标
//	POINT GetHead()
//	{
//		return m_head->pos;
//	}
//
//	// 获取尾部节点坐标
//	POINT GetTail()
//	{
//		return m_head->next->pos;
//	}
//
//	// 移动顶点
//	void Move()
//	{
//		m_head->next->pos.x = m_head->pos.x + m_step.x;
//		m_head->next->pos.y = m_head->pos.y + m_step.y;
//		m_head = m_head->next;
//
//		// 判断顶点是否越界
//		if (m_head->pos.x < 0)			{ m_head->pos.x = -m_head->pos.x;				m_step.x = rand() % MAXSTEP + 1; }
//		else if (m_head->pos.x >= WIDTH)	{ m_head->pos.x -= m_head->pos.x - WIDTH + 1;	m_step.x = -rand() % MAXSTEP - 1; }
//		if (m_head->pos.y < 0)			{ m_head->pos.y = -m_head->pos.y;				m_step.y = rand() % MAXSTEP + 1; }
//		else if (m_head->pos.y >= HEIGHT)	{ m_head->pos.y -= m_head->pos.y - HEIGHT + 1;	m_step.y = -rand() % MAXSTEP - 1; }
//	}
//};
//
//
//
//// 多边形
//class POLYGON
//{
//private:
//	COLORREF	m_color;		// 多边形的颜色
//	VERTEX		m_vertex[4];	// 构成多边形的四个顶点
//
//public:
//	// 构造函数
//	POLYGON(int lines)
//	{
//		// 初始化颜色
//		m_color = HSLtoRGB(float(rand() % 360), 1.0, 0.5);
//
//		// 初始化四个顶点
//		for (int i = 0; i<4; i++)
//			m_vertex[i].Init(lines);
//	}
//
//	// 移动多边形
//	void Move()
//	{
//		int i;
//
//		// 擦掉多边形的尾部
//		setcolor(BLACK);
//		moveto(m_vertex[3].GetTail().x, m_vertex[3].GetTail().y);
//		for (i = 0; i<4; i++)
//			lineto(m_vertex[i].GetTail().x, m_vertex[i].GetTail().y);
//
//		// 移动每个顶点
//		for (i = 0; i<4; i++)
//			m_vertex[i].Move();
//
//		// 画多边形的头部
//		setcolor(m_color);
//		moveto(m_vertex[3].GetHead().x, m_vertex[3].GetHead().y);
//		for (i = 0; i<4; i++)
//			lineto(m_vertex[i].GetHead().x, m_vertex[i].GetHead().y);
//
//		// 有 1% 的概率更换颜色
//		if (rand() % 100 == 0)
//			m_color = HSLtoRGB(float(rand() % 360), 1.0, 0.5);
//	}
//};
//
//
//
//// 主函数
//void main()
//{
//	// 初始化绘图窗口
//	initgraph(WIDTH, HEIGHT);
//
//	// 初始化随机种子
//	srand((unsigned)time(NULL));
//
//	// 定义两个多边形对象，分别有 7 层线和 12 层线
//	POLYGON s1(7), s2(12);
//
//	// 移动多边形，按任意键退出
//	while (!_kbhit())
//	{
//		s1.Move();
//		s2.Move();
//		Sleep(40);
//	}
//
//	// 关闭绘图窗口
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//// 欢迎界面
//void welcome()
//{
//	// 输出屏幕提示
//	cleardevice();
//	setcolor(YELLOW);
//	settextstyle(64, 0, "黑体");
//	outtextxy(160, 50, "打字母游戏");
//	setcolor(WHITE);
//	settextstyle(16, 0, "宋体");
//	outtextxy(100, 200, "就是很传统的那个掉字母然后按相应键就消失的游戏");
//	outtextxy(100, 240, "只是做了一个简单的实现");
//	outtextxy(100, 280, "功能并不很完善，比如生命数、分数等都没有写");
//	outtextxy(100, 320, "感兴趣的自己加进去吧");
//
//	// 实现闪烁的“按任意键继续”
//	int c = 255;
//	while (!_kbhit())
//	{
//		setcolor(RGB(c, 0, 0));
//		outtextxy(280, 400, "按任意键继续");
//		c -= 8;
//		if (c < 0) c = 255;
//		Sleep(20);
//	}
//	_getch();
//	cleardevice();
//}
//
//// 退出界面
//void goodbye()
//{
//	cleardevice();
//	setcolor(YELLOW);
//	settextstyle(48, 0, "黑体");
//	outtextxy(104, 180, "多写程序  不老青春");
//	_getch();
//}
//
//// 主函数
//void main()
//{
//	initgraph(640, 480);		// 初始化屏幕为 640x480
//
//	welcome();					// 显示欢迎界面
//
//	srand(time(NULL));			// 设置随机种子
//	settextstyle(16, 0, "Arial");	// 设置字母的字体和大小
//	setfillstyle(BLACK);		// 设置清除字母的填充区域颜色
//
//	char target;				// 目标字母
//	char key;					// 用户的按键
//	int x, y;					// 字母的位置
//
//	// 主循环
//	while (true)
//	{
//		target = 65 + rand() % 26;		// 产生任意大写字母
//		x = rand() % 620;				// 产生任意下落位置
//		for (y = 0; y<460; y++)
//		{
//			setcolor(WHITE);			// 设置字母的颜色
//			outtextxy(x, y, target);	// 显示字母
//
//			if (_kbhit())
//			{
//				key = _getch();			// 获取用户按键
//
//				if ((key == target) || (key == target + 32))
//				{
//					// 按键正确，“击落”字母（画黑色方块擦除）
//					bar(x, y, x + 16, y + 16);
//					break;				// 跳出循环，进行下一个字母
//				}
//				else if (key == 27)
//				{
//					goto EXIT;			// 如果按 ESC，退出游戏主循环
//				}
//			}
//
//			// 延时，并清除字母
//			Sleep(10);
//			bar(x, y, x + 16, y + 16);
//		}
//	}
//
//EXIT:
//	// 退出部分
//	goodbye();
//
//	// 关闭图形界面
//	closegraph();
//}
//#include <graphics.h>
//#include <time.h>
//#include <math.h>
//#include <conio.h>
//
//#define MAXPOINT	2000
//#define	PI			3.1415926536
//
//// 定义三维点
//struct POINT3D
//{
//	double x;
//	double y;
//	double z;
//};
//
//POINT3D p3d[MAXPOINT];		// 所有的三维点
//double viewZ = 3;			// 视点 z 轴坐标
//
//// 初始化三维点
//void InitPoint()
//{
//	// 产生随机种子
//	srand(time(NULL));
//
//	// 产生球体表面的随机点（根据球体面积与其外切圆柱面积的关系）
//	double rxy, a;
//	for (int i = 0; i<MAXPOINT; i++)
//	{
//		p3d[i].z = 2.0 * rand() / RAND_MAX - 1;	// 求随机 z 坐标
//		rxy = sqrt(1 - p3d[i].z * p3d[i].z);	// 计算三维矢量在 xoy 平面的投影长度
//		a = 2 * PI * rand() / RAND_MAX;			// 产生随机角度
//		p3d[i].x = cos(a) * rxy;
//		p3d[i].y = sin(a) * rxy;
//	}
//}
//
//// 使三维点按 x 轴旋转指定角度
//void RotateX(POINT3D &p, double angle)
//{
//	double y = p.y;
//	p.y = p.y * cos(angle) + p.z * sin(-angle);
//	p.z = y * sin(angle) + p.z * cos(angle);
//}
//
//// 使三维点按 y 轴旋转指定角度
//void RotateY(POINT3D &p, double angle)
//{
//	double x = p.x;
//	p.x = p.x * cos(angle) + p.z * sin(-angle);
//	p.z = x * sin(angle) + p.z * cos(angle);
//}
//
//// 使三维点按 z 轴旋转指定角度
//void RotateZ(POINT3D &p, double angle)
//{
//	double x = p.x;
//	p.x = p.x * cos(angle) + p.y * sin(-angle);
//	p.y = x * sin(angle) + p.y * cos(angle);
//}
//
//// 将三维点投影到二维屏幕上（单点透视）
//POINT Projection(POINT3D p)
//{
//	POINT p2d;
//	p2d.x = (int)(p.x * (viewZ / (viewZ - p.z)) * 200 + 0.5) + 320;
//	p2d.y = (int)(p.y * (viewZ / (viewZ - p.z)) * 200 + 0.5) + 240;
//	return p2d;
//}
//
//void main()
//{
//	initgraph(640, 480);
//	InitPoint();
//	BeginBatchDraw();
//
//	int c;
//	POINT p2d;
//	while (!_kbhit())
//	{
//		cleardevice();		// 清除屏幕
//
//		for (int i = 0; i<MAXPOINT; i++)
//		{
//			// 使该点围绕三个坐标轴做旋转运动
//			RotateX(p3d[i], PI / 180);
//			RotateY(p3d[i], PI / 170);
//			RotateZ(p3d[i], PI / 160);
//
//			// 根据点的深度，产生相应灰度的颜色
//			c = (int)(p3d[i].z * 100) + 155;
//
//			// 投影该点到屏幕上
//			p2d = Projection(p3d[i]);
//
//			// 画点
//			putpixel(p2d.x, p2d.y, RGB(c, c, c));
//		}
//
//		FlushBatchDraw();
//		Sleep(10);			// 延时 10 毫秒
//	}
//
//	EndBatchDraw();
//	closegraph();
//}