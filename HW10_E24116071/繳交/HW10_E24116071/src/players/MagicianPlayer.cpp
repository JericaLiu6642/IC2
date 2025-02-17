#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
#include "NovicePlayer.h"
#include "MagicianPlayer.h"

using namespace std;

//constructor
MagicianPlayer::MagicianPlayer() 
{
	setLevel(1);
	setname("anonymous");
}

MagicianPlayer::MagicianPlayer(int a) 
{
	setLevel(a);
	setname("anonymous");
}

MagicianPlayer::MagicianPlayer(int a, string s) 
{
	setLevel(a);
	setname(s);
}

MagicianPlayer::MagicianPlayer(const MagicianPlayer& p) 
{
	setLevel(p.getLevel());
	setname(p.getname());
}

//setter
void MagicianPlayer::setLevel(int a)
{
	level = a;
	maxhp = 120 + 15 * a;
	maxmp = 100 + 15 * a;
	attack = 30 + 8 * a;
	defense = 20 + 7 * a;
	lvupexp = ceil(pow(10, log2(level + 1)));
	sethp(120 + 15 * a);
	setmp(100 + 15 * a);
	setexp(ceil(pow(10, log2(a))));
	setmoney(getmoney() + (ceil(pow(10, log2(level)))) * 10);
}

//special
void MagicianPlayer::specialSkill(void)
{
	int l = NovicePlayer::getLevel();
	if (NovicePlayer::gethp() - l * 5 >= 0) {
		NovicePlayer::sethp(NovicePlayer::gethp() - l * 5);
		NovicePlayer::setmp(NovicePlayer::getmp() + l * 10);
	}
	else {
		cout << "Hp is too low to pray!\n" << endl;
	}
}

string MagicianPlayer::serialize()
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

NovicePlayer* MagicianPlayer::unserialize(string s)
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

	NovicePlayer *point = new MagicianPlayer(level, name);
	point->sethp(hp);
	point->setmp(mp);
	point->setexp(exp);
	point->setmoney(money);
	return point;
}