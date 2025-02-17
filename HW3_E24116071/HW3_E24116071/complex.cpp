//HW3_E24116071
#include <iostream>
#include <iomanip>
#include "complex.h"

using namespace std;

Complex::Complex(double a, double b)
{
	real = a;
	imag = b;
}

Complex Complex::add(Complex num)
{
	Complex ans = Complex(0,0); //先設定答案為0
	ans.real = real + num.real;
	ans.imag = imag + num.imag;
	return ans;
}

Complex Complex::multiply(Complex num)
{
	Complex ans = Complex(0, 0);
	ans.real = real * num.real - imag * num.imag;
	ans.imag = imag * num.real + real * num.imag;
	return ans;
}

Complex Complex::divide(Complex num)
{
	Complex ans = Complex(0, 0);
	ans.real = (real*num.real + imag * num.imag) / (num.real*num.real + num.imag*num.imag);
	ans.imag = (-real*num.imag + imag*num.real)/ (num.real*num.real + num.imag*num.imag);
	return ans;
}

Complex Complex::conjugate()
{
	Complex ans = Complex(0, 0);
	ans.real = real;
	ans.imag = imag * (-1);
	return ans;
}

void Complex::print()
{
	if (imag >= 0) {
		cout << real << "+" << imag << "i" << endl;
	}
	else {
		cout << real << imag << "i" << endl;
	}
}
