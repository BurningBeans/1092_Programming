#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>
using namespace std;
class Hugeint
{
    friend ostream & operator<<(ostream &, const Hugeint &);
    public:
    static const int digits = 30;
    Hugeint(long = 0);
    Hugeint(const string &);
    //addition operator Hugeint + Hugeint
    Hugeint operator+(const Hugeint &) const;
    //addition operator Hugeint + int
    Hugeint operator+(int) const;
    //addition operator
    //Hugeint + string that represents large interger value
    Hugeint operator+(const string &) const;
    private:
    short interger[digits];
};
#endif