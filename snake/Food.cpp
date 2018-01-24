#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include "Food.h"
#include "Game.h"


CFood::CFood(int x, int y, char pic)
	:CUnit(x,y,pic)
{
	srand((unsigned int)time(NULL));
}


CFood::~CFood()
{
}

void CFood::createPos(vector<CUnit> *vec, vector<CUnit> *vec1) {
	while (true) {
		int x = CGame::K_LEFT+rand() % (CGame::K_WIDTH-2);
		int y = CGame::K_UP+3+rand() % (CGame::K_HEIGH-2);
		size_t i,j;
		for (i = 0;i < vec->size();i++) {
			if (x == vec->at(i).m_ix&&y == vec->at(i).m_iy) {//判断是否生成到蛇身上
				break;
			}
		}
		for (j = 0;j < vec1->size();j++) {
			if (x == vec1->at(j).m_ix&&y == vec1->at(j).m_iy) {//判断是否生成到障碍上
				break;
			}
		}
		if (i == vec->size()&&j==vec1->size()) {//说明不是循环中途跳出
			m_ix = x;
			m_iy = y;
			return;
		}
		
	}
}
