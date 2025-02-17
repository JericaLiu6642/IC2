#include <string>
#include <cmath>
#include <sstream>
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

string OrcPlayer::serialize()
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

NovicePlayer* OrcPlayer::unserialize(string s)
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

	NovicePlayer *point = new OrcPlayer(level, name);
	point->sethp(hp);
	point->setmp(mp);
	point->setexp(exp);
	point->setmoney(money);
	return point;
}