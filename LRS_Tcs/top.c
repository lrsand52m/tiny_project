#define _CRT_SECURE_NO_WARNINGS
#include "TCS.h"
//全局变量//
extern int level ;                          //关卡数，0表示无尽模式
extern int score , add ;                    //总得分与每次吃食物得分
extern int status, sleeptime ;              //每次运行的时间间隔
extern snake *head, *food;                  //蛇头指针，食物指针
extern snake *q;                            //遍历蛇的时候用到的指针
extern int endgamestatus ;                  //游戏结束的情况，1：撞到墙；2：咬到自己；3：主动退出游戏。
extern int run ;                            //判断游戏是否还能运行
extern player top[61];                      //排行榜
extern int MAX_LL ;
extern int MAX_CC ;
extern int MAX_L ;
extern int MAX_C ;
//初始化排行
void inittop()
{
	int j = 0;
	for (j = 0; j < 3; j++)
	{
		int i = 0;
		top[20 * j + i].scores = 999;
		sprintf(top[20 * j + i].len, "%d", 56);
		top[20 * j + i].steps = 1658;
		for (i = 1; i < 20; i++)
		{
			top[20 * j + i].scores = 480 - 20 * i;
			sprintf(top[20 * j + i].len ,"%d", 48 - 2 * i);
			top[20 * j + i].steps = 999 - 20 * i;
		}
		for (i = 0; i < 21; i++)
		{
			strcpy(top[20 * j + i].name, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
			strcpy(top[20 * j + i].name, "LRS");
		}
	}
	top[60].scores = 0;
	loadtop();
}
//排行菜单
int topmenu()
{
	int input;
	do
	{
		system("cls");
		mapmenu();
		fflush(stdin);
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 2);
			printf("输入有误！");
			Sleep(500);
			break;
		}
	} while (1);
}
//显示排行
void showtop()
{
	int i = 0;
	int j = topmenu();
	system("cls");
	print();
	Pos(MAX_LL / 5, i + 3);
	color(15);
	printf("%-5s\t%-20s%-6s\t%-3s\t%-8s", "名次", "昵称", "分数","体长","路程");
	for (i = 0; i < 20; i++)
	{
		Pos(MAX_LL / 5, i + 4);
		if (i < 20)color(15);
		if (i < 10)color(10);
		if (i < 5)color(9);
		if (i < 3)color(13);
		if (i < 2)color(14);
		if (i < 1)color(12);
		printf("%-5d\t%-20s%-6d\t%-3s\t%-8d", i + 1, top[j * 20 + i].name, top[j * 20 + i].scores, top[j * 20 + i].len, top[j * 20 + i].steps);
	}
	Pos(MAX_LL / 5, i + 6);
	system("pause");
	system("cls");
}
//排序排行
void sorttop()
{
	int i = 0;
	int j = 0;
	int m = (MAX_LL - 100) / 30 * 20;
	for (i = 0; i < 20; i++)
	{
		if (top[60].scores >= top[m + i].scores)
		{
			for (j = 19 + m; j >(i + m); j--)
			{
				top[j] = top[j - 1];
			}
			top[i + m] = top[60];
			break;
		}
	}
	savetop();
}
//加载
void loadtop()
{
	int ret = 0;
	FILE* c = fopen(Filename,"a+");
	FILE* load = fopen(Filename, "rb");
	fclose(c);
	c = NULL;
	if (load == NULL)
	{
		perror("load top");
		exit(1);
	}
	while(fread(&top[ret++], sizeof(player), 1, load));
	//printf("%d", ret);
	//system("pause");
	fclose(load);
	load = NULL;
}
//保存
void savetop()
{
	int i = 0;
	FILE* save = fopen(Filename, "w");
	if (save == NULL)
	{
		perror("save top");
		exit(1);
	}
	fwrite(&top[0], sizeof(player), 60, save);
	fclose(save);
	save = NULL;
}