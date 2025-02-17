#include <string>
#include <cmath>
#include <sstream>
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
	if (a >= getLvupExp()) {
		exp = getLvupExp();
	}
	else {
		exp = a;
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

void NovicePlayer::specialSkill()
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