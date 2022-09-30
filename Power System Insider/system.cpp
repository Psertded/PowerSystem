#ifndef _PSYSTEM_MAIN_
#define _PSYSTEM_MAIN_
#include "controls.h"
#include "using.h"

#undef closegraph
#undef initgraph

#define VER "2.6.3 Dev"

using namespace std;

string scanedcommand;

#undef getmessage

#define RESERVE_TWO(x,y) y,x
#define RESERVE_ALL(x1,x2,y1,y2) y2,y1,x2,x1
#define TWO_TWO_RESERVE(x1,x2,y1,y2) x2,x1,y2,y1

wstring version_info()
{
	return L"2.6.3b";
}

void launchpad(int argc)
{
	ExMessage EMG;
	initgraph(640, 480);
	BYTE select = 0;
	IMAGE dstimg;
	loadimage(&dstimg, L".\\image\\logo", 200, 200);
	setbkmode(TRANSPARENT);
	if (argc != 1)
		goto systemmain;
	while (1)
	{

		while (1)
		{
			cleardevice();
			putimage(50, 30, &dstimg);
			setlinecolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			setlinestyle(PS_SOLID, 3);
			settextstyle(15, 0, L"Moder DOS 437");
			outtextxy(245, 3, L"Power LaunchPad");
			outtextxy(RESERVE_TWO(425, 30), L"Use the \x2191 and \x2193 keys to select which entry is highlighted.");
			outtextxy(RESERVE_TWO(440, 30), L"Press enter to boot selected OS.");
			settextstyle(12, 0, L"Moder DOS 437");
			outtextxy(15, 460, (wstring(L"System Version data:" + wstring(version_info())).c_str()));
			outtextxy(15, 470, (std::wstring(L"Launcher Version:") + std::wstring(TEXT(VER))).c_str());
			settextstyle(15, 0, L"Moder DOS 437");
			rectangle(5, 20, 635, 400);
			line(5, 245, 635, 245);
			line(TWO_TWO_RESERVE(245, 50, 400, 50));
			settextstyle(60, 0, L"Cascadia Code");
			outtextxy(300, 45, L"Power");
			outtextxy(300, 95, L"System");
			settextstyle(20, 0, L"Moder DOS 437");
			outtextxy(500, 110, L"Psertded");
			settextstyle(16, 0, L"Moder DOS 437");

			if (select == 0)
			{
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 250, 630, 275);
				settextcolor(0);
				outtextxy(70, 258, (wstring(L"*  Boot Power System - ") + wstring(version_info())).c_str());
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 288, L"   Tools");
				outtextxy(70, 318, L"   Exit");
			}
			else if (select == 1)
			{
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 280, 630, 305);
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
				settextcolor(0);
				outtextxy(70, 288, L"*  Tools");
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 318, L"   Exit");
			}
			else if (select == 2)
			{
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 310, 630, 335);
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
				outtextxy(70, 288, L"   Tools");
				settextcolor(0);
				outtextxy(70, 318, L"*  Exit");
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setlinestyle(PS_SOLID, 3);
				settextstyle(15, 0, L"Moder DOS 437");
				outtextxy(245, 3, L"Power LaunchPad");
			}
			while (1)
			{
				if (GetKeyState((USHORT)VK_ESCAPE) & 0x8000)
				{
					closegraph();
					exit(0x10);//Press ESC to exit.
				}
				else if (GetKeyState((USHORT)VK_RETURN) & 0x8000)
				{
					if (select == 0)
					{
						closegraph();
						goto systemmain;
					}
					if (select == 1)
					{
						MessageBox(NULL, L"Not create~Next Version willed!", L"From Psertded's warning", MB_OK | MB_ICONASTERISK);
						Sleep(300);
					}
					if (select == 2)
					{
						closegraph();
						return;//Exit options;
					}
					break;
				}
				else if (GetKeyState((USHORT)VK_UP) & 0x8000)
				{
					if (select == 0)
					{
						select = 0;
					}
					else
					{
						select--;
					}
					Sleep(150);
					break;
				}
				else if (GetKeyState((USHORT)VK_DOWN) & 0x8000)
				{
					if (select == 2)
					{
						select = 2;
					}
					else
					{
						select++;
					}
					Sleep(150);
					break;
				}
				else if (GetKeyState((USHORT)'1') & 0x8000)
				{
					select = 0;
					break;
				}
				else if (GetKeyState((USHORT)'2') & 0x8000)
				{
					select = 1;
					break;
				}
				else if (GetKeyState((USHORT)'3') & 0x8000)
				{
					select = 2;
					break;
				}
				getmessage(&EMG);
				if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 250 && EMG.x <= 630 && EMG.y <= 275)
				{
					select = 0;
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(14, 258, L"[1]");
					outtextxy(14, 288, L"[2]");
					outtextxy(14, 318, L"[3]");
					solidrectangle(55, 250, 630, 275);
					settextcolor(0);
					outtextxy(70, 258, (wstring(L"*  Boot Power System - ") + wstring(version_info())).c_str());
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(70, 288, L"   Tools");
					outtextxy(70, 318, L"   Exit");
					Sleep(10);
					closegraph();
					goto systemmain;
				}
				if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 280 && EMG.x <= 630 && EMG.y <= 305)
				{
					select = 1;
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(14, 258, L"[1]");
					outtextxy(14, 288, L"[2]");
					outtextxy(14, 318, L"[3]");
					solidrectangle(55, 280, 630, 305);
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));

					outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
					settextcolor(0);
					outtextxy(70, 288, L"*  Tools");
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(70, 318, L"   Exit");
					MessageBox(NULL, L"Not create~Next Version willed!", L"From Psertded's warning", MB_OK | MB_ICONASTERISK);
					Sleep(300);
					break;
				}
				if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 310 && EMG.x <= 630 && EMG.y <= 335)
				{
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(14, 258, L"[1]");
					outtextxy(14, 288, L"[2]");
					outtextxy(14, 318, L"[3]");
					solidrectangle(55, 310, 630, 335);
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
					outtextxy(70, 288, L"   Tools");
					settextcolor(0);
					outtextxy(70, 318, L"*  Exit");
					settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
					setlinestyle(PS_SOLID, 3);
					settextstyle(15, 0, L"Moder DOS 437");
					outtextxy(245, 3, L"Power LaunchPad");
					Sleep(10);
					select = 2;
					closegraph();
					return;
				}
				if (EMG.lbutton && EMG.x >= 360 && EMG.x <= 410 && EMG.y >= 110 && EMG.y <= 145)
				{
					system("start https://github.com/Psertded/Power-System");
				}
				if (EMG.lbutton && EMG.x >= 500 && EMG.x <= 568 && EMG.y >= 110 && EMG.y <= 123)//68,13
				{
					system("start https://space.bilibili.com/600523682");
				}
			}
			setlinecolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			setlinestyle(PS_SOLID, 3);
			settextstyle(15, 0, L"Moder DOS 437");
			outtextxy(245, 3, L"Power LaunchPad");
		}
	}
systemmain:
	closegraph();
	return;
}



int main(int argcount,const char* argvalue[])
{
	launchpad(argcount);
	//scan execute version
#ifdef _DEBUG
	cout << "Version:          Debug";
#else
	cout << "Version:        Release";
#endif
#ifdef _WIN64
	cout << endl << "Execute:Windows 64-bit";
#else
	cout << endl << "Execute:Windows 32-bit";
#endif
#ifdef _CONSOLE
	cout << endl << "Execute Version:Console" << endl;
#else
	cout << endl << "Execute Version:Window" << endl;
#endif
	//start
	cout << "Initialization,Please wait..." << endl << endl;
	ps_log(L"Run System");
	string* sargv = new string[argcount];
	for (int i = 0; i < argcount; i++)
	{
		sargv[i] = argvalue[i];
	}
	for (int i = 0; i < argcount; i++)
	{
		if (sargv[i].find("-oc") == 0)
		{
			sargv[i].erase(0, 3);
			fstream fs;
			ps_log(true, message, L"Founding password file");
			if (!isFile_ifstream(".\\data\\pin"))
			{
				cout << "Check password file failed!" << endl;
				ps_log(true, val, L"FAILED", L"Check password file");
			}
			fs.open(".\\data\\username", ios::in);
			getline(fs, this_username);
			ps_log(true, message, L"Get user name");
			fs.close();
			fs.clear();
			fs.open(".\\data\\pin", ios::in);
			getline(fs, this_pin);
			cin.clear();
			wcin.clear();
			ps_log(true, val, L"The -oc select with", (wchar_t*)(bstr_t)sargv[i].c_str());
			if (this_pin == "NULL")
			{
				scancommand(sargv[i]);
				exit(0);
			}
			else
			{
				string pin;
				while (1)
				{
					cout << "Please type your PIN there:";
					getline(cin, pin);
					if (base64encode_t(pin, LOCKNUM) == this_pin)
					{
						ps_log(true, message, L"The PIN are correctly.");
						scancommand(sargv[i]);
						exit(0);
					}
					else
					{
						ps_log(true, val, L"WRONG", L"Password");
						cout << "Invalid PIN" << endl;
					}
				}
			}
			exit(0);
		}
		if (sargv[i].find("-help") == 0)
		{
			ps_log(true, message, L"Show help");
			cout << "Usage:PowerSystem.exe (-oc[command] | -help)" << endl << "-oc          Start a command,example(the -oc and command are not have command):-ocloadaudio ";
			cout << endl << "-help        Show help" << endl;
		}
	}
	
	locale::global(locale(""));
	_wgetcwd(buffer, MAX_PATH);
	ps_log(true, message, L"Get root");
	origroot = buffer;
	if (origroot.back() != '\\')
	{
		origroot.push_back('\\');
	}
	root = buffer;
	syshwnd = FindWindow(sout << "ConsoleWindowClass", NULL);

	if (!isFile_ifstream(".\\data\\username"))
	{
		ps_log(true, message, L"The user are first use system.");
		_mkdir(".\\data");
		ps_log(true, message, L"Make the directory .\\data");
		_mkdir(".\\data\\settings");
		ps_log(true, message, L"Make the directory .\\data\\settings");
		cls;
		initsetting();
		cout << "Welcome to Power System!" << endl;
		system("pause");
		YN process;
		cls;
		LPTSTR namet=new TCHAR[1024];
		initgraph(1, 1);
		InputBox(namet, 255, L"First Question,what's your name?", L"Question 1:", 0, 0, 0, true);
		string name = (char*)((bstr_t)(namet));
		ps_log(true, message, L"Type FQ");
		cls;
#ifdef __cplusplus
#endif
		LPTSTR pin = new TCHAR[512];
		InputBox(pin, 128, L"Second Question,Please type your PIN(Empty is no PIN):",L"Question 2:", 0, 0, 0, true);
		ps_log(true, message, L"Type SQ");
		string val=(char*)((bstr_t)(pin));
		string dval;
		closegraph();
		cls;
		while (1)
		{
			cout << "Please rewrite your PIN:";
			getline(cin, dval);
			if (dval == val)
			{
				ps_log(true, message, L"check pin success");
				break;
			}
			else
			{
				ps_log(true, message, L"FAILED:check pin error");
				cout << "Invalid PIN" << endl;
			}
		}
		cls;
		cout << "Do you wan't rewrite this information?" << endl <<
			"Name:" << name << endl << "PIN : " << bool2string((val.empty()), "Empty", val) << endl << endl <<
			"If error,please reboot this execute(the information are not write.)";
		system("pause");
		cls;
		cout << "Writting..." << endl;
		fstream fs;
		fs.open(".\\data\\username", ios::in | ios::out | ios::trunc);
		fs << name;
		fs.close();
		fs.clear();
		ps_log(true, message, L"Success Write the usernmae file");
		fs.open(".\\data\\pin", ios::in | ios::out | ios::trunc);
		fs << bool2string(val.empty(), "NULL", base64encode_t(clearfirstspace(clearbackspace(val.c_str())),LOCKNUM));
		fs.close();
		ps_log(true, message, L"Success Write the PIN file");
		cout << "Completed!";
	}
	cls;
	rellist = ReadSetting();
systembaseboot:
	cout << endl;
	system();
	return 0;
}
#endif //_PSYSTEM_MAIN_
//2.1                                               2022/7/7  13:22    1767Lines
//2.3 Insider Project(Beta)                         2020/7/12  14:54   2209Lines
//2.4 beta                                          2022/7/14  17:38   2474Lines
//2.5 Release                                       2022/7/22  10:05   2778Lines
//2.6 Release                                       2022/8/9


//Licence
//EasyX graphics library