#define _CRT_SECURE_NO_WARNINGS
#include "Prints.h"
int main(int argc,char* argv[])
{
	unsigned int time = printimg("g:/VS2008/c.bmp");
	TCHAR over[256] = { 0 };
	wsprintf(over, _T("%s\n%s%u%s"), _T("��ӡ��ɣ�"), _T("��ʱ��"), time,_T("��"));
	MessageBox(0, over, _T("mission complete"), MB_OK);
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
	return 0;
}
