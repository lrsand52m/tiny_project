#define _CRT_SECURE_NO_WARNINGS 
#include "Prints.h"
//���ô�ӡλ��
void CaptureScreen(int x1, int y1, int x2, int y2)
{
	char c;
	unsigned int time;
	int t = 0;
	if (x2 < x1)
	{
		t = x2; x2 = x1; x1 = t;
	}
	if (y2 < y1)
	{
		t = y2; y2 = y1; y1 = t;
	}
	//������洰�ھ��
	HWND hDesktopWnd = GetDesktopWindow();
	//������洰���豸����
	HDC hDesktopDC = GetDC(hDesktopWnd);
	//����ȫ��Ļ�����豸������ļ����豸����
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	//����ȫ��Ļ�����豸������ļ���λͼ
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, x2, y2);
	printf("%d\n%d\n", x2 - x1, y2 - y1);
	//system("pause");
	//������λͼѡ������豸����
	SelectObject(hCaptureDC, hCaptureBitmap);
	//��ȫ��Ļ����λͼ���������ݿ����������豸������
	BitBlt(hCaptureDC, 0, 0, x2 - x1, y2 - y1, hDesktopDC, x1, y1, SRCCOPY);
	BITMAPINFO    bi;
	void *pBits = NULL;
	ZeroMemory(&bi, sizeof(bi));
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biHeight = (y2 - y1);
	bi.bmiHeader.biWidth = (x2 - x1);
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 24;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 3 * (y2 - y1)*(x2 - x1);
	//����λͼ�����豸������
	//DECLARE_HANDLE(HDC);
	HDC        hBmpFileDC = CreateCompatibleDC(hDesktopDC);
	//����λͼ����λͼ  
	HBITMAP    hBmpFileBitmap = CreateDIBSection(hDesktopDC, &bi, DIB_RGB_COLORS, &pBits, NULL, 0);
	//������λͼѡ����豸���������豸������
	SelectObject(hBmpFileDC, hBmpFileBitmap);
	//�������λͼ�����ؿ�����λͼ�豸����
	BitBlt(hBmpFileDC, 0, 0, x2 - x1, y2 - y1, hCaptureDC, 0, 0, SRCCOPY);
	//�����ļ�    typedef void *HANDLE;
	HANDLE    hFile = CreateFile("c:\\VS2008\\666.bmp", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//����λͼ�ļ�
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwRet = 0;
		BITMAPFILEHEADER bmfHeader;
		ZeroMemory(&bmfHeader, sizeof(bmfHeader));
		bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
		bmfHeader.bfSize = bi.bmiHeader.biSizeImage + bmfHeader.bfOffBits;
		bmfHeader.bfType = 'MB';
		//д��λͼ��Ϣͷ
		WriteFile(hFile, &bmfHeader, sizeof(bmfHeader), &dwRet, NULL);
		//д��λͼ�ߴ���ɫ�����Ϣ
		WriteFile(hFile, &bi.bmiHeader, sizeof(bi.bmiHeader), &dwRet, NULL);
		//д��λͼ���ݿ�
		WriteFile(hFile, pBits, bi.bmiHeader.biSizeImage, &dwRet, NULL);
		CloseHandle(hFile);
	}
	DeleteDC(hBmpFileDC);
	DeleteObject(hBmpFileBitmap);
	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
	printf("��ͼ��ϣ��Ƿ��ӡ��(y/n)\n");
	
	while (1)
	{
		if (GetAsyncKeyState('Y'))
		{
			time = printimg("c:\\VS2008\\666.bmp");
			TCHAR over[256] = { 0 };
			wsprintf(over, _T("%s\n%s%u%s"), _T("��ӡ��ɣ�"), _T("��ʱ��"), time, _T("��"));
			MessageBox(0, over, _T("mission complete"), MB_OK);
			exit(1);
		}
		scanf("%c", &c);
		if (c == 'n')break;
	}
}

void printpos(int *x, int* y,int z)
{
	long zx = -1;
	long zy = -1;
	POINT ptB = { 0, 0 };
	/*
	typedef struct tagPOINT
	{
	LONG  x;
	LONG  y;
	} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;
	*/
	while (1)
	{
		LPPOINT xy = &ptB;  //λ�ñ���
		GetCursorPos(xy);   //��ȡ��굱ǰλ��
		//�������ƶ���������ǰ������ı����ӡ�����꣩��ӡ�������ꡣ
		if ((zx != xy->x) || (zy != xy->y))
		{
			Pos(0, z);
			printf("x=%4d,y=%4d\n", xy->x, xy->y);
			zx = xy->x;
			zy = xy->y;
		}
		if (GetAsyncKeyState(VK_F1))
		{
			
			CaptureScreen(0, 0, 1920, 1080);
			exit(0);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			*x = xy->x;
			*y = xy->y;
			break;
		}
	}
}

