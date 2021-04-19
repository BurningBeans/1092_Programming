#include <iostream>
#include "Complex.h"
using namespace std;
Complex::Complex(float n1, float n2)
:num1(n1), 
num2(n2)
{}
Complex::Complex(float n1)
:num1(n1), 
num2(0)
{}
Complex::~Complex()
{}
Complex &Complex::add(Complex c)
{
    num1 += c.num1;
    num2 += c.num2;
    return *this;
}
Complex &Complex::multiply(Complex c)
{
    //(a+bi)×(c+di)=(ac−bd)+(bc+ad)i
    float n1 = num1*c.num1-num2*c.num2;
    float n2 = num2*c.num1+num1*c.num2;
    num1 = n1, num2 = n2;
    return *this;
}
void Complex::print() const
{
    cout << num1 << " + " << num2 << "i";
}

    