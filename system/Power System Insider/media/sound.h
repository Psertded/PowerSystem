#pragma once

#include <Windows.h>
#include <iomanip>
#include <DShow.h>
#include <iostream>
#include "controls.h"
using namespace std;
#pragma comment(lib,"strmiids.lib")
IGraphBuilder* g_pGraphBuilder = NULL;
IMediaControl* g_pMediaControl = NULL;
IMediaEvent* g_pMediaEvents = NULL;
IBasicAudio* g_pBasicAudio = NULL;
IMediaSeeking* g_pMediaSeeking = NULL;


void Release()
{
    if (g_pMediaControl != NULL)g_pMediaControl->Stop();


    if (g_pMediaEvents != NULL)
    {
        g_pMediaEvents->Release();
        g_pMediaEvents = NULL;
    }


    if (g_pMediaControl != NULL)
    {
        g_pMediaControl->Release();
        g_pMediaControl = NULL;
    }


    if (g_pGraphBuilder != NULL)
    {
        g_pGraphBuilder->Release();
        g_pGraphBuilder = NULL;
    }
}

LPCWSTR foubname;


void PlayMusic(LPCWSTR fileName)
{
    g_pGraphBuilder->RenderFile(fileName, NULL);

    g_pMediaControl->Run();
}


int HandleEvent(LPCWSTR fileName)
{
    int p;
    bool is_pause = false;
    while (TRUE)
    {
        long event_code;
        bool ca = false;
        long long param1, param2;
        if (SUCCEEDED(g_pMediaEvents->GetEvent(&event_code, &param1, &param2, 1)))
        {
            if (event_code == EC_COMPLETE)
            {
                g_pMediaControl->Stop();
                break;
            }
            g_pMediaEvents->FreeEventParams(event_code, param1, param2);
        }
        __int64 Len = -1, Pos = -1;
        g_pMediaSeeking->GetDuration(&Len);
        g_pMediaSeeking->GetCurrentPosition(&Pos);
        if (GetKeyState((unsigned short)VK_ESCAPE) & 0x8000)
        {
            break;
            Release();
        }
        if (GetKeyState((unsigned short)VK_SPACE) & 0x8000)
        {
            if (is_pause)
            {
                is_pause = false;
                g_pMediaControl->Run();
            }
            else
            {
                is_pause = true;
                g_pMediaControl->Stop();
            }
            Sleep(150);
        }
        if (GetKeyState((unsigned short)'R') & 0x8000)
        {
            Release();
            Pos = 0;
            if (FAILED(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&g_pGraphBuilder)))
            {
                cout << "CoCreateInstance failed" << endl;
                Release();
                CoUninitialize();
                return 0;
            }
            g_pGraphBuilder->QueryInterface(IID_IMediaControl, (void**)&g_pMediaControl);
            g_pGraphBuilder->QueryInterface(IID_IMediaEvent, (void**)&g_pMediaEvents);
            g_pGraphBuilder->QueryInterface(IID_IBasicAudio, (void**)&g_pBasicAudio);
            g_pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void**)&g_pMediaSeeking);
            g_pGraphBuilder->RenderFile(fileName, NULL);
            g_pMediaControl->Run();
            Sleep(150);
        }
        int p = (double)Pos / Len * 100;
        wstring c, d;
        while (p--)
        {
            c.push_back(L'¨€');
            if (c.size() > 110)
                return -1;
        }
        p = (double)Pos / Len * 100;
        while (p++ <= 100)
        {
            d.push_back(' ');
            if (d.size() > 110)
                return -1;
        }
        wcout << "\r[" << c << d << "]" << "    " << setw(6) << fixed << setprecision(3) << setiosflags(ios::left) << (double)Pos / Len * 100 << " % / 100.000 % ";
        if (is_pause)
            cout << "Pause...";
    }
    Release();
    return 0;
}

