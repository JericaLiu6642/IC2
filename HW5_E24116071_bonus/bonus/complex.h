#ifndef COMPLEX_H
#define COMPLEX_H
class  Complex   // a+bi
{
public:
	Complex();  // default constructor 存入 1+2i
	Complex(double, double);
	Complex add(Complex);
	Complex multiply(Complex);
	double getReal(); //取得private number real
	double getImag(); //取得private number imag
	void print(); // a+bi

private:
	double real; // a
	double imag; // b

}; 
#endif
