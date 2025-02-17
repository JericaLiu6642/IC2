//HW4_E24116071
#ifndef MAP_H
#define MAP_H

using namespace std;

class map
{
public:
	map(); //constructor
	vector<int> split(const string & , vector<int>& , const char , const char ); //Ū�J��ƥh��,�M�Ů�
	void setMaze(string); //Ū�J���pushback��maze
	void bestRoute(); //��̨θ��|
	void setBonus(); //�]�wbonus
	void print(); //�L�Xmaze
	int visit(pair<int, int>, pair<int, int>); //�̨θ��|:���j
	pair<int, int> newPoint(int, int); //�̨θ��|:�إ߷s�I
	void printTest(); //���տ�X

private:
	vector<vector<int>> maze;
	vector<vector<int>> routeMaze;
	
};
#endif // !MAP_H
