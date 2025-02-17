#include <string>
#include <cmath>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include<typeinfo>
#include "NovicePlayer.h"

using namespace std;

//constructor
NovicePlayer::NovicePlayer()
{
	setLevel(1);
	setname("anonymous");
}

NovicePlayer::NovicePlayer(int a)
{
	setLevel(a);
	setname("anonymous");
}

NovicePlayer::NovicePlayer(int a, string s)
{
	setLevel(a);
	setname(s);
}

NovicePlayer::NovicePlayer(const NovicePlayer& p)
{
	setLevel(p.getLevel());
	setname(p.getname());
}

//getter & setter
void NovicePlayer::setname(string s)
{
	name = s;
}

string NovicePlayer::getname(void) const
{
	return name;
}

void NovicePlayer::setLevel(int a)
{
	level = a;
	maxhp = 190 + 10 * a;
	maxmp = 50 + 5 * a;
	attack = 60 + 5 * a;
	defense = 60 + 5 * a;
	lvupexp = ceil(pow(10, log2(level + 1)));
	hp = 190 + 10 * a;
	mp = 50 + 5 * a;
	exp = ceil(pow(10, log2(level)));
	money = 0 + ceil(pow(10, log2(level + 1))) * 10;
}

int NovicePlayer::getLevel(void) const
{
	return level;
}

void NovicePlayer::sethp(int a)
{
	if (a >= getMaxHP()) {
		hp = getMaxHP();
	}
	else {
		hp = a;
	}
}

int NovicePlayer::gethp(void) const
{
	return hp;
}

void NovicePlayer::setmp(int a)
{
	if (a >= getMaxMP()) {
		mp = getMaxMP();
	}
	else {
		mp = a;
	}
}

int NovicePlayer::getmp(void) const
{
	return mp;
}

void NovicePlayer::setexp(int a)
{
	if (a < getLvupExp()) {
		exp = a;
	}
	else {
		int temp = a - getLvupExp();
		setLevel(getLevel() + 1);
		setexp(temp);
	}
}

int NovicePlayer::getexp(void) const
{
	return exp;
}

void NovicePlayer::setmoney(int a)
{
	money = a;
}

int NovicePlayer::getmoney(void) const
{
	return money;
}

int NovicePlayer::getAttack(void) const
{
	return attack;
}

int NovicePlayer::getDefense(void) const
{
	return defense;
}

int NovicePlayer::getMaxHP(void) const
{
	return maxhp;
}

int NovicePlayer::getMaxMP(void) const
{
	return maxmp;
}

int NovicePlayer::getLvupExp(void) const
{
	return lvupexp;
}

void NovicePlayer::specialSkill(NovicePlayer*)
{
}

void NovicePlayer::specialSkill(BaseMonster*)
{
}

string NovicePlayer::serialize()
{
	string s;
	s.clear();	
	s += name + "$";
	s += to_string(gethp()) + "$";
	s += to_string(getmp()) + "$";
	s += to_string(getexp()) + "$";
	s += to_string(getmoney()) + "$";
	s += to_string(getLevel()) + "$";

	return s;
}

NovicePlayer* NovicePlayer::unserialize(string s)
{
	stringstream ss(s);
	string temp;

	getline(ss, temp, '$');
	string name = temp;
	temp.clear();
	getline(ss, temp, '$');
	int hp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int mp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int exp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int money = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int level = stoi(temp);
	temp.clear();

	NovicePlayer *point = new NovicePlayer(level, name);
	point->sethp(hp);
	point->setmp(mp);
	point->setexp(exp);
	point->setmoney(money);
	return point;
}

bool NovicePlayer::equipWeapon(WeaponItem* w)
{
	if (getLevel() >= w->level_required) {
		weapon = w;
		attack += w->attack_increment;
		return true;
	}
	return false;
}

bool NovicePlayer::equipArmor(ArmorItem* a)
{
	if (getLevel() >= a->level_required) {
		armor = a;
		defense += a->defense_increment;
		return true;
	}
	return false;
}

void NovicePlayer::useConsumable(ConsumableItem* c, BaseMonster* b, int n)
{
	if (c->name == "LifePotion") {
		c->use(this);
	}
	else if (c->name == "Venom") {
		c->use(b, n);
	}
}

bool NovicePlayer::putItem(Item* i)
{
	backpack.push_back(i);
}

Item* NovicePlayer::takeItem(int n)
{
	Item* take = backpack[n];
	backpack.erase(backpack.begin() + n);
}

void NovicePlayer::printBP()
{
	system("cls");
	cout << "========================================" << endl;
	cout << "Press 'E' to leave your backpack" << endl;
	cout << "Press 'the number of item' to equip it" << endl;
	cout << "========================================" << endl;
	char c;
	c = _getch();

	WeaponItem* temp_w_on;
	ArmorItem* temp_a_on;
	ConsumableItem* temp_c_on;
	WeaponItem* temp_w_off;
	ArmorItem* temp_a_off;
	ConsumableItem* temp_c_off;
	string itemClass;

	if (!backpack.empty()) {
		//印出背包的東西
		for (int i = 0; i < backpack.size(); i++) {
			cout << setw(16) << "Item " << i << ":" << endl;
			cout << setw(16) << "Name: " << backpack[i]->name << endl;
			cout << setw(16) << "Effect: " << backpack[i]->effect << endl;
			cout << setw(16) << "Description: " << backpack[i]->description << endl;
			cout << endl;
		}

		if (c == 'e' || c == 'E') {
			return;
		}
		else if (c == '1' && backpack.size() >= 1) {
			switch (backpack[0]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[0]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(0); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[0]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(0); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else if (c == '2' && backpack.size() >= 2) {
			switch (backpack[1]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[1]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(1); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[1]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(1); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else if (c == '3' && backpack.size() >= 3) {
			switch (backpack[2]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[2]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(2); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[2]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(2); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else if (c == '4' && backpack.size() >= 4) {
			switch (backpack[3]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[3]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(3); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[3]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(3); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else if (c == '5' && backpack.size() >= 5) {
			switch (backpack[4]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[4]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(4); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[4]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(4); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else if (c == '6' && backpack.size() >= 6) {
			switch (backpack[5]->type)
			{
			case 'w':
				temp_w_on = static_cast<WeaponItem*>(backpack[5]);
				itemClass = typeid(*temp_w_on).name();
				if (itemClass == "class Sword" || itemClass == "class Wand") {
					temp_w_off = weapon; //原本穿戴的取下來
					putItem(temp_w_off); // 存回backpack
					weapon = temp_w_on; //新的weapon 穿上
					takeItem(5); //把0號這一格清空
				}
				else {
					cout << "equip weapon error!!" << endl;
				}
				break;

			case 'a':
				temp_a_on = static_cast<ArmorItem*>(backpack[5]);
				itemClass = typeid(*temp_a_on).name();
				if (itemClass == "class Patronum" || itemClass == "class Cloak") {
					temp_a_off = armor; //原本穿戴的取下來
					putItem(temp_a_off); // 存回backpack
					armor = temp_a_on; //新的weapon 穿上
					takeItem(5); //把0號這一格清空
				}
				else {
					cout << "equip armor error!!" << endl;
				}
				break;

			case 'c': //藥水只能在battle使用
				cout << "Potions can only be used in battle!" << endl;
				system("pause");
				system("cls");
				printBP();
				break;
			default:
				break;
			}
		}
		else {
			cout << "Input error!" << endl;
			system("pause");
			system("cls");
			printBP();
		}
	}
	else {
		cout << setw(50) << "Your backpack is currently empty." << endl;
		if (c == 'e' || c == 'E') {
			return;
		}
	}

}
