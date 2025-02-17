#ifndef COMPLEX_H
#define COMPLEX_H
class  Complex   // a+bi
{
public:
	Complex();  // default constructor �s�J 1+2i
	Complex(double, double);
	Complex add(Complex);
	Complex multiply(Complex);
	double getReal(); //���oprivate number real
	double getImag(); //���oprivate number imag
	void print(); // a+bi

private:
	double real; // a
	double imag; // b

}; 
#endif
