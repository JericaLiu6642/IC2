#include <iostream>
#include <string>
#include "LifePotion.h"
using namespace std;

LifePotion::LifePotion()
	:ConsumableItem(0, "Life Potion", "Fill your hp to max", 
		"Extend the lifespan of those who drank it, and so long as they keep drinking it regularly, they would remain immortal.", 2, 'c')
{

}

void LifePotion::use(NovicePlayer* n)
{
	n->sethp(n->getMaxHP());
}
