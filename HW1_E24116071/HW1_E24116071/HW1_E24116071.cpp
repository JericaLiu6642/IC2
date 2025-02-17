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
	vector<set<int>> check; //�ˬd���ۦP������set�X��

	//�n���X��
	for (int i = 0; i < round; i++) {
		vector<int> setSize; //�s�B�͸s�����h�֤H
		check.clear();
		bool flag = 1; //�P�_�O�_�Ҧ����Y�����B�͸s�F
		int n, m;
		int a = 0;
		int b = 0;
		in >> n >> m;
		vector<vector<int>> relations(m); //�����B�����Y�A�@��@��
		for (int j = 0; j < relations.size(); j++){
			relations[j].resize(2);
		}

		//�Ҧ������Y�쵲�x�s
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
			friGroup.insert(0); //����|����
			for (int j = 0; j < m; j++) {
				if (relations[j][0] != 0){
					friGroup.insert(relations[j][0]);
					friGroup.insert(relations[j][1]);
					//�s�J����M0
					relations[j][0] = 0;
					relations[j][1] = 0;
					break;
				}
			}

			for (int j = 0; j < m; j++) {
				if (friGroup.count(relations[j][0]) == 1 || friGroup.count(relations[j][1]) == 1) {
					friGroup.insert(relations[j][0]);
					friGroup.insert(relations[j][1]);
					//�s�J����M0
					relations[j][0] = 0;
					relations[j][1] = 0;
				}
			}
	
			int count = 0; //�p��0���ӼơA�Ω�T�{�O�_�Ҧ����Y�����B�͸s

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

		// �⦳�ۦP������set�X�֡A�C�@�����n���Y��
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
