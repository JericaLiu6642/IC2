#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

Item::Item(int l, string n, string e, string d, int w, char t)
	:level_required(l), name(n), effect(e), description(d), weight(w), type(t)
{

}