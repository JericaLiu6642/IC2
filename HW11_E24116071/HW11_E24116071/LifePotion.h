#ifndef LIFEPOTION_H
#define LIFEPOTION_H
#include <iostream>
#include <string>
#include "ConsumableItem.h"
using namespace std;

class LifePotion : public ConsumableItem
{
public:
	LifePotion();
	virtual void use(NovicePlayer*);
};
#endif

