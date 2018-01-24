#include "stdafx.h"
#include "Tools.h"
#include <windows.h>
#include<stdio.h>
#include "Unit.h"
#include <iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;
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

void CTools::start() {
	CUnit a[146];
	int high = 3;
	int nNumber = 30;
	int nNumber1 = nNumber + 12;
	int nNumber2 = nNumber + 24;
	int nNumber3 = nNumber + 36;
	int nNumber4 = nNumber + 48;
	int i = 0, j = 0, k = 0, m = 0, n = 0, o = 0;
	for (i = 0;i < 10;i++) {
		a[i].m_ix = i + nNumber;
		a[i].m_iy = high;
		a[i].m_pic = 'O';
	}
	for (j = 0;j < 4;j++) {
		a[i].m_ix = nNumber;
		a[i].m_iy = high + j;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 0;k < 10;k++) {
		a[i].m_ix = k + nNumber;
		a[i].m_iy = high + j;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (m = 0;m < 4;m++) {
		a[i].m_ix = k + nNumber - 1;
		a[i].m_iy = high + j + 1 + m;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (n = 0;n < 10;n++) {
		a[i].m_ix = nNumber + n;
		a[i].m_iy = high + j + m;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	//N´òÓ¡
	for (j = 0;j < 9;j++) {
		a[i].m_ix = nNumber1;
		a[i].m_iy = high + j;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 0;k < 8;k++) {
		a[i].m_ix = nNumber1 + 1 + k;
		a[i].m_iy = high + k + 1;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (m = 0;m < 8;m++) {
		a[i].m_ix = nNumber1 + k;
		a[i].m_iy = high + m;
		a[i].m_pic = 'O';
		i = i + 1;
	}

	//A
	for (j = 0;j < 9;j++) {
		a[i].m_ix = nNumber2;
		a[i].m_iy = high + j;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (j = 1;j < 9;j++) {
		a[i].m_ix = nNumber2 + j;
		a[i].m_iy = high;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 0;k < 9;k++) {
		a[i].m_ix = nNumber2 + j;
		a[i].m_iy = high + k;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (j = 1;j < 9;j++) {
		a[i].m_ix = nNumber2 + j;
		a[i].m_iy = high + 4;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 0;k < 9;k++) {
		a[i].m_ix = nNumber3;
		a[i].m_iy = high + k;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (j = 1;j < 5;j++) {
		a[i].m_ix = nNumber3 + j * 2;
		a[i].m_iy = high + 4 - j;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (j = 1;j < 5;j++) {
		a[i].m_ix = nNumber3 + j * 2;
		a[i].m_iy = high + 4 + j;
		a[i].m_pic = 'O';
		i = i + 1;
	}

	for (k = 0;k < 9;k++) {
		a[i].m_ix = nNumber4;
		a[i].m_iy = high + k;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 1;k < 9;k++) {
		a[i].m_ix = nNumber4 + k;
		a[i].m_iy = high;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 1;k < 9;k++) {
		a[i].m_ix = nNumber4 + k;
		a[i].m_iy = high + 4;
		a[i].m_pic = 'O';
		i = i + 1;
	}
	for (k = 1;k < 9;k++) {
		a[i].m_ix = nNumber4 + k;
		a[i].m_iy = high + 8;
		a[i].m_pic = 'O';
		i = i + 1;
	}

	for (j = 0;j < 10;j++) {
		for (o = 0;o < i;o++) {
			a[o].show();
		}
		Sleep(50);
		for (o = 0;o < i;o++) {
			a[o].erase();
		}
		for (o = 0;o < i;o++) {
			a[o].m_iy = a[o].m_iy + 1;
		}
		Sleep(50);
	}
	for (o = 0;o < i;o++) {
		a[o].show();
	}
	CTools::writeCHar(120, 60);
	getchar();
}
