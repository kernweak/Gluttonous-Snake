#include "stdafx.h"
#include "Tools.h"
#include <windows.h>
#include<stdio.h>
#pragma comment(lib,"winmm.lib")
CTools::CTools()
{
}


CTools::~CTools()
{
}

void CTools::writeCHar(int x, int y) {
	COORD coor;
	coor.X = x;
	coor.Y = y;
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, coor);
}

void CTools::setSomething() {
	system("title Ì°³ÔÉß");
	system("mode con cols=125 lines=55");
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	ShowCursor(false);
	PlaySoundA("sound\\¿ªÊ¼.wav", NULL, SND_ASYNC | SND_NODEFAULT);
}
void CTools::ShowCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = isShow;
	SetConsoleCursorInfo(hOutStd, &cci);
}


