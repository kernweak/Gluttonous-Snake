#pragma once
#include "Food.h"
#include "Snake.h"
#include "Barrer.h"

//添加注释用于测试
class CGame
{
public:
	CGame();
	virtual ~CGame();
	void drawArea();//绘制界面
	void drawInformation();//初始信息
	void run();

	bool isOver();
	bool isGoHighLeve();
	void changeInformation();
public:
	CFood* m_pfood;
	CSnake* m_psnake;
	CBarrer* m_pbarrer;
	int m_score;
	int m_leve;
	int m_blood;
public:
	//各种坐标偏移量
	static const int K_UP;
	static const int K_LEFT;
	static const int K_WIDTH;
	static const int K_HEIGH;
	static const int K_SCORE;
	static const int K_LEVE;
	static const int K_BLOOD;

};

