#include <iostream>
#include <string>
#include "Sword.h"
using namespace std;

Sword::Sword()
	:WeaponItem(3, "Sword of Gryffindor", "attack + 20", 
		"Fashioned from pure silver, it is inset with rubies, the stone that represents Gryffindor.",
		3, 'w', 20)
{
}