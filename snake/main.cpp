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
			cout << "*1.��ͼ�༭                   *" << endl;
			cout << "*2.��ʼ��Ϸ                   *" << endl;
//			cout << "*3.����                       *" << endl;
//			cout << "*5.����                       *" << endl;
			cout << "*4.�˳�                       *" << endl;
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
