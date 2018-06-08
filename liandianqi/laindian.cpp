#define _CRT_SECURE_NO_WARNINGS
#include "click.h"
int main()
{
	int x, y, count;
	int time;
	int dou = 0; 
	int lef = 0;
	int sum = 0;
	char mess[250];
	printf("欢迎使用鼠标连点器！\n按下ESC确认坐标：");
	printpos(&x,&y);
	printf("请输入延时(毫秒)和点击次数(0表示无限,随时可以按下ESC来中断点击):");
	scanf("%d %d", &time, &count);
	printf("十秒后开始点击！");
	Sleep(10000);
	sum = clicks(lef, dou, time, count, x, y);
	wsprintf(mess, _T("%s\n%s%d%s"), _T("点击完毕"), _T("共点击:"), sum, _T("次"));
	MessageBox(0, mess, _T("点击结束"), MB_OK);
	return 0;
}