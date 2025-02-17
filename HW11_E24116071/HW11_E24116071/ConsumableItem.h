#include <iostream>
#include <string>
#include "Item.h"

#ifndef CONSUMITEM_H
#define CONSUMITEM_H
using namespace std;

class ConsumableItem : public Item
{
public:
	ConsumableItem(int, string, string, string, int, char);
	virtual void use(const NovicePlayer* );
	virtual void use(BaseMonster*, int);
};
#endif
