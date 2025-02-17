#include "complex.h"

#include<iostream>
using namespace std;



#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
private:
	Complex ** data;    // �@�ӤG����Complex�x�}
	int row;            // �x�sdata�@���X��row
	int col;            // �x�sdata�@���X��col
	void setUp(int, int);   // utility function, �]�wrow�Mcol����
public:
	Matrix();
	// default constructor, ���򳣤���, �Ndata�s�J2*2���O0����
	Matrix(int, int);
	// constructor, �u�]�w�j�p, ��ƹw�]��0+0i
	Matrix(int, int, Complex[], int);
	// constructor, �N�ǤJ���@���}�C��s���G���}�C��Jdata��
	//�ĥ|�ӰѼƬ��ĤT�ӰѼƪ��}�C����
	Matrix(const Matrix &);
	// copy constructor
	~Matrix();
	// destructor, �M�zdata

	void setData(int, int, const Complex &);
	// �]�w��(r,c)��mdata����
	int getRow() const;     // �^��private member: row
	int getCol() const;     // �^��private member: col
	Complex getData(int, int) const;    // ����x�}(r,c)��m����
	Matrix add(const Matrix &); // �x�}�ۥ[, �^�Ǭۥ[�᪺�x�}
	Matrix multiply(const Matrix &);    // �x�}�ۭ�, �^�Ǭۭ��ᤧ�x�}
	Matrix transpose();     // �x�}��m, �^����m�᪺�x�}

	void displayData() const {// �N�o�ӯx�}����ƦL�X�� (�i�ۦ��@)
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				data[i][j].print();
				cout <<"\t";
			}
			cout << "" << endl;
		}
	}

};

#endif