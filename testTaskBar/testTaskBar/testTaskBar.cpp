// testTaskBar.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include "stdafx.h"
#include <windows.h> 
#include <stdio.h> 
#include <iostream>
using namespace std;
void openApp(TCHAR *appPath)
{
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
	//TCHAR cmdline[] = "c://program files//internet explorer//iexplore.exe";
	TCHAR *cmdline = appPath;
	BOOL bRet = ::CreateProcess(
		NULL,
		cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�	 
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi);
	
	int error = GetLastError();
	if (bRet)
	{
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
		
		//printf(" �½��̵Ľ���ID�ţ�%d /n", pi.dwProcessId);
		//printf(" �½��̵����߳�ID�ţ�%d /n", pi.dwThreadId);
	}
	else
	{
		printf("error code:%d/n", error);
	}
}
int main(int argc, char* argv[])
{
	//TCHAR app1[] = "C://Users//csy_uestc//AppData//Local//360Chrome//Chrome//Application//360chrome.exe";
	TCHAR app2[] = "C://Windows//notepad.exe";
	for (int i = 0; i < 5; i++)
	{
		openApp(app2);
		Sleep(5000);
		//openApp(app2);
		Sleep(3000);
	}
	//HWND h=::FindWindow("360chrome",NULL);
	//SetForegroundWindow(h);
	
	//Sleep(2000);

	return 0;
}

