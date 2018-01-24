#pragma once
#include <vector>
#include"Unit.h"
using namespace std;
class CBarrer
{
public:
	CBarrer(char pic = 'X');
	virtual ~CBarrer();
	void showBarrer();
	void MessageLoop();
	void drawArea1();
public:
	char m_pic;
	vector<CUnit> m_vecBarrer;
};

