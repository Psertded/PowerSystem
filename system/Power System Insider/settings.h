#pragma once

#include "controls.h"

using namespace std;




template <typename _Ty=string>
_Ty WriteSettings(string name, _Ty val)
{
	wfstream f;
	f.open(string(".\\data\\settings\\") + name.c_str(), wios::ate | wios::out);
	f << val;
	f.close();
	return val;
}

wstring ReadSettingsW(LPCSTR name)
{
	wfstream f;
	f.open(string(".\\data\\settings\\") + name, wios::in);
	wstring val;
	getline(f, val);
	return val;
}

string ReadSettingsA(LPCSTR name)
{
	fstream f;
	f.open(string(".\\data\\settings\\") + name, wios::in);
	string val;
	getline(f, val);
	return val;
}

long long ReadSettingsI(LPCSTR name)
{
	wfstream f;
	f.open(string(".\\data\\settings\\") + name, wios::in);
	long long val;
	f >> val;
	return val;
}

string SettingLists[3] =
{
	"Download use GUI",
	"Download Exit Key"
};

typedef struct SettingList
{
	unsigned short GUIDownload = false;
	char downexitkey = 'Q';
};

void WriteSetting(SettingList se)
{
	WriteSettings("DownGUI", se.GUIDownload);
	WriteSettings("DownExitKey", (int)se.downexitkey);
}

void ReadSetting(SettingList* se)
{
	se->GUIDownload = ReadSettingsI("DownGUI");
	se->downexitkey = ReadSettingsI("DownExitKey");
	return;
}

SettingList ReadSetting()
{
	SettingList set;
	set.GUIDownload = ReadSettingsI("DownGUI");
	set.downexitkey = ReadSettingsI("DownExitKey");
	return set;
}

void initsetting()
{
	CreateFile(L".\\data\\setting\\DownGUI", GENERIC_WRITE | GENERIC_READ, NULL, NULL, CREATE_ALWAYS, NULL, NULL);
	CreateFile(L".\\data\\setting\\DownExitKey", GENERIC_WRITE | GENERIC_READ, NULL, NULL, CREATE_ALWAYS, NULL, NULL);
	WriteSettings("DownGUI", 0);
	WriteSettings("DownExitKey", (int)'Q');
}

SettingList rellist;

void setting(SettingList se)
{
	hiex::Window Wnd;
	Wnd.Create(640, 480, 0, L"Power System Setting - HiEasyX", nullptr, nullptr);
	hiex::SysButton syb;
	settextstyle(26, 0, L"Segoe UI");
	outtextxy(260, 15, L"Settings");
	line(0, 45, 640, 45);
	settextstyle(20, 0, L"Segoe UI");

}