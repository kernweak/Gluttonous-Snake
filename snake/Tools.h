#pragma once
#include "Game.h"
class CTools
{
public:
	CTools();
	virtual ~CTools();
	void static writeCHar(int x, int y);
	void static setSomething();//关于启动的一些设置
	void static ShowCursor(bool isShow);
	void static start();
	/*void static save(CGame *game);
	void static load(CGame *game);*/
};

