#include "game.h"  
  
int main()  
{  
    int input=0;  
    do{  
        menu();  
        printf("请选择： \n");  
        scanf_s("%d", &input);  
        switch (input)
		{  
        case 1:
			game(); break;  
        case 0:
			exit(0); break;  
        default:
			printf("请重新输入\n"); break;  
        }  
    } while (1);  
  
  
}