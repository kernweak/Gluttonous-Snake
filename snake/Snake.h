#pragma once
#include <vector>
#include "Unit.h"
#include "Food.h"
using namespace std;
typedef enum
{
	UP,DOWN,RIGHT,LEFT
}Directions;

class CSnake
{
public:
	CSnake(int x=34, int y=20, int length=4, Directions direction=RIGHT, int speed=300, char pic='*');
	virtual ~CSnake();
	void showSnake();
	void eraseSnake();
	void growUp();
	void changeDirection(int vkValue);//传入玩家按键
	void move();
	bool eatFood(CFood* pFood);
public:
	int m_length;
	int m_headX;
	int m_headY;
	int m_speed;
	char m_pic;
	Directions m_neumCurrentDirection;
	vector<CUnit> m_vecBody;
};

