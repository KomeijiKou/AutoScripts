#include "a.h"
#include "AutoMessageSend.h"
#include "PointMetrix.h"
#include "ArkAuto.h"

#pragma warning(disable:4996)
#pragma comment(linker,"/entry:mainCRTStartup /subsystem:windows")



void PrintUI(const char* ExeName, const char* UIName, const char* color, short x, short y, WORD UIWide, WORD UIHeigh);


void bufClear();
unsigned _stdcall AutoThread(void* Parg);

int main(int argc, _TCHAR*argv[])
{
	PrintUI("ArkNightsAuto.exe", "ArkNightsAuto_V1.0.0_Beta", "color 0A", 500, 500, 800, 800);
	
	/****************************************************************************************************************************************************************/
	ArkAuto A;
	printf("F1��ʼ��ESC��ͣ>\n");
	cout << "ArkNights_Auto-����ͣ>" << endl;
	while (true)
	{
		if (-32767 == GetAsyncKeyState(VK_ESCAPE) && A.loopCon)
		{
			A.loopCon = false;
			system("cls");
			printf("F1��ʼ��ESC��ͣ>\n");
			cout << "ArkNights_Auto-����ֹͣ...>" << endl;
		}
		if (-32767 == GetAsyncKeyState(VK_F1) && !A.loopCon )
		{
			_beginthreadex(NULL, NULL, AutoThread, &A, 0, 0);
		}
		Sleep(20);
	}

	
	
	getchar();
}





void PrintUI(const char* ExeName, const char* UIName, const char* color, short x, short y, WORD UIWide, WORD UIHeigh)
{
	AllocConsole();
	freopen("conin$", "r+t", stdin);
	freopen("conout$", "w+t", stdout);
	SetConsoleTitleA(UIName);
	system(color);

	char oldpname[1024];
	char newpname[1024];
	GetModuleFileNameA(NULL, oldpname, 1024);
	strcpy(newpname, oldpname);

	for (size_t i = strlen(newpname); i > 0; i--)
	{
		if (newpname[i - 1] == '\\')
		{
			newpname[i] = 0;
			strcat(newpname, ExeName);
			break;
		}
	}
	char command[MAXBYTE] = { 0 };
	strcat(command, "del/f/q \"");
	strcat(command, newpname);
	strcat(command, "\">nu1 2>nu1");
	system(command);
	rename(oldpname, newpname);
	HWND PrintUI = GetConsoleWindow();

	SetWindowPos(PrintUI, 0, 0, 0, UIWide, UIHeigh, SWP_NOMOVE);

	std:wcout.imbue(std::locale("CHS"));
	system("cls");
}

unsigned _stdcall AutoThread(void* Parg)
{
	system("cls");
	printf("F1��ʼ��ESC��ͣ>\n");
	cout << "ArkNights_Auto-������>" << endl;
	((ArkAuto*)Parg)->StartArkAuto();
	system("cls");
	printf("F1��ʼ��ESC��ͣ>\n");
	cout << "ArkNights_Auto-����ͣ>" << endl;
	return 0;
}

void bufClear()
{
	char c;
	while((c = getchar()) != '\n'); 
}