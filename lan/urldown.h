#pragma once

#include <windows.h>
#include <urlmon.h>
#include "..\includes.h"

void downloadfileprogress(double inz,ULONG all,ULONG hve)
{
    cout << "\rDownloading... [";
    for (int i = 0; i < int(inz + 0.5); i++)
    {
        cout << "¨€";
    }
    for (int i = 0; i < 100 - int(inz + 0.5); i++)
    {
        cout << ' ';
    }
    if (all >= 1000000)
    {
        cout << "]     " << fixed << setprecision(3) << inz << "%/100.00%          " << setiosflags(ios::left) << setw(4) << setprecision(3) << double(hve / 1000000.0);
        cout << " MB / " << fixed << setprecision(3) << double(all / 1000000.0) << " MB";
    }
    else if (all >= 1000)
    {
        cout << "]     " << fixed << setprecision(3) << inz << "%/100.00%          " << setiosflags(ios::left) << setw(6) << setprecision(3) << hve / 1000;
        cout << " KB / " << setprecision(3) << all / 1000 << " KB";
    }
    else
    {
        cout << "]     " << fixed << setprecision(3) << inz << "%/100.00%          " << setiosflags(ios::left) << setw(8) << hve;
        cout << " B / " << all << " B";
    }
}



class GraphicsProgress
{
public:
    void init()
    {
        initgraph(1000,10, EW_SHOWCONSOLE);
        setbkcolor(RGB(240, 240, 240));
        cleardevice();
    }
    void inmessage(UINT allbytse, UINT thisbyste, double scac)
    {
        setfillcolor(RGB(6, 176, 37));
        solidrectangle(0, 0, scac * 10, 10);
        setfillcolor(RGB(230, 230, 230));
        solidrectangle(scac * 10, 0, 1000, 10);
        cout <<setiosflags(ios::left)<< '\r' << fixed << setw(6) << setprecision(3) << thisbyste / 1000000.0 << 
            "MB/" << fixed << setw(6) << setprecision(3) << allbytse / 1000000.0 << "MB          ";
        cout << fixed << setprecision(3) << scac << '%';
    } 
    void inmessage_C(UINT allbytse, UINT thisbyste, double scac)
    {
        setfillcolor(RGB(6, 176, 37));
        solidrectangle(0, 0, scac * 10, 10);
        setfillcolor(RGB(230, 230, 230));
        solidrectangle(scac * 10, 0, 1000, 10);
    }
};

GraphicsProgress prg;

class DownloadProgress : public IBindStatusCallback 
{
public:
    clock_t t1, t2;
    ULONG upbyte;
    ULONG speed;
    HRESULT __stdcall QueryInterface(const IID&, void**) 
    {
        return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef(void) 
    {
        return 1;
    }
    ULONG STDMETHODCALLTYPE Release(void)
    {
        return 1;
    }
    HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding* pib) 
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG* pnPriority) 
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved) 
    {
        return ((HRESULT)0L);
    }
    virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed) 
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown* punk)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
    {
        t2 = clock();
        if (KEY_DOWN(rellist.downexitkey))
        {
            return E_ABORT;
        }
        if (ulProgressMax != 0)
        {
            double* percentage = new double(ulProgress * 1.0 / ulProgressMax * 100);
            downloadfileprogress(*percentage, ulProgressMax, ulProgress);
            delete percentage;
        }
        return ((HRESULT)0L);
    }
};

class DownloadProgress_GUI : public IBindStatusCallback
{
public:
    clock_t t1, t2;
    ULONG upbyte;
    ULONG speed;
    HRESULT __stdcall QueryInterface(const IID&, void**)
    {
        return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return 1;
    }
    ULONG STDMETHODCALLTYPE Release(void)
    {
        return 1;
    }
    HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding* pib)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG* pnPriority)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved)
    {
        return ((HRESULT)0L);
    }
    virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown* punk)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
    {
        t2 = clock();
        if (KEY_DOWN(rellist.downexitkey))
        {
            return E_ABORT;
        }
        if (ulProgressMax != 0)
        {
            double* percentage = new double(ulProgress * 1.0 / ulProgressMax * 100);
            prg.inmessage(ulProgressMax, ulProgress, *percentage);
            delete percentage;
        }
        return ((HRESULT)0L);
    }
};

class DownloadProgress_GCL : public IBindStatusCallback
{
public:
    clock_t t1, t2;
    ULONG upbyte;
    ULONG speed;
    HRESULT __stdcall QueryInterface(const IID&, void**)
    {
        return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return 1;
    }
    ULONG STDMETHODCALLTYPE Release(void)
    {
        return 1;
    }
    HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding* pib)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG* pnPriority)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved)
    {
        return ((HRESULT)0L);
    }
    virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown* punk)
    {
        return E_NOTIMPL;
    }
    virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
    {
        t2 = clock();
        if (KEY_DOWN(rellist.downexitkey))
        {
            return E_ABORT;
        }
        if (ulProgressMax != 0)
        {
            double* percentage = new double(ulProgress * 1.0 / ulProgressMax * 100);
            prg.inmessage_C(ulProgressMax, ulProgress, *percentage);
            downloadfileprogress(*percentage, ulProgressMax, ulProgress);
            delete percentage;
        }
        return ((HRESULT)0L);
    }
};