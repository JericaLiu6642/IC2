#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
#ifndef WEAPONITEM_H
#define WEAPONITEM_H
class WeaponItem : public Item
{
public:
	const int attack_increment;
	WeaponItem(int, string, string, string, int, char, int);

};
#endif