#ifndef _PSYSTEM_MAIN_
#define _PSYSTEM_MAIN_
#include "controls.h"
#include "using.h"

#undef closegraph
#undef initgraph

#define VER "2.6.3 Dev"

using namespace std;

string scanedcommand;

_declspec(dllexport) wstring version_info()
{
	return L"2.6.3";
}


__declspec(dllexport) int system_main(int argc,const char* argv[])
{
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
#ifdef DEBUGGER
	function_debugpack = true;
#endif
	locale::global(locale(""));
	_wgetcwd(buffer, MAX_PATH);
	origroot = buffer;
	origroot.push_back(L'\\');
	root = buffer;
	syshwnd = FindWindow(sout << "ConsoleWindowClass", NULL);
	if (!isFile_ifstream(".\\data\\username"))
	{
		_mkdir(".\\data");
		_mkdir(".\\data\\settings");
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
		cls;
#ifdef __cplusplus
#endif
		LPTSTR pin = new TCHAR[512];
		InputBox(pin, 128, L"Second Question,Please type your PIN(Empty is no PIN):",L"Question 2:", 0, 0, 0, true);
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
				break;
			}
			else
			{
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
		fs.open(".\\data\\pin", ios::in | ios::out | ios::trunc);
		fs << bool2string(val.empty(), "NULL", base64encode_t(clearfirstspace(clearbackspace(val.c_str())),LOCKNUM));
		fs.close();
		cout << "Completed!";
	}
	cls;
	rellist = ReadSetting();
	systembaseboot:
	system();
	return 0;
}
#endif //_PSYSTEM_MAIN_
//2.1                                               2022/7/7  13:22    1767Lines
//2.3 Insider Project(Beta)                         2020/7/12  14:54   2209Lines
//2.4 beta                                          2022/7/14  17:38   2474Lines
//2.5 Release                                       2022/7/22  10:05   2778Lines
//2.6 Release                                       2022/8/9
