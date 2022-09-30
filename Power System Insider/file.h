#include "controls.h"


bool isFile_ifstream(wstring name)
{
	name.insert(0, root);
	wfstream f(name.c_str());
	return f.is_open();
}


bool isFile_ifstream(string name)
{
	wstring name2=root+sout.string2wstring(name);
	wfstream f(name2.c_str());
	return f.is_open();
}



bool isFile_stat(wstring name)
{
	name.insert(0, root);
	struct _stat64i32 buffer;
	return (_wstat(name.c_str(), &buffer) == 0);
}

bool isFile_stat(string name)
{
	name.insert(0, sout.wstring2string(root));
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}


void wloadfile()
{
	wfstream fin;
	wstring fname;
	cout << "File name:";
	getline(wcin, fname);
	fname.insert(0, root);
	fin.open(fname.c_str(), wios::in);
	if (!fin.is_open())
	{
		cout << "Not found file." << endl;
		return;
	}
	cls;
	wchar buff = 0;
	wstring buf;
	while (!(fin.eof()) || KEY_DOWN(VK_ESCAPE))
	{
		wcout << fin.get();
	}
	fin.close();
	while (!_kbhit())
	{
		Sleep(0);
	}
}



struct _stat64 getfileinfo(wstring &fname)
{
	fname.insert(0, root);
	struct _stat64 buf;
	_wstat64(fname.c_str(), &buf);
	return buf;
}
