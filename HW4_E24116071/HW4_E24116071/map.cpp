//HW4_E24116071
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<ctime>
#include"map.h"
#define WALL 1
#define START 200
#define DEST 201
#define PAVEMENT 0
#define BONUS 202
#define WENT -1

using namespace std;

map::map() //初始建構都先清零
{
	maze.clear();
}

vector<int> map::split(const string& s, vector<int>& help, const char delim1, const char delim2)
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

void map::setMaze(string file)
{
	ifstream in(file, ios::in);
	if (!in) {
		cerr << "File cannot be open!" << endl;
		exit(1);
	}
	
	int col, row;
	char skip;
	in >> col >> skip >> row;
	
	vector<int> help;
	string s;
	string t;

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
			maze.push_back(help);
		}
		help.clear();
	}

	//printTest();
}

void map::printTest()
{
	cout << maze.size() << " " << maze[0].size() << endl;
	for (auto & i : maze) {
		for (auto & j : i) {
			cout << j;
		}
		cout << endl;
	}
}

void map::bestRoute()
{
	pair<int, int> start;
	pair<int, int> dest;

	//先找起點終點的位置
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++){
			if (maze[i][j] == 200) {
				start.first = i;
				start.second = j;
			}
			else if (maze[i][j] == 201) {
				dest.first = i;
				dest.second = j;
			}
		}
	}

	//0表示還沒走過 -1表示走過
	routeMaze = maze;
	routeMaze[start.first][start.second] = 0;
	routeMaze[dest.first][dest.second] = 0;

	//開始找最佳路徑
	visit(start, dest);

	//把最佳路徑放回maze裡
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++) {
			if (routeMaze[i][j] == -1 && maze[i][j] == 0) {
				maze[i][j] = -1;
			}
		}
	}
}

pair<int, int> map::newPoint(int x, int y)
{
	pair<int, int> point = { x, y };
	return point;
}

int map::visit(pair<int, int> start, pair<int, int> dest)
{
	if (!routeMaze[start.first][start.second]) {
		routeMaze[start.first][start.second] = WENT;
		if (!routeMaze[dest.first][dest.second] &&
			!(visit(newPoint(start.first, start.second + 1), dest) ||
				visit(newPoint(start.first + 1, start.second), dest) ||
				visit(newPoint(start.first, start.second - 1), dest) ||
				visit(newPoint(start.first - 1, start.second), dest))) {
			routeMaze[start.first][start.second] = 0;
		}
	}
	return routeMaze[dest.first][dest.second];
}

void map::setBonus()
{
	//透過地圖大小決定bonus數量
	int a = maze.size();
	int b = maze[0].size();
	int bonus = 3;

	srand(time(NULL));
	while(bonus != 0)
	{	
		int x = rand() % a;
		int y = rand() % b;

		//不是牆壁起點終點或已存在bonus就可以放bonus
		if (maze[x][y] != WALL && maze[x][y] != START && maze[x][y] != DEST && maze[x][y] != BONUS) {
			maze[x][y] = BONUS;
			bonus--;
		}
	}
}


void map::print()
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

	for (auto & i : maze) {
		for (auto & j : i) {
			if (j == WALL) {
				//cout << "\x1b[37m\u2587\x1b[0m";
				cout << "\x1b[37m■\x1b[0m";
			}
			else if (j == START) {
				cout << "\x1b[31mS\x1b[0m";
			}
			else if (j == DEST) {
				cout << "\x1b[31mD\x1b[0m";
			}
			else if (j == BONUS) {
				cout << "\x1b[33mB\x1b[0m";
			}
			else if (j == WENT) {
				cout << "\x1b[32mX\x1b[0m";
			}
			else {
				//cout << "\x1b[37m\u2587\x1b[0m";
				cout << "\x1b[32m■\x1b[0m";
			}
		}
		cout << endl;
	}
}
