#pragma once

#include "..\includes.h"

#define DKEY(VKNAME) if((GetAsyncKeyState((unsigned short)VKNAME)&0x8000)?1:0)

using namespace std;

#include "refresh.h"

#define DESKTOPCOLOR ((COLORREF)(((BYTE)(0)|((WORD)((BYTE)(128))<<8))|(((DWORD)(BYTE)(128))<<16)))


//This version is graphics for Power System Insider Team(PSIT)
//Version 1.0.2022.7.27.12.08
//Add:
//1.Minimized

; namespace guide
{
	/*
	int wgmain(HWND winhwnd, LPCWSTR wintitle)
	{
		ExMessage msg;
		winhwnd = initgraph(graphx,graphy, EW_SHOWCONSOLE);

		LONG l_WinStyle = GetWindowLong(winhwnd, GWL_STYLE);
		SetWindowLong(winhwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
		setbkcolor(DESKTOPCOLOR);
		cleardevice();
		BOOLLAY func;
		setbkmode(TRANSPARENT);
		addwindow(L"Main", mkrect(15, 15, 500, 500));
		drawwindow(1);
		drawtoolbar(1);
		drawtitle(1);
		settextstyle(30, 0, L"Moder DOS 437");
		outtext(24, 0, L"Moder DOS 437", L"Hello Graphics World!", 15, 25, 1,0, 0x000000);
		while (true)
		{
			getmessage(&msg);
			scanbulider(CLOSE, msg, 1);
			func=scanbulider(2, msg, 1);
			if (func.stat == true && func.success == true)
			{
				outtext(48, 0, L"Moder DOS 437", L"Hello Graphics World!", 15, 25, 1,0, 0x000000);
				drawtoolbar(1);
			}
			else if (func.stat == false && func.success == true)
			{
				outtext(24, 0, L"Moder DOS 437", L"Hello Graphics World!", 15, 25, 1,0, 0x000000);
				drawtoolbar(1);
			}
			scanbulider(3, msg, 1);
		keybd:
			DKEY(VK_ESCAPE)
			{
				closegraph();
				return 0;
			}
			DKEY(VK_F2)
			{
				closegraph();
				wgmain(guidehwnd, L"Graphics");
			}
			DKEY('R')
			{
				AddWindowA(L"Main", mkrect(15, 15, 500, 500),1);
				drawwindow(1);
				drawtoolbar(1);
				drawtitle(1);
				settextstyle(30, 0, L"Moder DOS 437");
				outtext(24, 0, L"Moder DOS 437", L"Hello Graphics World!", 15, 25, 1, 0, 0x000000);
			}
		}
		closegraph();
	}
	*/
	int gmain(HWND winhwnd, LPCWSTR wintitle)
	{
		REMDO;
		return 0;
	}
}
