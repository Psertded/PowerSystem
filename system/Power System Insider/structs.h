#pragma once

#include "includes.h"

#include "convert.h"


std::wstring root = L".\\";



char color(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return 0;
	SetConsoleTextAttribute(hConsole, wAttributes);
	return 0;
}


ULONGLONG random(ULONGLONG min, ULONGLONG max)
{
	default_random_engine a;
	uniform_int_distribution <ULONGLONG> b(min, max);
	return b(a);
}

using namespace std;
class nchar
{
public:
	char _s;
	int get()
	{
		return (int)_s;
	}
	void operator=(int ed)
	{
		_s = ed;
	}
	void clear()
	{
		_s = 0;
	}
	bool operator==(int n)
	{
		if (n == _s)
		{
			return true;
		}
		return false;
	}
	bool operator&&(int m)
	{
		if (_s && m == 0)
		{
			return true;
		}
		return false;
	}
	bool operator||(int num)
	{
		if (_s || num)
			return true;
		return false;
	}
	bool operator^(int a)
	{
		if (_s ^ a)
		{
			return true;
		}
		return false;
	}
	int operator+(int num)
	{
		return (int)_s + num;
	}
	int operator-(int num)
	{
		return (int)_s - num;
	}
	int operator*(int num)
	{
		return (int)_s * num;
	}
	int operator/(int num)
	{
		return (int)_s / num;
	}
	void operator+=(int num)
	{
		_s + num;
	}
	void operator-=(int num)
	{
		_s / num;
	}
	void operator*=(int num)
	{
		_s* num;
	}
	void operator/=(int num)
	{
		_s / num;
	}
	int operator++(int num)
	{
		return _s++;
	}
	int operator--(int num)
	{
		return _s--;
	}
	operator int() const
	{
		return (int)_s;
	}

	nchar(int i)
	{
		_s = i;
	}
};

class nuchar
{
public:
	unsigned char _s;
	int get()
	{
		return (int)_s;
	}
	void operator=(int ed)
	{
		_s = ed;
	}
	void clear()
	{
		_s = 0;
	}
	bool operator==(int n)
	{
		if (n == _s)
		{
			return true;
		}
		return false;
	}
	bool operator&&(int m)
	{
		if (_s && m == 0)
		{
			return true;
		}
		return false;
	}
	bool operator||(int num)
	{
		if (_s || num)
			return true;
		return false;
	}
	bool operator^(int a)
	{
		if (_s ^ a)
		{
			return true;
		}
		return false;
	}
	int operator+(int num)
	{
		return (int)_s + num;
	}
	int operator-(int num)
	{
		return (int)_s - num;
	}
	int operator*(int num)
	{
		return (int)_s * num;
	}
	int operator/(int num)
	{
		return (int)_s / num;
	}
	void operator+=(int num)
	{
		_s + num;
	}
	void operator-=(int num)
	{
		_s / num;
	}
	void operator*=(int num)
	{
		_s* num;
	}
	void operator/=(int num)
	{
		_s / num;
	}
	int operator++(int num)
	{
		return _s++;
	}
	int operator--(int num)
	{
		return _s--;
	}
	operator int() const
	{
		return (int)_s;
	}
	nuchar(int i)
	{
		_s = i;
	}
};

namespace tracks
{
	void init(wstring message, unsigned long long slp)
	{
		GetConsoleCursorInfo(handle, &CursorInfo);
		CursorInfo.bVisible = false;
		SetConsoleCursorInfo(handle, &CursorInfo);
		int ntex = 0;
		int tmp = 0;
		wcout << message << " ["<<setiosflags(wios::left); 
		cout << setiosflags(ios::left);
		ios::sync_with_stdio(false);
		for (int i = 0; i < 101; i++)
		{
			color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "\r";
			wcout << message << " [ ";
			for (int i = 0; i < tmp; i++)
			{
				if (i <= 35)
				{
					color(FOREGROUND_RED);
				}
				else if (i <= 60)
				{
					color(FOREGROUND_RED | FOREGROUND_GREEN);
				}
				else if (i <= 90)
				{
					color(FOREGROUND_GREEN);
				}
				else if (i <= 100)
				{
					color(FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				cout << "█";
			}
			for (int i = 0; i < 100 - tmp; i++)
			{
				cout << " ";
			}
			color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "  ] All: 100% / ";
			if (tmp <= 35)
			{
				color(FOREGROUND_RED);
			}
			else if (tmp <= 60)
			{
				color(FOREGROUND_RED | FOREGROUND_GREEN);
			}
			else if (tmp <= 90)
			{
				color(FOREGROUND_GREEN);
			}
			else if (tmp <= 100)
			{
				color(FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			cout << setw(3) << tmp;
			color(FOREGROUND_WHITE);
			cout << '%';
			ntex = tmp;
			Sleep(slp);
			tmp++;
		}
		cout << endl << "\n";
		string ttm;
		ios::sync_with_stdio(true);
		cin.clear();
		wcin.clear();
		wcout.clear();
		wcin.clear();
		GetConsoleCursorInfo(handle, &CursorInfo);
		CursorInfo.bVisible = true;
		SetConsoleCursorInfo(handle, &CursorInfo);
	}
	void guide(wstring message, unsigned long long slp, HWND catchhwnd, COLORREF Color = RGB(6, 176, 37), COLORREF lColor = RGB(188, 188, 188), COLORREF sColor = RGB(230, 230, 230))
	{
		catchhwnd = initgraph(1000, 350, EW_SHOWCONSOLE);
		setbkmode(TRANSPARENT);
		setbkcolor(RGB(240, 240, 240));
		cleardevice();
		settextstyle(22, 0, L"微软雅黑");
		settextcolor(0);
		setlinecolor(lColor);
		float val = 0.0f;
		wchar_t* buf=new wchar_t[30];
		for (double i=65;i<935;i+=double(935-65)/100.0/2.0)
		{	
			setfillcolor(RGB(240,240,240));
			solidrectangle(820, 25, 945, 50);
			swprintf(buf, L"% 5.1lf%%/100.0%%", val);
			val += 0.5f;
			outtextxy(55, 45, message.c_str());
			outtextxy(825,30, buf);
			setfillcolor(Color);
			rectangle(65, 90, 935, 115);
			solidrectangle(66, 91, i, 114);
			setfillcolor(sColor);
			solidrectangle(i, 91, 934, 114);
			Sleep(slp);
		}
		closegraph();
		Sleep(slp*2);
	}
}