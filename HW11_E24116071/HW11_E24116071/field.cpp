#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <conio.h>
#include<windows.h>
#include"field.h"
#include"Battle.h"
#include"BaseMonster.h"
#include"NovicePlayer.h"
#define WALL 1
#define ROAD 0
#define START 200
#define DEST 201
#define BATTLE_A 202 //spiders
#define BATTLE_B 203 //giant
#define BATTLE_C 204 //warewolf
#define BATTLE_D 205 //Dementor
#define BATTLE_V 206 //Voldemort
#define CHARM 300
#define SAVE 400
using namespace std;

void Field::SetColor(int color = 7) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

vector<int> Field::split(const string& s, vector<int>& help, const char delim1, const char delim2)
{
	help.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, delim1))
	{
		istringstream iss2(temp);
		while (getline(iss2, temp, delim2)) {
			help.push_back(stoi(temp));
		}
	}
	return help;
}

Field::Field(string file, int x, int y, int w, int h, NovicePlayer* me)
{
	ifstream in(file, ios::in);
	if (!in) {
		cerr << "File cannot be open!" << endl;
		exit(1);
	}

	int col, row;
	char skip;
	in >> col >> skip >> row;

	//設定好地圖的大小
	map_data = new int*[row];
	for (int i = 0; i < row; i++) {
		map_data[i] = new int[col];
	}
	
	vector<int> help;
	string s;
	string t;
	int row_count = 0;

	// char we don't want to be put into the vector
	const char delim1 = ',';
	const char delim2 = ' ';
	while (getline(in, s)) {
		stringstream ss(s);
		string data;
		while (ss >> data)
		{
			split(s, help, delim1, delim2);
		}
		if (help.size() != 0) {
			for (int j = 0; j < help.size(); j++) {
				map_data[row_count][j] = help[j];
			}
			row_count++;
		}
		help.clear();
	}

	setPosition(x, y);
	setVisionSize(w, h);
	setPlayer(me);

	//取得地圖名字
	stringstream ss2(file);
	string n;
	getline(ss2, n, '.');
	map_name = n;
}

void Field::setPlayer(NovicePlayer* me)
{
	player = me;
}


Field::~Field()
{
	for (auto* ptr : playPoint) {
		delete ptr;
	}
	playPoint.clear();

	for (auto* ptr : monPoint) {
		delete ptr;
	}
	monPoint.clear();
}

bool Field::move(char c) //y控制col所以是左右 x控制row所以是上下
{
	switch (c)
	{
	case 'w':
	case 'W':
		if (map_data[current_position_x - 1][current_position_y] != WALL){
			setPosition(current_position_x - 1, current_position_y);
			system("cls");
			display();
			Events(map_data[current_position_x][current_position_y]);
			return true;
		}
		break;
	case 'a':
	case 'A':
		if (map_data[current_position_x][current_position_y - 1] != WALL){
			setPosition(current_position_x, current_position_y - 1);
			system("cls");
			display();
			Events(map_data[current_position_x][current_position_y]);
			return true;
		}
		break;
	case 's':
	case 'S':
		if (map_data[current_position_x + 1][current_position_y] != WALL){
			setPosition(current_position_x + 1, current_position_y);
			system("cls");
			display();
			Events(map_data[current_position_x][current_position_y]);
			return true;
		}
		break;
	case 'd':
	case 'D':
		if (map_data[current_position_x][current_position_y + 1] != WALL){
			setPosition(current_position_x, current_position_y + 1);
			system("cls");
			display();
			Events(map_data[current_position_x][current_position_y]);
			return true;
		}
		break;
	}
	cout << "Illegal move!\n";
	return false;
}

bool Field::moveUp(void)
{
	if (map_data[current_position_x - 1][current_position_y] != WALL) {
		setPosition(current_position_x - 1, current_position_y);
		system("cls");
		display();
		Events(map_data[current_position_x][current_position_y]);
		return true;
	}
	cout << "Illegal move!\n";
	return false;
}

bool Field::moveDown(void)
{
	if (map_data[current_position_x + 1][current_position_y] != WALL) {
		setPosition(current_position_x + 1, current_position_y);
		system("cls");
		display();
		Events(map_data[current_position_x][current_position_y]);
		return true;
	}
	cout << "Illegal move!\n";
	return false;
}

bool Field::moveLeft(void)
{
	if (map_data[current_position_x][current_position_y - 1] != WALL) {
		setPosition(current_position_x, current_position_y - 1);
		system("cls");
		display();
		Events(map_data[current_position_x][current_position_y]);
		return true;
	}
	cout << "Illegal move!\n";
	return false;
}

bool Field::moveRight(void)
{
	if (map_data[current_position_x][current_position_y + 1] != WALL) {
		setPosition(current_position_x, current_position_y + 1);
		system("cls");
		display();
		Events(map_data[current_position_x][current_position_y]);
		return true;
	}
	cout << "Illegal move!\n";
	return false;
}

int  Field::getCurrentPositionX(void) const
{
	return current_position_x;
}

int  Field::getCurrentPositionY(void) const
{
	return current_position_y;
}

int  Field::getVisionWidth(void) const
{
	return vision_width;
}

int  Field::getVisionHeight(void) const
{
	return vision_height;
}

string  Field::getMapName(void) const
{
	return map_name;
}

int  Field::getMapSymbol(int x, int y)
{
	return map_data[x][y];

}

void Field::setPosition(int x, int y)
{
	current_position_x = x;
	current_position_y = y;
}

void Field::setMapSymbol(int s, int x, int y)
{
	map_data[x][y] = s;
}

void Field::setVisionSize(int w, int h)
{
	vision_width = w;
	vision_height = h;
}

void Field::display(void) const
{
	#define BLOCK "\u2587"
	#define BLOCKIMAGE ■
	#define BLACK  "\x1b[30m"
	#define RED  "\x1b[31m"
	#define GREEN "\x1b[32m"
	#define YELLOW  "\x1b[33m"
	#define BLUE "\x1b[34m"
	#define MAGENTA  "\x1b[35m"
	#define CYAN "\x1b[36m"
	#define WHITE "\x1b[37m"
	#define RESET "\x1b[0m"
	#define Player △

	if (map_name != "Forbidden_Forest") {
		cout << "========================================================================" << endl;
		cout << "                              The keys to map                           " << endl;
		cout << "  S: Your initial place / D: Your destination / C: Classes / B : Battle " << endl;
		cout << "========================================================================" << endl;
	}
	else {
		cout << "========================================================================" << endl;
		cout << "                              The keys to map                           " << endl;
		cout << "  S: Your initial place / D: Your destination / C: Classes / B : Battle " << endl;
		cout << "                  V: Start a battle with Lord Voldemort                 " << endl;
		cout << "========================================================================" << endl;
	}

	cout << setw(25) << "Level: "; 
	SetColor(12);
	cout << player->getLevel() << endl;
	SetColor();

	//輸出玩家目前位置
	cout << "You are now at (" << getCurrentPositionX() << ", " << getCurrentPositionY() << ") of " << map_name << ". " << endl;

	//輸出7*7的視線
	cout << "Vision:" << endl;
	for (int i = current_position_x - 3; i <= current_position_x + 3; i++) {
		for (int j = current_position_y - 3; j <= current_position_y + 3; j++) {
			if (i == current_position_x && j == current_position_y) {
				if (getMapName() == "The_Great_Hall") {
					SetColor(236);
					cout << "▲ ";
					SetColor();
				}
				else if (getMapName() == "The_Quidditch_Pitch") {
					SetColor(172);
					cout << "▲ ";
					SetColor();
				}
				else if (getMapName() == "Forbidden_Forest") {
					SetColor(156);
					cout << "▲ ";
					SetColor();
				}
			}
			else if (map_data[i][j] == WALL) {
				SetColor(240);
				cout << "  ";
				SetColor();
			}
			else if (map_data[i][j] == ROAD  || map_data[i][j] == SAVE) {
				if (getMapName() == "The_Great_Hall") {
					SetColor(238);
					cout << "  ";
					SetColor();
				}
				else if (getMapName() == "The_Quidditch_Pitch") {
					SetColor(160);
					cout << "  ";
					SetColor();
				}
				else if (getMapName() == "Forbidden_Forest") {
					SetColor(153);
					cout << "  ";
					SetColor();
				}
			}
			else if (map_data[i][j] == START) {
				if (getMapName() == "The_Great_Hall") {
					SetColor(236);
					cout << "S ";
					SetColor();
				}
				else if (getMapName() == "The_Quidditch_Pitch") {
					SetColor(172);
					cout << "S ";
					SetColor();
				}
				else if (getMapName() == "Forbidden_Forest") {
					SetColor(156);
					cout << "S ";
					SetColor();
				}
			}
			else if (map_data[i][j] == DEST) {
				if (getMapName() == "The_Great_Hall") {
					SetColor(236);
					cout << "D ";
					SetColor();
				}
				else if (getMapName() == "The_Quidditch_Pitch") {
					SetColor(172);
					cout << "D ";
					SetColor();
				}
				else if (getMapName() == "Forbidden_Forest") {
					SetColor(156);
					cout << "D ";
					SetColor();
				}
			}
			else if (map_data[i][j] == CHARM) {
				SetColor(176);
				cout << "C ";
				SetColor();
			}
			else if (map_data[i][j] == BATTLE_A || map_data[i][j] == BATTLE_B || map_data[i][j] == BATTLE_C
				|| map_data[i][j] == BATTLE_D) {
				SetColor(206);
				cout << "B ";
				SetColor();
			}
			else if (map_data[i][j] == BATTLE_V) {
				SetColor(220);
				cout << "V ";
				SetColor();
			}
		}
		cout << endl;
	}

	//提示語
	cout << "Press (W : go up / S : go down / A : go left / D : go right)" << endl;

}

void Field::Events(int n)
{
	switch (n)
	{
	case DEST:
		if (map_name != "Forbidden_Forest") { //代表不是最後一張圖
			system("cls");
			cout << "Do you want to leave the current place and move onto the next one?" << endl;
			cout << "(Think wisely, you can not return)" << endl;
			cout << "Press Y to leave, press others to stay:";
			char c;
			cin >> c;
			switch (c) {
			case 'y':
			case 'Y':
				leave = true;
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				display();
				return;
			}
		}
		else {
			cout << "Are you sure to leave the game?" << endl;
			cout << "Press Y to leave, press others to stay:";
			char c;
			cin >> c;
			switch (c) {
			case 'y':
			case 'Y':
				leave = true;
				break;
				return;
			default:
				system("cls");
				display();
				return;
				break;
			}
		}
		break;

	case BATTLE_A:
		system("cls");
		playPoint.clear();
		monPoint.clear();
		monPoint.push_back(new GoblinMonster("Spider", 50, 20, 20, 20, 50, 5));

		cout << "Encounter ememies! Entering a battle! \nDo you need another wizard's help? ";
		cout << "Press Y for yes, press E for escape, press others for no:";
		char c;
		cin >> c;

		if (c == 'y' || c == 'Y') {
			system("cls");
			cout << "Choose your helper:" << endl;
			cout << "Enter 1 for Harry Potter: With special magic to change his mp into your hp." << endl;
			cout << "Enter 2 for Ron Weasley: Can cause huge damage to enemies when he attacks." << endl;
			cout << "Enter 3 for Hermione Granger: By decreasing her mp to decrease the enemy's defense." << endl;
			cout << "Please choose:";

			//輸入防呆
			char choice;
			while (1) {
				cin >> choice;
				if (choice == '1' || choice == '2' || choice == '3') {
					break;
				}
				else {
					cout << "Wrong input! Please try again:";
				}
			}

			switch (choice) {
			case '1':
				playPoint.push_back(player);
				playPoint.push_back(new KnightPlayer(player->getLevel(), "Harry Potter"));
				break;
			case '2':
				playPoint.push_back(player);
				playPoint.push_back(new OrcPlayer(player->getLevel(), "Ron Weasley"));
				break;
			case '3':
				playPoint.push_back(player);
				playPoint.push_back(new MagicianPlayer(player->getLevel(), "Hermione Granger"));
				break;
			}

			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		else if (c == 'e' || c == 'E') {
			system("cls");
			display();
			return;
			break;
		}
		else {
			playPoint.push_back(player);
			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		playPoint.clear();
		monPoint.clear();
		map_data[current_position_x][current_position_y] = 0;
		system("cls");
		display();
		return;
		break;

	case BATTLE_B:
		system("cls");
		playPoint.clear();
		monPoint.clear();
		monPoint.push_back(new ZombieMonster("Giant", 75, 45, 80, 100, 100, 30));

		cout << "Encounter ememies! Entering a battle! \nDo you need another wizard's help? ";
		cout << "Press Y for yes, press E for escape, press others for no:";
		char a;
		cin >> a;

		if (a == 'y' || a == 'Y') {
			system("cls");
			cout << "Choose your helper:" << endl;
			cout << "Enter 1 for Harry Potter: With special magic to change his mp into your hp." << endl;
			cout << "Enter 2 for Ron Weasley: Can cause huge damage to enemies when he attacks." << endl;
			cout << "Enter 3 for Hermione Granger: By decreasing her mp to decrease the enemy's defense." << endl;
			cout << "Please choose:";

			//輸入防呆
			char choice;
			while (1) {
				cin >> choice;
				if (choice == '1' || choice == '2' || choice == '3') {
					break;
				}
				else {
					cout << "Wrong input! Please try again:";
				}
			}
			switch (choice) {
			case '1':
				playPoint.push_back(player);
				playPoint.push_back(new KnightPlayer(player->getLevel(), "Harry Potter"));
				break;
			case '2':
				playPoint.push_back(player);
				playPoint.push_back(new OrcPlayer(player->getLevel(), "Ron Weasley"));
				break;
			case '3':
				playPoint.push_back(player);
				playPoint.push_back(new MagicianPlayer(player->getLevel(), "Hermione Granger"));
				break;
			}

			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		else if (a == 'e' || a == 'E') {
			system("cls");
			display();
			return;
			break;
		}
		else {
			playPoint.push_back(player);
			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		playPoint.clear();
		monPoint.clear();
		map_data[current_position_x][current_position_y] = 0;
		system("cls");
		display();
		return;
		break;

	case BATTLE_C:
		system("cls");
		playPoint.clear();
		monPoint.clear();
		monPoint.push_back(new ZombieMonster("Warewolf", 100, 65, 120, 150, 150, 30));

		cout << "Encounter ememies! Entering a battle! \nDo you need another wizard's help? ";
		cout << "Press Y for yes, press E for escape, press others for no:";
		char a1;
		cin >> a1;

		if (a1 == 'y' || a1 == 'Y') {
			system("cls");
			cout << "Choose your helper:" << endl;
			cout << "Enter 1 for Harry Potter: With special magic to change his mp into your hp." << endl;
			cout << "Enter 2 for Ron Weasley: Can cause huge damage to enemies when he attacks." << endl;
			cout << "Enter 3 for Hermione Granger: By decreasing her mp to decrease the enemy's defense." << endl;
			cout << "Please choose:";

			//輸入防呆
			char choice;
			while (1) {
				cin >> choice;
				if (choice == '1' || choice == '2' || choice == '3') {
					break;
				}
				else {
					cout << "Wrong input! Please try again:";
				}
			}
			switch (choice) {
			case '1':
				playPoint.push_back(player);
				playPoint.push_back(new KnightPlayer(player->getLevel(), "Harry Potter"));
				break;
			case '2':
				playPoint.push_back(player);
				playPoint.push_back(new OrcPlayer(player->getLevel(), "Ron Weasley"));
				break;
			case '3':
				playPoint.push_back(player);
				playPoint.push_back(new MagicianPlayer(player->getLevel(), "Hermione Granger"));
				break;
			}

			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		else if (a1 == 'e' || a1 == 'E') {
			system("cls");
			display();
			return;
			break;
		}
		else {
			playPoint.push_back(player);
			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		playPoint.clear();
		monPoint.clear();
		map_data[current_position_x][current_position_y] = 0;
		system("cls");
		display();
		return;
		break;

	case BATTLE_D:
		system("cls");
		playPoint.clear();
		monPoint.clear();
		monPoint.push_back(new ZombieMonster("Dementor", 150, 80, 180, 200, 200, 30));

		cout << "Encounter ememies! Entering a battle! \nDo you need another wizard's help? ";
		cout << "Press Y for yes, press E for escape, press others for no:";
		char a2;
		cin >> a2;

		if (a2 == 'y' || a2 == 'Y') {
			system("cls");
			cout << "Choose your helper:" << endl;
			cout << "Enter 1 for Harry Potter: With special magic to change his mp into your hp." << endl;
			cout << "Enter 2 for Ron Weasley: Can cause huge damage to enemies when he attacks." << endl;
			cout << "Enter 3 for Hermione Granger: By decreasing her mp to decrease the enemy's defense." << endl;
			cout << "Please choose:";

			//輸入防呆
			char choice;
			while (1) {
				cin >> choice;
				if (choice == '1' || choice == '2' || choice == '3') {
					break;
				}
				else {
					cout << "Wrong input! Please try again:";
				}
			}
			switch (choice) {
			case '1':
				playPoint.push_back(player);
				playPoint.push_back(new KnightPlayer(player->getLevel(), "Harry Potter"));
				break;
			case '2':
				playPoint.push_back(player);
				playPoint.push_back(new OrcPlayer(player->getLevel(), "Ron Weasley"));
				break;
			case '3':
				playPoint.push_back(player);
				playPoint.push_back(new MagicianPlayer(player->getLevel(), "Hermione Granger"));
				break;
			}

			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		else if (a2 == 'e' || a2 == 'E') {
			system("cls");
			display();
			return;
			break;
		}
		else {
			playPoint.push_back(player);
			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		playPoint.clear();
		monPoint.clear();
		map_data[current_position_x][current_position_y] = 0;
		system("cls");
		display();
		return;
		break;

	case BATTLE_V:
		system("cls");
		playPoint.clear();
		monPoint.clear();
		monPoint.push_back(new JWMonster("Lord Voldemort", 250, 150, 1000, 1000, 300, 100));

		cout << "Battle with Lord Voldemort! Win this battle to end the sememster! \nDo you need another wizard's help? ";
		cout << "Press Y for yes, press E for escape, press others for no:";
		char b;
		cin >> b;

		if (b == 'y' || b == 'Y') {
			system("cls");
			cout << "Choose your helper:" << endl;
			cout << "Enter 1 for Harry Potter: With special magic to change his mp into your hp." << endl;
			cout << "Enter 2 for Ron Weasley: Can cause huge damage to enemies when he attacks." << endl;
			cout << "Enter 3 for Hermione Granger: By decreasing her mp to decrease the enemy's defense." << endl;
			cout << "Please choose:";

			//輸入防呆
			char choice;
			while (1) {
				cin >> choice;
				if (choice == '1' || choice == '2' || choice == '3') {
					break;
				}
				else {
					cout << "Wrong input! Please try again:";
				}
			}

			switch (choice) {
			case '1':
				playPoint.push_back(player);
				playPoint.push_back(new KnightPlayer(player->getLevel(), "Harry Potter"));
				break;
			case '2':
				playPoint.push_back(player);
				playPoint.push_back(new OrcPlayer(player->getLevel(), "Ron Weasley"));
				break;
			case '3':
				playPoint.push_back(player);
				playPoint.push_back(new MagicianPlayer(player->getLevel(), "Hermione Granger"));
				break;
			}

			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 1) {
				system("pause");
				system("cls");
				cout << "GAME OVER! YOU WIN!" << endl;
				exit(1);
			}
			else if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		else if (b == 'e' || b == 'E') {
			system("cls");
			display();
			return;
			break;
		}
		else {
			playPoint.push_back(player);
			Battle battle(playPoint, monPoint);
			if (battle.playerWin == 2) {
				system("pause");
				system("cls");
				cout << "YOU LOSE THE GAME!" << endl;
				exit(1);
			}
		}
		playPoint.clear();
		monPoint.clear();
		map_data[current_position_x][current_position_y] = 0;
		system("cls");
		display();
		return;
		break;

	case CHARM:
		system("cls");
		cout << "Welcome to Hogwarts charm lesson. I'm your professor Filius Flitwick." << endl;
		cout << "Today we are learning the floating charm. Please put out your wand and spell the spell" << endl;
		cout << "(Hint:WingardiumLeviosa)" << endl;
		cout << "Please spell the spell:";
		string ans;
		cin >> ans;
		if (ans == "WingardiumLeviosa") {
			cout << "Correct Spell! Your mp will decrease by 10 and exp incerase by 50." << endl;
			player->setmp(player->getmp() - 10);
			player->setexp(player->getexp() + 50);
		}
		else {
			cout << "Wrong spell! I recommand you check the spell on your textbook carefully and comeback later." << endl;
		}
		cout << "Class dismiss!" << endl;
		map_data[current_position_x][current_position_y] = 0;
		system("pause");
		system("cls");
		display();
		return;
	}
}