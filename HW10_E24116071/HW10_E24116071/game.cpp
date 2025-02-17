#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<typeinfo>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include"field.h"
#include"BaseMonster.h"
#include"NovicePlayer.h"
#include"GoblinMonster.h"
#include"ZombieMonster.h"
#include"JWMonster.h"
#include"OrcPlayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"Battle.h"

using namespace std;

void intro()
{
	cout << setw(25) << "====================================" << endl;
	cout << setw(25) << "|          Hogwarts School         |" << endl;
	cout << setw(25) << "|    Of Witchcraft and Wizardry    |" << endl;
	cout << setw(25) << "|                                  |" << endl;
	cout << setw(25) << "| We're pleased to imform you that |" << endl;
	cout << setw(25) << "|   you have a place at Hogwarts.  |" << endl;
	cout << setw(25) << "|    You'll be traveling to the    |" << endl;
	cout << setw(25) << "| Wizarding World of Harry Potter. |" << endl;
	cout << setw(25) << "|         Enjoy your trip!         |" << endl;
	cout << setw(25) << "====================================" << endl;
	system("pause");
	system("cls");
}

void task()
{
	cout << setw(25) << "=================================================" << endl;
	cout << setw(25) << "|             Task for the semester:             |" << endl;
	cout << setw(25) << "|              Defeat Lord Voldemort             |" << endl;
	cout << setw(25) << "|                                                |" << endl;
	cout << setw(25) << "|      You might encounter enemies at school.    |" << endl;
	cout << setw(25) << "|   Defeat them wins you money and experience,   |" << endl;
	cout << setw(25) << "|   which might help you fight with Voldemort.   |" << endl;
	cout << setw(25) << "|  Whenever you encounter an enemy, you can ask  |" << endl;
	cout << setw(25) << "|  other wizard for help. If you lose all your   |" << endl;
	cout << setw(25) << "|   hp during the battle, you lose the game.     |" << endl;
	cout << setw(25) << "|  The Ministery of Magic will send you back to  |" << endl;
	cout << setw(25) << "|     your house and delete all your memory.     |" << endl;
	cout << setw(25) << "|             Wish you all the best:)            |" << endl;
	cout << setw(25) << "==================================================" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//簡介遊戲背景和取名
	intro();
	string s;
	cout << "What's your name:";
	cin >> s;
	system("pause");
	system("cls");

	//歡迎和說明遊戲規則
	NovicePlayer me(1, s);
	cout << "Welcome to Hogwarts School, " << s << "!" << endl;
	task();

	Field f("Forbidden_Forest.txt", 2, 2, 5, 5, &me);
	f.display();

	char c;
	while (c = _getch()){
		f.move(c);
		if (f.leave) {
			break;
		}
	}
}