#include<iostream>
#include<string>
#include<iomanip>
#include<set>
#include<vector>
#include<typeinfo>
#include<stdlib.h>
#include"BaseMonster.h"
#include"NovicePlayer.h"
#include"GoblinMonster.h"
#include"ZombieMonster.h"
#include"JWMonster.h"
#include"OrcPlayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"Battle.h"

using namespace std;
bool checkRepeatChar(set<int> s, int a)
{
	if (s.count(a) == 1) {
		return true;
	}
	return false;
}
/*
int t()
{
	//先建好角色和儲存空間
	vector<NovicePlayer*> playerPoint;
	vector<BaseMonster*> monPoint;
	NovicePlayer novice(5, "NovicePlayer");
	OrcPlayer orc(5, "OrcPlayer");
	KnightPlayer knight(5, "KnightPlayer");
	MagicianPlayer magician(5, "MagicianPlayer");

	set<int> record;

	//戰鬥前初始設定
	int n; //number of players
	int m; //number of monsters
	cout << "Encounter ememies! Entering a battle! \nHow many players are joining the battle (1~4 players):";
	cin >> n;

	if (n == 1) m = 1;
	else if (n == 2) m = 2;
	else m = 3;

	while (n != 0) {
		int c;
		cout << "\nChoose your character for the battle (Each character is only allowed to choose for once):" << endl;
		cout << setw(10) << "Enter 1: Novice Player" << endl;
		cout << setw(10) << "Enter 2: Orc Player" << endl;
		cout << setw(10) << "Enter 3: Knight Player" << endl;
		cout << setw(10) << "Enter 4: Magician Player" << endl;
		cout << "Please choose:";
		cin >> c;

		if (checkRepeatChar(record, c)) { ///檢查是否選過
			cout << "Repeated character!!\n";
			continue;
		}
		else {
			record.insert(c);
			switch (c) {
			case 1:
				playerPoint.push_back(&novice);
				break;
			case 2:
				playerPoint.push_back(&orc);
				break;
			case 3:
				playerPoint.push_back(&knight);
				break;
			case 4:
				playerPoint.push_back(&magician);
				break;
			}
			n--;
		}
	}

	if (m == 1) {
		monPoint.push_back(new GoblinMonster);
	}
	else if (m == 2) {
		monPoint.push_back(new GoblinMonster);
		monPoint.push_back(new ZombieMonster);
	}
	else {
		monPoint.push_back(new GoblinMonster);
		monPoint.push_back(new ZombieMonster);
		monPoint.push_back(new JWMonster);
	}

	system("cls");
	Battle battle(playerPoint, monPoint);

}*/