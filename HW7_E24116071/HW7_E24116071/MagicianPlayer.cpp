#include <string>
#include<iostream>
#include<cmath>
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
void MagicianPlayer::pray(void)
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