//HW4_E24116071
#ifndef MAP_H
#define MAP_H

using namespace std;

class map
{
public:
	map(); //constructor
	vector<int> split(const string & , vector<int>& , const char , const char ); //讀入資料去除,和空格
	void setMaze(string); //讀入資料pushback到maze
	void bestRoute(); //找最佳路徑
	void setBonus(); //設定bonus
	void print(); //印出maze
	int visit(pair<int, int>, pair<int, int>); //最佳路徑:遞迴
	pair<int, int> newPoint(int, int); //最佳路徑:建立新點
	void printTest(); //測試輸出

private:
	vector<vector<int>> maze;
	vector<vector<int>> routeMaze;
	
};
#endif // !MAP_H
