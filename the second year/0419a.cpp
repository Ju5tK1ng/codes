/*-------------------------------------------------
   CHECKER1.C -- Mouse Hit-Test Demo Program No. 1
				 (c) Charles Petzold, 1998
  -------------------------------------------------*/

#include <windows.h>
#include<stdlib.h>
#define DIVISIONS 5

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR  szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("Rectangle Move!");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("Checker1 Mouse Hit-Test Demo"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static BOOL fState[DIVISIONS][DIVISIONS];
	static int  cxChar, cxCaps, cyChar, cxClient, cyClient;;
	TEXTMETRIC  tm;
	static char T;
	TCHAR       szBuffer[100];
	PAINTSTRUCT ps;

	RECT rctA;
	HDC         hdc;

	switch (message) {
	case WM_CREATE:
		GetWindowRect(hwnd, &rctA);
		cxClient = (rctA.right - rctA.left);
		cyClient = (rctA.bottom - rctA.top);
		hdc = BeginPaint(hwnd, &ps);

		T = 48 + rand() % (57-48);

		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
		cyChar = tm.tmHeight + tm.tmExternalLeading;

		EndPaint(hwnd, &ps);

		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		return 0;
	case WM_PAINT:
		hdc = GetDC(hwnd);

		wsprintf(szBuffer, TEXT("%C\n"), T);
		TextOut(hdc, cxClient/2 , cyClient/2, szBuffer, 1);
		
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_CHAR:
		//if(wParam==T)

		
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);
}

