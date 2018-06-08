//#include <stdio.h>
//#include <stdlib.h>
//#include <wtypes.h>
//
//#ifndef CAPTUREBLT
//#define CAPTUREBLT 0x40000000
//#endif
//HBITMAP CaptureScreen(LPRECT lpRect)//lpRect为NULL时表示全屏幕截图
//{
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