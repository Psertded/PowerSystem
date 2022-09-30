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

bool bechar(char a)
{
	return ((a >= 32) && (a <= 127));
}

bool beochar(char a)
{
	return (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')));
}
bool benum(char a)
{
	if (a >= '0' && a <= '9')
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
		cout << "Press ESCAPE To exit";
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
		setbkmode(TRANSPARENT);
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

#define nline '\n'

#define STRING __cdecl

void error(wstring text)
{
	wcout << "Unknown command :" << " -" << text << "-" << (sout >> endls(2));
}

string getfullram()
{
	return "The control was deleted.";
}

string STRING toupper(string _Str)
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

wstring STRING toupper(wstring _Str)
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

string STRING tolower(string _Str)
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

wstring STRING tolower(wstring _Str)
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


namespace premium
{
	bool comcmp(wstring str1, wstring str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		for (; str1[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(len1) - 1] == ' '; len1--);
		for (; str1[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(len2) - 1] == ' '; len2--);
		if (len1 != len2)return false;
		for (int i = 0; i < len1; i++)
		{
			if (str1[i] == '/')str1[i] = '-';
			if (str2[i] == '/')str2[i] = '-';
			if (str1[i] != str2[i] && str1[i] + 32 != str2[i] && str1[i] - 32 != str2[i])
			{
				return false;
			}
		}
		return true;
	}

	int calc(const wstring& s)
	{
		vector<int> stk1;
		vector<char> stk2;
		int optnum = 0, isd = 0;
		auto cal = [&](char c)
		{
			int rhs = stk1.back();
			stk1.pop_back();
			int lhs = stk1.back();
			stk1.pop_back();
			switch (c)
			{
			case '+':
				stk1.push_back(lhs + rhs);
				break;
			case '-':
				stk1.push_back(lhs - rhs);
				break;
			case '*':
				stk1.push_back(lhs * rhs);
				break;
			case '/':
				stk1.push_back(lhs / rhs);
				break;
			}
		};
		auto level = [](char c)
		{
			switch (c)
			{
			case '(':
				return 0;
				break;
			case '+':
			case '-':
				return 1;
				break;
			case '*':
			case '/':
				return 2;
				break;
			}
			return -1;
		};
		for (const auto c : s)
		{
			if (c >= '0' and c <= '9')
			{
				optnum = 10 * optnum + (c - 48);
				isd = 1;
			}
			else
			{
				if (isd)
				{
					stk1.push_back(optnum);
					isd = 0;
					optnum = 0;
				}

				if (stk2.empty())
				{
					stk2.push_back(c);
				}
				else
				{
					switch (c)
					{
					case '(':
						stk2.push_back(c);
						break;
					case ')':
						while (stk2.back() != '(')
						{
							cal(stk2.back());
							stk2.pop_back();
						}
						stk2.pop_back();
						break;
					default:
						while (!stk2.empty() and level(c) <= level(stk2.back()))
						{
							cal(stk2.back());
							stk2.pop_back();
						}
						stk2.push_back(c);
					}
				}
			}
		}
		if (isdigit(s.back()))
		{
			stk1.push_back(optnum);
		}
		while (!stk2.empty())
		{
			cal(stk2.back());
			stk2.pop_back();
		}
		return stk1.back();
	}
};

void getFileNames(wstring path, vector<wstring>& files)
{
	intptr_t hFile = 0;
	struct _wfinddata_t fileinfo;
	wstring p;
	if ((hFile = _wfindfirst(p.assign(path).append(L"\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				files.push_back(fileinfo.name);
			}
			else
			{
				files.push_back(fileinfo.name);
			}
		} while (_wfindnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

const wchar* adddel(long long val)
{
	wstring str = to_wstring(val);
	size_t len = str.length();
	for (int index = (int)len - 3; index > 0; index -= 3)
		str.insert(index, L",");
	return str.c_str();
}


enum PVALTYPE
{
	nul = 0, newline = 1, pointer = 2, val = 4, message = 8
};

void ps_log(bool out_time, PVALTYPE style = nul, wstring input = L"", wstring secmessage = L"")
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = localtime(&timep);
	wifstream f;
	f.open(".\\log.txt", wios::in);
	bool theloghas = f.is_open();
	f.close();
	wfstream wfs;
	if (theloghas)
	{
		wfs.open(".\\log.txt", wios::app | wios::out);
	}
	else
	{
		CreateFile(L".\\log.txt", GENERIC_ALL, NULL, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		wfs.open(".\\log.txt", wios::app | wios::out);
	}
	char* timetmp = new char[1024];
	if (out_time)
	{

		time_t timep;
		struct tm* p;
		time(&timep);
		p = localtime(&timep);
		sprintf(timetmp, "[%04d/%02d/%02d %02d:%02d:%02d.%03d]", (1900 + (p->tm_year)), 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, (clock() % 1000));
		wfs << timetmp;
	}
	switch (style)
	{
	case nul:
		return;
		break;
	case newline:
		wfs << endl;
		return;
		break;
	case pointer:
		wfs << input << "-->" << secmessage << endl;
		return;
		break;
	case val:
		wfs << input << ':' << secmessage << endl;
		return;
		break;
	case message:
		wfs << input << endl;
		return;
		break;
	}
}

void ps_log(PVALTYPE style = nul, wstring input = L"", wstring secmessage = L"", bool out_time = true)
{
	ps_log(out_time, style, input, secmessage);
}

void ps_log(wstring input = L"", PVALTYPE style = message, wstring secmessage = L"", bool out_time = true)
{
	ps_log(out_time, style, input, secmessage);
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


void system()
{
	color(FOREGROUND_WHITE);
	string scanedcommand;
	fstream fs;
	if (!isFile_ifstream(".\\data\\pin"))
	{
		ps_log(true, val,L"FAILED", L"Check password file failed");
		cout << "Check password file failed!" << endl;
		return;
	}
	fs.open(".\\data\\username", ios::in);
	getline(fs, this_username);
	fs.close();
	fs.clear();
	ps_log(message,L"Success get Username");
	fs.open(".\\data\\pin", ios::in);
	getline(fs, this_pin);
	ps_log(message, L"Success get PIN");
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
				if (base64encode_t(clearbackspace(clearfirstspace(iniscode)), LOCKNUM) == this_pin)
				{
					ps_log(L"The PIN are correct");
					break;
				}
				else
				{
					ps_log(L"The PIN are failed");
					cout << "The code are failed.Please type it again" << endl;
					continue;
				}
			}
		}
	}
	if (!isFile_ifstream(".\\data\\pin"))
	{
		ps_log(true, val, L"FAILED", L"Check password file failed");
		cout << "Check password file failed!" << endl;
		return;
	}
	fs.open(".\\data\\username", ios::in);
	getline(fs, this_username);
	fs.close();
	fs.clear();
	ps_log(message, L"Success get Username");
	fs.open(".\\data\\pin", ios::in);
	getline(fs, this_pin);
	ps_log(message, L"Success get PIN");
	cout << this_username << endl;
	cout << "Welcome!" << endl << endl;
	cin.clear();
	wcin.clear();
	cout << "Prepairing..."<<endl;
	root = buffer;
	root.push_back('\\');
	wcout << "The current root set was:" << root << endl;
	ps_log(L"The root currectly set", val, root);
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
		if (!scanedcommand.empty())
		{
			wstring titlet = L"Terminal - ";
			titlet.append(sout << scanedcommand);
			SetConsoleTitleW(titlet.c_str());
			scancommand(scanedcommand);
			ps_log(wstring(L"Run the command:") + (sout << scanedcommand));
			cout << nline;
		}
	}
	closegraph();
}
