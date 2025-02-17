#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class NovicePlayer
{
private:
	string name;
	int hp;
	int mp;
	int exp;
	int money;
protected:
	int level;
	int attack;
	int defense;
	int maxhp;
	int maxmp;
	int lvupexp;
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

	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);

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
};
#endif