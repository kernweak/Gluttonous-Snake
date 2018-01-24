#include "stdafx.h"
#include "Game.h"
#include "Tools.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Barrer.h"
using namespace std;

const int CGame::K_LEFT = 5;
const int CGame::K_UP = 2;
const int CGame::K_WIDTH = 110;
const int CGame::K_HEIGH = 40;
const int CGame::K_SCORE = 38;
const int CGame::K_LEVE=53;
const int CGame::K_BLOOD=68;


CGame::CGame()
{	
	this->m_pfood = new CFood();
	this->m_psnake = new CSnake();
	this->m_pbarrer = new CBarrer();
	this->m_score = 0;
	this->m_leve = 1;
	this->m_blood = 2;
	drawArea();
	drawInformation();
}


CGame::~CGame()
{
	delete m_pfood;
	delete m_psnake;
	delete m_pbarrer;
	m_pfood = NULL;
	m_psnake = NULL;
	m_pbarrer = NULL;
}


void CGame::drawArea(){//绘制界面
	CTools::writeCHar(K_LEFT, K_UP);
	for (int i = 0;i < K_WIDTH;i++) {
		cout << '#';
	}
	for (int i = 0;i < K_HEIGH;i++) {
		CTools::writeCHar(K_LEFT, K_UP + 1 + i);
		cout << '#';
		CTools::writeCHar(K_LEFT + K_WIDTH - 1, K_UP + 1 + i);
		cout << '#';

	}
	CTools::writeCHar(K_LEFT, K_UP + K_HEIGH + 1);
	for (int i = 0;i < K_WIDTH;i++) {
		cout << '#';
	}
	CTools::writeCHar(K_LEFT + 1, K_UP + 2);
	for (int i = 0;i < K_WIDTH - 2;i++) {
		cout << '#';
	}
	m_pbarrer->showBarrer();
}
void CGame::drawInformation() {//初始信息
	CTools::writeCHar(K_LEFT + 1, K_UP + 1);
	cout << "贪吃蛇";
	CTools::writeCHar(K_LEFT + 15, K_UP + 1);
	cout << "作者：杨睿琦";
	CTools::writeCHar(K_LEFT + 30, K_UP + 1);
	cout << "当前得分";
	CTools::writeCHar(K_LEFT + K_LEVE, K_UP + 1);
	cout << m_score;
	CTools::writeCHar(K_LEFT + 45, K_UP + 1);
	cout << "当前关卡";
	CTools::writeCHar(K_LEFT + K_BLOOD, K_UP + 1);
	cout << m_leve;
	CTools::writeCHar(K_LEFT + 60, K_UP + 1);
	cout << "当前血量";
	CTools::writeCHar(K_LEFT + K_BLOOD, K_UP + 1);
	cout << m_blood;
	CTools::writeCHar(K_LEFT + K_BLOOD+15, K_UP + 1);
	cout << "按ESC退出,空格键暂停";
}
void CGame::run() {
	system("cls");
	drawArea();
	changeInformation();
	m_pfood->createPos(&(m_psnake->m_vecBody), &(m_pbarrer->m_vecBarrer));
	m_pfood->show();
	m_psnake->showSnake();
	int press = 0;
	bool stopMove = true;
	bool pauseFlag = true;
	while (press != 0X1b&&stopMove) {
		m_pbarrer->showBarrer();
		if (_kbhit()) {
			press = _getch();
			if (press == 0x20) {
				pauseFlag = !pauseFlag;
			}
			m_psnake->changeDirection(press);
		}
		else {
			if (pauseFlag) {
				continue;
			}
			m_psnake->move();
			if (m_psnake->eatFood(m_pfood)) {
				m_score += 10;
				if(isGoHighLeve()){stopMove=false;}
				changeInformation();
				m_pfood->createPos(&(m_psnake->m_vecBody),&(m_pbarrer->m_vecBarrer));
				m_pfood->show();
			}
			if (isOver()) {
				m_blood = m_blood - 1;
				if (m_blood == 0) {
					stopMove = false;
					CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH + 2);
					cout << "失 败";
				}
				CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH + 2);
				cout << "减一命";
				changeInformation();
				m_psnake->eraseSnake();
				drawArea();
				m_psnake->m_vecBody[0].m_ix=34;
				m_psnake->m_vecBody[0].m_iy = 20;
				m_psnake->showSnake();
			}
		}
	}
}
bool CGame::isOver(){
//检测是否撞墙,1.上边
	if (m_psnake->m_vecBody[0].m_iy <= CGame::K_UP+2) {
		return true;
	}
//检测是否撞墙,2.下边
	if (m_psnake->m_vecBody[0].m_iy >= CGame::K_UP + 1+ CGame::K_HEIGH) {
		return true;
	}
//检测是否撞墙,3.左边
	if (m_psnake->m_vecBody[0].m_ix <= CGame::K_LEFT) {
		return true;
	}
//检测是否撞墙,4.右边
	if (m_psnake->m_vecBody[0].m_ix >= CGame::K_LEFT+ CGame::K_WIDTH-1) {
		return true;
	}


//检测是否自残
	for (int i = 1;i < m_psnake->m_length;i++) {
		if (m_psnake->m_vecBody[0].m_ix == m_psnake->m_vecBody[i].m_ix\
			&&m_psnake->m_vecBody[0].m_iy == m_psnake->m_vecBody[i].m_iy) {
			return true;
		}
	}
	//检测是否撞到障碍物
	for (int j = 0;j < m_pbarrer->m_vecBarrer.size();j++) {
		if (m_psnake->m_vecBody[0].m_ix == m_pbarrer->m_vecBarrer[j].m_ix\
			&&m_psnake->m_vecBody[0].m_iy == m_pbarrer->m_vecBarrer[j].m_iy) {
			return true;
		}
	}
	return false;
}

bool CGame::isGoHighLeve()
{
	int tmp = m_score / 30 + 1;
	if (tmp == m_leve)return false;
	m_leve = tmp;
	switch (m_leve) {
	case 1:
		CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH+2);
		cout << "第一关" << endl;
		break;
	case 2:
		CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH+2);
		cout << "第二关" << endl;
		break;
	case 3:
		CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH+2);
		cout << "第三关" << endl;
		break;
	case 4:
		CTools::writeCHar(CGame::K_LEFT, CGame::K_UP + CGame::K_HEIGH);
		cout << "通关" << endl;
		return true;
		break;
	}
	return false;
}

void CGame::changeInformation() {
	CTools::writeCHar(K_LEFT + K_SCORE+1, K_UP + 1);
	cout << " ";
	CTools::writeCHar(K_LEFT + K_SCORE+1, K_UP + 1);
	cout << m_score;
	CTools::writeCHar(K_LEFT + K_LEVE, K_UP + 1);
	cout << " ";
	CTools::writeCHar(K_LEFT + K_LEVE, K_UP + 1);
	cout << m_leve;
	CTools::writeCHar(K_LEFT + K_BLOOD, K_UP + 1);
	cout << " ";
	CTools::writeCHar(K_LEFT + K_BLOOD, K_UP + 1);
	cout << m_blood;


	CTools::writeCHar(K_LEFT + 1, K_UP + 1);
	cout << "贪吃蛇";
	CTools::writeCHar(K_LEFT + 15, K_UP + 1);
	cout << "作者：杨睿琦";
	CTools::writeCHar(K_LEFT + 30, K_UP + 1);
	cout << "当前得分";
	CTools::writeCHar(K_LEFT + 45, K_UP + 1);
	cout << "当前关卡";
	CTools::writeCHar(K_LEFT + 60, K_UP + 1);
	cout << "当前血量";
	CTools::writeCHar(K_LEFT + K_BLOOD + 15, K_UP + 1);
	cout << "按ESC退出,空格键暂停";

}