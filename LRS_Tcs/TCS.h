#pragma once
#ifndef __TCS_H__
#define __TCS_H__
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#define Filename "tcs.52m"
#define U 1
#define D 2
#define L 3
#define R 4       //蛇的状态，U：上 ；D：下；L:左 R：右
typedef struct SNAKE //蛇身的一个节点
{
	int x;
	int y;
	struct SNAKE *next;
}snake;
typedef struct PLAYER
{
	char name[20];
	int scores;
	char len[3];
	int steps;
}player;
typedef struct ACHEVE
{
	int step;
	int eat;
	int score;
}acheve;
typedef struct POS
{
	int x;
	int y;
}pos,*ppos;
typedef struct LEL
{
	ppos pos;
	int sz;
	int capacity;
}lel,plel;
//声明全部函数//
void Pos();
void creatMap();
void initsnake();
int biteself();
void createfood(int x);
void cantcrosswall();
void snakemove();
void pause();
void gamecircle();
void welcometogame();
void gamestart();
void endgame();
void print();
void menu();
void inittop();
void showtop();
void sorttop();
void startshow();
void selectmap();
void mapmenu();
int topmenu();
void loadtop();
void savetop();
void color();
void showach();
void loadach();
void saveach();
void tfree(snake* p);
void initlevel();
void printlevel();
void push(int l,int x,int y);
void selectmode();
void uplevel();
void modemenu();
#endif//__TCS_H__
