#include "stdafx.h"
#include "Game.h"
#include "Tools.h"
#include "Barrer.h"
#include<stdlib.h>
#include<iostream>
#include"Unit.h"


using namespace std;
int main(){
	CTools::setSomething();	
	CTools::start();
	system("cls");
	CGame game;
	system("cls");
		while (true) {
			int nNum = -1;
			system("cls");
			CTools::writeCHar(29, 20);
			cout << "*******************************" << endl;
			CTools::writeCHar(29, 21);
			cout << "*1.地图编辑                   *" << endl;
			CTools::writeCHar(29, 22);
			cout << "*2.开始游戏                   *" << endl;
			CTools::writeCHar(29, 23);
//			cout << "*3.保存                       *" << endl;
//			cout << "*5.载入                       *" << endl;
			cout << "*3.退出                       *" << endl;
			CTools::writeCHar(29, 24);
			cout << "*******************************" << endl;
			CTools::writeCHar(29, 25);
			cin >> nNum;
			if (nNum == 3)
				return 0;
			switch (nNum)
			{
			case 1:
				game.m_pbarrer->MessageLoop();
				break;
			case 2:
				game.run();
				break;
			default:
				break;
			}
		}
}
