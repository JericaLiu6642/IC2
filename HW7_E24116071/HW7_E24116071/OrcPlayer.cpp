#include <string>
#include<cmath>
#include "NovicePlayer.h"
#include "OrcPlayer.h"

using namespace std;

//constructor
OrcPlayer::OrcPlayer()
{
	setLevel(1);
	setname("anonymous");
}

OrcPlayer::OrcPlayer(int a)
{
	setLevel(a);
	setname("anonymous");
}

OrcPlayer::OrcPlayer(int a, string s) 
{
	setLevel(a);
	setname(s);
}

OrcPlayer::OrcPlayer(const OrcPlayer& p)
{
	setLevel(p.getLevel());
	setname(p.getname());
}

//setter
void OrcPlayer::setLevel(int a)
{
	level = a;
	maxhp = 200 + 20 * a;
	maxmp = 50 + 5 * a;
	attack = 50 + 12 * a;
	defense = 30 + 10 * a;
	lvupexp = ceil(pow(10, log2(level + 1)));
	sethp(200 + 20 * a);
	setmp(50 + 5 * a);
	setexp(ceil(pow(10, log2(level))));
	setmoney(getmoney() + (ceil(pow(10, log2(level)))) * 10);
}