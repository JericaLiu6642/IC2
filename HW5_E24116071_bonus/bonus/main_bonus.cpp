#include "matrix.h"
#include "complex.h"

#include<iostream>
using namespace std;

int main()
{
	Matrix m1;	
	Complex cs[9] ; // default constructor 建立 大小為9 的陣列 ，且每格皆放入1+2i
	Matrix m2(3, 3, cs, 9);
	Matrix m3(m2);

	cout << "\nMatrix m1 is : \n";
	m1.displayData();
	cout << "\nMatrix m2 is : \n";
	m2.displayData();
	cout << "\nMatrix m3 is : \n";
	m3.displayData();


	int r = 1, c = 3;
	Complex c1 = Complex(3, 4);
	m3.setData(r, c, c1);
	cout << "\n( " << r << "," << c << " ) of Matrix m3 is :  ";
	m3.getData(r, c).print();
	cout << "\nMatrix m3 after setup is : \n";
	m3.displayData();
	cout << "\ntranspose of Matrix m3 is :  \n";
	m3.transpose().displayData();


	Matrix m4(3, 3);
	cout << "\nrow of Matrix m4 is :  " << m4.getRow();
	cout << "\ncol of Matrix m4 is :  " << m4.getCol();


	cout << "\n\n m2 + m3 is : \n";
	m2.add(m3).displayData();

	cout << "\n m2 ˙ (m3)^T is : \n";
	m2.multiply(m3.transpose()).displayData();
	/*  矩陣乘法  (https://zh.wikipedia.org/wiki/%E7%9F%A9%E9%99%A3%E4%B9%98%E6%B3%95)
	矩陣乘法 範例 ：
	┌             ┐        ┌         ┐         ┌         ┐
	|   1   0   2   |        |   3   1   |         |   5   1   |
	|  -1   3   1   |   ˙   |   2   1   |     =   |   4   2   |
	└             ┘        |   1   0   |         └         ┘
	                         └         ┘
	*/

	system("pause");
	return 0;
}

