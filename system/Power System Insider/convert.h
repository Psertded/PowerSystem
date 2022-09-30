#pragma once

#include <windows.h>
#include <conio.h>
#include <string>
#include <comutil.h> 
#include <direct.h>
#include <locale>
#include <codecvt>
#include <wchar.h>

using namespace std;

#define _ADD_OPERATOR(returnvalue,operators , ...) returnvalue operator operators(__VA_ARGS__)
#define __ADD_OPERATOR(returnvalue,mode,operators , ...) returnvalue mode operator operators(__VA_ARGS__)


namespace convert
{
	class convert
	{
	public:
		const char* string2ccharx(string _before_str)
		{
			return _before_str.c_str();
		}
		char* string2charx(string _beforestr)
		{
			return const_cast<char*>(_beforestr.c_str());
		}
		char* ccharx2charx(const char* beforec)
		{
			return const_cast<char*>(beforec);
		}
		LPCWSTR operator <<(string& orig)
		{
			return ((wchar*)(((_bstr_t)(orig.c_str())).copy()));
		}
		LPCWSTR operator<<(wstring wStr)
		{
			return wStr.c_str();
		}
		LPCWSTR operator<<(const char* str)
		{
			return ((wchar*)(((_bstr_t)(str)).copy()));
		}
		LPWSTR ccharx2LPWSTR(const char* szString)
		{
			return ((wchar_t*)(((_bstr_t)(szString)).copy()));
		}
		LPCWSTR string2LPCWSTR(string& orig)
		{
			return ((wchar_t*)(((_bstr_t)(orig.c_str())).copy()));
		}
		wchar* wccharx2wcharx(const wchar* beforec)
		{
			return const_cast<wchar*>(beforec);
		}
		_ADD_OPERATOR
		(
			wchar*,
			<< ,
			const wchar* beforec
		)
		{
			return const_cast<wchar_t*>(beforec);
		}
		string wstring2string(const wstring& ws)
		{
			return ((char*)(((_bstr_t)(ws.c_str())).copy()));
		}
		wstring string2wstring(const string& s)
		{
			return ((wchar*)(((_bstr_t)(s.c_str())).copy()));
		}
		_ADD_OPERATOR
		(
			wstring,
			>> ,
			const string& s
		)
		{
			return ((wchar*)((_bstr_t)(s.c_str())).copy());
		}
		_ADD_OPERATOR
		(
			string,
			>> ,
			const wstring ws
		)
		{
			return ((char*)(((_bstr_t)(ws.c_str())).copy()));
		}
		_ADD_OPERATOR
		(
			LPCWSTR,
			>> ,
			LPWSTR orig
		)
		{
			return (LPCWSTR)orig;
		};
		_ADD_OPERATOR(char*, >> , const char* input)
		{
			return const_cast<char*>(input);
		}
		_ADD_OPERATOR(const char*, >> , char* input)
		{
			return input;
		};
	};
	convert cstream;
};

convert::convert sout;
