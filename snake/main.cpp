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

			cout << "*******************************" << endl;
			cout << "*1.地图编辑                   *" << endl;
			cout << "*2.开始游戏                   *" << endl;
//			cout << "*3.保存                       *" << endl;
//			cout << "*5.载入                       *" << endl;
			cout << "*4.退出                       *" << endl;
			cout << "*******************************" << endl;
			cin >> nNum;
			if (nNum == 4)
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
