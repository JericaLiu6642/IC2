#include<iostream>
#include<string>
#include<sstream>
#include"BaseMonster.h"
#include"JWMonster.h"
using namespace std;

JWMonster::JWMonster() : BaseMonster("JWMaster", 120, 100, 42, 175, 250, 100)
{

}

JWMonster::JWMonster(string n, int a, int b, int c, int d, int e, int f)
	: BaseMonster(n, a, b, c, d, e, f)
{

}

string JWMonster::serialize()
{
	string s;
	s.clear();
	s += name + "$";
	s += to_string(attack) + "$";
	s += to_string(defense) + "$";
	s += to_string(exp) + "$";
	s += to_string(money) + "$";
	s += to_string(max_hp) + "$";
	s += to_string(max_mp) + "$";
	s += to_string(getHP()) + "$";
	s += to_string(getMP()) + "$";

	return s;
}

BaseMonster* JWMonster::unserialize(string s)
{
	stringstream ss(s);
	string temp;

	getline(ss, temp, '$');
	string name = temp;
	temp.clear();
	getline(ss, temp, '$');
	int attack = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int defense = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int exp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int money = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int max_hp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int max_mp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int hp = stoi(temp);
	temp.clear();
	getline(ss, temp, '$');
	int mp = stoi(temp);
	temp.clear();

	BaseMonster* point = new JWMonster(name, attack, defense, exp, money, max_hp, max_mp);
	point->setHP(hp);
	point->setMP(mp);

	return point;
}