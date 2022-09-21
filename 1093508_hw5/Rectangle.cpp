#include "Rectangle.h"
Rectangle::Rectangle(int x, int y):Shape(x,y){}
float Rectangle::area() const
{
    return x*y;
}