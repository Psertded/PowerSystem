#include <graphics.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <direct.h>
#include <comdef.h>
using namespace std;

extern wstring version_info();
extern int system_main(int, const char* []);

#define RESERVE_TWO(x,y) y,x
#define RESERVE_ALL(x1,x2,y1,y2) y2,y1,x2,x1
#define TWO_TWO_RESERVE(x1,x2,y1,y2) x2,x1,y2,y1

#define VER "1.00"

_declspec(dllexport) extern int padmain(int s);

int main()
{
	padmain(0);
}