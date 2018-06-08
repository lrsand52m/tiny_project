//#include <windows.h>
////#include "resource.h"
////#include <afx.h>
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);        //��������������Ϣ�ĺ���
//HBITMAP CaptureScreen(LPRECT);
//BOOL SaveBmp(HBITMAP, const char*);
//HINSTANCE g_hInstance;
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//{
//	static TCHAR szAppName[] = TEXT("MyWindow");
//	HWND hwnd;
//	MSG msg;
//	WNDCLASS wndclass;        //����һ�����������
//
//	HMENU hMenu = CreateMenu();
//	HMENU hMenuPopup = CreateMenu();
//	AppendMenu(hMenuPopup, MF_STRING, 100, "����");
//	AppendMenu(hMenuPopup, MF_STRING, 101, "���Ϊ");
//	AppendMenu(hMenuPopup, MF_STRING, 103, "��ʱ3�벢����");
//	AppendMenu(hMenu, MF_POPUP, (ULONG_PTR)hMenuPopup, "����");
//	//����Ϊ���������wndclass������
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;                         //������ʽ
//	wndclass.lpszClassName = szAppName;                               //��������
//	wndclass.lpszMenuName = NULL;                                     //���ڲ˵�:��
//	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //���ڱ�����ɫ
//	wndclass.lpfnWndProc = WndProc;                                   //���ڴ�����
//	wndclass.cbWndExtra = 0;                                          //����ʵ����չ:��
//	wndclass.cbClsExtra = 0;                                          //��������չ:��
//	wndclass.hInstance = hInstance;                                   //����ʵ�����
//	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(10000));               //������С��ͼ��:ʹ��ȱʡͼ��
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //���ڲ��ü�ͷ���
//
//	if (!RegisterClass(&wndclass))
//	{    //ע�ᴰ����, ���ע��ʧ�ܵ���������ʾ
//		MessageBox(NULL, TEXT("����ע��ʧ��!"), TEXT("����"), MB_OK | MB_ICONERROR);
//		return 0;
//	}
//
//	hwnd = CreateWindow(                   //��������
//		szAppName,                 //��������
//		TEXT("��ͼ����"),           //���ڱ���
//		WS_OVERLAPPEDWINDOW,       //���ڵķ��
//		CW_USEDEFAULT,             //���ڳ�ʼ��ʾλ��x:ʹ��ȱʡֵ
//		CW_USEDEFAULT,             //���ڳ�ʼ��ʾλ��y:ʹ��ȱʡֵ
//		400,             //���ڵĿ��:ʹ��ȱʡֵ
//		100,             //���ڵĸ߶�:ʹ��ȱʡֵ
//		NULL,                      //������:��
//		hMenu,                      //�Ӳ˵�:��
//		hInstance,                 //�ô���Ӧ�ó����ʵ����� 
//		NULL                       //
//		);
//	g_hInstance = hInstance;
//	ShowWindow(hwnd, iCmdShow);        //��ʾ����
//	UpdateWindow(hwnd);                //���´���
//
//	while (GetMessage(&msg, NULL, 0, 0))        //����Ϣ�����л�ȡ��Ϣ
//	{
//		TranslateMessage(&msg);                 //���������Ϣת��Ϊ�ַ���Ϣ
//		DispatchMessage(&msg);                  //�ַ����ص�����(���̺���)
//	}
//	return msg.wParam;
//}
//
//long CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc, hdcMem;
//	static RECT rect;
//	static HBITMAP hBitmap;
//	static int cx, cy;
//	BITMAP bitmap;
//	static OPENFILENAME ofn;
//	static TCHAR szBuffer[1000] = "";
//	static LONG xPos, yPos;
//	PAINTSTRUCT ps;
//	ofn.lStructSize = sizeof(OPENFILENAME);
//	ofn.lpstrFilter = "bmp";
//	ofn.lpstrInitialDir = NULL;
//	ofn.lpstrFile = szBuffer;
//	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
//	ofn.nFilterIndex = 0;
//	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
//
//	switch (message)        //����õ�����Ϣ
//	{
//	case WM_COMMAND:
//
//		switch (LOWORD(wParam))
//		{
//		case 100:
//			SetCursor(LoadCursor(g_hInstance, IDC_WAIT));
//			MoveWindow(hwnd, 0, 0, 0, 0, 0);
//			ShowWindow(hwnd, SW_HIDE);
//			hBitmap = CaptureScreen(NULL);
//			ShowWindow(hwnd, SW_SHOW);
//			SetCursor(LoadCursor(g_hInstance, IDC_ARROW));
//			MoveWindow(hwnd, 0, 0, 400, 100, 0);
//			MessageBox(hwnd, "�Ѿ��ɹ���ͼ", "����", MB_OK | MB_ICONINFORMATION);
//			if (!GetSaveFileName(&ofn))
//				return 0;
//			SaveBmp(hBitmap, szBuffer);
//			break;
//		case 101:
//			if (!GetSaveFileName(&ofn))
//				return 0;
//			SaveBmp(hBitmap, szBuffer);
//			break;
//		case 103:
//			Sleep(3000);
//			SetCursor(LoadCursor(g_hInstance, IDC_WAIT));
//			ShowWindow(hwnd, SW_HIDE);
//			hBitmap = CaptureScreen(NULL);
//			ShowWindow(hwnd, SW_SHOW);
//			SetCursor(LoadCursor(g_hInstance, IDC_ARROW));
//			MessageBox(hwnd, "�Ѿ��ɹ���ͼ", "����", MB_OK );
//			if (!GetSaveFileName(&ofn))
//				return 0;
//			SaveBmp(hBitmap, szBuffer);
//		}
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		hdcMem = CreateCompatibleDC(hdc);
//		SelectObject(hdcMem, hBitmap);
//		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
//		cx = bitmap.bmWidth;
//		cy = bitmap.bmHeight;
//		BitBlt(hdcMem, 10, 10, cx, cy, hdc, 0, 0, SRCCOPY);
//		EndPaint(hwnd, &ps);
//		return 0;
//	case WM_DESTROY:
//		DeleteObject(hBitmap);
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hwnd, message, wParam, lParam);
//}
//
//#ifndef CAPTUREBLT
//#define CAPTUREBLT 0x40000000
//#endif
//HBITMAP CaptureScreen(LPRECT lpRect)//lpRectΪNULLʱ��ʾȫ��Ļ��ͼ
//{
//	Sleep(1000);
//	HDC      hdc, hdcMem;
//	HBITMAP  hemfCopy;
//	HWND     hwndScr;
//	int      dstcx, dstcy;
//	if (lpRect)
//	{
//		dstcx = lpRect->right - lpRect->left;
//		dstcy = lpRect->bottom - lpRect->top;
//	}
//	else
//	{
//		dstcx = GetSystemMetrics(SM_CXSCREEN);
//		dstcy = GetSystemMetrics(SM_CYSCREEN);
//	}
//	if (LockWindowUpdate(hwndScr = GetDesktopWindow()))
//	{
//		hdc = GetDCEx(hwndScr, NULL, DCX_CACHE | DCX_LOCKWINDOWUPDATE);
//		hdcMem = CreateCompatibleDC(hdc);
//		if (NULL == hdcMem)
//		{
//			ReleaseDC(hwndScr, hdc);
//			LockWindowUpdate(NULL);
//			return NULL;
//		}
//		hemfCopy = CreateCompatibleBitmap(hdc, abs(dstcx), abs(dstcy));
//		if (NULL == hemfCopy)
//		{
//			DeleteDC(hdcMem);
//			ReleaseDC(hwndScr, hdc);
//			LockWindowUpdate(NULL);
//			return NULL;
//		}
//		SelectObject(hdcMem, hemfCopy);
//		if (lpRect)
//			StretchBlt(hdcMem, 0, 0, abs(dstcx), abs(dstcy),
//			hdc, lpRect->left, lpRect->top, dstcx, dstcy, SRCCOPY | CAPTUREBLT);
//		else
//			BitBlt(hdcMem, 0, 0, dstcx, dstcy,
//			hdc, 0, 0, SRCCOPY | CAPTUREBLT);
//		DeleteDC(hdcMem);
//		ReleaseDC(hwndScr, hdc);
//		LockWindowUpdate(NULL);
//		return hemfCopy;
//	}
//	return NULL;
//}
//
//BOOL SaveBmp(HBITMAP hBitmap, const char *FileName)
//{
//	HDC     hDC;
//	//��ǰ�ֱ�����ÿ������ռ�ֽ���       
//	int     iBits;
//	//λͼ��ÿ������ռ�ֽ���       
//	WORD     wBitCount;
//	//�����ɫ���С��     λͼ�������ֽڴ�С     ��λͼ�ļ���С     ��     д���ļ��ֽ���           
//	DWORD     dwPaletteSize = 0, dwBmBitsSize = 0, dwDIBSize = 0, dwWritten = 0;
//	//λͼ���Խṹ           
//	BITMAP     Bitmap;
//	//λͼ�ļ�ͷ�ṹ       
//	BITMAPFILEHEADER     bmfHdr;
//	//λͼ��Ϣͷ�ṹ           
//	BITMAPINFOHEADER     bi;
//	//ָ��λͼ��Ϣͷ�ṹ               
//	LPBITMAPINFOHEADER     lpbi;
//	//�����ļ��������ڴ�������ɫ����           
//	HANDLE     fh, hDib, hPal, hOldPal = NULL;
//
//	//����λͼ�ļ�ÿ��������ռ�ֽ���           
//	hDC = CreateDC("DISPLAY", NULL, NULL, NULL);
//	iBits = GetDeviceCaps(hDC, BITSPIXEL) *GetDeviceCaps(hDC, PLANES);
//	DeleteDC(hDC);
//	if (iBits <= 1)
//	{
//		wBitCount = 1;
//	}
//	else if (iBits <= 4)
//	{
//		wBitCount = 4;
//	}
//	else if (iBits <= 8)
//	{
//		wBitCount = 8;
//	}
//	else
//	{
//		wBitCount = 24;
//	}
//
//	GetObject(hBitmap, sizeof(Bitmap), (LPSTR)&Bitmap);
//	bi.biSize = sizeof(BITMAPINFOHEADER);
//	bi.biWidth = Bitmap.bmWidth;
//	bi.biHeight = Bitmap.bmHeight;
//	bi.biPlanes = 1;
//	bi.biBitCount = wBitCount;
//	bi.biCompression = BI_RGB;
//	bi.biSizeImage = 0;
//	bi.biXPelsPerMeter = 0;
//	bi.biYPelsPerMeter = 0;
//	bi.biClrImportant = 0;
//	bi.biClrUsed = 0;
//
//	dwBmBitsSize = ((Bitmap.bmWidth     *     wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;
//
//	//Ϊλͼ���ݷ����ڴ�           
//	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
//	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
//	*lpbi = bi;
//
//	//     �����ɫ��               
//	hPal = GetStockObject(DEFAULT_PALETTE);
//	if (hPal)
//	{
//		hDC = GetDC(NULL);
//		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE);
//		RealizePalette(hDC);
//	}
//
//	//     ��ȡ�õ�ɫ�����µ�����ֵ           
//	GetDIBits(hDC,
//		hBitmap,
//		0,
//		(UINT)Bitmap.bmHeight,
//		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER)+dwPaletteSize,
//		(BITMAPINFO *)lpbi,
//		DIB_RGB_COLORS);
//
//	//�ָ���ɫ��               
//	if (hOldPal)
//	{
//		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
//		RealizePalette(hDC);
//		ReleaseDC(NULL, hDC);
//	}
//
//	//����λͼ�ļ�               
//	fh = CreateFile(FileName,
//		GENERIC_WRITE,
//		0,
//		NULL,
//		CREATE_ALWAYS,
//		FILE_ATTRIBUTE_NORMAL,
//		NULL);/*     FILE_FLAG_SEQUENTIAL_SCAN,     NULL);  */
//
//	if (fh == INVALID_HANDLE_VALUE)
//	{
//		return     FALSE;
//	}
//
//	//     ����λͼ�ļ�ͷ           
//	bmfHdr.bfType = 0x4D42;     //     "BM"           
//	dwDIBSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+dwPaletteSize + dwBmBitsSize;
//	bmfHdr.bfSize = dwDIBSize;
//	bmfHdr.bfReserved1 = 0;
//	bmfHdr.bfReserved2 = 0;
//	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER)+dwPaletteSize;
//	//     д��λͼ�ļ�ͷ           
//	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
//	//     д��λͼ�ļ���������           
//	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);
//	//���               
//	GlobalUnlock(hDib);
//	GlobalFree(hDib);
//	CloseHandle(fh);
//
//	return     TRUE;
//}