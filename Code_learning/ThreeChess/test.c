#include "game.h"  
  
int main()  
{  
    int input=0;  
    do{  
        menu();  
        printf("��ѡ�� \n");  
        scanf_s("%d", &input);  
        switch (input)
		{  
        case 1:
			game(); break;  
        case 0:
			exit(0); break;  
        default:
			printf("����������\n"); break;  
        }  
    } while (1);  
  
  
}