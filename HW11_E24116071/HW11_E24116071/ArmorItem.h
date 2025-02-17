#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
#ifndef ARMORITEM_H
#define ARMORITEM_H
class ArmorItem :public Item
{
public:
	const int defense_increment;
	ArmorItem(int, string, string, string, int, char, int);
};
#endif
