#define _CRT_SECURE_NO_WARNINGS
#include "Prints.h"
int main(int argc,char* argv[])
{
	int x1, x2, y1, y2;
	system("mode con cols=30 lines=15");
	system("md c:\\VS2008");
	Pos(0, 9);
	printf("����F1���ٽ�ȡȫ��\n");
	Pos(0, 0);
	printf("���¿ո�ѡȡ��ͼ���\n");
	printpos(&x1, &y1, 1);
	Sleep(300);
	printf("���¿ո�ѡȡ��ͼ�յ�\n");
	printpos(&x2, &y2, 3);
	//x2 -= (x2 - x1) % 4;
	CaptureScreen(x1, y1, x2, y2);
	return 0;
	//system("start /b C:/Windows/system32/mspaint.exe");
	////_T��һ���꣬����������ĳ���֧��Unicode����.
	//HWND hwnd_notepad = FindWindow(_T("notepad++"), 0);
	////#define DECLARE_HANDLE(name)
	////struct name##__{int unused;};
	////typedef struct name##__ *name
	/////DECLARE_HANDLE        (HWND);
	//if (hwnd_notepad == 0)
	//{
	//	MessageBox(0, _T("dont run notepad"), _T("error"), MB_OK);
	//	return 0;
	//}
	////��ȡ���ڴ�д
	//RECT rect;
	//GetWindowRect(hwnd_notepad, &rect);
	//LONG height = rect.bottom - rect.top;
	//LONG width = rect.right - rect.left;
	////������ڴ�С��Ϣ
	//TCHAR tzbuf[256] = { 0 };
	//wsprintf(tzbuf, _T("%s%d\n%s%d"), _T("height="), height, _T("width="), width);
	////������Ϣ��
	//MessageBox(0, tzbuf, _T("notepad window size"), MB_OK);
	//printf("%s\n", tzbuf);
	//system("pause");
	//prints(argv[1],0);
}

