#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex{
    private:
    float num1;
    float num2;
    public:
    Complex(float, float);
    Complex(float);
    ~Complex();
    Complex &add(Complex);
    Complex &multiply(Complex);
    void print() const;
};
#endif