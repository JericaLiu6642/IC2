#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iomanip>
#include <iostream>
#include <string>
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "ConsumableItem.h"
#include "BaseMonster.h"
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

	virtual void specialSkill(NovicePlayer*);
	virtual void specialSkill(BaseMonster*);

	virtual string serialize();
	static NovicePlayer* unserialize(string);

	//backpack
	vector<Item*> backpack;
	WeaponItem* weapon; // weapon item
	ArmorItem* armor; // armor item
	bool equipWeapon(WeaponItem*);
	bool equipArmor(ArmorItem*);
	void useConsumable(ConsumableItem* c, BaseMonster* b, int n);
	bool putItem(Item*);
	Item* takeItem(int);
	void printBP();

	void print() {
		cout << "-------------------------" << endl;
		cout << setw(10) << "name:" << getname() << endl;
		cout << setw(10) << "hp:" << gethp() << endl;
		cout << setw(10) << "mp:" << getmp() << endl;
		cout << setw(10) << "exp:" << getexp() << endl;
		cout << setw(10) << "money:" << getmoney() << endl;
		cout << setw(10) << "level:" << getLevel() << endl;
		cout << setw(10) << "attack:" << getAttack() << endl;
		cout << setw(10) << "defense:" << getDefense() << endl;
		cout << setw(10) << "maxhp:" << getMaxHP() << endl;
		cout << setw(10) << "maxmp:" << getMaxMP() << endl;
		cout << setw(10) << "lvup_exp:" << getLvupExp() << endl;
		cout << "-------------------------" << endl;
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