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
	printf("��ӭʹ�������������\n����ESCȷ�����꣺");
	printpos(&x,&y);
	printf("��������ʱ(����)�͵������(0��ʾ����,��ʱ���԰���ESC���жϵ��):");
	scanf("%d %d", &time, &count);
	printf("ʮ���ʼ�����");
	Sleep(10000);
	sum = clicks(lef, dou, time, count, x, y);
	wsprintf(mess, _T("%s\n%s%d%s"), _T("������"), _T("�����:"), sum, _T("��"));
	MessageBox(0, mess, _T("�������"), MB_OK);
	return 0;
}