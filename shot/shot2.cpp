//#include <windows.h>  
//#include <stdio.h>  
//#include "resource.h"
//
//
//HINSTANCE g_hInstance = NULL;//ȫ�ֽ��̾��  
//HWND g_hwndMain = NULL;//ȫ�������ھ��  
//
//#define UM_SCREENCUT    WM_USER+1  
//#define UM_CUTSUCCESS   WM_USER+2  
//
//INT_PTR CALLBACK MyDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
//INT_PTR CALLBACK MyScreenCutProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
////Win��������  
//WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
//{
//	g_hInstance = hInstance;
//	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), (HWND)NULL, MyDialogProc);//�Ի���ģ̬��ʾ  
//	return 0;
//}
//
////��������ť  
//void EnableButtons(HWND hwndDlg, BOOL flag, int num, ...)
//{
//	int i = 0;
//	int iButton = 0;
//	va_list var_arg;
//	va_start(var_arg, num);
//	for (; i < num; i++)
//	{
//		iButton = va_arg(var_arg, int);
//		EnableWindow(GetDlgItem(hwndDlg, iButton), flag);
//	}
//	va_end(var_arg);
//}
//
////�����ͼͼƬ  
//BOOL SavePicture(HBITMAP hbitmap, TCHAR* filepath)
//{
//	HDC hdc = GetDC(NULL);
//	BITMAP bitmap = { 0 };
//	WORD clrbits = 0;
//	BITMAPINFO* bitmapinfo = NULL;
//	BITMAPFILEHEADER fileheader;
//	DWORD temp;
//	void* buf = NULL;
//	FILE* fp = NULL;
//
//	GetObject(hbitmap, sizeof(BITMAP), &bitmap);
//	clrbits = bitmap.bmBitsPixel * bitmap.bmPlanes;//ÿ�����ɫλ��*ƽ����  
//	if (clrbits == 1);
//	else if (clrbits <= 4) clrbits = 4;
//	else if (clrbits <= 8) clrbits = 8;
//	else if (clrbits <= 16) clrbits = 16;
//	else if (clrbits <= 24) clrbits = 24;
//	else clrbits = 32;
//
//	if (clrbits < 24)//24λ������Ҫ��ɫ��  
//		bitmapinfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*(1 << clrbits));
//	else
//		bitmapinfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD));
//
//	bitmapinfo->bmiHeader.biBitCount = clrbits;//ͼ����ɫλ��  
//	bitmapinfo->bmiHeader.biClrImportant = 0;
//	bitmapinfo->bmiHeader.biClrUsed = (clrbits<24) ? (1 << clrbits) : 0;//ʹ�õ���ɫ��  
//	bitmapinfo->bmiHeader.biCompression = BI_RGB;//ѹ����ʽ,BI_RGB��ѹ��  
//	bitmapinfo->bmiHeader.biHeight = bitmap.bmHeight;//λͼ�߶�  
//	bitmapinfo->bmiHeader.biPlanes = bitmap.bmPlanes;//�豸ƽ����  
//	bitmapinfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//BITMAPINFOHEADER�ṹ���С  
//	bitmapinfo->bmiHeader.biSizeImage = (bitmap.bmWidth * clrbits + 31) / 32 * 4 * bitmap.bmHeight;//λͼ���ݴ�С  
//	bitmapinfo->bmiHeader.biWidth = bitmap.bmWidth;//λͼ���  
//	bitmapinfo->bmiHeader.biXPelsPerMeter = bitmapinfo->bmiHeader.biYPelsPerMeter = 0;
//
//	fileheader.bfType = 0x4d42;
//	fileheader.bfSize = sizeof(BITMAPFILEHEADER)+bitmapinfo->bmiHeader.biSize +
//		sizeof(RGBQUAD)*(bitmapinfo->bmiHeader.biClrUsed == 0 ? 0 : bitmapinfo->bmiHeader.biClrUsed)
//		+ bitmapinfo->bmiHeader.biSizeImage;
//	fileheader.bfReserved1 = fileheader.bfReserved2 = 0;
//	fileheader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+
//		sizeof(RGBQUAD)*(bitmapinfo->bmiHeader.biClrUsed == 0 ? 0 : bitmapinfo->bmiHeader.biClrUsed);
//
//	buf = malloc(bitmapinfo->bmiHeader.biSizeImage);
//	GetDIBits(hdc, hbitmap, 0, bitmap.bmHeight, buf, bitmapinfo, DIB_RGB_COLORS);
//
//	fp = _wfopen(filepath, TEXT("wb"));
//	fwrite(&fileheader, sizeof(BITMAPFILEHEADER), 1, fp);
//	fwrite(bitmapinfo, sizeof(BITMAPINFO), 1, fp);
//	fwrite(buf, bitmapinfo->bmiHeader.biSizeImage, 1, fp);
//	fclose(fp);
//
//	ReleaseDC(NULL, hdc);
//}
//
////���Ի���ص�����  
//INT_PTR CALLBACK MyDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	BOOL bRet = TRUE;//Ĭ���Ѵ���  
//	RECT rWindow = { 0 };//���ڴ�С����  
//	int iXscreen = 0;//��Ļ���  
//	static HWND hScreenCut = NULL;//��ͼ���ھ��  
//	HICON hicon = NULL;
//	HBITMAP hbitmap = NULL;//������ȡ���а��е�HBITMAP  
//	BITMAP bm = { 0 };
//	HDC hdc = NULL;
//	HDC hdc2 = NULL;
//
//	switch (uMsg)
//	{
//	case WM_CLOSE:
//		SendMessage(hwndDlg, WM_COMMAND, MAKEWPARAM(IDC_BUTTON_CANCEL, 0), 0);
//		EndDialog(hwndDlg, 0);
//		break;
//	case WM_INITDIALOG://û��WM_CREATE  
//		g_hwndMain = hwndDlg;
//		hicon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPICON));
//		if (hicon)
//		{
//			SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hicon);//�޸ĳ���ͼ��  
//			SendMessage(hwndDlg, WM_SETICON, ICON_BIG, (LPARAM)hicon);
//			FreeResource(hicon);
//		}
//		EnableButtons(hwndDlg, TRUE, 1, IDC_BUTTON_START);
//		EnableButtons(hwndDlg, FALSE, 4, IDC_BUTTON_CUT, IDC_BUTTON_RESTART, IDC_BUTTON_SAVE, IDC_BUTTON_CANCEL);
//		iXscreen = GetSystemMetrics(SM_CXSCREEN);
//		GetWindowRect(hwndDlg, &rWindow);
//		MoveWindow(hwndDlg, iXscreen - rWindow.right - 50, 50, rWindow.right - rWindow.left, rWindow.bottom - rWindow.top, TRUE);
//		break;
//	case UM_CUTSUCCESS://��ͼ�ɹ�  
//		SendMessage(hwndDlg, WM_COMMAND, MAKEWPARAM(IDC_BUTTON_CANCEL, 0), 0);
//		EnableButtons(hwndDlg, TRUE, 1, IDC_BUTTON_SAVE);
//		break;
//	case WM_COMMAND://�Ӵ��ڿؼ��������ڷ��͵���Ϣ  
//		switch (LOWORD(wParam))//LOWORD(wParam)�ؼ�ID  
//		{
//		case IDC_BUTTON_START://start  
//			if (hScreenCut)
//			{
//				DestroyWindow(hScreenCut);
//				hScreenCut = NULL;
//			}
//			hScreenCut = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG_SCREENCUT), NULL, MyScreenCutProc);//���︸���ھ������ΪNULL  
//			if (hScreenCut)
//			{
//				ShowWindow(hScreenCut, SW_SHOW);
//				EnableButtons(hwndDlg, TRUE, 2, IDC_BUTTON_RESTART, IDC_BUTTON_CANCEL);
//				EnableButtons(hwndDlg, FALSE, 3, IDC_BUTTON_START, IDC_BUTTON_CUT, IDC_BUTTON_SAVE);
//				/*SetWindowPos(hwndDlg,HWND_TOP,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);*/
//			}
//			break;
//		case IDC_BUTTON_RESTART:
//		case IDC_BUTTON_CANCEL://cancel  
//			if (hScreenCut)
//			{
//				DestroyWindow(hScreenCut);
//				hScreenCut = NULL;
//			}
//			EnableButtons(hwndDlg, TRUE, 1, IDC_BUTTON_START);
//			EnableButtons(hwndDlg, FALSE, 4, IDC_BUTTON_CUT, IDC_BUTTON_RESTART, IDC_BUTTON_SAVE, IDC_BUTTON_CANCEL);
//			if (IDC_BUTTON_RESTART == LOWORD(wParam))
//			{
//				SendMessage(hwndDlg, WM_COMMAND, MAKEWPARAM(IDC_BUTTON_START, 0), 0);
//			}
//			break;
//		case IDC_BUTTON_SAVE:
//			if (IsClipboardFormatAvailable(CF_BITMAP))
//			{
//				if (OpenClipboard(hwndDlg))
//				{
//					hbitmap = GetClipboardData(CF_BITMAP);
//					SavePicture(hbitmap, TEXT("hello.bmp"));
//					CloseClipboard();
//				}
//			}
//			break;
//		case IDC_BUTTON_CUT:
//			SendMessage(hScreenCut, UM_SCREENCUT, 0, 0);
//			break;
//		default:
//			bRet = FALSE;
//			break;
//		}
//		break;
//	default:
//		bRet = FALSE;
//		break;
//	}
//
//	return bRet;
//}
//
////��ͼ�Ի���ص�����  
//INT_PTR CALLBACK MyScreenCutProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	BOOL bRet = TRUE;//Ĭ�ϱ��TRUE��ʾ�Ѵ�����Ϣ  
//	HDC ScreenDC = NULL;//��ĻDC  
//	static HDC MemDC = NULL;//�ڴ�DC  
//	HDC ClientDC = NULL;//����DC  
//	static HBRUSH hbrush = NULL;
//	static int iXscreen = 0;//��Ļ���  
//	static int iYscreen = 0;//��Ļ�߶�  
//	static RECT RectCut = { 0 };//��ͼ����  
//	static POINT PointOrg = { 0 };//ԭ��  
//	int temp = 0;
//
//	int width = 0;
//	int height = 0;
//	HDC CutDC = NULL;
//	HBITMAP hbitmap = NULL, hbitmap2 = NULL;
//	BITMAP bm;//ͼ����Ϣ  
//
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//		ScreenDC = GetDC(NULL);
//		if (!ScreenDC)
//		{
//			DestroyWindow(hwndDlg);
//			break;
//		}
//		iXscreen = GetSystemMetrics(SM_CXSCREEN);
//		iYscreen = GetSystemMetrics(SM_CYSCREEN);
//		MemDC = CreateCompatibleDC(ScreenDC);
//		hbitmap = CreateCompatibleBitmap(ScreenDC, iXscreen, iYscreen);
//		if (!MemDC || !hbitmap)
//		{
//			DeleteObject(hbitmap);
//			hbitmap = NULL;
//			ReleaseDC(hwndDlg, ScreenDC);
//			DestroyWindow(hwndDlg);
//			break;
//		}
//		SelectObject(MemDC, hbitmap);
//		BitBlt(MemDC, 0, 0, iXscreen, iYscreen, ScreenDC, 0, 0, SRCCOPY);
//		DeleteObject(hbitmap);
//		hbitmap = NULL;
//		ReleaseDC(hwndDlg, ScreenDC);
//		hbrush = CreateSolidBrush(RGB(255, 0, 0));
//		/*SendMessage(hwndDlg,WM_SYSCOMMAND,SC_MAXIMIZE,0);*/
//		MoveWindow(hwndDlg, 0, 0, iXscreen, iYscreen, FALSE);
//		break;
//	case WM_PAINT:
//		if (MemDC)
//		{
//			if (ClientDC = GetDC(hwndDlg))
//			{
//				BitBlt(ClientDC, 0, 0, iXscreen, iYscreen, MemDC, 0, 0, SRCCOPY);
//				if (!IsRectEmpty(&RectCut))//IsRectEmpty�����εĿ�Ȼ�߶ȵ���0��С��0����գ�  
//				{
//					FrameRect(ClientDC, &RectCut, hbrush ? hbrush : GetStockObject(BLACK_BRUSH));
//					EnableButtons(g_hwndMain, TRUE, 1, IDC_BUTTON_CUT);
//				}
//				else
//				{
//					EnableButtons(g_hwndMain, FALSE, 1, IDC_BUTTON_CUT);
//				}
//				ReleaseDC(hwndDlg, ClientDC);
//				ClientDC = NULL;
//				break;
//			}
//		}
//		break;
//	case WM_LBUTTONDOWN://WM_LBUTTONDOWN��Ϣ��LOWORD(lParam)������x����(�ͻ�����),HIWORD(lParam)������y����(�ͻ�����)  
//		RectCut.left = RectCut.right = LOWORD(lParam);
//		RectCut.top = RectCut.bottom = HIWORD(lParam);
//		PointOrg.x = RectCut.left;
//		PointOrg.y = RectCut.top;
//		EnableButtons(g_hwndMain, FALSE, 1, IDC_BUTTON_CUT);
//		break;
//	case WM_MOUSEMOVE:
//		if (MK_LBUTTON & wParam)//WM_MOUSEMOVE��Ϣ��wParam������һЩ״̬���  
//		{
//			if (PointOrg.x > LOWORD(lParam))
//			{
//				RectCut.left = LOWORD(lParam);
//				RectCut.right = PointOrg.x;
//			}
//			else
//			{
//				RectCut.left = PointOrg.x;
//				RectCut.right = LOWORD(lParam);
//			}
//			if (PointOrg.y > HIWORD(lParam))
//			{
//				RectCut.top = HIWORD(lParam);
//				RectCut.bottom = PointOrg.y;
//			}
//			else
//			{
//				RectCut.top = PointOrg.y;
//				RectCut.bottom = HIWORD(lParam);
//			}
//		}
//		break;
//	case UM_SCREENCUT:
//		width = RectCut.right - RectCut.left;
//		height = RectCut.bottom - RectCut.top;
//		CutDC = CreateCompatibleDC(MemDC);
//		hbitmap = CreateCompatibleBitmap(MemDC, width, height);
//		SelectObject(CutDC, hbitmap);
//		BitBlt(CutDC, 0, 0, width, height, MemDC, RectCut.left, RectCut.top, SRCCOPY);
//		if (OpenClipboard(hwndDlg))
//		{
//			EmptyClipboard();
//			SetClipboardData(CF_BITMAP, hbitmap);
//			CloseClipboard();
//			PlaySound(TEXT("kd.wav"), g_hInstance, SND_FILENAME | SND_ASYNC);
//			SendMessage(g_hwndMain, UM_CUTSUCCESS, 0, 0);
//		}
//		DeleteObject(hbitmap);
//		DeleteDC(CutDC);
//		break;
//	case WM_KEYDOWN:
//		if (wParam == VK_ESCAPE)//ESC  
//		{
//			SendMessage(g_hwndMain, WM_COMMAND, MAKEWPARAM(IDC_BUTTON_CANCEL, 0), 0);
//		}
//		break;
//	case WM_DESTROY:
//		if (MemDC)
//		{
//			DeleteDC(MemDC);
//			MemDC = NULL;
//		}
//		SetRectEmpty(&RectCut);
//		PointOrg.x = PointOrg.y = 0;
//		break;
//	default:
//		bRet = FALSE;
//		break;
//	}
//
//	return bRet;
//}