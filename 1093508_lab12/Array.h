// Fig. 11.6: Array.h
// Array class for storing arrays of integers.
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Array
{
    template <typename U> friend ostream &operator<<( ostream&, const Array<U> & );
    template <typename U> friend istream &operator>>( istream&, Array<U> & );

public:
    Array(int = 10);                       // default constructor
    Array(const Array &);                  // copy constructor
    ~Array();                              // destructor
    int getSize() const;                   // return size
    const Array &operator=(const Array &); // assignment operator
    bool operator==(const Array &) const;  // equality operator
    // inequality operator; returns opposite of == operator
    bool operator!=(const Array &right) const
    {
        return !(*this == right); // invokes Array::operator==
    }                             // end function operator!=
    // subscript operator for non-const objects returns modifiable lvalue
    T &operator[](int);
    // subscript operator for const objects returns rvalue
    T operator[](int) const;

    void swap(int , int);

private:
    int size; // pointer-based array size
    T *ptr; // pointer to first element of pointer-based array
};            // end class Array
#endif