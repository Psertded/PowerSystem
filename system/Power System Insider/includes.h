#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#define DEBUGGER			"Bilibili\\Psertded"


#include <comdef.h>
#include <graphics.h>
#include <shellapi.h>
#include <windows.h>
#include <iostream>
#include <urlmon.h>
#include <TlHelp32.h>
#include <map>
#include <wininet.h>
#include <fstream>
#include <random>
#include <dshow.h>
#include <iomanip>
#include <string>
#include <vector>

//unistd.h
#include <io.h>
#include <process.h>

#include "defined.h"
#include "settings.h"
#include "media/sound.h"
#include "cbxtxt.h"
#include "base64.h"
#include "lan/urldown.h"
#include "using.h"


using namespace std;

fstream file;
wfstream wfile;

HWND syshwnd,guidehwnd;

wchar buffer[MAX_PATH];

wstring origroot;


IGraphBuilder* pGBuilder;
IMediaControl* pMControl;
IMediaPosition* pMPos;
IMediaEvent* pEvent;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO CursorInfo;

UINT graphx = 1920;
UINT graphy = 1080;

string this_username, this_pin;