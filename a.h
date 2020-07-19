#pragma once
#include <sdkddkver.h>
#include <stdio.h>
#include <tchar.h>
#include <bitset>
#include <conio.h>
#include "atlstr.h"
#include <atlimage.h>
#include <iostream>
#include <WinSock2.h>
#include "Winhttp.h"
#define INITGUID
#include <guiddef.h>
#include <GPEdit.h>
#include <Shlwapi.h>
#include <direct.h>
#pragma warning(disable: 4996)
#include <ctime>
#include <TlHelp32.h>
#include <Psapi.h>
#include <io.h>
#include <iphlpapi.h>
#include <fstream>
#include <string>
#include <process.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <sys/timeb.h>
#include <ShlObj.h>
#include <vector>
#pragma comment(lib,"Iphlpapi.lib")
#pragma comment(lib,"winhttp.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"psapi.lib")
#pragma comment(lib,"shlwapi.lib")
using namespace std;
/*VOID randomseed()
{
	srand(time(0));
}
FLOAT randomnum(FLOAT 底数, WORD 增加数, WORD 除数)
{
	float fnum = rand() % (增加数 + 1) + 底数;
	fnum = fnum / 除数;
	return fnum;
}*/