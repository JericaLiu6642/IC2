#include <iostream>
#include <string>
#include"ConsumableItem.h"

using namespace std;

ConsumableItem::ConsumableItem(int l, string n, string e, string d, int w, char t)
	:Item(l, n, e, d, w, t)
{
}

void ConsumableItem::use(const NovicePlayer* )
{

}

void ConsumableItem::use(BaseMonster*, int)
{

}
