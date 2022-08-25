#pragma once

#include<Windows.h>
#include<iomanip>
#include<DShow.h>
#include<iostream>
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


int HandleEvent()
{
    int p;
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
        if (GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)
        {
            break;
            Release();
        }
        int p = (double)Pos / Len * 100;
        if (p >= 110)
        {
            return 0;
        }
        wstring c, d;
        while (p--)
        {
            c.push_back(L'¨€');
        }
        p = (double)Pos / Len * 100;
        while (p++ <= 100)
        {
            d.push_back(' ');
        }
        wcout << "\r\r[" << c << d << "]" << "    " << setw(6) << fixed << setprecision(3) << setiosflags(ios::left) << (double)Pos / Len * 100 << " % / 100.000 % ";
    }
    return 0;
}

