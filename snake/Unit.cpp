#include "stdafx.h"
#include "Unit.h"
#include "Tools.h"
#include <iostream>
using namespace std;


CUnit::CUnit(int x, int y, char pic)
	:m_ix(x),m_iy(y),m_pic(pic)
{


}


CUnit::~CUnit()
{
}

void CUnit::show()
{
	CTools::writeCHar(m_ix,m_iy);
	cout << m_pic;
}

void CUnit::erase()
{
	CTools::writeCHar(m_ix, m_iy);
	cout << " ";
}
