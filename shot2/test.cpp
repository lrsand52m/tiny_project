#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>			// ��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include <conio.h>				// ����̨�������ͷ�ļ���system("pause")�����Ҫ
#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdio.h>
//void main()
//{
//	initgraph(640, 480);		// ��ʼ��640x480�Ļ�ͼ��Ļ
//	line(200, 240, 440, 240);	// ����(200,240) - (440,240)
//	line(320, 120, 320, 360);	// ����(320,120) - (320,360)
//	system("pause");
//	closegraph();				// �رջ�ͼ��Ļ
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
//		// ���ƻ��ߡ���ɫ����Բ
//		setlinecolor(YELLOW);
//		setfillcolor(GREEN);
//		fillcircle(x, 100, 20);
//
//		// ��ʱ
//		Sleep(500);
//
//		// ���ƺ��ߡ���ɫ����Բ
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
//	// ����ʼͼ��
//	setlinecolor(YELLOW);
//	setfillcolor(GREEN);
//	fillcircle(x, 240, 20);
//
//	char c = 0;
//	while (c != 27)
//	{
//		// ��ȡ����
//		c = getc(stdin);
//
//		// �Ȳ����ϴ���ʾ�ľ�ͼ��
//		setlinecolor(BLACK);
//		setfillcolor(BLACK);
//		fillcircle(x, 240, 20);
//
//		// �������룬�����µ�����
//		switch (c)
//		{
//		case 'a': x -= 2; break;
//		case 'd': x += 2; break;
//		case 27: break;
//		}
//
//		// �����µ�ͼ��
//		setlinecolor(YELLOW);
//		setfillcolor(GREEN);
//		fillcircle(x, 240, 20);
//
//		// ��ʱ
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
//	double a_hour, a_min, a_sec;					// ʱ���֡�����Ļ���ֵ
//	int x_hour, y_hour, x_min, y_min, x_sec, y_sec;	// ʱ���֡������ĩ��λ��
//
//	// ����ʱ���֡�����Ļ���ֵ
//	a_sec = second * 2 * PI / 60;
//	a_min = minute * 2 * PI / 60 + a_sec / 60;
//	a_hour = hour * 2 * PI / 12 + a_min / 12;
//
//	// ����ʱ���֡������ĩ��λ��
//	x_sec = 320 + (int)(120 * sin(a_sec));
//	y_sec = 240 - (int)(120 * cos(a_sec));
//	x_min = 320 + (int)(100 * sin(a_min));
//	y_min = 240 - (int)(100 * cos(a_min));
//	x_hour = 320 + (int)(70 * sin(a_hour));
//	y_hour = 240 - (int)(70 * cos(a_hour));
//
//	// ��ʱ��
//	setlinestyle(PS_SOLID, 10, NULL);
//	setlinecolor(WHITE);
//	line(320, 240, x_hour, y_hour);
//
//	// ������
//	setlinestyle(PS_SOLID, 6, NULL);
//	setlinecolor(LIGHTGRAY);
//	line(320, 240, x_min, y_min);
//
//	// ������
//	setlinestyle(PS_SOLID, 2, NULL);
//	setlinecolor(RED);
//	line(320, 240, x_sec, y_sec);
//}
//
//void main()
//{
//	initgraph(640, 480);		// ��ʼ�� 640 x 480 �Ļ�ͼ����
//
//	// ����һ���򵥵ı���
//	circle(320, 240, 2);
//	circle(320, 240, 60);
//	circle(320, 240, 160);
//	outtextxy(296, 310, _T("BestAns"));
//
//	// ���� XOR ��ͼģʽ
//	setwritemode(R2_XORPEN);	// ���� XOR ��ͼģʽ
//
//	// ���Ʊ���
//	SYSTEMTIME ti;				// ����������浱ǰʱ��
//	while (!_kbhit())				// ��������˳��ӱ����
//	{
//		GetLocalTime(&ti);		// ��ȡ��ǰʱ��
//		Draw(ti.wHour, ti.wMinute, ti.wSecond);	// ������
//		Sleep(1000);							// ��ʱ 1 ��
//		Draw(ti.wHour, ti.wMinute, ti.wSecond);	// �����루������ͻ�����Ĺ�����һ���ģ�
//	}
//
//	closegraph();				// �رջ�ͼ����
//}
//#include <graphics.h>
//#include <conio.h>
//
//void main()
//{
//	// ��ʼ��ͼ�δ���
//	initgraph(640, 480);
//	MOUSEMSG m;						// ���������Ϣ
//	while (true)
//	{
//		// ��ȡһ�������Ϣ
//		m = GetMouseMsg();
//
//		switch (m.uMsg)
//		{
//		case WM_MOUSEMOVE:		// ����ƶ���ʱ�򻭺�ɫ��С��
//			putpixel(m.x, m.y, RED);
//			break;
//
//		case WM_LBUTTONDOWN:	// ����������ͬʱ������ Ctrl ��
//			if (m.mkCtrl)		// ��һ���󷽿�
//				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
//			else				// ��һ��С����
//				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
//			break;
//
//		case WM_RBUTTONUP:
//			return;				// ������Ҽ��˳�����
//		}
//	}
//	 //�ر�ͼ�δ���
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
//	// ������
//	for (x = 0; x <= 480; x += 30)
//	for (y = 0; y <= 240; y += 30)
//	{
//		line(x, 0, x, 240);
//		line(0, y, 480, y);
//	}
//
//	// �����ά����
//	bool cell[16][8];
//	// ��ʼ����ά����
//	for (x = 0; x<16; x++)
//	for (y = 0; y<8; y++)
//		cell[x][y] = false;
//
//	// ��ÿ��������д����
//	for (int i = 1; i <= 128; i++)
//	{
//		// �ҵ�һ��û��д���ֵ��������
//		do
//		{
//			x = rand() % 16;
//			y = rand() % 8;
//		} while (cell[x][y] == true);
//
//		// ��Ǹø�������
//		cell[x][y] = true;
//
//		// �ڸ�����д����
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
//	// ��������������
//	int x[100];            // ��� x ����
//	int y[100];            // ��� y ����
//	int i;
//
//	// ��ʼ����ĳ�ʼ����
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
//			// ����ǰһ����
//			putpixel(x[i], y[i], BLACK);
//			// ����������
//			y[i] += 3;
//			if (y[i] >= 480) y[i] = 0;
//			// �����µ�
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
//	// ���� IMAGE ����
//	IMAGE img;
//
//	// ��������
//	circle(100, 100, 20);
//	line(70, 100, 130, 100);
//	line(100, 70, 100, 130);
//
//	// ���������� img ����
//	getimage(&img, 70, 70, 60, 60);
//
//	// �� img �Զ�����ʾ����Ļ��ĳ��λ��
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
//	IMAGE img;	// ���� IMAGE ����
//	loadimage(&img, "G:/VS2008/c.bmp");	// ��ȡͼƬ�� img ������
//	putimage(200, 200, &img);	// ������ (0, 0) λ����ʾ IMAGE ����
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
//	// ��ȡ���ھ��
//	HWND hwnd = GetHWnd();
//	// ���ô��ڱ�������
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
//// ������
//void main()
//{
//	// ������СΪ 800 * 600 �Ļ�ͼ����
//	initgraph(800, 600);
//
//	// ����ԭ�� (0, 0) Ϊ��Ļ���루Y��Ĭ������Ϊ����
//	setorigin(400, 300);
//
//	// ʹ�ð�ɫ��䱳��
//	setbkcolor(WHITE);
//	cleardevice();
//
//
//	// ����
//	setfillcolor(RGB(7, 190, 234));						// ͷ
//	setlinecolor(BLACK);
//	fillroundrect(-135, -206, 135, 54, 248, 248);
//
//	setfillcolor(WHITE);								// ��
//	fillellipse(-115, -144, 115, 46);
//
//	fillroundrect(-63, -169, 0, -95, 56, 56);			// ����
//	fillroundrect(0, -169, 63, -95, 56, 56);			// ����
//
//	setfillcolor(BLACK);
//	solidcircle(-16, -116, 6);							// ������
//	solidcircle(16, -116, 6);							// ������
//
//	setfillcolor(RGB(201, 62, 0));						// ����
//	fillcircle(0, -92, 15);
//
//	line(0, -77, 0, -4);								// ����
//	arc(-108, -220, 108, -4, PI * 5 / 4, PI * 7 / 4);	// ��
//
//	line(-42, -73, -90, -91);							// ����
//	line(42, -73, 90, -91);
//	line(-41, -65, -92, -65);
//	line(41, -65, 92, -65);
//	line(-42, -57, -90, -39);
//	line(42, -57, 90, -39);
//
//
//	// ������
//	line(-81, 32, -138, 72);					// �ֱ�(��)
//	line(81, 32, 138, 72);
//	line(-96, 96, -116, 110);					// �ֱ�(��)
//	line(96, 96, 116, 110);
//
//	line(-96, 85, -96, 178);					// �����
//	line(96, 85, 96, 178);
//	arc(-10, 168, 10, 188, 0, PI);				// ���ڲ�
//
//	setfillcolor(WHITE);						// ��
//	fillcircle(-140, 99, 27);
//	fillcircle(140, 99, 27);
//	fillroundrect(-2, 178, -112, 205, 24, 24);	// ��
//	fillroundrect(2, 178, 112, 205, 24, 24);
//
//	setfillcolor(RGB(7, 190, 234));				// ���������ɫ
//	floodfill(0, 100, BLACK);
//
//	setfillcolor(WHITE);						// ��Ƥ
//	fillcircle(0, 81, 75);
//	solidrectangle(-60, 4, 60, 24);				// �ð�ɫ���β�������Ķ�Ƥ
//
//	pie(-58, 23, 58, 139, PI, 0);				// �ڴ�
//
//
//	// ������
//	setfillcolor(RGB(169, 38, 0));				// ����
//	fillroundrect(-100, 23, 100, 42, 12, 12);
//
//	setfillcolor(RGB(245, 237, 38));			// ��������
//	fillcircle(0, 49, 19);
//
//	setfillcolor(BLACK);						// �����ϵĶ�
//	solidellipse(-4, 50, 4, 57);
//	setlinestyle(PS_SOLID, 3);
//	line(0, 57, 0, 68);
//
//	setlinestyle(PS_SOLID, 1);					// �����ϵ���·
//	line(-16, 40, 16, 40);
//	line(-18, 44, 18, 44);
//
//
//	// ��������˳�
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//
//// ����ص�
//void(*callback)(int x, int y);
//
//
//// �������ϵ�С����
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
//// Բ�е�ÿ����(�ص�����)
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
//// ���� Bresenham �㷨�����Բ
//void FillCircle_Bresenham(int x, int y, int r)
//{
//	int tx = 0, ty = r, d = 3 - 2 * r, i;
//
//	while (tx < ty)
//	{
//		// ��ˮƽ��������(<45��)
//		for (i = x - ty; i <= x + ty; i++)
//		{
//			CirclePoints(i, y - tx);
//			if (tx != 0)	// ��ֹˮƽ���ظ�����
//				CirclePoints(i, y + tx);
//		}
//
//		if (d < 0)			// ȡ����ĵ�
//			d += 4 * tx + 6;
//		else				// ȡ����ĵ�
//		{
//			// ��ˮƽ��������(>45��)
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
//	if (tx == ty)			// ��ˮƽ��������(=45��)
//	for (i = x - ty; i <= x + ty; i++)
//	{
//		CirclePoints(i, y - tx);
//		CirclePoints(i, y + tx);
//	}
//}
//
//
//// ������
//void main()
//{
//	// ������ͼ����
//	initgraph(640, 480);
//	setbkcolor(LIGHTGRAY);
//	cleardevice();
//	setorigin(320, 240);
//
//	// �� 15 x 15 �ļ���ڰ׿飬ÿ�� 26 x 26���� 390 x 390
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
//	// �����Բ�ڵķ����ڻ�С����
//	setrop2(R2_XORPEN);
//	setfillcolor(WHITE);
//	FillCircle_Bresenham(0, 0, 6);
//
//	// ��������˳�
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//void main()
//{
//	srand((unsigned)time(NULL));						// �����������
//	POINT P[3] = { { 320, 50 }, { 120, 400 }, { 520, 400 } };	// �趨�����ε���������
//	POINT p = { rand() % 640, rand() % 480 };				// ���������ǰ��
//
//	// ��ʼ��ͼ��ģʽ
//	initgraph(640, 480);
//
//	// �����������
//	int n;
//	for (int i = 0; i <= 30000; i++)
//	{
//		n = rand() % 3;
//		p.x = (p.x + P[n].x) / 2;
//		p.y = (p.y + P[n].y) / 2;
//		putpixel(p.x, p.y, GREEN);
//	}
//
//	// ��������˳�
//	_getch();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//
//// ���峣��
//#define ITERATIONS 1000		// ����������Խ�ߣ�ͼ��Խ��ϸ
//#define MAXCOLOR 64			// ��ɫ��
//
//
///////////////////////////////////////////////////
//// ���帴�����ˡ�������
///////////////////////////////////////////////////
//
//// ���帴��
//struct COMPLEX
//{
//	double re;
//	double im;
//};
//
//// ���帴�����ˡ�����
//COMPLEX operator * (COMPLEX a, COMPLEX b)
//{
//	COMPLEX c;
//	c.re = a.re * b.re - a.im * b.im;
//	c.im = a.im * b.re + a.re * b.im;
//	return c;
//}
//
//// ���帴�����ӡ�����
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
//// ������ɫ����ʼ����ɫ
///////////////////////////////////////////////////
//
//// ������ɫ
//int Color[MAXCOLOR];
//
//// ��ʼ����ɫ
//void InitColor()
//{
//	// ʹ�� HSL ��ɫģʽ�����Ƕ� h1 �� h2 �Ľ���ɫ
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
//// ���� Mandelbrot Set (���²����ؼ�)
///////////////////////////////////////////////////
//void Draw(double fromx, double fromy, double tox, double toy)
//{
//	COMPLEX z, c;
//	int x, y, k;	// ����ѭ������
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
//// ������
///////////////////////////////////////////////////
//void main()
//{
//	// ��ʼ����ͼ���ڼ���ɫ
//	initgraph(640, 480);
//	InitColor();
//
//
//	// ��ʼ�� Mandelbrot Set(���²����ؼ�)����ϵ
//	double fromx, fromy, tox, toy;
//	fromx = -2.1; tox = 1.1;
//	fromy = -1.2; toy = 1.2;
//	Draw(fromx, fromy, tox, toy);
//
//
//	// ������������ʵ�ַŴ����ѡ������
//	MOUSEMSG m;
//	bool isLDown = false;
//	int selfx, selfy, seltx, selty;	// ����ѡ��
//
//	while (!_kbhit())
//	{
//		m = GetMouseMsg();			// ��ȡһ�������Ϣ
//
//		switch (m.uMsg)
//		{
//			// ������м��ָ�ԭͼ������ϵ
//		case WM_MBUTTONUP:
//			fromx = -2.1; tox = 1.1;
//			fromy = -1.2; toy = 1.2;
//			Draw(fromx, fromy, tox, toy);
//			break;
//
//			// �����������϶���ѡ������
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
//			// �����������϶���ѡ������
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
//			// �����������϶���ѡ������
//		case WM_LBUTTONUP:
//			rectangle(selfx, selfy, seltx, selty);
//			setwritemode(R2_COPYPEN);
//			isLDown = false;
//			seltx = m.x;
//			selty = m.y;
//
//			if (selfx == seltx || selfy == selty)	break;
//
//			// ����ѡ��Ϊ 4:3
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
//			// ��������ϵ
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
//			// ��ͼ��
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
//#define WIDTH		1024		// ��Ļ��
//#define HEIGHT		576			// ��Ļ��
//#define NUM_MOVERS	600			// С������
//#define	FRICTION	0.96f		// Ħ����
//
//
//// ����С��ṹ
//struct Mover
//{
//	COLORREF	color;			// ��ɫ
//	float		x, y;			// ����
//	float		vX, vY;			// �ٶ�
//};
//
//
//// ����ȫ�ֱ���
//Mover	movers[NUM_MOVERS];			// С������
//int		mouseX, mouseY;			// ��ǰ�������
//int		mouseVX, mouseVY;		// ����ٶ�
//int		prevMouseX, prevMouseY;		// �ϴ��������
//bool	isMouseDown;				// �������Ƿ���
//DWORD*	pBuffer;					// �Դ�ָ��
//
//
//// ��ʼ��
//void init()
//{
//	// ��ʼ��С������
//	for (int i = 0; i < NUM_MOVERS; i++)
//	{
//		movers[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
//		movers[i].x = WIDTH * 0.5;
//		movers[i].y = HEIGHT * 0.5;
//		movers[i].vX = float(cos(float(i))) * (rand() % 34);
//		movers[i].vY = float(sin(float(i))) * (rand() % 34);
//	}
//
//	// ��ʼ��������
//	mouseX = prevMouseX = WIDTH / 2;
//	mouseY = prevMouseY = HEIGHT / 2;
//
//	// �����������
//	srand((unsigned int)time(NULL));
//
//	// ��ȡ�Դ�ָ��
//	pBuffer = GetImageBuffer(NULL);
//}
//
//
//// ȫ���䰵 50%
//void darken()
//{
//	for (int i = WIDTH * HEIGHT - 1; i >= 0; i--)
//	if (pBuffer[i] != 0)
//		pBuffer[i] = RGB(GetRValue(pBuffer[i]) >> 1, GetGValue(pBuffer[i]) >> 1, GetBValue(pBuffer[i]) >> 1);
//}
//
//
//// ������ʱ
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
//// ���ƶ���(һ֡)
//void run()
//{
//	darken();	// ȫ���䰵
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
//		// ��С��
//		setcolor(movers[i].color);
//		setfillstyle(movers[i].color);
//		fillcircle(int(nextX + 0.5), int(nextY + 0.5), int(sc + 0.5));
//	}
//}
//
//
//// ������
//void main()
//{
//	// ������ͼ����
//	initgraph(WIDTH, HEIGHT);
//	// ��������ͼģʽ
//	BeginBatchDraw();
//
//	// ��ʼ��
//	init();
//
//	// �����Ϣ����
//	MOUSEMSG m;
//
//	while (true)
//	{
//		// ���������Ϣ
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
//		// ���ƶ���
//		run();
//
//		// ��ʾ����Ļ�������
//		FlushBatchDraw();
//
//		// ��ʱ 20 ����
//		delay(20);
//	}
//
//	// �ر�
//	EndBatchDraw();
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//// �곣��
//#define	WIDTH		640
//#define HEIGHT		480
//#define FIREWIDTH	320
//#define	FIREHEIGHT	180
//
//// ȫ�ֱ���
//COLORREF	g_Colors[193];						// ����ɫϵ��ʹ�õ�ȫ����ɫ
//BYTE		g_Fire[FIREWIDTH];					// ��������
//BYTE		g_Bits[FIREHEIGHT * FIREWIDTH];		// ��������
//
//// ��������
//int m_nDecay = 5;			// ˥���ȣ���Χ [1, 100]��Ĭ�� 5
//int m_nFlammability = 385;	// ��ȼ�ԣ���Χ [1, 399]��Ĭ�� 385
//int m_nMaxHeat = 192;		// ����ȶȣ���Χ [0, 192]��Ĭ�� 192
//int m_nSpreadRate = 20;		// �������ʣ���Χ [1, 100]��Ĭ�� 20
//int m_nSize = 160;			// ��Դ��ȣ���Χ [40, FIREWIDTH]��Ĭ�� 160
//int m_nSmoothness = 1;		// ƽ���ȣ���Χ [0, 5]��Ĭ�� 1
//int m_nDistribution = 1;	// �ֲ�����Χ [0, 10]��Ĭ�� 1
//int m_nChaos = 50;			// ���磬��Χ [1, 100]��Ĭ�� 50
//
//
//
//// ��ʼ������
//void InitFire()
//{
//	// ��ʼ����ɫ
//	int r, g, b;
//
//	// Ĭ�Ϻ�ɫ���档����ע��ѡ��ͬ�Ļ���Ч��
//	b = 256 + 256 + 255;	g = 256 + 255;	r = 255;	// ��ɫ����
//	 r = 256+256+255;	g = 256+255;	b = 255;	// ��ɫ����
//	 g = 256+256+255;	b = 256+255;	r = 255;	// ��ɫ����
//
//	// ���ɻ���ɫϵ
//	for (int i = 192; i >= 0; i--)
//	{
//		g_Colors[i] = RGB((r > 255) ? 255 : r, (g > 255) ? 255 : g, (b > 255) ? 255 : b);
//		r = (r > 3) ? (r - 4) : 0;
//		g = (g > 3) ? (g - 4) : 0;
//		b = (b > 3) ? (b - 4) : 0;
//	}
//
//	// �ÿջ�������
//	memset(g_Fire, 0, FIREWIDTH);
//	memset(g_Bits, 0, FIREWIDTH * FIREHEIGHT);
//}
//
//
//
//// ��ɫϵ
//void DrawColorScheme()
//{
//	POINT s[8] = { { 0, 450 }, { 580, 450 }, { 580, 420 }, { 610, 420 },
//	{ 610, 0 }, { 639, 0 }, { 639, 479 }, { 0, 479 } };
//
//	HRGN rgn1 = CreatePolygonRgn(s, 8, WINDING);
//	HRGN rgn2 = CreateEllipticRgn(550, 390, 611, 451);
//	CombineRgn(rgn1, rgn1, rgn2, RGN_DIFF);
//
//	// ����ü�����
//	setcliprgn(rgn1);			// �������� rgn Ϊ�ü���
//	DeleteObject(rgn1);
//	DeleteObject(rgn2);
//
//	// ��ɫϵ
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
//	// ȡ���ü�����
//	setcliprgn(NULL);
//}
//
//
//
//// ��������ÿ����
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
//// �������
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
//	for (y = FIREHEIGHT - 1; y > 0; y--)	// y = 0 �������y++ �����С
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
//// ��ʾ����
//void PaintFlame(int offset_x, int offset_y)
//{
//	DWORD* pDst = GetImageBuffer();	// ��ȡ�Դ�ָ��
//
//	for (int y = 0; y < FIREHEIGHT; y++)
//	for (int x = 0; x < FIREWIDTH; x++)
//	{
//		COLORREF c = g_Colors[g_Bits[y * FIREWIDTH + x]];
//		pDst[(offset_y - y) * WIDTH + offset_x + x] = c;
//	}
//
//	FlushBatchDraw();				// ʹ�Դ������Ч
//}
//
//
//
//// ������
//void main()
//{
//	initgraph(WIDTH, HEIGHT);		// ������ͼ����
//	srand((unsigned)time(NULL));	// �����������
//
//	InitFire();						// ��ʼ������
//	DrawColorScheme();				// ����ɫϵͼ
//
//	while (!_kbhit())					// ��������˳�
//	{
//		RenderFlame();				// ��Ⱦ����
//		PaintFlame(145, 320);		// ��ʾ����
//		Sleep(33);					// ��ʱ
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
//HPALETTE	g_hPal, g_hOldPal;	// ��ɫ����
//LOGPALETTE*	g_pLOGPAL;			// ��ɫ����Ϣ�ṹ��
//HDC			g_hDC;				// EasyX ���ڵ� DC ���
//
//
//// ��ʼ��
//void Init()
//{
//	initgraph(WIDTH, HEIGHT);	// ������ͼ����
//	g_hDC = GetImageHDC();		// ��ȡ��ͼ���ڵľ��
//
//	// �趨����ɫϵ
//	int r = 216;
//	int g = 0;
//	int b = 0;
//
//	///////////////////
//	// ��ʼ����ɫ��
//
//	// Ϊ��ɫ��ṹ������ڴ�(�õ�ɫ�庬�� 32 ����ɫ)
//	// ��ʵ�ʶ��ĸ��ֽ��������� palVersion �� palNumEntries ������Ա��
//	// ��� MSDN �� LOGPALETTE �Ķ���
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
//	g_hPal = CreatePalette(g_pLOGPAL);					// ������ɫ��
//	g_hOldPal = SelectPalette(g_hDC, g_hPal, false);	// ѡ���ɫ��
//}
//
//
//// �ı��ɫ��
//void ChangePal()
//{
//	// ʹ��ɫ�����ɫѭ������
//	PALETTEENTRY t = g_pLOGPAL->palPalEntry[0];
//	for (int i = 0; i < 31; i++)
//		g_pLOGPAL->palPalEntry[i] = g_pLOGPAL->palPalEntry[i + 1];
//	g_pLOGPAL->palPalEntry[31] = t;
//
//	// ʹ��ɫ����޸���Ч
//	AnimatePalette(g_hPal, 0, 32, g_pLOGPAL->palPalEntry);
//	RealizePalette(g_hDC);
//}
//
//
//// ��ͼ��
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
//// �˳�
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
//// ������
//void main()
//{
//	Init();					// ��ʼ��
//
//	while (!_kbhit())		// ��������˳�
//	{
//		ChangePal();		// �ı��ɫ��
//		Draw();				// ��ͼ��(ÿ�λ��Ķ�һ������̬ͼ������Ϊ��ɫ��ĸı�)
//		FlushBatchDraw();	// ʹ GDI ��ͼ������Ч
//		Sleep(33);			// ��ʱ
//	}
//
//	Quit();					// �˳�
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
//// �ڵ㣨��������Ľڵ㻷�����һ�����㣩
//struct POINTNODE
//{
//	POINT		pos;	// λ��
//	POINTNODE*	next;	// ָ����һ���ڵ��ָ��
//};
//
//
//
//// ���㣨�ĸ����㣬���һ������Σ�
//class VERTEX
//{
//public:
//	POINTNODE*	m_head;		// ͷ����ָ��
//	POINT		m_step;		// �ƶ�����
//
//	// ���캯��
//	VERTEX()
//	{
//		m_head = NULL;
//	}
//
//	// ��������
//	~VERTEX()
//	{
//		if (m_head != NULL)
//			delete[] m_head;
//	}
//
//	// ��ʼ������
//	void Init(int count)
//	{
//		// ��ʼ��ǰ������
//		m_step.x = ((rand() % 2) * 2 - 1) * (rand() % MAXSTEP + 1);
//		m_step.y = ((rand() % 2) * 2 - 1) * (rand() % MAXSTEP + 1);
//
//		// ��ʼ���ڵ㻷
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
//	// ��ȡͷ���ڵ�����
//	POINT GetHead()
//	{
//		return m_head->pos;
//	}
//
//	// ��ȡβ���ڵ�����
//	POINT GetTail()
//	{
//		return m_head->next->pos;
//	}
//
//	// �ƶ�����
//	void Move()
//	{
//		m_head->next->pos.x = m_head->pos.x + m_step.x;
//		m_head->next->pos.y = m_head->pos.y + m_step.y;
//		m_head = m_head->next;
//
//		// �ж϶����Ƿ�Խ��
//		if (m_head->pos.x < 0)			{ m_head->pos.x = -m_head->pos.x;				m_step.x = rand() % MAXSTEP + 1; }
//		else if (m_head->pos.x >= WIDTH)	{ m_head->pos.x -= m_head->pos.x - WIDTH + 1;	m_step.x = -rand() % MAXSTEP - 1; }
//		if (m_head->pos.y < 0)			{ m_head->pos.y = -m_head->pos.y;				m_step.y = rand() % MAXSTEP + 1; }
//		else if (m_head->pos.y >= HEIGHT)	{ m_head->pos.y -= m_head->pos.y - HEIGHT + 1;	m_step.y = -rand() % MAXSTEP - 1; }
//	}
//};
//
//
//
//// �����
//class POLYGON
//{
//private:
//	COLORREF	m_color;		// ����ε���ɫ
//	VERTEX		m_vertex[4];	// ���ɶ���ε��ĸ�����
//
//public:
//	// ���캯��
//	POLYGON(int lines)
//	{
//		// ��ʼ����ɫ
//		m_color = HSLtoRGB(float(rand() % 360), 1.0, 0.5);
//
//		// ��ʼ���ĸ�����
//		for (int i = 0; i<4; i++)
//			m_vertex[i].Init(lines);
//	}
//
//	// �ƶ������
//	void Move()
//	{
//		int i;
//
//		// ��������ε�β��
//		setcolor(BLACK);
//		moveto(m_vertex[3].GetTail().x, m_vertex[3].GetTail().y);
//		for (i = 0; i<4; i++)
//			lineto(m_vertex[i].GetTail().x, m_vertex[i].GetTail().y);
//
//		// �ƶ�ÿ������
//		for (i = 0; i<4; i++)
//			m_vertex[i].Move();
//
//		// ������ε�ͷ��
//		setcolor(m_color);
//		moveto(m_vertex[3].GetHead().x, m_vertex[3].GetHead().y);
//		for (i = 0; i<4; i++)
//			lineto(m_vertex[i].GetHead().x, m_vertex[i].GetHead().y);
//
//		// �� 1% �ĸ��ʸ�����ɫ
//		if (rand() % 100 == 0)
//			m_color = HSLtoRGB(float(rand() % 360), 1.0, 0.5);
//	}
//};
//
//
//
//// ������
//void main()
//{
//	// ��ʼ����ͼ����
//	initgraph(WIDTH, HEIGHT);
//
//	// ��ʼ���������
//	srand((unsigned)time(NULL));
//
//	// ������������ζ��󣬷ֱ��� 7 ���ߺ� 12 ����
//	POLYGON s1(7), s2(12);
//
//	// �ƶ�����Σ���������˳�
//	while (!_kbhit())
//	{
//		s1.Move();
//		s2.Move();
//		Sleep(40);
//	}
//
//	// �رջ�ͼ����
//	closegraph();
//}
//#include <graphics.h>
//#include <conio.h>
//#include <time.h>
//
//// ��ӭ����
//void welcome()
//{
//	// �����Ļ��ʾ
//	cleardevice();
//	setcolor(YELLOW);
//	settextstyle(64, 0, "����");
//	outtextxy(160, 50, "����ĸ��Ϸ");
//	setcolor(WHITE);
//	settextstyle(16, 0, "����");
//	outtextxy(100, 200, "���Ǻܴ�ͳ���Ǹ�����ĸȻ����Ӧ������ʧ����Ϸ");
//	outtextxy(100, 240, "ֻ������һ���򵥵�ʵ��");
//	outtextxy(100, 280, "���ܲ��������ƣ������������������ȶ�û��д");
//	outtextxy(100, 320, "����Ȥ���Լ��ӽ�ȥ��");
//
//	// ʵ����˸�ġ��������������
//	int c = 255;
//	while (!_kbhit())
//	{
//		setcolor(RGB(c, 0, 0));
//		outtextxy(280, 400, "�����������");
//		c -= 8;
//		if (c < 0) c = 255;
//		Sleep(20);
//	}
//	_getch();
//	cleardevice();
//}
//
//// �˳�����
//void goodbye()
//{
//	cleardevice();
//	setcolor(YELLOW);
//	settextstyle(48, 0, "����");
//	outtextxy(104, 180, "��д����  �����ഺ");
//	_getch();
//}
//
//// ������
//void main()
//{
//	initgraph(640, 480);		// ��ʼ����ĻΪ 640x480
//
//	welcome();					// ��ʾ��ӭ����
//
//	srand(time(NULL));			// �����������
//	settextstyle(16, 0, "Arial");	// ������ĸ������ʹ�С
//	setfillstyle(BLACK);		// ���������ĸ�����������ɫ
//
//	char target;				// Ŀ����ĸ
//	char key;					// �û��İ���
//	int x, y;					// ��ĸ��λ��
//
//	// ��ѭ��
//	while (true)
//	{
//		target = 65 + rand() % 26;		// ���������д��ĸ
//		x = rand() % 620;				// ������������λ��
//		for (y = 0; y<460; y++)
//		{
//			setcolor(WHITE);			// ������ĸ����ɫ
//			outtextxy(x, y, target);	// ��ʾ��ĸ
//
//			if (_kbhit())
//			{
//				key = _getch();			// ��ȡ�û�����
//
//				if ((key == target) || (key == target + 32))
//				{
//					// ������ȷ�������䡱��ĸ������ɫ���������
//					bar(x, y, x + 16, y + 16);
//					break;				// ����ѭ����������һ����ĸ
//				}
//				else if (key == 27)
//				{
//					goto EXIT;			// ����� ESC���˳���Ϸ��ѭ��
//				}
//			}
//
//			// ��ʱ���������ĸ
//			Sleep(10);
//			bar(x, y, x + 16, y + 16);
//		}
//	}
//
//EXIT:
//	// �˳�����
//	goodbye();
//
//	// �ر�ͼ�ν���
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
//// ������ά��
//struct POINT3D
//{
//	double x;
//	double y;
//	double z;
//};
//
//POINT3D p3d[MAXPOINT];		// ���е���ά��
//double viewZ = 3;			// �ӵ� z ������
//
//// ��ʼ����ά��
//void InitPoint()
//{
//	// �����������
//	srand(time(NULL));
//
//	// ����������������㣨�������������������Բ������Ĺ�ϵ��
//	double rxy, a;
//	for (int i = 0; i<MAXPOINT; i++)
//	{
//		p3d[i].z = 2.0 * rand() / RAND_MAX - 1;	// ����� z ����
//		rxy = sqrt(1 - p3d[i].z * p3d[i].z);	// ������άʸ���� xoy ƽ���ͶӰ����
//		a = 2 * PI * rand() / RAND_MAX;			// ��������Ƕ�
//		p3d[i].x = cos(a) * rxy;
//		p3d[i].y = sin(a) * rxy;
//	}
//}
//
//// ʹ��ά�㰴 x ����תָ���Ƕ�
//void RotateX(POINT3D &p, double angle)
//{
//	double y = p.y;
//	p.y = p.y * cos(angle) + p.z * sin(-angle);
//	p.z = y * sin(angle) + p.z * cos(angle);
//}
//
//// ʹ��ά�㰴 y ����תָ���Ƕ�
//void RotateY(POINT3D &p, double angle)
//{
//	double x = p.x;
//	p.x = p.x * cos(angle) + p.z * sin(-angle);
//	p.z = x * sin(angle) + p.z * cos(angle);
//}
//
//// ʹ��ά�㰴 z ����תָ���Ƕ�
//void RotateZ(POINT3D &p, double angle)
//{
//	double x = p.x;
//	p.x = p.x * cos(angle) + p.y * sin(-angle);
//	p.y = x * sin(angle) + p.y * cos(angle);
//}
//
//// ����ά��ͶӰ����ά��Ļ�ϣ�����͸�ӣ�
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
//		cleardevice();		// �����Ļ
//
//		for (int i = 0; i<MAXPOINT; i++)
//		{
//			// ʹ�õ�Χ����������������ת�˶�
//			RotateX(p3d[i], PI / 180);
//			RotateY(p3d[i], PI / 170);
//			RotateZ(p3d[i], PI / 160);
//
//			// ���ݵ����ȣ�������Ӧ�Ҷȵ���ɫ
//			c = (int)(p3d[i].z * 100) + 155;
//
//			// ͶӰ�õ㵽��Ļ��
//			p2d = Projection(p3d[i]);
//
//			// ����
//			putpixel(p2d.x, p2d.y, RGB(c, c, c));
//		}
//
//		FlushBatchDraw();
//		Sleep(10);			// ��ʱ 10 ����
//	}
//
//	EndBatchDraw();
//	closegraph();
//}