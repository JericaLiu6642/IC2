#include <iostream>
#include <string>
#include <cmath>
#include "Venom.h"
using namespace std;

Venom::Venom()
	:ConsumableItem(0, "Nagini's venom", "Emeny's hp decrease through time ", 
		"An extremely potent poison that prevented the wounds of the victim from healing.", 2, 'c')
{

}

void Venom::use(BaseMonster *m, int turn)
{
	m->setHP(m->getHP() - pow(1.5, turn));
}
