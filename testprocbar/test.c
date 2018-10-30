#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void color(int x)
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
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
void xp()
{
	char bar[40] = {0};
	const char*label = "-\\/|";
	int time = 0;
	bar[0] = 1;
	bar[1] = 1;
	bar[2] = 1;
	int left = 0;
	int right = 2;
	while (1)
	{
		Pos(20, 3);
		printf("[");
		int i = 0;
		for (i = 0; i < 40; i++)
		{
			if (bar[i])
				printf("■");
			else
				printf("  ");
		}
		bar[left] = 0;
		right = (right + 1) % 40;
		left = (left + 1) % 40;
		bar[right] = 1;
		printf("]");
		Sleep(60);
		time += rand() % 2;
		Pos(55, 5);
		printf("[%c]  %d%%", label[time % 4], time);
		if (time >= 100)break;
		//system("cls");
	}
	Pos(55, 5);
	printf("[OK]");
}
void printbp(int c,int n)
{
	color(c*16);
	while (n--&&n>=0)
	{
		printf(" ");
	}
	color(15);
}
void centos()
{
	int time = 0;
	char*label = "-\\|/";
	size_t i = 1;
	for (; i <= 120;)
	{
		int G, B, W;
		i += rand() % 2;
		G = i*i / 120;
		B = i - G;
		W = 12 * sqrt(i*100/120) - B - G;
		Pos(0, 7);
		printbp(15, G);
		printbp(1, B);
		printbp(9, W);
		Pos(55,9);
		printf("[%3d%%][%c]", i*100/120, label[time++ % 4]);
		Sleep(60);
	}
}
void load()
{
	COORD pos[8] = { { 56, 11 }, { 58, 12 }, { 60, 13 }, { 58, 14 }, {56,15}, { 54, 14 }, { 52, 13 }, { 54, 12 } };
	int a[8] = { 0 };
	a[0] = 1;
	int time = 0;
	int cur = 0;
	while (time < 100)
	{
		for (int i = 0; i < 8; i++)
		{
			Pos(pos[i].X, pos[i].Y);
			if (a[i])
				printf("●");
			else
				printf("○");
		}
		a[cur] = 0;
		cur = (cur + 1) % 8;
		a[cur] = 1;
		Pos(55, 17);
		printf("%d%%", time);
		time+=rand()%2;
		Sleep(80);
	}
	for (int i = 0; i < 8; i++)
	{
		Pos(pos[i].X, pos[i].Y);
		printf("○");
	}
	Pos(56, 13);
	printf("●");
	Pos(55,17);
	printf("OK!");
}
int main()
{
	system("title 进度条测试程序");
	system("mode con cols=122 lines=38");
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO){ 30, 0 });
	srand(time(0));
	//xp();
	centos();
	//load();
	color(15);
	printf("\n");
	system("pause");
	return 0;
}
