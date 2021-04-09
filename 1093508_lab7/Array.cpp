#include "Array.h"
#include <iomanip>
Array::Array(int arraysize)//default constructor
{
    size = (arraysize > 0 ? arraysize : 10);
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
}
Array::Array(const Array &copyarray)//copy constructor
:size(copyarray.size)
{
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = copyarray.ptr[i];
    }
}
Array::~Array()
{
    delete [] ptr;
}
int Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if(&right != this)
    {
        if(size != right.size)
        {
            delete [] ptr;
            size = right.size;
            ptr = new int[size];
        }
    }
    for(int i = 0; i < size; i++)
    {
        ptr[i] = right.ptr[i];
    }
    return *this;
}
//----------------------------------------------------------------

 Array Array::operator+(const Array &right)
{
    Array newarray(size+right.size);
    for(int i = 0; i < size; i++)
    {
        newarray.ptr[i] = ptr[i];
    }
    int counter = 0;
    for(int i = size; i < newarray.size; i++)
    {
        newarray.ptr[i] = right.ptr[counter];
        counter++;
    }
    return newarray;
}

Array &Array::operator-()
{
    for(int i = 0; i < size; i++)
    {
        ptr[i] = -ptr[i];
    }
    return *this;
}

Array operator>>(Array &a, int &input)
{
    int shift;
    input >> shift;
    shift %= a.size;
    for(int i = 0; i < shift; i++)
    {
        int temp = a.ptr[0];
        for(int j = 0; j < a.size; j++)
        {
            a.ptr[j] = a.ptr[j+1];
        }
        a.ptr[a.size] = temp;
    }
    return a;
}

//----------------------------------------------------------------
bool Array::operator==(const Array &right) const
{
    if(size != right.size)
        return false;//size is not equal
    for(int i = 0; i < size; i++)
    {
        if(ptr[i] != right.ptr[i])//if data is not equal
            return false;
    }
    return true;
}
int &Array::operator[](int subscript)//refrence return create a modifialbe lvalue
{
    if(subscript < 0 || subscript >= size)
    {
        cerr << "\n Error: Subscript " << subscript << " out of range\n";
        exit(1);
    }
    return ptr[subscript];
}
ostream &operator<<( ostream &output, const Array &a )
{
    int i;
    // output private ptr-based array
    for ( i = 0; i < a.size; i++ ) 
    {
        output << setw( 12 ) << a.ptr[ i ];
        if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
            output << endl;
    } // end for
    if ( i % 4 != 0 )  // end last line of output
        output << endl;
    return output;   // enables cout << x << y;
}
istream &operator>>( istream &input, Array &a )
{
    for ( int i = 0; i < a.size; i++ )
        input >> a.ptr[i];
    return input;   // enables cin >> x >> y;
}
