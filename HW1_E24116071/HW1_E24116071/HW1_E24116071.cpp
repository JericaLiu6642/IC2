// HW1_E24116071
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ifstream in("sample.txt", ios::in);
	int round;
	in >> round;
	vector<int> answer;
	vector<set<int>> check; //檢查有相同元素的set合併

	//要做幾輪
	for (int i = 0; i < round; i++) {
		vector<int> setSize; //存朋友群內有多少人
		check.clear();
		bool flag = 1; //判斷是否所有關係都有朋友群了
		int n, m;
		int a = 0;
		int b = 0;
		in >> n >> m;
		vector<vector<int>> relations(m); //紀錄朋友關係，一行一組
		for (int j = 0; j < relations.size(); j++){
			relations[j].resize(2);
		}

		//所有的關係鏈結儲存
		for (int j = 0; j < m; j++) {
			in >> a >> b;
			if (a > b) {
				relations[j][0] = b;
				relations[j][1] = a;
			}
			else {
				relations[j][0] = a;
				relations[j][1] = b;
			}
		}

		while (flag) {
			set<int> friGroup;
			friGroup.insert(0); //之後會扣掉
			for (int j = 0; j < m; j++) {
				if (relations[j][0] != 0){
					friGroup.insert(relations[j][0]);
					friGroup.insert(relations[j][1]);
					//存入之後清0
					relations[j][0] = 0;
					relations[j][1] = 0;
					break;
				}
			}

			for (int j = 0; j < m; j++) {
				if (friGroup.count(relations[j][0]) == 1 || friGroup.count(relations[j][1]) == 1) {
					friGroup.insert(relations[j][0]);
					friGroup.insert(relations[j][1]);
					//存入之後清0
					relations[j][0] = 0;
					relations[j][1] = 0;
				}
			}
	
			int count = 0; //計算0的個數，用於確認是否所有關係都有朋友群

			for (int x = 0; x < m; x++) {
				for (int y = 0; y < 2; y++) {
					if (relations[x][y] == 0) {
						count++;
					}
				}
			}

			if (count == m * 2) {
				flag = false;
			}

			friGroup.erase(0);
			check.push_back(friGroup);
		}

		// 把有相同元素的set合併，每一次都要重頭找
		for (int i = 0; i < check.size(); i++) {
			for (int j = 0; j < check.size(); j++) {
				bool merge = false;
				if (i == j) continue;
				for (auto& k : check[j]) {
					if (check[i].count(k)) {
						check[i].insert(check[j].begin(), check[j].end());
						merge = true;
						break;
					}
				}
				if (merge) {
					check.erase(check.begin() + j);
					j--;
				}
			}
		}

		int Max = 0;
		for (auto &i : check) {
			if (i.size() > Max) {
				Max = i.size();
			}
		}
		answer.push_back(Max);
	}

	for (int k = 0; k < answer.size(); k++) {
		cout << answer[k] << endl;
	}
}
