#pragma once


#include <string>
//stats

#define backspace '\b'

#define FOREGROUND_WHITE                FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED
#define FOREGROUND_YELLOW				FOREGROUND_RED | FOREGROUND_GREEN
#define FOREGEOUND_CYAN					FOREGROUND_BLUE | FOREGROUND_GREEN
#define FOREGROUND_PURPLE				FOREGROUND_BLUE | FOREGROUND_RED


#define ASCIIBSR						32

#define strsize size()


#define SND_BASE SND_FILENAME | SND_ASYNC

#define S_OK		 0
#define S_FAIL	 	 1
#define S_READ		 2
#define S_DEFINE	 3		 

#define sleep Sleep

#define yes          121
#define no           110

#define YES          89
#define no           78

#define null NULL

//control

#define cls						system("cls");

#define printhex(text)			hex<<text<<dex
#define re(start,truestat,doing)	for(int ttmmpppp=start;ttmmpppp##truestat;ttmmpppp##doing)


#define KEY_DOWN(KNAME) ((GetAsyncKeyState((unsigned short)KNAME)&0x8000)?1:0)
#define _DEFINE_USING_CPP(returnvalue,usingdesi,name,...)					returnvalue usingdesi name(__VA_ARGS__)

using wchar = wchar_t;

#define addroot(f)    f.insert(0,root);


//stat

#define drivename st_dev
#define filesys st_ino
#define ifntfs st_nlink
#define userid st_uid
#define groupid st_gid
#define filesize st_size

typedef unsigned long long ULLONG;

#define REMDO cout<<"The control has removed."<<endl;

typedef unsigned int SHA1;
#define wstr wstring

#define wwidth x
#define wheight y

#define popf erase(0,1)z
#define pushf(_Ch) insert(0,_Ch)

typedef wchar_t widechar;

#define charram char_traits

#define calcbase64 base64_encode

using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>;

#define LOCKNUM 40

#define EXPORT_DLL __declspec(dllexport)

#define UNFOR unsigned

//char

#define POINT_UP					L'\x25b4'
#define POINT_DOWN					L'\x25be'
#define POINT_LEFT					L'\x25c2'
#define POINT_RIGHT					L'\x25b8'
