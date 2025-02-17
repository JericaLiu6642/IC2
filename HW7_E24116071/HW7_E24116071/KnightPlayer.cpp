#include <string>
#include<iostream>
#include<cmath>
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
void KnightPlayer::heal(void)
{
	int l = KnightPlayer::getLevel();
	if (KnightPlayer::getmp() - l * 5 >= 0) {
		KnightPlayer::setmp(KnightPlayer::getmp() - l * 5);
		KnightPlayer::sethp(KnightPlayer::gethp() + l * 10);
	}
	else {
		cout << "\nMp is too low to heal!\n" << endl;
	}
}