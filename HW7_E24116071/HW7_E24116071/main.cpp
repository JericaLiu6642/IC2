#include <iostream>
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
#include "NovicePlayer.h"
#include "OrcPlayer.h"

using namespace std;

int main()
{
	//NovicePlayer
	NovicePlayer novice1;
	novice1.setmoney(0);
	NovicePlayer novice2(2);
	novice2.setmoney(0);
	NovicePlayer novice3(3, "testNovice");
	novice3.setmoney(0);
	NovicePlayer novice4(novice3);
	novice4.setmoney(0);

	cout << "novice1:" << endl;
	novice1.print();
	cout << endl;

	cout << "novice2:" << endl;
	novice2.print();
	cout << endl;

	cout << "novice3:" << endl;
	novice3.print();
	cout << endl;

	cout << "novice4:" << endl;
	novice4.print();
	cout << endl;

	novice4.setLevel(novice4.getLevel() + 1);
	cout << "novice4 after upgrade:" << endl;
	novice4.print();
	cout << endl;

	//OrcPlayer
	OrcPlayer Orc1;
	Orc1.setmoney(0);
	OrcPlayer Orc2(2);
	Orc2.setmoney(0);
	OrcPlayer Orc3(3, "testOrc");
	Orc3.setmoney(0);
	OrcPlayer Orc4(Orc3);
	Orc4.setmoney(0);

	cout << "Orc1:" << endl;
	Orc1.print();
	cout << endl;

	cout << "Orc2:" << endl;
	Orc2.print();
	cout << endl;

	cout << "Orc3:" << endl;
	Orc3.print();
	cout << endl;

	cout << "Orc4:" << endl;
	Orc4.print();
	cout << endl;

	Orc4.setLevel(Orc4.getLevel() + 1);
	cout << "Orc4 after upgrade:" << endl;
	Orc4.print();
	cout << endl;

	//KnightPlayer
	KnightPlayer Knight1;
	Knight1.setmoney(0);
	KnightPlayer Knight2(2);
	Knight2.setmoney(0);
	KnightPlayer Knight3(3, "testKnight");
	Knight3.setmoney(0);
	KnightPlayer Knight4(Knight3);
	Knight4.setmoney(0);

	cout << "Knight1:" << endl;
	Knight1.print();
	cout << endl;

	cout << "Knight2:" << endl;
	Knight2.print();
	cout << endl;

	cout << "Knight3:" << endl;
	Knight3.print();
	cout << endl;

	cout << "Knight4:" << endl;
	Knight4.print();
	cout << endl;

	Knight4.setLevel(Knight4.getLevel() + 1);
	Knight4.sethp(Knight4.gethp() - 40);
	cout << "Knight4 after upgrade and losing hp:" << endl;
	Knight4.print();
	cout << endl;

	Knight4.heal();
	cout << "Knight4 after healing:" << endl;
	Knight4.print();
	cout << endl;

	//MagicianPlayer
	MagicianPlayer Magician1;
	Magician1.setmoney(0);
	MagicianPlayer Magician2(2);
	Magician2.setmoney(0);
	MagicianPlayer Magician3(3, "testMagician");
	Magician3.setmoney(0);
	MagicianPlayer Magician4(Magician3);
	Magician4.setmoney(0);

	cout << "Magician1:" << endl;
	Magician1.print();
	cout << endl;

	cout << "Magician2:" << endl;
	Magician2.print();
	cout << endl;

	cout << "Magician3:" << endl;
	Magician3.print();
	cout << endl;

	cout << "Magician4:" << endl;
	Magician4.print();
	cout << endl;

	Magician4.setLevel(Magician4.getLevel() + 1);
	Magician4.setmp(Magician4.getmp() - 30);
	cout << "Magician4 after upgrade and losing mp:" << endl;
	Magician4.print();
	cout << endl;

	Magician4.pray();
	cout << "Magician4 after praying:" << endl;
	Magician4.print();
	cout << endl;

	return 0;
}
