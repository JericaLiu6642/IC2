#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
#include "NovicePlayer.h"
#include "KnightPlayer.h"

using namespace std;

//constructor
KnightPlayer::KnightPlayer() 
{
	setLevel(1);
	setname("anonymous");
}

KnightPlayer::KnightPlayer(int a) 
{
	setLevel(a);
	setname("anonymous");
}

KnightPlayer::KnightPlayer(int a, string s) 
{
	setLevel(a);
	setname(s);
}

KnightPlayer::KnightPlayer(const KnightPlayer& p) 
{
	setLevel(p.getLevel());
	setname(p.getname());
}

//setter
void KnightPlayer::setLevel(int a)
{
	level = a;
	maxhp = 150 + 25 * a;
	maxmp = 70 + 10 * a;
	attack = 40 + 10 * a;
	defense = 20 + 12 * a;
	lvupexp = ceil(pow(10, log2(level + 1)));
	sethp(150 + 25 * a);
	setmp(70 + 10 * a);
	setexp(ceil(pow(10, log2(a))));
	setmoney(getmoney() + (ceil(pow(10, log2(level)))) * 10);
}

//special
void KnightPlayer::specialSkill(void)
{
	int l = KnightPlayer::getLevel();
	if (KnightPlayer::getmp() - l * 5 >= 0) {
		KnightPlayer::setmp(KnightPlayer::getmp() - l * 5);
		KnightPlayer::sethp(KnightPlayer::gethp() + l * 10);
	}
	else {
		cout << "\nMp is too low to heal!$" << endl;
	}
}

string KnightPlayer::serialize()
{
	string s;
	s.clear();
	s += getname() + "$";
	s += to_string(gethp()) + "$";
	s += to_string(getmp()) + "$";
	s += to_string(getexp()) + "$";
	s += to_string(getmoney()) + "$";
	s += to_string(getLevel()) + "$";

	return s;
}

NovicePlayer* KnightPlayer::unserialize(string s)
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

	NovicePlayer *point = new KnightPlayer(level, name);
	point->sethp(hp);
	point->setmp(mp);
	point->setexp(exp);
	point->setmoney(money);
	return point;
}