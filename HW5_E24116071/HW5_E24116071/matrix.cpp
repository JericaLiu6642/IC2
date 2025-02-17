//HW5_E24116071
#include <iostream>
#include "matrix.h"

using namespace std;

void Matrix::setUp(int a, int b)	// utility function, 設定row和col的值
{
	row = a;
	col = b;
}


Matrix::Matrix() // default constructor, 什麼都不傳, 將data存入2*2都是0的值
{
	setUp(2, 2);
	data = new double*[2];
	for (int i = 0; i < 2; i++) {
		data[i] = new double[2]{ 0 };
	}
}

Matrix::Matrix(int a, int b) // constructor, 只設定大小, 資料預設為0
{
	setUp(a, b);
	data = new double*[a];
	for (int i = 0; i < a; i++) {
		data[i] = new double[b] {0};
	}
}

Matrix::Matrix(int a, int b, double c[], int d) // constructor, 將傳入的一維陣列轉存為二維陣列放入data中
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

Matrix::~Matrix() 	// destructor, 清理data
{
	delete[] data;
}

void Matrix::setData(int r, int c, double value)	// 設定第(r,c)位置data的值
{
	data[r-1][c-1] = value;
}

int Matrix::getRow() const		// 回傳private member: row
{
	return row;
}

int Matrix::getCol() const		// 回傳private member: col
{
	return col;
}

double Matrix::getData(int r, int c) const	// 拿到矩陣(r,c)位置的值
{
	return data[r - 1][c - 1];
}

Matrix Matrix::add(const Matrix &matrixToAdd)	// 矩陣相加, 回傳相加後的矩陣
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

Matrix Matrix::multiply(const Matrix & matrixToMult)	// 矩陣相乘, 回傳相乘後之矩陣
{
	if (getCol() != matrixToMult.getRow()) {
		cout << "The two matrixs cannot multiply because their sizes don't match." << endl;
		exit(1);
	}

	const int answerRow = getRow();
	const int answerCol = matrixToMult.getCol();

	double *ans = new double[answerRow*answerCol]{ 0 }; //一維array紀錄答案

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

Matrix Matrix::transpose()		// 矩陣轉置, 回傳轉置後的矩陣
{
	Matrix ans(row,col);

	for (int i = 0; i < getRow(); i++) {
		for (int j = 0; j < getCol(); j++) {
			ans.data[j][i] = data[i][j];
		}
	}

	return ans;
}