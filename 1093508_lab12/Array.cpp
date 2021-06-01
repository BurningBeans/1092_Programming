// Fig 11.7: Array.cpp
// Member-function definitions for class Array
#include <iostream>
#include <iomanip>
#include "Array.h" // Array class definition
using namespace std;
// default constructor for class Array (default size 10)
template<typename T>
Array<T>::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10); // validate arraySize
    ptr = new T[size];                     // create space for pointer-based array
    // for (int i = 0; i < size; i++)
    //     ptr[i] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
template<typename T>
Array<T>::Array(const Array &arrayToCopy)
    : size(arrayToCopy.size)
{
    ptr = new T[size]; // create space for pointer-based array
    for (int i = 0; i < size; i++)
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor
// destructor for class Array
template<typename T>
Array<T>::~Array()
{
    delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
template<typename T>
int Array<T>::getSize() const
{
    return size; // number of elements in Array
} // end function getSize
// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template<typename T>
const Array<T> &Array<T>::operator=(const Array &right)
{
    if (&right != this) // avoid self-assignment
    {
        // for Arrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if (size != right.size)
        {
            delete[] ptr;        // release space
            size = right.size;   // resize this object
            ptr = new T[size]; // create space for array copy
        }                        // end inner if
        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i]; // copy array into object
    }                              // end outer if
    return *this;                  // enables x = y = z, for example
} // end function operator=
// determine if two Arrays are equal and
// return true, otherwise return false
template<typename T>
bool Array<T>::operator==(const Array &right) const
{
    if (size != right.size)
        return false; // arrays of different number of elements

    for (int i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return false; // Array contents are not equal
    return true;          // Arrays are equal
} // end function operator==
// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template<typename T>
T &Array<T>::operator[](int subscript)
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
    {
        cerr << "Error : Subscript " << subscript
             << " out of range"
             << endl;
        exit(1);           // terminate program; subscript out of range
    }                      // end if
    return ptr[subscript]; // reference return
} // end function operator[]
// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template<typename T>
T Array<T>::operator[](int subscript) const
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
    {
        cerr << "Error : Subscript " << subscript
             << " out of range"
             << endl;
        exit(1); // terminate program; subscript out of range
    }            // end if

    return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
template <typename U>
istream &operator>>(istream &input, Array<U> &a)
{
    for (int i = 0; i < a.size; i++)
        input >> a.ptr[i];

    return input; // enables cin >> x >> y;
} // end function

// overloaded output operator for class Array
template <typename U>
ostream &operator<<(ostream &output, const Array<U> &a)
{
    int i;

    // output private ptr-based array
    for (i = 0; i < a.size; i++)
    {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0) // 4 numbers per row of output
            output << endl;
    } // end for

    if (i % 4 != 0) // end last line of output
        output << endl;

    return output; // enables cout << x << y;
} // end function operator<<


template <typename T>
void Array<T>::swap(int p1, int p2)
{
    if(p1 >= size)
    {
        cout << "** Error: swapping fails, subscript " << p1 << " is out of range.\n";
    }
    else if(p2 >= size)
    {
        cout << "** Error: swapping fails, subscript " << p2 << " is out of range.\n";
    }
    else
    {
        T tmp = ptr[p1];
        ptr[p1] = ptr[p2];
        ptr[p2] = tmp;
    }
}