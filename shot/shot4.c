#include <stdio.h>
#include <stdlib.h>
#include <wtypes.h>
#include <tchar.h>
#include<math.h>
#include<time.h>
//���ô�ӡλ��
void CaptureScreen(int x1, int y1, int x2, int y2)
{
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
	BitBlt(hCaptureDC,  0, 0, x2-x1, y2-y1, hDesktopDC, x1, y1, SRCCOPY);
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
	HANDLE    hFile = CreateFile("g:/VS2008/666.bmp", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
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
}
void Pos(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
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
			printf("x=%4d,y=%4d\n", xy->x*1920/1536, xy->y*1080/864);
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
			*x = xy->x*1920/1536;
			*y = xy->y*1080/864;
			break;
		}
	}
}

int main()
{
	int x1, x2, y1, y2;
	system("mode con cols=20 lines=10");
	Pos(0, 9);
	printf("����F1���ٽ�ȡȫ��\n");
	Pos(0, 0);
	printf("���¿ո�ѡȡ��ͼ���\n");
	printpos(&x1, &y1, 1);
	Sleep(300);
	printf("���¿ո�ѡȡ��ͼ�յ�\n");
	printpos(&x2, &y2, 3);
	CaptureScreen(x1,y1,x2,y2);
	return 0;
}