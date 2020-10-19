#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#pragma comment(lib,"Urlmon.lib")

int _tmain(int argc, TCHAR* argv[])
{
	HKEY hKey = NULL;
	TCHAR* lpszSubKey = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
	LONG lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS, &hKey);
	if (lRet == ERROR_SUCCESS)
	{
		DWORD dwType = 0, dwDataLen = 0;
		BYTE* lpData = NULL;
		lRet = RegQueryValueEx(hKey, _T("YoukuMediaCenter"), NULL, &dwType, NULL, &dwDataLen);
		lpData = new BYTE[dwDataLen + 1];
		ZeroMemory(lpData, dwDataLen + 1);
		lRet = RegQueryValueEx(hKey, _T("YoukuMediaCenter"), NULL, &dwType,lpData,&dwDataLen);
		RegCloseKey(hKey);

		wcout << lpData << endl;
	}

	return 0;
}