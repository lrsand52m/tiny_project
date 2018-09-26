#include "game.h"  
void game()  
{  
	int input;
    char ret;  
    char arr[ROW][LIN] ; 
	while(1)
	{
		system("cls");
		initboard(arr, ROW, LIN);  
		printf("**************************************\n");
		printf("*                                    *\n");
		printf("*请选择难度：1.简单   2.困难   3.大师*\n");
		printf("*                                    *\n");
		printf("**************************************\n");
		scanf("%d",&input);
		if (input>3 || input<1)
		{
			printf("输入错误！重新输入！");
			Sleep(500);
		}
		else break;
	}
	system("cls");
	printf("\n");
	checkboard(arr, ROW, LIN);
    srand((unsigned int)time(NULL));  
    do
	{  
        player_go(arr, ROW, LIN);
		//system("cls");
        checkboard(arr, ROW, LIN);  
        ret = is_win(arr, ROW, LIN);
        if (ret != ' ')
		{  
            break;  
        }  
		Sleep(1000);
		system("cls");
        pc_go(arr, ROW, LIN, input);  
        checkboard(arr, ROW, LIN);  
        ret = is_win(arr, ROW, LIN);  
        if (ret != ' ')
		{  
            break;  
        }  
    } while (1);  
    if (ret == 'X')
	{  
        printf("你赢了！\n");  
		system("pause");
		system("cls");
    }  
    else if (ret == 'O')
	{  
        printf("你输了！\n");  
		system("pause");
		system("cls");
    }  
    else if (ret == 'f')  
    {  
        printf("平局！\n"); 
		system("pause");
		system("cls");
    }  
} 
void menu()  
{  
	printf("\n         三子棋       \n\n");
    printf("***********************\n");
    printf("***** 1.开始游戏  *****\n");
    printf("***** 0.退出游戏  *****\n");
    printf("***********************\n");
}  
void initboard(char arr[][LIN], int row,int lin)//初始化棋盘
{
    memset(arr, ' ', sizeof(arr[0][0])*lin*row);
}
void checkboard(char arr[][LIN], int row, int lin)//打印棋盘
{
    int i = 0;
	int j = 0;
    for (i=0; i<row; i++)
	{  
		for(j=0; j<lin; j++)
		{
			printf(" %c ", arr[i][j]);
			if(j < lin-1)
				printf("|");
			else 
				printf("\n");
		}
        if (i < row-1)
		{  
			for(j=0; j<lin; j++)
			{
				printf("---");
				if(j < lin-1)
					printf("|");
				else 
					printf("\n");
			}
        }
    }
    printf("\n");
}  
void player_go(char arr[][LIN], int row, int lin)//玩家走
{
    int i, j, input; 
    while(1)
	{  
        printf("请你落子(1-9): \n");  
        //scanf_s("%d %d", &i, &j); 
		scanf("%d",&input);
		i = (input+2)/3;
		j = (input%3 == 0)? 3:input%3; 
        if (i >=1 && i <= row&&j >=1 && j <= lin)
		{  
            if (arr[i - 1][j - 1] ==' ')
			{  
                arr[i - 1][j - 1] = 'X';  
                break;  
            }  
            else {   
                printf("已经有子了！\n");  
                 }  
        }  
        else {  
            printf("错误落子，请重新落子\n");  
        }  
    } 
	//system("cls");
}  
void pc_go(char arr[][LIN], int row, int lin, int nan)//电脑走  
{  
    int i, j, count;
	int sig = 0;
	int i2 = 6, j2 = 6;
	int m = 0;
	int n = 0;
	count = 0;
	printf("电脑思考中");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".\n电脑落子：\n");
	switch(nan)
	{
		//难度1
		case 1:
			do
			{
				i = rand() % row;  
				j = rand() % lin;  
				if (arr[i][j] == ' ')
				{  
					arr[i][j] = 'O';  
					break;  
				}  
			} while (1);
			break;
		//难度二
		case 2:	
			count = 1;
			if(arr[1][1] == ' ')
			{
				arr[1][1] = 'O';
				goto done2;
			}
nan2:
			for(i=0; i<row; i++)
			{
				n = 0;
				m = 0;
				for(j=0; j<lin; j++)
				{
					m += arr[i][j];//行
					n += arr[j][i];//列
				}
				if(m == 'O'*2 + ' ')
				{
					for(j=0; j<lin; j++)
					{
						if(arr[i][j] == ' ')
						{
							arr[i][j] = 'O';
							goto done2;
						}
					}
				}
				if(m == 'X'*2 + ' ')
				{
					sig++;
					i2 = i;
				}
				if(n == 'O'*2 + ' ')
				{
					for(j=0; j<row; j++)
					{
						if(arr[j][i] == ' ')
						{
							arr[j][i] = 'O';
							goto done2;
						}
					}
				}
				if(n == 'X'*2 + ' ')
				{
					sig++;
					j2 = i;
				}
			}//这里确定电脑不能一步下赢，开始阻拦玩家
				if(sig)
				{
					if(i2 < row)
					{
						for(j=0; j<lin; j++)
						{
							if(arr[i2][j] == ' ')
							{
								arr[i2][j] = 'O';
								goto done2;
							}
						}
					}
					else
					{
						for(j=0; j<row; j++)
						{
							if(arr[j][j2] == ' ')
							{
								arr[j][j2] = 'O';
								goto done2;
							}
						}
					}
				}//行列判定over
			if(arr[0][0]+arr[1][1]+arr[2][2] == 'O'*2 + ' '||arr[0][0]+arr[1][1]+arr[2][2] == 'X'*2 + ' ')
			{			
				for(i=0; i<lin; i++)
				{
					if(arr[i][i] == ' ')
					{
						arr[i][i] = 'O';
						goto done2;
					}	
				}
			}
			if(arr[2][0]+arr[1][1]+arr[0][2] == 'O'*2 + ' '||arr[2][0]+arr[1][1]+arr[0][2] == 'X'*2 + ' ')
			{
				for(j=0; j<row; j++)
				{
					if(arr[row-j-1][j] == ' ')
					{
						arr[row-j-1][j] = 'O';
						goto done2;
					}
				}
			}//斜
			do
			{
				i = rand() % row;  
				j = rand() % lin;  
				if (arr[i][j] == ' ')
				{  
					arr[i][j] = 'O';  
					goto done2;
				}  
			} while (1);
done2:
			break;
		//难度三
		case 3:
			if(arr[1][1] == ' ')
			{
				arr[1][1] = 'O';
			}
			else 
			{
				for(i=0; i<row; i++)
				{
					for(j=0; j<lin; j++)
					{
						count += arr[i][j];
					}
				}
				if((count == 'X'+ 8*' ') && arr[1][1] == 'X')
				{
					arr[0][0] = 'O';
				}
				else if((count == 'X'*2 + 'O'*1 + ' '*6) && arr[1][1] == 'X' && arr[2][2] == 'X')
				{
					arr[0][2] = 'O';
				}
				else if((count == 'X'*2 + 'O'*1 + ' '*6) && arr[1][1] == 'O' && (arr[0][0] == 'X' && arr[2][2] == 'X')||(arr[2][0] == 'X' && arr[0][2] == 'X'))
				{
					arr[0][1] = 'O';
				}
				else goto nan2;
			}
			break;
	}
    //system("cls");
}  
int is_full(char arr[][LIN], int row, int lin)//判断棋盘是否为满  
{  
    int i=0, j=0;  
    for (i=0; i<row; i++)
	{  
        for (j=0; j<lin; j++)
		{  
            if (arr[i][j] == ' ')
                return 0;   
        }  
    } 
	return 1;
}  
char is_win(char arr[][LIN], int row, int lin)//判断输赢  
{  
    int i = 0, j = 0;  
    for (i=0; i<row; i++)
	{  
        if ((arr[i][0] == arr[i][1])&&( arr[i][1] == arr[i][2] )&& arr[i][1] != ' ')  //判断行
        {  
            return arr[i][1];
        }         
    }  
    for (j=0; j<lin; j++) //判断列  
    {  
        if ((arr[0][j] == arr[1][j] ) && ( arr[1][j] == arr[2][j]) && arr[1][j] != ' ')  
        {  
            return arr[1][j];  
        }  
    }  
    if ((arr[0][0] == arr[1][1] ) && (arr[1][1] == arr[2][2]) && arr[1][1] != ' ') //判断斜列  
        {  
            return arr[1][1];  
        }  
    else if( (arr[0][2] == arr[1][1]) && ( arr[1][1] == arr[2][0]) && arr[1][1] != ' ')  
        {  
            return arr[1][1];  
        }  
    else if (is_full(arr,row,lin))
	{  
        return  'f';  
    }  
    else return  ' ';  
}  
