#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>
using namespace std;
class Hugeint
{
    friend Hugeint operator+(int ,const Hugeint &);
    friend Hugeint operator+(const string &, const Hugeint &);
    friend bool operator>=(int , const Hugeint &);
    friend bool operator>=(const string &, const Hugeint &);

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
    //----------------------------------------------------------------
    Hugeint &operator++(); // prefix increment operator
    Hugeint operator++(int); // postfix increment operator
    bool operator>=(const Hugeint &);
    bool operator>=(int);
    bool operator>=(const string &);
    //----------------------------------------------------------------
    private:
    short interger[digits];
};
#endif