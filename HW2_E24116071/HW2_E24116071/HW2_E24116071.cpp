//HW2_E24116071

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <iomanip>
#include <sstream>
#define WALL -2
#define MINE -1
#define UNSTEPPED 0
#define STEPPED 1
#define WIN 2
#define BOOM 1
#define NOTBOOM 0


using namespace std;

struct gameMap {
	int info; //紀錄牆壁、炸彈和數字
	int press; //紀錄是否踩過
	string show; //板子輸出時該有的長相
};

vector<vector<gameMap>> chessboard; //遊戲板子

int checktypo1()
{
	while (1){
		bool check = true;
		string a;
		getline(cin, a);
		for (int i = 0; i < a.size(); i++){
			if (a[i]<'0' || a[i]>'9'){
				check = false;
			}
		}
		if (!check){
			cout << "Input error!";
			cout << "\nPlease enter a new number:";
			continue;
		}
		int j = atoi(a.c_str());
		if (j > 0){
			return j;
		}
	}
}

int checktypo2(int mn)
{
	while (1) {
		bool check = true;
		string b;
		getline(cin, b);
		for (int i = 0; i < b.size(); i++) {
			if (b[i]<'0' || b[i]>'9') {
				check = false;
			}
		}
		if (!check) {
			cout << "Input error!";
			cout << "\nPlease enter a new number:";
			continue;
		}
		int j = atoi(b.c_str());
		if (j > 0 && j <= mn) {
			return j;
		}
		else {
			cout << "Input error!";
			cout << "\nPlease enter a new number:";
		}
	}
}

int checktypo3(int a)
{
	while (1){
		bool check = true;
		string c;
		getline(cin, c);
		for (int i = 0; i < c.size(); i++){
			if (c[i]<'0' || c[i]>'9'){
				check = false;
			}
		}
		if (!check){
			cout << "Input error!";
			cout << "\nPlease enter a new number:";
			continue;
		}
		int j = atoi(c.c_str());
		if (j > 0 && j < a + 1){
			return j + 1;
		}
		else
		{
			cout << "Input error!";
			cout << "\nPlease enter a new number:";
		}
	}
}

void initialSetUp(int m, int n, int mine)
{
	//設定標號
	chessboard[0][0].show = " ";
	chessboard[0][m+2].show = " ";
	chessboard[n+2][0].show = " ";
	chessboard[0][1].show = "x";
	chessboard[1][0].show = "y";
	int k = 1;
	char buffer[100];
	for (int i = 2; i < m + 2; i++) {
		_itoa_s(k, buffer, 10);
		chessboard[0][i].show = string(buffer);
		k++;
	}
	int t = 1;
	for (int i = 2; i < n + 2; i++) {
		_itoa_s(t, buffer, 10);
		chessboard[i][0].show = string(buffer);
		t++;
	}

	//設定牆壁
	for (int i = 1; i < m + 3; i++) {
		chessboard[1][i].info = WALL;
		chessboard[1][i].show = "-";
		chessboard[n+2][i].info = WALL;
		chessboard[n+2][i].show = "-";
	}
	for (int i = 2; i < n + 2; i++) {
		chessboard[i][1].info = WALL;
		chessboard[i][1].show = "|";
		chessboard[i][m+2].info = WALL;
		chessboard[i][m+2].show = "|";
	}

	//設定地雷和每格的數字
	while (mine != 0) {
		srand(time(NULL));
		int x = rand() % n + 2;
		int y = rand() % m + 2;
		if (chessboard[x][y].info != WALL && chessboard[x][y].info != MINE) {
			chessboard[x][y].info = MINE;
			//設定周遭八格的數字
			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (chessboard[i][j].info != WALL && chessboard[i][j].info != MINE) {
						chessboard[i][j].info += 1;
					}
				}
			}
			mine--;
		}
	}
}

void showBoard(int m, int n, int condition)
{
	char buffer2[100];
	switch (condition) 
	{
	case BOOM:
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= m + 1; j++) {
				if (chessboard[i][j].info == 0) {
					chessboard[i][j].show = " ";
				}
				else if (chessboard[i][j].info == MINE) {
					chessboard[i][j].show = "*";
				}
				else {
					_itoa_s(chessboard[i][j].info, buffer2, 10);
					chessboard[i][j].show = string(buffer2);
				}
			}
		}
		for (auto & i : chessboard) {
			for (auto & j : i) {
				cout << j.show;
			}
			cout << endl;
		}
		break;

	case WIN:
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= m + 1; j++) {
				if (chessboard[i][j].info == 0) {
					chessboard[i][j].show = " ";
				}
				else if (chessboard[i][j].info == MINE) {
					chessboard[i][j].show = "M";
				}
				else {
					_itoa_s(chessboard[i][j].info, buffer2, 10);
					chessboard[i][j].show = string(buffer2);
				}
			}
		}
		for (auto & i : chessboard) {
			for (auto & j : i) {
				cout << j.show;
			}
			cout << endl;
		}
		break;

	case NOTBOOM:
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= m + 1; j++) {
				if (chessboard[i][j].press == UNSTEPPED) {
					chessboard[i][j].show = "■";
				}
				else if (chessboard[i][j].press == STEPPED) {
					if (chessboard[i][j].info == 0) {
						chessboard[i][j].show = " ";
					}
					else {
						_itoa_s(chessboard[i][j].info, buffer2, 10);
						chessboard[i][j].show = string(buffer2);
					}
				}
			}
		}
		for (auto & i : chessboard) {
			for (auto & j : i) {
				cout << j.show;
			}
			cout << endl;
		}
		break;
	}
}

int checkWin(int m, int n, int noMine)
{
	int counter = 0;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 2; j <= m + 1; j++) {
			if (chessboard[i][j].press == STEPPED) {
				counter++;
			}
		}
	}
	if (counter == noMine) {
		return 1;
	}
	else {
		return 0;
	}
}

void recursiveCheck(int x, int y)
{
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			if (chessboard[i][j].info > 0) {
				chessboard[i][j].press = STEPPED;
			}
			else if (chessboard[i][j].info == 0 && chessboard[i][j].press == UNSTEPPED) {
				chessboard[i][j].press = STEPPED;
				recursiveCheck(j, i);
			}
		}
	}
}

int main()
{
	bool playAgain = true;
	while (playAgain) {
		int m, n, mine, noMine;
		cout << "Please input the width of your map:";
		m = checktypo1();
		cout << "Please input the height of your map:";
		n = checktypo1();
		cout << "Please input the number of mines in your map:";
		mine = checktypo2(m*n);
		noMine = m*n - mine;

		//設定板子大小
		vector<gameMap> col (m + 3);
		chessboard.assign(n + 3, col); 

		initialSetUp(m, n, mine);
		showBoard(m, n, NOTBOOM);

		while (1) {
			int x, y;
			cout << "\nPlease input (x,y) to tell where you want to press" << endl;
			cout << "x:";
			x = checktypo3(m);
			cout << "y:";
			y = checktypo3(n);

			//開始判斷踩到的地方
			if (chessboard[y][x].info == MINE) {
				showBoard(m, n, BOOM);
				cout << "\nGAME OVER!! YOU LOSE!!\n";
				cout << "* indicates the position of exploded mines.\n" << endl;
				break;
			}
			else if (chessboard[y][x].info > 0) {
				chessboard[y][x].press = STEPPED;

				if (checkWin(m, n, noMine)) {
					showBoard(m, n, WIN);
					cout << "\nYOU WIN!!\n";
					cout << "M indicates the position of mines.\n" << endl;
					break;
				}
				else {
					showBoard(m, n, NOTBOOM);
					continue;
				}
			}
			else {
				recursiveCheck(x, y);
				if (checkWin(m, n, noMine) == 1) {
					showBoard(m, n, WIN);
					cout << "\nYOU WIN!!\n";
					cout << "M indicates the position of mines.\n" << endl;
					break;
				}
				else {
					showBoard(m, n, NOTBOOM);
					continue;
				}
			}
		}
		//詢問是否再玩
		int answer;
		cout << "Do you want to play again? Press 1 to play again, press others to leave:";
		cin >> answer;
		cout << endl;

		if (answer == 1) {
			playAgain = true;
		}
		else {
			playAgain = false;
			break;
		}
	}
}