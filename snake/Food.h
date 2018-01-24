#pragma once
#include "Unit.h"
#include <vector>
using namespace std;
class CFood :
	public CUnit
{
public:
	CFood(int x=0,int y=0,char pic='$');
	virtual ~CFood();

	void createPos(vector<CUnit> *vec, vector<CUnit> *vec1);//创建食物位置
};

