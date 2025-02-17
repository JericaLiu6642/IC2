//HW5_E24116071
#include <iostream>
#include "matrix.h"

using namespace std;

void Matrix::setUp(int a, int b)	// utility function, �]�wrow�Mcol����
{
	row = a;
	col = b;
}


Matrix::Matrix() // default constructor, ���򳣤���, �Ndata�s�J2*2���O0����
{
	setUp(2, 2);
	data = new double*[2];
	for (int i = 0; i < 2; i++) {
		data[i] = new double[2]{ 0 };
	}
}

Matrix::Matrix(int a, int b) // constructor, �u�]�w�j�p, ��ƹw�]��0
{
	setUp(a, b);
	data = new double*[a];
	for (int i = 0; i < a; i++) {
		data[i] = new double[b] {0};
	}
}

Matrix::Matrix(int a, int b, double c[], int d) // constructor, �N�ǤJ���@���}�C��s���G���}�C��Jdata��
{
	if (a*b != d) {
		cout << "Wrong input! The size of the 1D array doesn't match with the 2D array!" << endl;
		exit(1);
	}

	setUp(a, b);
	data = new double*[a];
	for (int i = 0; i < a; i++) {
		data[i] = new double[b]{ 0 };
	}

	int Length = 0;

	while (Length < d) {
		for (int i = 0; i < getRow(); i++) {
			for (int j = 0; j < getCol(); j++) {
				data[i][j] = c[Length];
				Length++;
			}
		}
	}
}

Matrix::Matrix(const Matrix &matrixToCopy) // copy constructor
{
	int r = matrixToCopy.getRow();
	int c = matrixToCopy.getRow();

	setUp(r, c);

	data = new double*[r];
	for (int i = 0; i < r; i++) {
		data[i] = new double[c]{ 0 };
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			data[i][j] = matrixToCopy.getData(i + 1, j + 1);
		}
	}
}

Matrix::~Matrix() 	// destructor, �M�zdata
{
	delete[] data;
}

void Matrix::setData(int r, int c, double value)	// �]�w��(r,c)��mdata����
{
	data[r-1][c-1] = value;
}

int Matrix::getRow() const		// �^��private member: row
{
	return row;
}

int Matrix::getCol() const		// �^��private member: col
{
	return col;
}

double Matrix::getData(int r, int c) const	// ����x�}(r,c)��m����
{
	return data[r - 1][c - 1];
}

Matrix Matrix::add(const Matrix &matrixToAdd)	// �x�}�ۥ[, �^�Ǭۥ[�᪺�x�}
{
	if (getRow() != matrixToAdd.getRow() || getCol() != matrixToAdd.getCol()) {
		cout << "The size of the two matrixes are different. You can't add them together." << endl;
		exit(1);
	}

	Matrix ans(row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.setData(i + 1, j + 1, data[i][j] + matrixToAdd.getData(i + 1, j + 1));
		}
	}
	return ans;
}

Matrix Matrix::multiply(const Matrix & matrixToMult)	// �x�}�ۭ�, �^�Ǭۭ��ᤧ�x�}
{
	if (getCol() != matrixToMult.getRow()) {
		cout << "The two matrixs cannot multiply because their sizes don't match." << endl;
		exit(1);
	}

	const int answerRow = getRow();
	const int answerCol = matrixToMult.getCol();

	double *ans = new double[answerRow*answerCol]{ 0 }; //�@��array��������

	Matrix ansM(answerRow,answerCol);

	int counter = 0;
	int temp = 0;

	for (int i = 0; i < getRow(); i++) {
		for (int k = 0; k < matrixToMult.getCol(); k++) {
			for (int j = 0; j < getCol(); j++) {
				temp += getData(i + 1, j + 1) * matrixToMult.getData(j + 1, k + 1);
			}
			ansM.setData(i + 1, k + 1, temp);
			counter++;
			temp = 0;
		}
	}
	return ansM;
}

Matrix Matrix::transpose()		// �x�}��m, �^����m�᪺�x�}
{
	Matrix ans(row,col);

	for (int i = 0; i < getRow(); i++) {
		for (int j = 0; j < getCol(); j++) {
			ans.data[j][i] = data[i][j];
		}
	}

	return ans;
}