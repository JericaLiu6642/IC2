#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
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
#define CONTINUE  0
#define PLAYERWIN 1
#define MONWIN 2

using namespace std;

Battle::Battle(vector<NovicePlayer*> play, vector<BaseMonster*> mon)
{
	int p = play.size();
	int m = mon.size();
	ActionList = new Character[p + m];
	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
	string temp;

	//初始建構ActionList
	int count = 0;
	for (int i = 0; i < play.size(); i++) {
		ActionList[count].type = 'p';
		ActionList[count].alive = true;
		ActionList[count].instance = play[i];
		count++;
	}

	for (int i = 0; i < mon.size(); i++) {
		ActionList[count].type = 'm';
		ActionList[count].alive = true;
		ActionList[count].instance = mon[i];
		count++;
	}

	while (result(p, m) == CONTINUE) {
		//player先攻
		cout << setw(10) << "=============" << endl;
		cout << setw(10) << "Wizard's turn" << endl;
		cout << setw(10) << "==============" << endl;
		system("pause");
		system("cls");
		cout << "Here's your enemy:" << endl;
		showMoninfo(p + m);
		for (int i = 0; i < p + m; i++) {
			if (ActionList[i].type == 'p' && ActionList[i].alive == true) {
				tmp_player = static_cast<NovicePlayer*>(ActionList[i].instance);
				temp = typeid(*tmp_player).name();
				if (temp == "class NovicePlayer" || temp == "class OrcPlayer") {
					cout << "\nThe player now: " << tmp_player->getname() << endl;
					cout << tmp_player->getname() << " attacks all monster by " << tmp_player->getAttack() << "." << endl;
					for (int j = 0; j < p + m; j++) {
						if (ActionList[j].type == 'm' && ActionList[j].alive == true) {
							tmp_monster = static_cast<BaseMonster*>(ActionList[j].instance);
							tmp_monster->setHP(tmp_monster->getHP() - (tmp_player->getAttack() - tmp_monster->defense*0.5));
							if (tmp_monster->getHP() <= 0) {
								tmp_monster->setHP(0);
								ActionList[j].alive = false;
							}
						}
					}
					cout << tmp_player->getname() << "'s " << "attack completed!" << endl;
					system("pause");
					system("cls");
					cout << "All enemies' status show as below:" << endl;
					showMoninfo(p + m);
					system("pause");
					system("cls");
					//攻擊完成要判斷勝負
					if (result(p, m) == PLAYERWIN) {
						break;
					}
				}

				//角色是knight player
				if (temp == "class KnightPlayer") {
					tmp_player = static_cast<KnightPlayer*>(ActionList[i].instance);
					//騎士可以選擇技能
					cout << "The player now: " << tmp_player->getname() << endl;
					cout << "Enter 1 to attack" << endl;
					cout << "Enter 2 to perform magic" << endl;
					cout << "Please choose: ";
					int choice = 0;
					while (1) {
						cin >> choice;
						if (choice == 1 || choice == 2) {
							break;
						}
						else {
							"\nWrong input! Please try again:";
						}
					}

					system("pause");
					system("cls");

					switch (choice) {
					case 1:
						cout << tmp_player->getname() << " attacks all monster by " << tmp_player->getAttack() << "." << endl;
						for (int j = 0; j < p + m; j++) {
							if (ActionList[j].type == 'm' && ActionList[j].alive == true) {
								tmp_monster = static_cast<BaseMonster*>(ActionList[j].instance);
								tmp_monster->setHP(tmp_monster->getHP() - (tmp_player->getAttack() - tmp_monster->defense*0.5));
								if (tmp_monster->getHP() <= 0) {
									tmp_monster->setHP(0);
									ActionList[j].alive = false;
								}
							}
						}
						cout << tmp_player->getname() << "'s " << "attack completed!" << endl;
						system("pause");
						system("cls");
						cout << "All enemies' status show as below:" << endl;
						showMoninfo(p + m);
						system("pause");
						system("cls");
						//攻擊完成要判斷勝負
						if (result(p, m) == PLAYERWIN) {
							break;
						}
						break;

					case 2:
						cout << tmp_player->getname() << " performs special magic : HEAL" << endl;
						tmp_player->specialSkill();
						system("pause");
						system("cls");
						cout << "All wizards' status show as below:" << endl;
						showPlayerinfo(p + m);
						system("pause");
						system("cls");
						break;
					}
				}

				//角色是magician player
				if (temp == "class MagicianPlayer") {
					tmp_player = static_cast<MagicianPlayer*>(ActionList[i].instance);
					//騎士可以選擇技能
					cout << "The player now: " << tmp_player->getname() << endl;
					cout << "Enter 1 to attack" << endl;
					cout << "Enter 2 to perform magic" << endl;
					cout << "Please choose: ";
					int choice = 0;
					while (1) {
						cin >> choice;
						if (choice == 1 || choice == 2) {
							break;
						}
						else {
							"\nWrong input! Please try again:";
						}
					}

					system("pause");
					system("cls");

					switch (choice) {
					case 1:
						cout << tmp_player->getname() << " attacks all monster by " << tmp_player->getAttack() << "." << endl;
						for (int j = 0; j < p + m; j++) {
							if (ActionList[j].type == 'm' && ActionList[j].alive == true) {
								tmp_monster = static_cast<BaseMonster*>(ActionList[j].instance);
								tmp_monster->setHP(tmp_monster->getHP() - (tmp_player->getAttack() - tmp_monster->defense*0.5));
								if (tmp_monster->getHP() <= 0) {
									tmp_monster->setHP(0);
									ActionList[j].alive = false;
								}
							}
						}
						cout << tmp_player->getname() << "'s " << "attack completed!" << endl;
						system("pause");
						system("cls");
						cout << "All enemies' status show as below:" << endl;
						showMoninfo(p + m);

						//攻擊完成要判斷勝負
						if (result(p, m) == PLAYERWIN) {
							break;
						}
						break;

					case 2:
						cout << tmp_player->getname() << " performs special magic : PRAY" << endl;
						tmp_player->specialSkill();
						system("pause");
						system("cls");
						cout << "All wizards' status show as below:" << endl;
						showPlayerinfo(p + m);
						break;
					}
				}
			}
		}
		if (result(p, m) == PLAYERWIN) {
			turn++; //player提前消滅怪物 還是要加一輪
			break; //跳出while loop
		}

		system("pause");
		system("cls");

		//怪獸後攻
		cout << setw(10) << "==============" << endl;
		cout << setw(10) << "Enemies' turn" << endl;
		cout << setw(10) << "==============" << endl;
		system("pause");
		system("cls");
		for (int i = 0; i < p + m; i++) {
			if (ActionList[i].type == 'm' && ActionList[i].alive == true) {
				tmp_monster = static_cast<BaseMonster*>(ActionList[i].instance);
				cout << tmp_monster->name << " attacks all wizards by " << tmp_monster->attack << "." << endl;
				for (int j = 0; j < p + m; j++) {
					if (ActionList[j].type == 'p' && ActionList[j].alive == true) {
						tmp_player = static_cast<NovicePlayer*>(ActionList[j].instance);
						tmp_player->sethp(tmp_player->gethp() - (tmp_monster->attack - tmp_player->getDefense()*0.5));
						if (tmp_player->gethp() <= 0) {
							tmp_player->sethp(0);
							ActionList[j].alive = false;
						}
					}
				}
			}
		}
		//怪物全部攻擊完再顯示player狀態
		system("pause");
		system("cls");
		cout << "All wizards' status show as below:" << endl;
		showPlayerinfo(p + m);
		if (result(p, m) == MONWIN) {
			turn++; //提前消滅player 加一輪
			break; //跳出while loop
		}
		system("pause");
		system("cls");
		turn++; //所有都攻擊完 結束一輪
	}

	//判斷勝負
	if (result(p, m) == PLAYERWIN) {
		cout << "\n***Wizards defeat all enemies***\n";
		cout << "Leaving the battle..." << endl;
		system("pause");
		//玩家的角色一定被放在第一格
		tmp_player = static_cast<NovicePlayer*>(ActionList[1].instance);
		for (int i = 0; i < p + m; i++) {
			if (ActionList[i].type == 'm') {
				tmp_monster = static_cast<BaseMonster*>(ActionList[i].instance);
				tmp_player->setexp(tmp_player->getexp() + tmp_monster->exp);
				tmp_player->setmoney(tmp_player->getmoney() + tmp_monster->money);
			}
		}
		playerWin = 1;
	}
	else if(result(p, m) == MONWIN) {
		cout << "\n***Enemies defeat all wizards***\n";
		cout << "Leaving the battle..." << endl;
		system("pause");
		playerWin = 2;
	}

	//cout << "\nNumber of turns: " << turn << endl;
}



int Battle::result(int p, int m)
{
	int count = 0;
	//看player是否全數死亡
	for (int i = 0; i < p+m; i++) {
		if (ActionList[i].type == 'p' && ActionList[i].alive == false) {
			count++;
		}
	}
	
	if (count == p) {
		return MONWIN;
	}

	//看怪獸是否全部死亡
	count = 0;
	for (int i = 0; i < p + m; i++) {
		if (ActionList[i].type == 'm' && ActionList[i].alive == false) {
			count++;
		}
	}

	if (count == m) {
		return PLAYERWIN;
	}

	return CONTINUE;
}

Battle::~Battle()
{
	delete[] ActionList;
}

void Battle::showPlayerinfo(int n)
{
	NovicePlayer *tmp_player;
	for (int i = 0; i < n; i++) {
		if (ActionList[i].type == 'p') { 
			tmp_player = static_cast<NovicePlayer*>(ActionList[i].instance);
			if (tmp_player != 0) {
				tmp_player->print();
			}
		}
	}
}

void Battle::showMoninfo(int n)
{
	BaseMonster *tmp_monster;
	for (int i = 0; i < n; i++) {
		if (ActionList[i].type == 'm') {
			tmp_monster = static_cast<BaseMonster*>(ActionList[i].instance);
			if (tmp_monster != 0) {
				tmp_monster->print();
			}
		}
	}
}
