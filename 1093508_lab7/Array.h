#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
class Array{
    friend ostream &operator<<(ostream &, const Array & );
    friend istream &operator>>(istream &, Array & );
    friend Array operator>>(Array &, int &);
    public:
    Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size
    const Array &operator=(const Array & ); // assignment operator
    //----------------------------------------------------------------
    Array operator+(const Array &); // plus operator
    Array &operator-(); // minus operator

    //----------------------------------------------------------------
    bool operator==(const Array & ) const; // equality operator
    // inequality operator; returns opposite of operator
    bool operator!=(const Array &right ) const
    {
        return !(*this == right); // invokes Array::operator
    } // end function
    // subscript operator for non-const objects returns modifiable Ivalue
    int &operator[](int);
    // subscript operator for const objects retums rvalue
    int operator[](int) const;
    private:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-based array
}; // end class Array
#endif
                
