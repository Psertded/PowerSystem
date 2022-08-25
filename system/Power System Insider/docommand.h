#pragma once

#include "includes.h"

#include "controls.h"

#undef closegraph


#define elif else if


int scancommand(string text)
{
	color(FOREGROUND_WHITE);
	int commant = 101;
	string ntext = clearfirstspace(text);
	if (ntext.empty())return 0;
	string nntext = clearbackspace(ntext);
	if (nntext.empty())return 0;
	for (int i = 0; i < 100; i++)
	{
		if (tolower(nntext) == commandlist[i])
		{
			commant = i + 1;
			break;
		}
	}
	if (commant == 1)
	{
		color(FOREGROUND_WHITE);
		cout << ver;
	}
	if (commant == 2 || commant == 3 || commant == 4)
	{
		color(FOREGROUND_WHITE);
		wstring sca;
		cout << "Out text:";
		getline(wcin, sca);
		wcout << endl << sca << endl;
		
	}
	if (commant == 5 || commant == 6)
	{
		color(FOREGROUND_WHITE);
		cls;
	}
	if (commant == 7)
	{
		color(FOREGROUND_WHITE);
		exit(0);
	}
	if (commant == 8)
	{
		color(FOREGROUND_WHITE);
		cout << "None doing." << endl;
	}
	if (commant == 9)
	{
		color(FOREGROUND_WHITE);
		cout << endl << endl;
		for (int i = 0; i <= 255; i++)
		{
			if (i % 16 == 0)
			{
				cout << endl;
			}
			color(i);
			printf("% 4d ", i);
		}
		color(FOREGROUND_WHITE);

	}
	if (commant == 10)
	{
		exit(0);
	}
	if (commant == 11)
	{
		Sleep(1000);
		crash();
	}
	if (commant == 12)
	{
		for (int i = 0; i < 40; i++)
		{
			cout << setiosflags(ios::left) << setw(20) << commandlist[i];
			cout << " - " << helps[i] << endl;
		}
		cout << "--More--";
		system("pause>nul");
		endl(cout);
		for (int i = 41; i < 67; i++)
		{
			cout << setiosflags(ios::left) << setw(20) << commandlist[i];
			cout << " - " << helps[i] << endl;
		}
		cout << setiosflags(ios::right);
	}
	if (commant == 13)
	{
		int ret=guide::gmain(guidehwnd,L"Terminal - Graphics User Interface");
	}
	if (commant == 14)
	{
		color(FOREGROUND_WHITE);
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
	if (commant == 15)
	{
		cls;
		cout << "Removed";
	}
	if (commant == 16)
	{
		color(FOREGROUND_WHITE);
		cout << gettime() << endls(2);
	}
	if (commant == 17)
	{
		color(FOREGROUND_WHITE);
		SKIPBOOT = 1;
	}
	if (commant == 18)
	{
		color(FOREGROUND_WHITE);
		cout << "Press any key to continue...";
		system("pause>nul");
		cout << endl;
	}
	if (commant == 19)
	{
		color(FOREGROUND_WHITE);
		unsigned long long full = 0;
		cout << "RAM Full(KB):";
		cin >> full;
		fullram(full);
	}
	if (commant == 20)
	{
		cout << "The Control was deleted.";
	}
	if (commant == 21)
	{
		color(FOREGROUND_WHITE);
		cout << getfullram();
	}
	if (commant == 22)
	{
		color(FOREGROUND_WHITE);
		wstring tt1;
		UINT tt2;
		cout << "Text:";
		getline(wcin, tt1);
		cout << "Sleep time(Second):";
		cin >> tt2;
		tracks::init(tt1, tt2);
	}
	if (commant == 23)
	{
		cout << "REMOVED";
	}
	if (commant == 24)
	{
		cout << "Execute Name:";
		wstring efas;
		getline(wcin, efas);
		efas.insert(0, root);
		boot(efas);
	}
	if (commant == 25)
	{
		cout << "File name:";
		wstring fname;
		getline(wcin, fname);
		CoInitialize(NULL);
		fname.insert(0, root);
		if (FAILED(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&g_pGraphBuilder)))
		{
			cout << "CoCreateInstance failed" << endl;
			Release();
			CoUninitialize();
			return 0;
		}
		CONSOLE_CURSOR_INFO co;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&co);
		co.bVisible = false;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &co);
		g_pGraphBuilder->QueryInterface(IID_IMediaControl, (void**)&g_pMediaControl);
		g_pGraphBuilder->QueryInterface(IID_IMediaEvent, (void**)&g_pMediaEvents);
		g_pGraphBuilder->QueryInterface(IID_IBasicAudio, (void**)&g_pBasicAudio);
		g_pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void**)&g_pMediaSeeking);
		PlayMusic(fname.c_str());
		cout << "Press [Space]to pause/continue.\nPress [ESC] to exit.\nPress [R] to replay.";
		if (HandleEvent() == -1)
		{
			wcout << "Failed:Not found file - " << fname;
		}
		Release();
		CoUninitialize();
		co.bVisible = true;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &co);
	}
	if (commant == 26 || commant == 50)
	{
		cout << "Root Where:";
		wstring rooast;
		getline(wcin, rooast);
		if (!rooast.empty())
		{
			char tmp = rooast.back();
			if (tmp != '\\')
			{
				rooast.push_back('\\');
			}
			if (rooast[0] == '\\')
			{
				rooast.erase(0, 1);
				rooast.insert(0, root);
			}
			if (rooast[0] == '.' && rooast[1] == '\\')
			{
				wstring bufs = rooast.substr(0, 2);
				if (wcscmp(bufs.c_str(), root.c_str()) != 0)
				{
					rooast.erase(0, 2);
					rooast.insert(0, root);
				}
			}
			if (bechar(rooast[0]) && bechar(rooast[1]))
			{
				rooast.insert(0, root);
			}
			if (rooast[0] == '.' || rooast[0] == '.')
			{
				const wchar* tmpss = root.substr(1).c_str();
				if (tmpss == L":\\")
				{
					cout << "This is the root directory." << endl;
					return false;
				}
				wstring ttm = root;
				ttm.pop_back();
				size_t len = ttm.find_last_of(L"\\");
				ttm.erase(++len, string::npos);
				rooast = ttm;
			}
			root = rooast;
			wcout << endl << endl << "Root AS         " << root << endl;
		}
	}
	if (commant == 27)
	{
		REMDO
	}
	if (commant == 61 || commant==28)
	{
		fstream fs;
		remove(".\\data\\username");
		cout << "Name:";
		string uname;
		getline(cin, uname);
		fs.open(".\\data\\username", ios::trunc | ios::out);
		fs << uname;
		this_username = uname;
	}
	if (commant == 29)
	{
		REMDO
	}
	if (commant == 30)
	{
		REMDO
	}
	if (commant == 31)
	{
		cout << "File name:";
		wstring filem;
		getline(wcin, filem);
		filem.insert(0, root);
		fstream f;
		f.open(filem, wios::app);
		if (!f.is_open())
		{
			cout << "Failed to open ";
		}
		else
		{
			CreateFile(sout << filem, GENERIC_WRITE | GENERIC_READ, NULL, NULL, CREATE_ALWAYS, NULL, NULL);
		}
	}
	if (commant == 32)
	{
		ULLONG lines;
		wstring fmale;
		wfstream fil;
		cout << "File name:";
		getline(wcin, fmale);
		fmale.insert(0, root);
		cout << "Lines:";
		cin >> lines;
		fil.open(fmale, wios::out | wios::app);
		if (!fil.is_open())
		{
			cout << "Invalid!";
			return false;
		}
		else
		{
			cls;
			wstring in;
			for (int i = 0; i < lines + 1; i++)
			{
				getline(wcin, in);
				in.push_back('\n');
				fil << in;
			}
		}
	}
	if (commant == 33)
	{
		cout << "Using sys/stat." << endl;
		cout << "File name:";
		wstring fname;
		getline(wcin, fname);
		fname.insert(0, root);
		if (isFile_stat(fname))
		{
			color(FOREGROUND_GREEN);
			cout << "Exist." << endl << endl;
			color(FOREGROUND_WHITE);
		}
		else
		{
			color(FOREGROUND_RED);
			cout << "NONE." << endl << endl;
			color(FOREGROUND_WHITE);
		}
	}
	if (commant == 34)
	{
		WCHAR wchars[MAX_PATH];
		swprintf(wchars, L"dir \"%ls\"", root.c_str());
		_wsystem(wchars);
		//It make me a morning,Fuck!!!!!!!!!!
	}
	if (commant == 35)
	{
		wloadfile();
	}
	if (commant == 36)
	{
		wstring fname;
		cout << "File name:";
		getline(wcin, fname);
		fname.insert(0, root);
		if (_wremove(fname.c_str()) == 0)
		{
			cout << "Complete";
		}
		else
		{
			cout << "Invalid";
		}
	}
	if (commant == 37)
	{
		cout << "Directory Name:";
		wstring fn;
		getline(wcin, fn);
		fn.insert(0, root);
		_wmkdir(fn.c_str());
	}
	if (commant == 38)
	{
		cout << "Directory Name:";
		wstring fn;
		getline(wcin, fn);
		fn.insert(0, root);
		_wrmdir(fn.c_str());

	}
	if (commant == 39)
	{
		system("%systemroot%\\system32\\cmd.exe");  
	}
	if (commant == 40)
	{
		cout << "This command has many bug,so it was removed";
	}
	if (commant == 41)
	{
		wstring filelng;
		cout << "File name:";
		wstring fname; 
		getline(wcin, fname);
		fname.insert(0, root);
		cout << "File long(Byte):";
		wcin >> filelng;
		wstring command = sout << "fsutil file createnew ";
		command.append(wcscpy(sout << (fname.c_str()), wcscpy(sout << (sout << " "), filelng.c_str())));
		_wsystem(command.c_str());
	}
	if (commant == 42)
	{
		wstring f1;
		wstring f2;
		wcout << "File name:";
		getline(wcin, f1);
		wcout << "Copy to where:";
		getline(wcin, f2);
		if (f2.back() != '\\')
		{
			f2.push_back('\\');
		}
		f1.insert(0, root);
		if (isFile_ifstream(f2 + f1))
		{
			cout << "The fine was have.Cover it?  (Y/N)";
			char yn;
			cin >> yn;
			if (yn != 'Y')
			{
				CopyFile(sout << f1, (f2 + f1).c_str(), FALSE);
			}
			else CopyFile(sout << f1, (f2 + f1).c_str(), TRUE);
		}
		else
		{
			CopyFile(sout << f1, (f2 + f1).c_str(), FALSE);
		}
		
	}
	if (commant == 43)
	{
		wstring f1;
		wstring f2;
		wcout << "File name:";
		getline(wcin, f1);
		f1.insert(0, root);
		wcout << "Move to where:";
		getline(wcin, f2);
		if (f2.back() != '\\')
		{
			f2.push_back('\\');
		}
		MoveFile(sout << f1, sout << f2);
	}
	if (commant == 44 || commant == 45)
	{
		wstring fname1;
		wstring end;
		cout << "File name:";
		getline(wcin, fname1);
		fname1.insert(0, root);
		cout << "Rename to:";
		getline(wcin, end);
		_wrename(fname1.c_str(), end.c_str());
	}
	if (commant == 46)
	{
		cout << "The control has removed";
	}
	if (commant == 47)
	{
		REMDO
	}
	if (commant == 48)
	{
		REMDO
	}
	if (commant == 49)
	{
		wstring ttm = root;
		if (ttm.size() == 3)
		{
			return false;
		}
		ttm.pop_back();
		size_t len = ttm.find_last_of(L"\\");
		ttm.erase(++len, string::npos);
		root = ttm;
	}
	if (commant == 51)
	{
		wstring finfo = _wloadfile();
		hash <wstring> calc;
		SHA1 hashcalc = calc(finfo);
		printf("\n\n%llX", hashcalc);
	}
	if (commant == 52)
	{
		cout << "Lines:";
		ULLONG lines=NULL;
		cin >> lines;
		wstring line;
		wstring all;
		hash<wstring>calc;
		cls;
		for (ULLONG tms = 0; tms < lines; tms++)
		{
			getline(wcin, line);
			all.append(line);
			all.push_back('\n');
		}
		printf("%llX", calc(all));
	}
	if (commant == 53)
	{
		loadimg();
	}
	if (commant == 55)
	{
		wcin.clear();
		cin.clear();
		wcout.clear();
		cout.clear();
	}
	if (commant == 56)
	{
		vector<vector<COLORREF>> trmp;
		wloadimg(trmp);
		wfstream fin;
		cout << "File name:";
		wstring fname;
		getline(wcin, fname);
		addroot(fname);
		fin.open(fname, wios::out | wios::in);
		fin << gx << endl << gy << endl;
		if (fin.good())
		{
			for (int i = 0; i <= gx; i++)
			{
				for (int j = 0; j <= gy; j++)
				{
					fin << trmp[i][j]<<endl;
				}
			}
		}
		else cout << "Invalid.";
	}
	if (commant == 57)
	{
		cout << "X:";
		cin >> graphx;
		cout << "Y:";
		cin >> graphy;
	}
	if (commant == 58)
	{
		cout << "Launching...";

		if (!function_debugpack)
		{
			cout << "The Debug Pack not init.";
		}
		else
		{
			cout << "Execute name 1 (Child):";
			int hnd1, hnd2;
			scanf_s("%lX", &hnd1);
			cout << "Execute name 2 (Parent):";
			scanf_s("%lX", &hnd2);
			HWND hwnd1, hwnd2;
			hwnd1 = (HWND)hnd1;
			hwnd2 = (HWND)hnd2;
			SetParent(hwnd1, hwnd2);
		}
	}
	if (commant == 60)
	{
		if (this_pin != "NULL")
		{
			string iniscode;
			while (1)
			{
				cout << "Please type your PIN in there:";
				getline(cin, iniscode);
				if (base64encode_t(clearbackspace(clearfirstspace(iniscode)).c_str(),LOCKNUM) == this_pin)
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
		cout << endl << endl << "Please type your new PIN:";
		string pin;
		getline(cin, pin);
		string npin;
		cls;
		while (true)
		{
			cout << "Please retype your PIN : ";
			getline(cin, npin);
			if (npin == pin)
			{
				break;
			}
			else
			{
				cout << "Invalid PIN" << endl;
			}
		}
		fstream fs;
		fs.open(".\\data\\pin", ios::out);
		remove(".\\data\\pin");
		fs << bool2string((pin.empty()), "NULL", base64encode_t(clearfirstspace(clearbackspace(pin.c_str())),LOCKNUM));
		fs.close();
		cout.put(cout.widen('\n'));
		cout << endl << "Your PIN are rewrited";
	}
	if (commant == 62)
	{
		cout << "Lines:";
		int lns;
		cin >> lns;
		string buf;
		string butbuf;
		for (int i = 0; i < lns; i++)
		{
			getline(cin, buf);
			butbuf.append(buf);
		}
		cout<<base64_encode(butbuf.c_str());
	}
	if (commant == 63)
	{
		cout << "Lines:";
		int lns;
		cin >> lns;
		string buf;
		string butbuf;
		for (int i = 0; i < lns; i++)
		{
			getline(cin, buf);
			butbuf.append(buf);
		}
		cout << base64_decode(butbuf);
	}
	if (commant == 64)
	{
		cout << "Message:";
		wstring g;
		getline(wcin, g);
		cout << "Time:";
		int vol;
		cin >> vol;
		tracks::guide(g, vol, NULL);
	}
	if (commant == 65)
	{
		cls;
		while (!_kbhit())
		{
			Sleep(1);
		}
	}
	if (commant == 66)
	{
		cout << "URL:";
		wstring url;
		getline(wcin, url);
		DeleteUrlCacheEntry(url.c_str());
		wstring fname;
		cout << "File name:";
		getline(wcin, fname);
		fname.insert(0, root);
		GetConsoleCursorInfo(handle, &CursorInfo);
		CursorInfo.bVisible = false;
		SetConsoleCursorInfo(handle, &CursorInfo);
		ios::sync_with_stdio(false);
		HRESULT get;
		if (rellist.GUIDownload == 0)
		{
			DownloadProgress_GCL progress;
			prg.init();
			printf("Press [%c] to exit the download.%c", rellist.downexitkey, '\n');
			IBindStatusCallback* callback = (IBindStatusCallback*)&progress;
			get = URLDownloadToFile(NULL, url.c_str(), fname.c_str(), NULL, static_cast<IBindStatusCallback*>(&progress));
		}
		else if (rellist.GUIDownload == 1)
		{
			DownloadProgress progress;
			prg.init();
			printf("Press [%c] to exit the download.%c", rellist.downexitkey, '\n');
			IBindStatusCallback* callback = (IBindStatusCallback*)&progress;
			get = URLDownloadToFile(NULL, url.c_str(), fname.c_str(), NULL, static_cast<IBindStatusCallback*>(&progress));
		}
		else
		{
			DownloadProgress_GUI progress;
			prg.init();
			printf("Press [%c] to exit the download.%c", rellist.downexitkey, '\n');
			IBindStatusCallback* callback = (IBindStatusCallback*)&progress;
			get = URLDownloadToFile(NULL, url.c_str(), fname.c_str(), NULL, static_cast<IBindStatusCallback*>(&progress));
		}
		closegraph();
		if (get == S_OK)
		{
			cout << endl << endl << "Completed!";
		}
		else if (get == E_OUTOFMEMORY)
		{
			cout << endl << endl << "Out of memory";
		}
		else if (get == INET_E_DOWNLOAD_FAILURE)
		{
			cout << endl << endl << "Failed URL";
		}
		ios::sync_with_stdio(true);
		GetConsoleCursorInfo(handle, &CursorInfo);
		CursorInfo.bVisible = true;
		SetConsoleCursorInfo(handle, &CursorInfo);
		closegraph();
	}
	if (commant == 66)
	{
		cout << "You can edit in .\\data\\settings ." << endl << "DownGUI\n = 0 : GUI + CLI\n = 1 : CLI \n = 2 : GUI\n\nDownExitKey\n The exit key(ASCII Code).";
		cout << endl << "The Graphics editor will install in next version.";
	}
	if (commant == 101)
	{
		color(FOREGROUND_WHITE);
		error(sout << text);
		return false;
	}
	return true;
}