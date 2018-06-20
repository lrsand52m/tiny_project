#define _CRT_SECURE_NO_WARNINGS
#include "TCS.h"
extern acheve ach;
extern int MAX_LL;
struct achname
{
	char name[20];
	int num;
}name[9] = { { "旅行蛇",10000 }
,{ "环游中国",100000 } ,{"遨游太空",1000000 },{"大胃王", 100}
,{ "上古腐鲸蛇",10000 },{ "宇宙级大蛇", 100000},{ "得分高手",10000 }
,{ "得分大师",100000 },{"得分宗师",1000000 }};
//展示成就
void showach()
{
	int i = 0;
	system("cls");
	print();
	Pos(MAX_LL / 5, i + 3);
	color(15);
	printf("%-20s\t         %-12s\t", "成就", "状态");
	for (i = 0; i < 9; i++)
	{
		color(i % 3 + 10);//判断颜色
		Pos(MAX_LL / 5, 2 * (i + 1) + 3);
		printf("%-20s\t", name[i].name);
		switch (i / 3)//判断类型
		{
		case 0:
			if (ach.step >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.step, name[i].num);
			break;
		case 1:
			if (ach.eat >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.eat, name[i].num);
			break;
		case 2:
			if (ach.score >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.score, name[i].num);
			break;
		}
	}
	Pos(MAX_LL / 5, 2 * (i + 1) + 5);
	printf("走过的总步数:%d步\t吃过的食物总数:%d个\t得到的总分数:%d分", ach.step, ach.eat, ach.score);
	Pos(MAX_LL / 5, 2 * (i + 1) + 7);
	system("pause");
}
//加载
void loadach()
{
	FILE* c = fopen("ach.52m","a+");//如果没有就新建
	FILE* load = fopen("ach.52m", "rb");
	fclose(c);
	c = NULL;
	if (load == NULL)
	{
		perror("load ach");
		exit(1);
	}
	ach.eat = 0;
	ach.score = 0;
	ach.step = 0;
	fread(&ach, sizeof(acheve), 1, load);
	fclose(load);
	load = NULL;
}
//保存
void saveach()
{
	FILE* save = fopen("ach.52m", "wb");
	if (save == NULL)
	{
		perror("save ach");
		exit(1);
	}
	fwrite(&ach, sizeof(acheve), 1, save);
	fclose(save);
	save = NULL;
}