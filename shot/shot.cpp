//#include <windows.h>
////#include "resource.h"
////#include <afx.h>
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);        //声明用来处理消息的函数
//HBITMAP CaptureScreen(LPRECT);
//BOOL SaveBmp(HBITMAP, const char*);
//HINSTANCE g_hInstance;
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//{
//	static TCHAR szAppName[] = TEXT("MyWindow");
//	HWND hwnd;
//	MSG msg;
//	WNDCLASS wndclass;        //声明一个窗口类对象
//
//	HMENU hMenu = CreateMenu();
//	HMENU hMenuPopup = CreateMenu();
//	AppendMenu(hMenuPopup, MF_STRING, 100, "截屏");
//	AppendMenu(hMenuPopup, MF_STRING, 101, "另存为");
//	AppendMenu(hMenuPopup, MF_STRING, 103, "延时3秒并截屏");
//	AppendMenu(hMenu, MF_POPUP, (ULONG_PTR)hMenuPopup, "截屏");
//	//以下为窗口类对象wndclass的属性
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;                         //窗口样式
//	wndclass.lpszClassName = szAppName;                               //窗口类名
//	wndclass.lpszMenuName = NULL;                                     //窗口菜单:无
//	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //窗口背景颜色
//	wndclass.lpfnWndProc = WndProc;                                   //窗口处理函数
//	wndclass.cbWndExtra = 0;                                          //窗口实例扩展:无
//	wndclass.cbClsExtra = 0;                                          //窗口类扩展:无
//	wndclass.hInstance = hInstance;                                   //窗口实例句柄
//	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(10000));               //窗口最小化图标:使用缺省图标
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //窗口采用箭头光标
//
//	if (!RegisterClass(&wndclass))
//	{    //注册窗口类, 如果注册失败弹出错误提示
//		MessageBox(NULL, TEXT("窗口注册失败!"), TEXT("错误"), MB_OK | MB_ICONERROR);
//		return 0;
//	}
//
//	hwnd = CreateWindow(                   //创建窗口
//		szAppName,                 //窗口类名
//		TEXT("截图工具"),           //窗口标题
//		WS_OVERLAPPEDWINDOW,       //窗口的风格
//		CW_USEDEFAULT,             //窗口初始显示位置x:使用缺省值
//		CW_USEDEFAULT,             //窗口初始显示位置y:使用缺省值
//		400,             //窗口的宽度:使用缺省值
//		100,             //窗口的高度:使用缺省值
//		NULL,                      //父窗口:无
//		hMenu,                      //子菜单:无
//		hInstance,                 //该窗口应用程序的实例句柄 
//		NULL                       //
//		);
//	g_hInstance = hInstance;
//	ShowWindow(hwnd, iCmdShow);        //显示窗口
//	UpdateWindow(hwnd);                //更新窗口
//
//	while (GetMessage(&msg, NULL, 0, 0))        //从消息队列中获取消息
//	{
//		TranslateMessage(&msg);                 //将虚拟键消息转换为字符消息
//		DispatchMessage(&msg);                  //分发到回调函数(过程函数)
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
//	switch (message)        //处理得到的消息
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
//			MessageBox(hwnd, "已经成功截图", "提醒", MB_OK | MB_ICONINFORMATION);
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
//			MessageBox(hwnd, "已经成功截图", "提醒", MB_OK );
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
//HBITMAP CaptureScreen(LPRECT lpRect)//lpRect为NULL时表示全屏幕截图
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
//	//当前分辨率下每象素所占字节数       
//	int     iBits;
//	//位图中每象素所占字节数       
//	WORD     wBitCount;
//	//定义调色板大小，     位图中像素字节大小     ，位图文件大小     ，     写入文件字节数           
//	DWORD     dwPaletteSize = 0, dwBmBitsSize = 0, dwDIBSize = 0, dwWritten = 0;
//	//位图属性结构           
//	BITMAP     Bitmap;
//	//位图文件头结构       
//	BITMAPFILEHEADER     bmfHdr;
//	//位图信息头结构           
//	BITMAPINFOHEADER     bi;
//	//指向位图信息头结构               
//	LPBITMAPINFOHEADER     lpbi;
//	//定义文件，分配内存句柄，调色板句柄           
//	HANDLE     fh, hDib, hPal, hOldPal = NULL;
//
//	//计算位图文件每个像素所占字节数           
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
//	//为位图内容分配内存           
//	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
//	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
//	*lpbi = bi;
//
//	//     处理调色板               
//	hPal = GetStockObject(DEFAULT_PALETTE);
//	if (hPal)
//	{
//		hDC = GetDC(NULL);
//		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE);
//		RealizePalette(hDC);
//	}
//
//	//     获取该调色板下新的像素值           
//	GetDIBits(hDC,
//		hBitmap,
//		0,
//		(UINT)Bitmap.bmHeight,
//		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER)+dwPaletteSize,
//		(BITMAPINFO *)lpbi,
//		DIB_RGB_COLORS);
//
//	//恢复调色板               
//	if (hOldPal)
//	{
//		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
//		RealizePalette(hDC);
//		ReleaseDC(NULL, hDC);
//	}
//
//	//创建位图文件               
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
//	//     设置位图文件头           
//	bmfHdr.bfType = 0x4D42;     //     "BM"           
//	dwDIBSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+dwPaletteSize + dwBmBitsSize;
//	bmfHdr.bfSize = dwDIBSize;
//	bmfHdr.bfReserved1 = 0;
//	bmfHdr.bfReserved2 = 0;
//	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER)+dwPaletteSize;
//	//     写入位图文件头           
//	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
//	//     写入位图文件其余内容           
//	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);
//	//清除               
//	GlobalUnlock(hDib);
//	GlobalFree(hDib);
//	CloseHandle(fh);
//
//	return     TRUE;
//}