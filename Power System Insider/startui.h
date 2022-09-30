#pragma once

#include "runtime/HiEasyX.h"
#include "includes.h"

void Blur(DWORD*);

using namespace std;


RECT makerect(LONG left, LONG top, LONG right, LONG bottom)
{
	RECT ret = { left,top,right,bottom };
	return ret;
}

string _copy_base64encode_t(string ff, unsigned long long num)
{
	string endval = base64_encode(ff);
	for (int i = 0; i < num; i++)
	{
		endval = base64_encode(endval);
	}
	return endval;
}


string getusername, getpin;


#undef initgraph
#undef closegraph
#undef getmessage

int startUI()
{
	initgraph(1280, 720);
	IMAGE img, blurimg;
	loadimage(&img, L".\\image\\start.pic");
	loadimage(&blurimg, L".\\image\\startblur.pic");
	DWORD _imgbuf;
	ExMessage msg;
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 96;
	_tcscpy(f.lfFaceName, _T("Segoe UI"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	time_t t;
	tm* ss;
	time(&t);
	ss = localtime(&t);
	putimage(0, 0, &img);
	while (1)
	{
		time(&t);
		ss = localtime(&t);
		getmessage(&msg);

		if (msg.lbutton)
			break;
		else
		{
			cleardevice();
			putimage(0, 0, &img);
			outtextxy(550, 100, (wstring(to_wstring(ss->tm_hour)) + L':' + to_wstring(ss->tm_min)).c_str());
		}
		Sleep(30);
	}
	cleardevice();
	Blur(GetImageBuffer());
	closegraph();
	hiex::Window Wnd;
	Wnd.Create(1280, 720, 0, L"Type Pin !");
	fstream fs;
	fs.open(".\\data\\pin", ios::in);
	getline(fs, getpin);
	fs.close();
	fs.clear();
	fs.open(".\\data\\username", ios::in);
	getline(fs, getusername);
	fs.close();
	fs.clear();
	hiex::SysEdit syb;
	hiex::SysButton sycb;
	syb.PreSetStyle(false, false, false, false, false, true);
	syb.SetFont(20, 0, L"Segoe UI");
	sycb.SetFont(20, 0, L"Segoe UI");
	syb.Create(Wnd.GetHandle(), makerect(490, 360, 830, 390), L"");
	sycb.Create(Wnd.GetHandle(), makerect
	(
		830, 360, 860, 390
	), L"\x2192");
	gettextstyle(&f);
	f.lfHeight = 20;
	_tcscpy(f.lfFaceName, _T("Segoe UI"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	outtextxy(550, 300, (wchar*)(bstr_t)(getusername.c_str()));
	while (1)
	{
		if (getpin == "NULL")
			break;
		else
		{
			while (1)
			{
				putimage(0, 0, &blurimg);
				if (sycb.isClicked())
				{
					if (_copy_base64encode_t((CHAR*)(bstr_t)(syb.GetText().c_str()), LOCKNUM) == getpin.c_str())
					{
						hiex::closegraph_win32(Wnd.GetHandle());
						return 0;
					}
					else
					{
						MessageBox(NULL, L"Invalid PIN", L"Power System", MB_OK);
					}
				}
			}
		}
	}
	hiex::closegraph_win32(Wnd.GetHandle());
	return 0;
}