#include <graphics.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <direct.h>
#include <comdef.h>
using namespace std;

extern wstring version_info();
extern int system_main(int, const char* []);

#define RESERVE_TWO(x,y) y,x
#define RESERVE_ALL(x1,x2,y1,y2) y2,y1,x2,x1
#define TWO_TWO_RESERVE(x1,x2,y1,y2) x2,x1,y2,y1

#define VER "1.00"

_declspec(dllexport) int padmain(int s)
{
	ExMessage EMG;
	initgraph(640, 480);
	IMAGE logo;
	loadimage(&logo, L".\\image\\logo", 200, 200);
	BYTE select = 0;
	setbkmode(TRANSPARENT);
	while (1)
	{
		cleardevice();
		setlinecolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
		setlinestyle(PS_SOLID, 3);
		settextstyle(15, 0, L"Moder DOS 437");
		outtextxy(245, 3, L"Power LaunchPad");
		outtextxy(RESERVE_TWO(425, 30), L"Use the ¡ü and ¡ý keys to select which entry is highlighted.");
		outtextxy(RESERVE_TWO(440, 30), L"Press enter to boot selected OS.");
		settextstyle(12, 0, L"Moder DOS 437");
		outtextxy(15, 460, (wstring(L"System Version data:"+wstring(version_info())).c_str()));
		outtextxy(15, 470, (std::wstring(L"Launcher Version:") + std::wstring(TEXT(VER))).c_str());
		settextstyle(15, 0, L"Moder DOS 437");
		rectangle(5, 20, 635, 400);
		line(5, 245, 635, 245);
		line(TWO_TWO_RESERVE(245, 50, 400, 50));
		putimage(80, 35, &logo);
		settextstyle(60, 0, L"Cascadia Code");
		outtextxy(300, 45, L"Power");
		outtextxy(300, 95, L"System");
		settextstyle(20, 0, L"Moder DOS 437");
		outtextxy(500, 110, L"Psertded");
		settextstyle(16, 0, L"Moder DOS 437");
		if (select == 0)
		{
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));	
			setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(14, 258, L"[1]");
			outtextxy(14, 288, L"[2]");
			outtextxy(14, 318, L"[3]");
			solidrectangle(55, 250, 630, 275);
			settextcolor(0);
			outtextxy(70, 258, (wstring(L"*  Boot Power System - ") + wstring(version_info())).c_str());
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(70, 288, L"   Tools");
			outtextxy(70, 318, L"   Exit");
		}
		else if (select == 1)
		{
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(14, 258, L"[1]");
			outtextxy(14, 288, L"[2]");
			outtextxy(14, 318, L"[3]");
			solidrectangle(55, 280, 630, 305);
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));

			outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
			settextcolor(0);
			outtextxy(70, 288, L"*  Tools");
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(70, 318, L"   Exit");
		}
		else if (select == 2)
		{
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(14, 258, L"[1]");
			outtextxy(14, 288, L"[2]");
			outtextxy(14, 318, L"[3]");
			solidrectangle(55, 310, 630, 335);
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
			outtextxy(70, 288, L"   Tools");
			settextcolor(0);
			outtextxy(70, 318, L"*  Exit");
			settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
			setlinestyle(PS_SOLID, 3);
			settextstyle(15, 0, L"Moder DOS 437");
			outtextxy(245, 3, L"Power LaunchPad");
		}
		while (1)
		{
			if (GetKeyState((USHORT)VK_ESCAPE) & 0x8000)
			{
				closegraph();
				exit(0x10);//Press ESC to exit.
			}
			else if (GetKeyState((USHORT)VK_RETURN) & 0x8000)
			{
				if (select == 0)
				{
					closegraph();
					system_main(0, 0);
				}
				if (select == 1)
				{
					MessageBox(NULL, L"Not create~Next Version willed!", L"From Psertded's warning", MB_OK | MB_ICONASTERISK);
					Sleep(300);
				}
				if (select == 2)
				{
					closegraph();
					return 0x12;//Exit options;
				}
				break;
			}
			else if (GetKeyState((USHORT)VK_UP) & 0x8000)
			{
				if (select == 0)
				{
					select = 0;
				}
				else
				{
					select--;
				}
				Sleep(150);
				break;
			}
			else if (GetKeyState((USHORT)VK_DOWN) & 0x8000)
			{
				if (select == 2)
				{
					select = 2;
				}
				else
				{
					select++;
				}
				Sleep(150);
				break;
			}
			else if (GetKeyState((USHORT)'1') & 0x8000)
			{
				select = 0;
				break;
			}
			else if (GetKeyState((USHORT)'2') & 0x8000)
			{
				select = 1;
				break;
			}
			else if (GetKeyState((USHORT)'3') & 0x8000)
			{
				select = 2;
				break;
			}
			getmessage(&EMG);
			if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 250 && EMG.x <= 630 && EMG.y <= 275)
			{
				select = 0;
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 250, 630, 275);
				settextcolor(0);
				outtextxy(70, 258, (wstring(L"*  Boot Power System - ") + wstring(version_info())).c_str());
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 288, L"   Tools");
				outtextxy(70, 318, L"   Exit");
				Sleep(10);
				closegraph();
				system_main(0, 0);
			}
			if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 280 && EMG.x <= 630 && EMG.y <= 305)
			{
				select = 1;
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 280, 630, 305);
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));

				outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
				settextcolor(0);
				outtextxy(70, 288, L"*  Tools");
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 318, L"   Exit");
				MessageBox(NULL, L"Not create~Next Version willed!", L"From Psertded's warning", MB_OK | MB_ICONASTERISK);
				Sleep(300);
				break;
			}
			if (EMG.lbutton && EMG.x >= 55 && EMG.y >= 310 && EMG.x <= 630 && EMG.y <= 335)
			{
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setfillcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(14, 258, L"[1]");
				outtextxy(14, 288, L"[2]");
				outtextxy(14, 318, L"[3]");
				solidrectangle(55, 310, 630, 335);
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				outtextxy(70, 258, (wstring(L"   Boot Power System - ") + wstring(version_info())).c_str());
				outtextxy(70, 288, L"   Tools");
				settextcolor(0);
				outtextxy(70, 318, L"*  Exit");
				settextcolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
				setlinestyle(PS_SOLID, 3);
				settextstyle(15, 0, L"Moder DOS 437");
				outtextxy(245, 3, L"Power LaunchPad");
				Sleep(10);
				select = 2;
				closegraph();
				return(0x12);
			}
			if (EMG.lbutton && EMG.x >= 360 && EMG.x <= 410 && EMG.y >= 110 && EMG.y <= 145)
			{
				system("start https://github.com/Psertded/Power-System");
			}
			if (EMG.lbutton && EMG.x >= 500 && EMG.x <= 568 && EMG.y >= 110 && EMG.y <= 123)//68,13
			{
				system("start https://space.bilibili.com/600523682");
			}
		}
		setlinecolor(((COLORREF)(((BYTE)(255) | ((WORD)((BYTE)(255)) << 8)) | (((DWORD)(BYTE)(255)) << 16))));
		setlinestyle(PS_SOLID, 3);
		settextstyle(15, 0, L"Moder DOS 437");
		outtextxy(245, 3, L"Power LaunchPad");
	}
	closegraph();
	return 0;
}