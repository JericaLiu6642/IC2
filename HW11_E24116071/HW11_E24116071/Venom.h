#ifndef VENOM_H
#define VENOM_H
#include <iostream>
#include <string>
#include "ConsumableItem.h"
using namespace std;

class Venom : public ConsumableItem
{
public:
	Venom();
	virtual void use(BaseMonster*, int);
};
#endif

