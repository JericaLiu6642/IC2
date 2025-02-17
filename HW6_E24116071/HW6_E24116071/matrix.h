#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
	friend ostream & operator<<(ostream &, Matrix &);
	friend istream & operator>>(istream &, Matrix &);

private:
	double **data;		  // store all the values according to number of rows and columes
	int row;			  // number of rows
	int col;			  // number of columns
	static int count;	  // store number of matrix objects
	void setUp(int, int); // set up number of rows and columes
public:
	const Matrix & operator= (const Matrix &);
	Matrix operator+ (const Matrix &);
	Matrix operator+ (double);
	Matrix operator+= (const Matrix &);
	Matrix operator++ (int);
	Matrix operator* (const Matrix &);
	Matrix operator() ();
	bool operator== (const Matrix &) const;


	Matrix();						 //  default constructor, build a 2*2 matrix with all values 0
	Matrix(int, int);				 // set up number of rows and columes with all values 0
	Matrix(int, int, double[], int); // convert the array into a matrix according to number of rows and columns
	Matrix(const Matrix &);			 // copy constructor
	~Matrix();						 // destructor

	void setData(int, int, double); // set up the value at the position, (row, col)

	int getRow() const;				// get the number of rows
	int getCol() const;				// get the number of columns
	double getData(int, int) const; // get the value at the position, (row, col)
	static int getCount();			// get the number of objects now

	void displayData()
	{ // display data
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << "" << endl;
		}
	}
};

#endif
