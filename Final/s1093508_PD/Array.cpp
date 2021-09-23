// Fig 11.7: Array.cpp
// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include <stdexcept>
#include "Array.h" // Array class definition
using namespace std;

template <typename T>
Array<T>::Array(int cols, int rows)
{
	colsize = cols;
	rowsize = rows;
	ptr = new T[colsize * rowsize + 1];
	// size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
	// ptr = new int[ size ]; // create space for pointer-based array

	// for ( int i = 0; i < size; i++ )
	//    ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
template <typename T>
Array<T>::Array(const Array &arrayToCopy)
	: colsize(arrayToCopy.colsize), rowsize(arrayToCopy.rowsize)
{
	ptr = new T[colsize * rowsize + 1]; // create space for pointer-based array

	for (int i = 0; i < colsize*rowsize; i++)
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
template <typename T>
Array<T>::~Array()
{
	delete[] ptr; // release pointer-based array space
} // end destructor
template <typename T>
T &Array<T>::operator()(int cols, int rows)
{
	
	if(cols < 0 || cols >= colsize)
		throw "ERROR:row subscript out of range.\n";
	else if(rows < 0 || rows >= rowsize)
		throw "ERROR:colum subscript out of range.\n";
	return ptr[cols*rowsize+rows];

}
// template <typename T>
// const T &Array<T>::operator()(int cols, int rows)
// {
// 	return ptr[(colsize*rows)+cols];
// }



// return number of elements of Array
// template<typename T>
// int Array<T>::getSize() const
// {
//    return size; // number of elements in Array
// } // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3

template <typename T>
const Array<T> &Array<T>::operator=(const Array &right)
{
	if (&right != this) // avoid self-assignment
	{
		// for Arrays of different sizes, deallocate original
		// left-side array, then allocate new left-side array
		if (rowsize != right.rowsize||colsize != right.colsize)
		{
			delete[] ptr;		 // release space
			colsize = right.colsize;	 // resize this object
			rowsize = right.rowsize;
			ptr = new int[colsize*rowsize+1]; // create space for array copy
		}						 // end inner if

		for (int i = 0; i < colsize * rowsize; i++)
			ptr[i] = right.ptr[i]; // copy array into object
	}							   // end outer if

	return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
template <typename T>
bool Array<T>::operator==(const Array &right) const
{
	if (colsize != right.colsize||rowsize != right.rowsize)
		return false; // arrays of different number of elements

	for(int i = 0; i < rowsize; i++)
		for (int j = 0; j < colsize; j++)
			if (ptr[i*j] != right.ptr[i*j])
				return false; // Array contents are not equal

	return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template <typename T>
T &Array<T>::operator[]( int subscript )
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= colsize*rowsize )
   {
      cerr << "\nError: Subscript " << subscript
         << " out of range" << endl;
      exit( 1 ); // terminate program; subscript out of range
   } // end if

   return ptr[ subscript ]; // reference return
} // end function operator[]

// // overloaded subscript operator for const Arrays
// // const reference return creates an rvalue
template <typename T>
T Array<T>::operator[]( int subscript ) const
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= colsize*rowsize )
   {
      cerr << "\nError: Subscript " << subscript
         << " out of range" << endl;
      exit( 1 ); // terminate program; subscript out of range
   } // end if

   return ptr[ subscript ]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
template <typename T>
istream &operator>>(istream &input, Array<T> &a)
{
	for (int i = 0; i < a.colsize*a.rowsize; i++)
		input >> a.ptr[i];

	return input; // enables cin >> x >> y;
} // end function

// overloaded output operator for class Array
template <typename T>
ostream &operator<<(ostream &output, const Array<T> &a)
{
	int i;
	
	for( i = 0; i < a.colsize * a.rowsize; i++)
	{
		output << a.ptr[i] << " ";
		if((i+1)%a.rowsize == 0)
		{
			output << endl;
		}
	}
	output << endl;
	return output; // enables cout << x << y;
	// int i;

	// // output private ptr-based array
	// for (i = 0; i < a.size; i++)
	// {
	// 	output << setw(12) << a.ptr[i];

	// 	if ((i + 1) % 4 == 0) // 4 numbers per row of output
	// 		output << endl;
	// } // end for

	// if (i % 4 != 0) // end last line of output
	// 	output << endl;

	
} // end function operator<<