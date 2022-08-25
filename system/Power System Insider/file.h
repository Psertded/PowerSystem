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


wstring loadfile(wstring fname)
{
	wfstream fin;
	fname.insert(0, root);
	fin.open(fname.c_str(), wios::in);
	if (!fin.is_open())
	{
		cout << "Not found file." << endl;
		wstring ttl;
		return ttl;
	}
	cls;
	wchar buff = 0;
	wstring buf;
	while ((buff = fin.get()) != EOF)
	{
		buf.push_back(buff);
	}
	fin.close();
	return buf;
}
string loadfile(string fname)
{
	fstream fin;
	fname.insert(0, convert::cstream.wstring2string(root));
	fin.open(fname.c_str(), ios::in);
	if (!fin.is_open())
	{
		cout << "Not found file." << endl;
		string ends;
		return ends;
	}
	cls;
	char buff = 0;
	string buf;
	while ((buff = fin.get()) != EOF)
	{
		buf.push_back(buff);
	}
	fin.close();
	return buf;
}

void loadfile()
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
	while ((buff = fin.get()) != EOF)
	{
		buf.push_back(buff);
	}
	fin.close();
	system("pause");
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
	while ((buff = fin.get()) != EOF || KEY_DOWN(VK_ESCAPE))
	{
		wcout << buff;
	}
	fin.close();
	system("pause");
}

wstring _wloadfile()
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
		wstring space;
		return space;
	}
	cls;
	wchar buff = 0;
	wstring buf;
	while ((buff = fin.get()) != EOF)
	{
		buf.push_back(buff);
	}
	fin.close();
	return buf;
}

bool isFile_stat(wstring &wname,size_t size)
{
	wname.insert(0, root);
	struct _stat64i32 buffer;
	bool ifload=_wstat64i32(wname.c_str(), &buffer) == 0;
	return (ifload && (buffer.filesize > size) ? 1 : 0);
}

struct _stat64 getfileinfo(wstring &fname)
{
	fname.insert(0, root);
	struct _stat64 buf;
	_wstat64(fname.c_str(), &buf);
	return buf;
}
