// Fig. 11.6: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Array
{
   template <typename U>friend ostream &operator<<( ostream &, const Array<U>& );
   template <typename U>friend istream &operator>>( istream &, Array<U> & );
public:
   Array( int = 3 ,int = 3); // default constructor
   Array( const Array & ); // copy constructor
   ~Array(); // destructor
   //int getSize() const; // return size
   
   T &operator()(int, int);
   //const T &operator()(int, int);
 
   const Array &operator=( const Array & ); // assignment operator
   bool operator==( const Array & ) const; // equality operator
   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   T &operator[]( int );              

   // subscript operator for const objects returns rvalue
   T operator[]( int ) const;  
private:
   int colsize; // pointer-based array size
   int rowsize;
   T *ptr;
}; // end class Array

#endif

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
