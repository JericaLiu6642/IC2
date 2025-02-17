#include <string>
#include<cmath>
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
	maxhp = 100 + 10 * a;
	maxmp = 40 + 5 * a;
	attack = 20 + 5 * a;
	defense = 20 + 5 * a;
	lvupexp = ceil(pow(10, log2(level + 1)));
	hp = 100 + 10 * a;
	mp = 40 + 5 * a;
	exp = ceil(pow(10, log2(level)));
	money += ceil(pow(10, log2(level + 1))) * 10;
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