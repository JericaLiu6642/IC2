#include "matrix.h"

#include<iostream>
using namespace std;

int main()
{
	Matrix m1;

	double d[9] = { 1,2,3,4,5,6,7,8,9 };

	Matrix m2(3, 3, d, 9);
	Matrix m3(m2);

	cout << "Matrix m1 is : " << endl;
	m1.displayData();
	cout << endl;
	cout << "Matrix m2 is : \n" << m2 << endl;
	cout << "Matrix m3 is : \n" << m3 << endl;

	if (m2 == m3)
		cout << "m2 and m3 are the same.\n" << endl;
	else
		cout << "m2 and m3 are different. \n" << endl;

	m3.setData(1, 1, 99);
	cout << "m3 after setup is : \n" << m3 << endl;
	if (m2 == m3)
		cout << "m2 and m3 are the same. \n" << endl;
	else
		cout << "m2 and m3 are different. \n" << endl;

	Matrix m4(3, 3);
	cout << "Please enter 9 doubles for matrix m4:" << endl;
	cin >> m4;
	cout << "Matrix m4 is : \n" << m4 << endl;

	Matrix m5 = m2 + m3;
	cout << "m2+m3 is : \n" << m5 << endl;
	m5 = m2 + 3;
	cout << "m2 + 3 is : \n" << m5 << endl;
	m5 += m2;
	cout << "m2 + m2 + 3 is : \n" << m5 << endl;
	m5++;
	cout << "m2 + m2 + 4 is : \n" << m5 << endl;
	m5 = m2 * m3;
	cout << "m2 * m3 is : \n" << m5 << endl;
	m5 = m4();
	cout << "transpose of m4 is : \n" << m5 << endl;

	cout << "number of matrices now is : " << Matrix::getCount() << endl;

	system("pause");
	return 0;
}
