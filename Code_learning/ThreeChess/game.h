#ifndef __GAME_H__
#define __GAME_H__
 
#include<stdio.h> 
#include<stdlib.h>
#include<windows.h>  
#include<time.h>  
#include<string.h>  
 
#define ROW 3  
#define LIN 3  
void game();
void menu();  
void initboard(char arr[ROW][LIN], int row, int lin);  
void checkboard(char arr[ROW][LIN], int row, int lin);  
void player_go(char arr[ROW][LIN], int row, int lin);  
void pc_go(char arr[ROW][LIN], int row, int lin, int nan);  
int is_full(char arr[ROW][LIN], int row, int lin);  
char is_win(char arr[ROW][LIN], int row, int lin);

#endif //game.h