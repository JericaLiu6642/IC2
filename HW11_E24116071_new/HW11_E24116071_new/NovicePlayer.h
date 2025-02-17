#pragma once
#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iomanip>
#include <iostream>
#include <string>
// #include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "ConsumableItem.h"
#include "BaseMonster.h"
#include <cmath>
#include <sstream>
#include <conio.h>
#include <typeinfo>

using namespace std;

class NovicePlayer
{
private:
	string name;
	int hp;
	int mp;
	int exp;
protected:
	int level;
	int attack;
	int defense;
	int maxhp;
	int maxmp;
	int lvupexp;
	int money;
	vector<Item*> backpack;
	WeaponItem* weapon; // weapon item
	ArmorItem* armor; // armor item
	int bp_weight_limit = 20;
	int current_weight;
public:
	NovicePlayer();
	NovicePlayer(int);
	NovicePlayer(int, string);
	NovicePlayer(const NovicePlayer&);
	
	void setname(string);
	string getname()const;

	virtual void setLevel(int);
	int getLevel()const;

	void sethp(int);
	int gethp()const;

	void setmp(int);
	int getmp()const;

	void setexp(int);
	int getexp()const;

	void setmoney(int);
	int getmoney() const;

	int getAttack() const;
	int getDefense() const;
    int getMaxHP() const;
	int getMaxMP() const;
	int getLvupExp() const;

	void setWeapon(WeaponItem*);
	void setArmor(ArmorItem*);

	virtual void specialSkill(NovicePlayer*);
	virtual void specialSkill(BaseMonster*);

	virtual string serialize();
	static NovicePlayer* unserialize(string);

	//backpack

	bool equipWeapon(WeaponItem*);
	bool equipArmor(ArmorItem*);
	bool haveCon();
	Item* chooseCon();
	void removeCon(Item*);
	bool putItem(Item*);
	Item* takeItem(int);
	void printBP();
	int count_weight();

	void print() {
		cout << "------------------------------------------------------------------------" << endl;
		cout << "  name:" << getname() << endl;
		cout << "  hp:" << gethp() << "       mp:" << getmp() << "       attack:" << getAttack() << "       defense:" << getDefense() << endl;
		if (weapon != NULL) {
			cout << "  weapon:" << weapon->name << endl;
		}
		if (armor != NULL) {
			cout << "  armor:" << armor->name << endl;
		}
		cout << "------------------------------------------------------------------------" << endl;
	}

	void printInb() {
		cout << "-------------------------" << endl;
		cout << setw(10) << "name:" << getname() << endl;
		cout << setw(10) << "hp:" << gethp() << endl;
		cout << setw(10) << "mp:" << getmp() << endl;
		cout << setw(10) << "attack:" << getAttack() << endl;
		cout << setw(10) << "defense:" << getDefense() << endl;
		cout << "-------------------------" << endl;
	}
};
#endif