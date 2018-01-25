#include "stdafx.h"
#include "Barrer.h"
#include "Tools.h"
#include <iostream>
#include<windows.h>
#include<conio.h>
#include"Unit.h"
#include"Game.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

CBarrer::CBarrer(char pic)
{
	m_pic = pic;
}

	void CBarrer::showBarrer() {
  	for(int i=0;i<m_vecBarrer.size();i++)
  		m_vecBarrer[i].show();
  	
  }


CBarrer::~CBarrer()
{
}


void CBarrer::MessageLoop() {
	system("cls");
	CTools::writeCHar(0, 0);
	cout << "编辑地图";
	drawArea1();
//	CBarrer barrer;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };//一个结构体
	DWORD dwRead;//上面结构体的大小
	//int x, y;
	int i=0;
	SetConsoleMode(hStdin, ENABLE_INSERT_MODE|ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		COORD pos = { 0,0 };
		
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		if (stcRecord.EventType == KEY_EVENT&&stcRecord.Event.KeyEvent.bKeyDown) {
			
			
		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MOUSE_EVENT_RECORD mer=stcRecord.Event.MouseEvent;
			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				PlaySoundA("sound\\鼠标.wav", NULL, SND_ASYNC | SND_NODEFAULT);
				pos = stcRecord.Event.MouseEvent.dwMousePosition;
				CUnit unit(pos.X, pos.Y, '#');
				m_vecBarrer.push_back(unit);
				CTools::writeCHar(0, 0);
				cout << "             ";
				CTools::writeCHar(0, 0);
				cout << "x坐标(" << pos.X << ","<<pos.Y << ")";
				CTools::writeCHar(pos.X,pos.Y);
				cout <<'#';
			}
			else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
				PlaySoundA("sound\\鼠标.wav", NULL, SND_ASYNC | SND_NODEFAULT);
				CTools::writeCHar(0, 0);
				cout << "             ";
				CTools::writeCHar(0, 0);
				cout << "编辑完成";
				system("pause");
				return;
			}
		}
	}
//	barrer.showBarrer();
}

void CBarrer::drawArea1() {
	CTools::writeCHar(CGame::K_LEFT, CGame::K_UP);
	for (int i = 0;i < CGame::K_WIDTH;i++) {
		cout << '#';
	}
	CTools::writeCHar(CGame::K_LEFT, CGame::K_UP+1);
	cout << "请在下方方块处添加障碍物，鼠标左键添加，右键完成";
	for (int i = 0;i < CGame::K_HEIGH;i++) {
		CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + 1 + i);
		cout << '#';
		CTools::writeCHar(CGame::K_LEFT + CGame::K_WIDTH - 1, CGame::K_UP + 1 + i);
		cout << '#';

	}
	CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH + 1);
	for (int i = 0;i < CGame::K_WIDTH;i++) {
		cout << '#';
	}
	CTools::writeCHar(CGame::K_LEFT + 1, CGame::K_UP + 2);
	for (int i = 0;i <CGame::K_WIDTH - 2;i++) {
		cout << '#';
	}
}


