#include<iostream>
#include"matrix.h"

using namespace std;

///static
int Matrix::count = 0;

int Matrix::getCount()
{
	return count;
}

///member functions
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
	count++;
}

Matrix::Matrix(int a, int b) // constructor, �u�]�w�j�p, ��ƹw�]��0
{
	setUp(a, b);
	data = new double*[a];
	for (int i = 0; i < a; i++) {
		data[i] = new double[b] {0};
	}
	count++;
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
		data[i] = new double[b] { 0 };
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
	count++;
}

Matrix::Matrix(const Matrix &matrixToCopy) // copy constructor
{
	int r = matrixToCopy.getRow();
	int c = matrixToCopy.getRow();

	setUp(r, c);

	data = new double*[r];
	for (int i = 0; i < r; i++) {
		data[i] = new double[c] { 0 };
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			data[i][j] = matrixToCopy.getData(i + 1, j + 1);
		}
	}
	count++;
}

Matrix::~Matrix() 	// destructor, �M�zdata
{
	delete[] data;
	count--;
}

void Matrix::setData(int r, int c, double value)	// �]�w��(r,c)��mdata����
{
	data[r - 1][c - 1] = value;
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

///operators
ostream & operator<<(ostream & output, Matrix & m)
{
	for (int i = 0; i < m.getRow(); i++) {
		for (int j = 0; j < m.getCol(); j++) {
			output << m.getData(i + 1, j + 1) << " ";
		}
		cout << endl;
	}
	return output;
}

istream & operator>>(istream & input, Matrix & m)
{
	m.setUp(3, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			input >> m.data[i][j];
		}
	}
	return input;
}

const Matrix & Matrix::operator= (const Matrix &m)
{
	if (&m != this) {
		if (getRow() != m.getRow() || getCol() != m.getCol()) { //�j�p���P �R�����]
			delete[] data;
			int r = m.getRow();
			int c = m.getRow();
			setUp(r, c);

			data = new double*[r];
			for (int i = 0; i < r; i++) {
				data[i] = new double[c] { 0 };
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					data[i][j] = m.getData(i + 1, j + 1);
				}
			}
		}
		else { // �j�p�ۦP �u����
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					data[i][j] = m.getData(i + 1, j + 1);
				}
			}
		}
	}
	return *this;
}

Matrix Matrix::operator+ (const Matrix & m)
{
	if (getRow() != m.getRow() || getCol() != m.getCol()) {
		cout << "The size of the two matrixes are different. You can't add them together." << endl;
		return *this;
	}

	Matrix ans(row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.setData(i + 1, j + 1, data[i][j] + m.getData(i + 1, j + 1));
		}
	}
	return ans;
}

Matrix Matrix::operator+ (double k)
{
	Matrix ans = *this;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.data[i][j] += k;
		}
	}
	return ans;
}

Matrix Matrix::operator+= (const Matrix & m)
{
	if (getRow() != m.getRow() || getCol() != m.getCol()) {
		cout << "The size of the two matrixes are different. You can't add them together." << endl;
		return *this;
	}

	*this = *this + m;
	return *this;
}

Matrix Matrix::operator++ (int)
{
	*this = *this + 1;
	return *this;
}

Matrix Matrix::operator* (const Matrix & m)
{
	if (getCol() != m.getRow()) {
		cout << "The two matrixs cannot multiply because their sizes don't match." << endl;
		return *this;
	}

	const int answerRow = getRow();
	const int answerCol = m.getCol();

	double *ans = new double[answerRow*answerCol]{ 0 }; //�@��array��������

	Matrix ansM(answerRow, answerCol);

	int counter = 0;
	int temp = 0;

	for (int i = 0; i < getRow(); i++) {
		for (int k = 0; k < m.getCol(); k++) {
			for (int j = 0; j < getCol(); j++) {
				temp += getData(i + 1, j + 1) * m.getData(j + 1, k + 1);
			}
			ansM.setData(i + 1, k + 1, temp);
			counter++;
			temp = 0;
		}
	}
	return ansM;
}

Matrix Matrix::operator() ()
{
	Matrix ans(row, col);

	for (int i = 0; i < getRow(); i++) {
		for (int j = 0; j < getCol(); j++) {
			ans.data[j][i] = data[i][j];
		}
	}

	return ans;
}

bool Matrix::operator== (const Matrix & m) const
{
	if (getRow() != m.getRow() || getCol() != m.getCol()) {
		return false;
	}

	for (int i = 0; i < getRow(); i++) {
		for (int j = 0; j < getCol(); j++) {
			if (data[i][j] != m.data[i][j]) {
				return false;
			}
		}
	}

	return true;
}