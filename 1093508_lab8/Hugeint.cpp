#include <cctype>
#include "Hugeint.h"
//default constructor: converstion constructor that converts a long interger into a Hugeint object
Hugeint::Hugeint(long value)
{
    //initialize array to zero
    for(int i = 0; i < digits; i++)
        interger[i] = 0;
    //place digits of argument into array
    for(int i = digits - 1; value!= 0 && i >= 0; i--)
    {
        interger[i] = value%10;
        value /= 10;
    }
}
//conversion constructor that converts a char string representing a large interger into Hugeint
Hugeint::Hugeint(const string &number)
{
    //initialize array to zero
    for(int i = 0; i < digits; i++)
        interger[i] = 0;
    for(int i = digits - number.size(), j = 0 ; i < digits; i++, j++)
        if(isdigit(number[j]))
            interger[i] = number[j] - '0';
}
//addition operator: Hugeint + Hugeint
Hugeint Hugeint::operator+(const Hugeint &op2) const 
{
    Hugeint result;
    int carry = 0;
    for(int i = digits - 1; i >=0 ; i--)
    {
        result.interger[i] = interger[i] + op2.interger[i] + carry;
        //determin whether to carry or not
        if(result.interger[i] > 9)
        {
            result.interger[i] %= 10; //reduce to 0-9
            carry = 1;
        }
        else
            carry = 0;
    }
    return result;
}
Hugeint Hugeint::operator+(int op2) const
{
    //convert op2 to Hugeint than invoke operator + for two Hugeint object
    return *this+Hugeint(op2);
}
Hugeint Hugeint::operator+(const string &op2) const
{
    //convert op2 to Hugeint than invoke operator + for two Hugeint object
    return *this+Hugeint(op2);
}
//overloaded output operator
ostream &operator<<( ostream &output, const Hugeint &num)
{
    int i;
    for( i = 0; (num.interger[i]==0) && (i <= Hugeint::digits); i++);
    //skip leading zeros
    if(i == Hugeint::digits)
        output << 0;
    else
        for(;i < Hugeint::digits; i++)
            output << num.interger[i];
    return output;
}
//----------------------------------------------------------------
//friend function
Hugeint operator+(int num ,const Hugeint &op2)
{
    return op2+num;
}
Hugeint operator+(const string & str, const Hugeint & op2)
{
    return op2+str;
}
bool operator>=(int num, const Hugeint &op2)
{
    Hugeint temp(num);
    if(temp >= op2)
        return true;
    else
        return false;
}
bool operator>=(const string &str, const Hugeint &op2)
{
    Hugeint temp(str);
    if(temp >= op2)
        return true;
    else
        return false;
}
//----------------------------------------------------------------
//member function
Hugeint &Hugeint::operator++() // prefix increment operator
{
    *this = *this+Hugeint(1);
    return *this;
}
Hugeint Hugeint::operator++( int ) // postfix increment operator
{
    Hugeint temp = *this;
    *this = *this+Hugeint(1);
    return temp;
}
bool Hugeint::operator>=(const Hugeint &op2)
{
    bool ret = true;
    for(int i = 0; i < digits; i++)
    {
        if(interger[i] != op2.interger[i])
        {
            ret = false;
            break;
        }
    }
    if(ret)
        return true;
    for(int i = 0; i < digits; i++)
    {
        if(interger[i] > op2.interger[i])
            return true;
        else if(op2.interger[i] > interger[i])
            return false;
    }
    return false;
}
bool Hugeint::operator>=(int num)
{
    Hugeint temp(num);
    if(*this >= temp)
        return true;
    else
        return false;
}
bool Hugeint::operator>=(const string &str)
{
    Hugeint temp(str);
    if(*this >= temp)
        return true;
    else
        return false;
}
//----------------------------------------------------------------