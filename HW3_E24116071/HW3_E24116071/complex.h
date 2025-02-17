//HW3_E24116071

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex(double, double); //constructor
	Complex add(Complex);
	Complex multiply(Complex);
	Complex divide(Complex);
	Complex conjugate();
	void print();

private:
	double real;
	double imag;
};

#endif
