//HW4_E24116071
#include<iostream>
#include<vector>
#include<string>
#include"map.h"

using namespace std;

int main()
{
	map gameMaze;
	string file;
	cout << "Please input the name of your maze file (ex. maze1.txt):";
	cin >> file;
	gameMaze.setMaze(file);
	gameMaze.bestRoute();
	gameMaze.setBonus();
	gameMaze.print();
}