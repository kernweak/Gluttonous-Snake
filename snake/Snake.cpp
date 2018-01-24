#include "stdafx.h"
#include "Snake.h"
#include <windows.h>
#pragma comment(lib,"winmm.lib")

CSnake::CSnake(int x,int y,int length,Directions direction,int speed,char pic)
{
	m_headX = x;
	m_headY = y;
	m_length = length;
	m_speed = speed;
	m_neumCurrentDirection = direction;
	m_pic = pic;
	int tmpX = 0, tmpY = 0;
	for (int i = 0;i < m_length;i++) {
		switch (m_neumCurrentDirection)
		{
		case UP:
			tmpX = m_headX;
			tmpY = m_headY+i;
			break;
		case DOWN:
			tmpX = m_headX;
			tmpY = m_headY - i;
			break;
		case LEFT:
			tmpX = m_headX + i;
			tmpY = m_headY;
			break;
		case RIGHT:
			tmpX = m_headX-i;
			tmpY = m_headY;
			break;
		
		default:
			break;
		}
		CUnit unit(tmpX,tmpY,pic);
		m_vecBody.push_back(unit);
	}
}


CSnake::~CSnake()
{
}


void CSnake::showSnake() {
	for (int i = 0;i < m_length;i++) {
		m_vecBody[i].show();
	}
}

void CSnake::eraseSnake() {
	for (int i = 0;i < m_length;i++) {
		m_vecBody[i].erase();
	}
}

void CSnake::changeDirection(int value) {
	PlaySoundA("sound\\转向.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	switch (value)
	{
	case 119://按下w键
		if (m_neumCurrentDirection == RIGHT || m_neumCurrentDirection == LEFT) {
			m_neumCurrentDirection = UP;
		}
		break;
	case 115://按下s键
		if (m_neumCurrentDirection == RIGHT || m_neumCurrentDirection == LEFT) {
			m_neumCurrentDirection = DOWN;
		}
		break;
	case 97://按下a键
		if (m_neumCurrentDirection == UP || m_neumCurrentDirection == DOWN) {
			m_neumCurrentDirection = LEFT;
		}
		break;
	case 100://按下d键
		if (m_neumCurrentDirection == UP || m_neumCurrentDirection == DOWN) {
			m_neumCurrentDirection = RIGHT;
		}
		break;
	}
}

void CSnake::move() {
	eraseSnake();
	for (int i = m_length - 1;i > 0;i--) {
		m_vecBody[i].m_ix = m_vecBody[i - 1].m_ix;
		m_vecBody[i].m_iy = m_vecBody[i - 1].m_iy;
	}
	switch (m_neumCurrentDirection)
	{
	case UP:
		m_vecBody[0].m_iy--;
		break;
	case DOWN:
		m_vecBody[0].m_iy++;
		break;
	case RIGHT:
		m_vecBody[0].m_ix++;
		break;
	case LEFT:
		m_vecBody[0].m_ix--;
		break;
	}
	showSnake();
	Sleep(m_speed);
}

void CSnake::growUp() {
	CUnit unit(0, 0, m_pic);
	m_vecBody.push_back(unit);
	m_length++;
}

bool CSnake::eatFood(CFood* pFood) {
	if (m_vecBody[0].m_ix == pFood->m_ix&&m_vecBody[0].m_iy == pFood->m_iy)
	{
		PlaySoundA("sound\\硬币.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		growUp();
		return true;
	}
	return false;
}