#pragma once

#include "..\includes.h"

#define WINDOWREV RGB(207, 248, 249)
#define WINDOWTIT RGB(10, 49, 160)
#define WINDOWSPACE RGB(192, 192, 192)
#define TOOLBUTTONMAIN WINDOWSPACE
#define NOSELECT RGB(135, 136, 143)

#define MINIMIZED 3
#define MAXMIZED 2
#define CLOSE 1

#define setline(rgbhead,thinkness) setlinestyle(PS_SOLID,thinkness);setlinecolor(rgbhead)

#define getrect(pid) winrect[wintitle[pid-1]]
#define getrectfull(pid) getrect(pid).left,getrect(pid).top,getrect(pid).right,getrect(pid).bottom

#define BEGIN namespace guide
#define CLOSEWIN L"REMOVEDWIN"
#define addpid PID pid

typedef UINT PID;

#define IDEXIT 1
#define IDFULLSCREEN 2


#define gcls cleardevice();


typedef unsigned long long QWORD;

struct ExMessageX
{
	int x;
	int y;
	bool lbuttom;
	bool rbuttom;
	operator ExMessage() const
	{
		ExMessage ret;
		ret.lbutton = this->lbuttom;
		ret.rbutton = this->rbuttom;
		ret.x = this->x;
		ret.y = this->y;
		return ret;
	}
	void operator=(ExMessage msg)
	{
		this->x = msg.x;
		this->y = msg.y;
		this->lbuttom = msg.lbutton;
		this->rbuttom = msg.rbutton;
	}
	ExMessageX(ExMessage msg)
	{
		this->operator=(msg);
	}
};

struct GraphMouse
{
	int left;
	int top;
	int right;
	int bottom;
	bool lmouse;
	bool rmouse;
	bool operator==(ExMessageX mesg)
	{
		return (mesg.y > left && mesg.y < right&& mesg.lbuttom == rmouse && mesg.rbuttom == lmouse);
	}
};

struct BOOLLAY
{
	bool success;
	bool stat;
	BOOLLAY(bool suc)
	{
		this->success = suc;
	}
	BOOLLAY() {}
};

ExMessage mkexmsg(int x, int y, bool lbut, bool rbut)
{
	ExMessage ret;
	ret.lbutton = lbut;
	ret.rbutton = rbut;
	ret.x = x;
	ret.y = y;
	return ret;
}

namespace guide
{
	vector <wstring> wintitle;
#define winnum wintitle.size()
	map<wstring, RECT> winrect;
	map<wstring, RECT> origrect;
	map<wstring, bool, less<wstring>, allocator<pair<const wstring, bool> > > full;
	map<wstring, bool, less<wstring>, allocator<pair<const wstring, bool> > > sview;
	UINT iter;
	void forcerect(addpid)
	{
		origrect[wintitle[pid - 1]] = getrect(pid);
	}
	void drawwindow(UINT pid)
	{
		switch (sview[wintitle[pid - 1]])
		{
			case false:
			{
				if (wintitle[pid - 1] == L"REMOVEDWIN")
				{
					return;
				}
				setlinestyle(0, 2);
				setline(WINDOWREV, 2);
				rectangle
				(
					winrect[wintitle[pid - 1]].left,
					winrect[wintitle[pid - 1]].top,
					winrect[wintitle[pid - 1]].right,
					winrect[wintitle[pid - 1]].bottom
				);
				setfillcolor(WINDOWTIT);
				solidrectangle(getrect(pid).left + 2, getrect(pid).top + 1, getrect(pid).right - 2, getrect(pid).top + 20);
				setfillcolor(WINDOWSPACE);
				solidrectangle(getrect(pid).left + 2, getrect(pid).top + 21, getrect(pid).right - 2, getrect(pid).bottom - 2);
			}
			case true:
			{
				return;
			}
		}
	}
	bool scanmouse(ExMessage msg, GraphMouse nmsg)
	{
		return ((msg.x > nmsg.top) && (msg.x < nmsg.bottom) && (msg.y > nmsg.left) && (msg.y < nmsg.right) && (msg.lbutton == nmsg.lmouse) && (msg.rbutton == nmsg.rmouse));
	}
	int addwindow(LPCTSTR tit, RECT rect)
	{
		wintitle.push_back(tit);
		winrect[tit] = rect;
		gcls;
		drawwindow(wintitle.size());
		forcerect(wintitle.size());
		return wintitle.size();
	}
	void outtext(int nheight, int nwidth, LPCTSTR fontface, LPCTSTR text, int x, int y, addpid, int nWeight, COLORREF color = 0x000000)
	{
		settextstyle(nheight, nwidth, fontface, 0, 0, nWeight, false, false, false);
		settextcolor(color);
		outtextxy(getrect(pid).top + x, getrect(pid).left + y, text);
	}
	int AddWindowA(LPCTSTR lTitle,RECT Rect,PID pPID)
	{
		wintitle[pPID - 1] = lTitle;
		winrect[lTitle] = Rect;
		gcls;
		drawwindow(pPID);
		forcerect(pPID);
		return pPID;
	}
	void remwindow(UINT pid)
	{
		winrect.erase(wintitle[pid - 1]);
		wintitle[pid - 1] = L"REMOVEDWIN";
		origrect.erase(wintitle[pid - 1]);
		gcls
		drawwindow(pid);
	}

	void drawsmallico(PID pid)
	{
		solidrectangle(iter*35, graphx-35, iter*35+35, graphx);
		outtext(25, 0, L"Î¢ÈíÑÅºÚ", to_wstring(pid).c_str(), graphx - 35, iter * 35 + 10, pid, 600, 0);
		iter++;
	}
	void drawtoolbar(PID pid)
	{
		switch (sview[wintitle[pid - 1]])
		{
		case 0:
			RECT re = getrect(pid);
			setfillcolor(TOOLBUTTONMAIN);
			solidrectangle(re.right - 5, re.top + 5, re.right - 17, re.top + 17);
			setline(RGB(0, 0, 0), 2);
			line(re.right - 8, re.top + 8, re.right - 14, re.top + 14);
			line(re.right - 14, re.top + 8, re.right - 8, re.top + 14);
			solidrectangle(re.right - 20, re.top + 5, re.right - 37, re.top + 17);
			rectangle(re.right - 23, re.top + 8, re.right - 34, re.top + 14);
			solidrectangle(re.right - 40, re.top + 5, re.right - 57, re.top + 17);
			line(re.right - 43, re.top + 15, re.right - 54, re.top + 15);
		case 1:
			return;
		}
		
	}
	void redrawwindow()
	{
		gcls;
		for (int i = 1; i <= wintitle.size(); i++)
		{
			drawwindow(i);
			drawtoolbar(i);
		}
	}
	void smallscreen(PID pid)
	{
		sview[wintitle[pid - 1]] = true;
	}
	RECT getwinrect(LPRECT rec, UINT pid)
	{
		return winrect[wintitle[pid - 1]];
	}
	RECT makerect(LONG left, LONG top, LONG right, LONG bottom)
	{
		RECT ret = { left,top,right,bottom };
		return ret;
	}
	void drawtitle(addpid)
	{
		outtext(20, 0, L"Î¢ÈíÑÅºÚ", wintitle[pid - 1].c_str(), 10, 2, pid,450, 0x000000);
	}
#define mkrect makerect
	VOID setwindow(PID pid,RECT rect)
	{
		getrect(pid)=rect;
	}
	VOID refscreen(PID pid)
	{
		switch (full[wintitle[pid - 1]])
		{
		case 0:
			setwindow(pid, makerect(0, 0, graphx, graphy));

			full[wintitle[static_cast<std::vector<std::wstring, std::allocator<std::wstring>>::size_type>(pid) - 1]] = 1;
			goto cont;
		case 1:
			setwindow(pid, origrect[wintitle[static_cast<std::vector<std::wstring, std::allocator<std::wstring>>::size_type>(pid) - 1]]);

			full[wintitle[static_cast<std::vector<std::wstring, std::allocator<std::wstring>>::size_type>(pid) - 1]] = 0;
			goto cont;
		}
		cont:
		cleardevice();
		redrawwindow();
	}
	BOOLLAY scanbulider(int need,ExMessage msg,PID pid)
	{
		BOOLLAY sub;
		RECT re = winrect[wintitle[pid - 1]];
		switch (need)
		{
			
		case 1:
			if
			(
				re.right - 5 > msg.x
				&&
				re.top+5<msg.y
				&&
				re.right-17<msg.x
				&&
				re.top+17>msg.y
				&&
				msg.lbutton==true
			)
			{
				remwindow(pid);
				cleardevice();
				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:close\n", msg.x, msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				printinfo(S_OK, (string)"Close window PID:" + to_string(pid), 0);
				sub.success = true;
				return sub;
			}
			else
			{
				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:nan\n",msg.x,msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				return false;
			}
		case 2:
			if
				(
					re.right - 20 > msg.x
					&&
					re.top + 5 < msg.y
					&&
					re.right - 37 < msg.x
					&&
					re.top + 17 > msg.y
					&&
					msg.lbutton == true
				)
			{
				refscreen(pid);
				drawtitle(pid);
				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:fullscr\n", msg.x, msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				printinfo(S_OK, (string)"Full screen window PID:" + to_string(pid), 0);
				sub.success = true;
				sub.stat = full[wintitle[pid - 1]];
				return sub;
			}
			else
			{

				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:nan\n", msg.x, msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				return false;
			}
		case 3:
			if
				(
					re.right - 40 > msg.x
					&&
					re.top + 5 < msg.y
					&&
					re.right - 57 < msg.x
					&&
					re.top + 17 > msg.y
					&&
					msg.lbutton == true
				)
			{
				smallscreen(pid);
				drawsmallico(pid);
				redrawwindow();
				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:fullscr\n", msg.x, msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				printinfo(S_OK, (string)"Small windows PID:" + to_string(pid), 0);
				sub.success = true;
				sub.stat = full[wintitle[pid - 1]];
				return sub;
			}
			else
			{

				printf("lPcomm1x=%04ld  lPcomm1y=%04ld     bPcomm1l=%s   bPcomm1l=%s      stat:nan\n", msg.x, msg.y, bool2string(msg.lbutton, "TRUE ", "FALSE").c_str(),
					bool2string(msg.rbutton, "TRUE ", "FALSE").c_str());
				return false;
			}
		}
	}
	PID functionwindow(LPCTSTR title, RECT rec, PID pid = 0)
	{
		PID ret;
		switch (pid)
		{
		case 0:
			ret = addwindow((LPCWSTR)title, rec);
			drawwindow(ret);
			drawtoolbar(ret);
			drawtitle(ret);
			return ret;
		default:
			AddWindowA(title, rec, pid);
			drawtoolbar(pid);
			drawtitle(pid);
			return pid;
		}
	}
}

/*
|------|
|      |                |=Y
|------|                -=X
*/
/*
#pragma once

#include "..\includes.h"

#define WINDOWREV RGB(207, 248, 249)
#define WINDOWTIT RGB(10, 49, 160)
#define WINDOWSPACE RGB(192, 192, 192)
#define TOOLBUTTONMAIN WINDOWSPACE
#define NOSELECT RGB(135, 136, 143)

#define MINIMIZED 3
#define MAXMIZED 2
#define CLOSE 1

#define setline(rgbhead,thinkness) setlinestyle(PS_SOLID,thinkness);setlinecolor(rgbhead)

#define getrect(pid) winrect[wintitle[pid-1]]
#define getrectfull(pid) getrect(pid).left,getrect(pid).top,getrect(pid).right,getrect(pid).bottom

#define BEGIN namespace guide
#define CLOSEWIN L"REMOVEDWIN"
#define addpid PID pid

typedef UINT PID;

#define IDEXIT 1
#define IDFULLSCREEN 2


#define gcls cleardevice();


typedef unsigned long long QWORD;

struct ExMessageX
{
	int x;
	int y;
	bool lbuttom;
	bool rbuttom;
	operator ExMessage() const
	{
		ExMessage ret;
		ret.lbutton = this->lbuttom;
		ret.rbutton = this->rbuttom;
		ret.x = this->x;
		ret.y = this->y;
		return ret;
	}
	void operator=(ExMessage msg)
	{
		this->x = msg.x;
		this->y = msg.y;
		this->lbuttom = msg.lbutton;
		this->rbuttom = msg.rbutton;
	}
	ExMessageX(ExMessage msg)
	{
		this->operator=(msg);
	}
};

struct GraphMouse
{
	int left;
	int top;
	int right;
	int bottom;
	bool lmouse;
	bool rmouse;
	bool operator==(ExMessageX mesg)
	{
		return (mesg.y > left && mesg.y < right&& mesg.lbuttom == rmouse && mesg.rbuttom == lmouse);
	}
};

struct BOOLLAY
{
	bool success;
	bool stat;
	BOOLLAY(bool suc)
	{
		this->success = suc;
	}
	BOOLLAY() {}
};

ExMessage mkexmsg(int x, int y, bool lbut, bool rbut)
{
	ExMessage ret;
	ret.lbutton = lbut;
	ret.rbutton = rbut;
	ret.x = x;
	ret.y = y;
	return ret;
}

typedef class WindowFunction
{
public:
	basic_string<widechar, char_traits<widechar>, allocator<widechar>> wintitle;
	RECT nowrect;
	RECT smallrect;
	bool isSmallWindow;
	bool isfullscreen;
	operator RECT()const
	{
		return this->nowrect;
	}
	operator wstring()const
	{
		return this->wintitle;
	}
}
*LPWindowFunction,WinFunc,*PWindowsFunction,*LPWinFunc,*PWinFunc;

WinFunc mkwinfunc(LPCTSTR wintit, RECT rec, bool isSmallWin = false, bool isFullWin = false)
{
	WinFunc func;
	func.wintitle = wintit;
	func.smallrect = rec;
	func.nowrect = rec;
	func.isfullscreen = isFullWin;
	func.isSmallWindow = isSmallWin;
	return func;
}

namespace guide
{
	vector <WinFunc> winfunc;
	PID addwindow(LPCTSTR wintit,RECT rec)
	{
		winfunc.push_back(mkwinfunc(wintit, rec));
		return winfunc.size();
	}
}
*/
/*
|------|
|      |                |=Y
|------|                -=X
*/