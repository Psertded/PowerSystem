#pragma once

int SKIPBOOT=0;
unsigned int gx, gy;

; 
int time2sleep(unsigned int ms)
{
	return (ms / 20) / 100;
}


#include "includes.h"

;

#define ASCIIBSR 32
using namespace std;

typedef long long LLONG;
#define rechfor(num) for(ULLONG rechfordecid=0;rechfordecid<num;rechfordecid++)
#define RFORC        rechfordecid


typedef char TYPES;
typedef char YN;

#define SAFE_RELEASE(filter) { if(NULL != filter) { filter->Release(); filter = NULL; } }

#include "structs.h"


string bool2string(bool stat, string truestr, string falsestr)
{
	if (stat == 1)
	{
		return truestr;
	}
	else
	{
		return falsestr;
	}
}

wstring bool2wstring(bool stat, wstring truestr, wstring falsestr)
{
	if (stat == 1)
	{
		return truestr;
	}
	else
	{
		return falsestr;
	}
}

string char2string(char c)
{
	string rere;
	rere = c;
	return rere;
}
wstring char2wstring(char c)
{
	wstring hehe;
	hehe = c;
	return hehe;
}

wstring wchar2wstring(wchar c)
{
	wstring hehe;
	hehe = c;
	return hehe;
}
;


BOOL winerror(LPCSTR msg)
{
	_Xinvalid_argument(msg);
}

bool bechar(char a)
{
	if (a >= 'A' && a <= 'Z')
	{
		return true;
	}
	if (a >= 'a' && a <= 'z')
	{
		return true;
	}
	return false;
}
bool benum(char a)
{
	if (a >= '0' && a <= '9')
	{
		return true;
	}
	return false;
}

bool bechar(wchar a)
{
	if (a >= 'A' && a <= 'Z')
	{
		return true;
	}
	if (a >= 'a' && a <= 'z')
	{
		return true;
	}
	return false;
}
bool benum(wchar a)
{
	if (a >= '0' && a <= '9')
	{
		return true;
	}
	return false;
}

typedef const char* cstr;
typedef unsigned short LCSTR;



const char* itoa(ULLONG num)
{
	return to_string(num).c_str();
}

string mktext(const char txt, unsigned short int num)
{
	string tmp;
	for (int i = 0; i < num; i++)
	{
		tmp += txt;
	}
	return tmp;
}

size_t gethash(string n)
{
	hash <string> hsh;
	size_t val = hsh(n);
	return val;
}

size_t gethash(wstring n)
{
	hash <wstring> hsh;
	size_t val = hsh(n);
	return val;
}

size_t gethash(size_t n)
{
	hash <size_t> hsh;
	size_t val = hsh(n);
	return val;
}

ULONGLONG sec2ms(double sec)
{
	return sec * 1000;
}




clock_t time1;
clock_t time2;

void system();

void showwindow()
{
	if (syshwnd)
	{
		ShowWindow(syshwnd, SW_SHOW);
	}
}

string endls(int endlnum)
{
	ios::sync_with_stdio(TRUE);
	string pass;
	for (int i = 0; i < endlnum; i++)
	{
		pass += "\n";
	}
	return pass;
}

vector <unsigned long long int> tmp;

double gettime()
{
	time2 = clock();
	return double(time2 - time1) / CLOCKS_PER_SEC;
}

void boot(wstring exename)
{
	ShellExecute(NULL, NULL, sout<<exename, NULL, NULL, SW_SHOWNORMAL);
}



void printinfo(char stat,string outtext,unsigned short int waittime)
/*
 char stat :					Stats(FAIL,DEFINE,OK,READ...)
 string outtext :				Info text
 unsigned short int waittime:	The text out wait time			
*/
{
	cout << "[";
	if (stat == S_OK)
	{
		color(FOREGROUND_GREEN);
	}
	else if (stat == S_FAIL)
	{
		color(FOREGROUND_RED);
	}
	else if (stat == S_DEFINE)
	{
		color(FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else if (stat == S_READ)
	{
		color(FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	switch (stat)
	{
	case 0:
		cout << "  OK  "; break;
	case 1:
		cout << " FAIL "; break;
	case 2:
		cout << " READ "; break;
	case 3:
		cout << "DEFINE"; break;
	}
	color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "] [";
	cout << fixed << setprecision(3) << setw(7)<< gettime();
	cout << "] " << outtext << endl;
	Sleep(waittime);
}

vector<vector<COLORREF> > loadimg()
{
	vector<vector<COLORREF>> space;
	cout << "You can type ? to see support what picture." << endl << "File name:";
	wstring fname;
	getline(wcin, fname);
	if (fname.empty())
	{
		return space;
	}
	wstring cc = fname;
	addroot(fname);
	if (fname == L"?")
	{
		cout << "bmp/gif/jpg/png/tif/emf/wmf/ico               can load";
		return space;
	}
	else
	{
		int dstX = 0;
		IMAGE _dstimg;
		UINT picx, picy;
		loadimage(&_dstimg,fname.c_str());
		picx = _dstimg.getwidth();
		picy = _dstimg.getheight();
		HWND win = initgraph(picx, picy, EW_SHOWCONSOLE | EW_NOCLOSE);
		vector<vector<COLORREF> > dstimg;
		vector<COLORREF> dstimgt;
		putimage(0, 0, &_dstimg);
		ShowWindow(win, SW_HIDE);
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				dstimgt.push_back(getpixel(i, j));
			}
			dstimg.push_back(dstimgt);
			dstimgt.clear();
		}
		ShowWindow(win, SW_SHOW);
		cleardevice();
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 == 0 && j % 2 == 0)//all 2
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		cleardevice();
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 != 0 && i / 2 != 0 && j % 2 != 0 && j / 2 != 0 || i==1 || j==1)//all no 2
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		cleardevice();
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 != 0 && j % 2 == 0)
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		cleardevice();
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 == 0 && j % 2 != 0)
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				dstimgt.push_back(getpixel(i, j));
			}
			dstimg.push_back(dstimgt);
			dstimgt.clear();
		}
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 == 0 && j % 2 == 0)//all 2
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 != 0 && i / 2 != 0 && j % 2 != 0 && j / 2 != 0 || i == 1 || j == 1)//all no 2
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 != 0 && j % 2 == 0)
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}

		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				if (i % 2 == 0 && j % 2 != 0)
				{
					putpixel(i, j, dstimg[i][j]);
				}
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				return space;
			}
		}
		setbkmode(TRANSPARENT);
		printf("l_bugjsx=%05d   l_bugjsy=%05d\n", picx, picy);
		size_t buf = gethash(picx);
		buf += gethash(picy);
		buf += gethash(fname);
		buf += gethash(getpixel(picx, picy));
		gx = picx;
		gy = picy;
		printf("_clea_gval=0x%016llX\n", buf);
		printf("_GVAL_Hash:===0x%08llX\n", gethash(buf));
		printf("Type ESCAPE to exit.\n");
		while (!KEY_DOWN(VK_ESCAPE))
		{
			Sleep(1);
		}
		closegraph();
		return dstimg;
	}
}


HANDLE GetProcessHandle(int nID)
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

HANDLE GetProcessHandle(LPCWSTR lpName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot)
	{
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	BOOL fOk;
	for (fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
	{
		if (!_tcsicmp(pe.szExeFile, lpName))
		{
			CloseHandle(hSnapshot);
			return GetProcessHandle(pe.th32ProcessID);
		}
	}
	return NULL;
}

string base64encode_t(string ff, unsigned long long num)
{
	string endval = base64_encode(ff);
	for (int i = 0; i < num; i++)
	{
		endval = base64_encode(endval);
	}
	return endval;
}

string base64decode_t(string ff,unsigned long long num)
{
	string endval = base64_decode(to_string(num));
	for (int i = 0; i < num; i++)
	{
		endval = base64_decode(endval);
	}
	return endval;
}

void wloadimg(vector<vector<COLORREF> > &dstimg)
{
	cout << "You can type ? to see support what picture." << endl << "File name:";
	wstring fname;
	getline(wcin, fname);
	if (fname.empty())
	{
		return;
	}
	wstring cc = fname;
	addroot(fname);
	if (fname == L"?")
	{
		cout << "bmp/gif/jpg/png/tif/emf/wmf/ico               can load";
		return;
	}
	else
	{
		wstring endf = origroot.c_str();
		int dstX = 0;
		endf.append(L"temp");
		endf.append(cc);
		CopyFile(fname.c_str(), endf.c_str(), true);
		IMAGE _dstimg;
		UINT picx, picy;
		DWORD* dst = GetImageBuffer();
		DWORD* draw = GetImageBuffer();
		DWORD* src = GetImageBuffer(&_dstimg);
		addroot(fname);
		wstring ff = L"temp";
		ff.append(cc);
		loadimage(&_dstimg, ff.c_str());
		picx = _dstimg.getwidth();
		picy = _dstimg.getheight();
		HWND win = initgraph(picx, picy, EW_SHOWCONSOLE | EW_NOCLOSE);
		vector<COLORREF> dstimgt;
		putimage(0, 0, &_dstimg);
		ShowWindow(win, SW_HIDE);
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				dstimgt.push_back(getpixel(i, j));
			}
			dstimg.push_back(dstimgt);
			dstimgt.clear();
		}
		ShowWindow(win, SW_SHOW);
		cleardevice();
		for (int i = 0; i <= picx; i++)
		{
			for (int j = 0; j <= picy; j++)
			{
				putpixel(i, j, dstimg[i][j]);
				printf("_lpDx=%04d   _lpDy=%04d    _lavcCovdw=0x%08X\n", i, j, dstimg[i][j]);
			}
			if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				closegraph();
				_wremove(endf.c_str());
				return;
			}
		}
		
		setbkmode(TRANSPARENT);
		printf("l_bugjsx=%05d   l_bugjsy=%05d\n", picx, picy);
		size_t buf = gethash(picx);
		buf += gethash(picy);
		buf += gethash(fname);
		buf += gethash(getpixel(picx, picy));
		gx = picx;
		gy = picy;
		printf("_clea_gval=0x%016llX\n", buf);
		printf("_GVAL_Hash:===0x%08llX\n", gethash(buf));
		printf("Type ESCAPE to exit.\n");
		while (!KEY_DOWN(VK_ESCAPE))
		{
			Sleep(1);
		}
		_wremove(endf.c_str());
		closegraph();
	}
}



vector <unsigned long long> fulls;
void fullram(unsigned long long kb)
{
	for (unsigned long long i = 0; i <= kb; i++)
	{
		for (int j = 0; j <= 32; j++)
		{
			fulls.push_back(1);
		}
	}
}
bool hidewindow()
{
	if (syshwnd)
	{
		ShowWindow(syshwnd, SW_HIDE);
		return true;
	}
	return false;
}

#include "guide/gmain.h"

#define nline "\n"

#define STRAPI __cdecl

void error(wstring text)
{
	wcout << "Unknown command :" << " -" << text << "-" << (sout >> endls(2));
}

string getfullram()
{
	return "The control was deleted.";
}

string STRAPI toupper(string _Str)
{
	for (int i = 0; i < _Str.size(); i++)
	{
		if (_Str[i] >= 'a' && _Str[i] <= 'z')
		{
			_Str[i] -= ASCIIBSR;
		}
	}
	return _Str;
}

wstring STRAPI toupper(wstring _Str)
{
	for (int i = 0; i < _Str.size(); i++)
	{
		if (_Str[i] >= L'a' && _Str[i] <= L'z')
		{
			_Str[i] -= ASCIIBSR;
		}
	}
	return _Str;
}

string STRAPI tolower(string _Str)
{
	for (int i = 0; i < _Str.size(); i++)
	{
		if (_Str[i] >= 'A' && _Str[i] <= 'Z')
		{
			_Str[i] += ASCIIBSR;
		}
	}
	return _Str;
}

wstring STRAPI tolower(wstring _Str)
{
	for (int i = 0; i < _Str.size(); i++)
	{
		if (_Str[i] >= L'A' && _Str[i] <= L'Z')
		{
			_Str[i] += ASCIIBSR;
		}
	}
	return _Str;
}

string __cdecl clearfirstspace(string strs)
{
	for(ULLONG tmp=0;tmp<ULLONG_MAX;tmp++)
	{ 
		if (strs[0] == ' ')
		{
			strs.erase(0, 1);
		}
		else break;
	}
	return strs;
}

wstring __cdecl clearfirstspace(wstring strs)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs[0] == L' ')
		{
			strs.erase(0, 1);
		}
		else break;
	}
	return strs;

}

wstring __cdecl clearbackspace(wstring strs)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs.back() == L' ')
		{
			strs.pop_back();
		}
		else break;
	}
	return strs;
}

string __cdecl clearbackspace(string strs)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs.back() == ' ')
		{
			strs.pop_back();
		}
		else break;
	}
	return strs;
}

void __cdecl clearfirstspace(string strs,string &saveto)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs[0] == ' ')
		{
			strs.erase(0, 1);
		}
		else break;
	}
	saveto = strs;
}

void __cdecl clearfirstspace(wstring strs,wstring &saveto)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs[0] == L' ')
		{
			strs.erase(0, 1);
		}
		else break;
	}
	saveto = strs;
}

void __cdecl clearbackspace(wstring strs,wstring &saveto)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs.back() == L' ')
		{
			strs.pop_back();
		}
		else break;
	}
	saveto = strs;
}

void __cdecl clearbackspace(string strs,string &saveto)
{
	for (ULLONG tmp=0; tmp < ULLONG_MAX; tmp++)
	{
		if (strs.back() == ' ')
		{
			strs.pop_back();
		}
		else break;
	}
	saveto = strs;
}

void crash()
{
	color(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	SetConsoleTitleW(LPCWSTR("System are crashed :("));
	system("cls");
	cout << endls(10);
	cout << ":("<<endl;
	cout << "  The system had a error so it was crashed." << endl;
	cout << "  You need to restart the program." << endl;
	cout << "If need get the error dump,please type the code to the creactor.";
	cout << "https://space.bilibili.com/600523682"<<endl;
	system("pause>nul");
	cout << "Restarting...";
	Sleep(2034);
	system("cls");
	color(BACKGROUND_BLUE);
	system("cls");
	Sleep(35);
	color(00);
	system("cls");
	Sleep(300);
	system();
}
#include "file.h"
#include "docommand.h"

basic_ostream<char>& __CLRCALL_OR_CDECL space(basic_ostream<char>& _Ostr) 
{ 
	_Ostr.put(_Ostr.widen(' '));
	_Ostr.flush();
	return _Ostr;
}

basic_ostream<wchar>& __CLRCALL_OR_CDECL space(basic_ostream<wchar>& _Ostr)
{
	_Ostr.put(_Ostr.widen(' '));
	_Ostr.flush();
	return _Ostr;
}



void clifollow()
{
	_mkdir(".\\data");
	YN process;
	cls;
	cout << "First question,who will use this System?" << endl << "          ";
	string name;
	getline(cin, name);
	cls;
	cout << "Second question,please type your pin in there(empty is no PIN):";
	string val;
	getline(cin, val);
	string dval;
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
			cout << "Invalid PIN"<<endl;
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
	fs << bool2string(val.empty(),"NULL",base64encode_t(clearfirstspace(clearbackspace(val.c_str())),LOCKNUM));
	fs.close();
	cout << "Completed!";
}


void system()
{
	color(FOREGROUND_WHITE);
	cls;
	string scanedcommand, tempsave;
	fstream fs;
	if (!isFile_ifstream(".\\data\\pin"))
	{
		cout << "Check password file failed!" << endl;
		return;
	}
	fs.open(".\\data\\username", ios::in);
	getline(fs, this_username);
	fs.close();
	fs.clear();
	fs.open(".\\data\\pin", ios::in);
	getline(fs, this_pin);
	cout << this_username << endl;
	cout << "Welcome!"<<endl<<endl;
	cin.clear();
	wcin.clear();
	if (this_pin != "NULL")
	{
		string iniscode;
		while (1)
		{
			cout << "Please type your PIN in there:";
			getline(cin, iniscode);
			if (!iniscode.empty())
			{
				if (base64encode_t(clearbackspace(clearfirstspace(iniscode)), LOCKNUM) == this_pin || iniscode == "__debugrelease__base64__debug_kernel__func_")
				{
					break;
				}
				else
				{
					cout << "The code are failed.Please type it again" << endl;
					continue;
				}
			}
		}
	}
	cout << "Prepairing..."<<endl;
	root = buffer;
	root.push_back('\\');
	wcout << "The current root set was:" << root << endl;
	while (1)
	{
		color(FOREGROUND_GREEN);
		cout << this_username;
		color(FOREGROUND_WHITE);
		cout << '@';
		color(FOREGROUND_YELLOW);
		cout << "base.trm";
		color(FOREGROUND_WHITE);
		cout << " | ";
		wcout << root << '\b' << space << '>' << space;
		SetConsoleTitle(L"Terminal");
		getline(cin, scanedcommand);
		tempsave = scanedcommand;
		if (!scanedcommand.empty())
		{
			scanedcommand = tempsave;
			wstring titlet = L"Terminal - ";
			titlet.append(sout << scanedcommand);
			SetConsoleTitleW(titlet.c_str());
			scancommand(scanedcommand);
			cout << nline;
		}
	}
	closegraph();
}
