#include "IsoscelesTriangle.h"
IsoscelesTriangle::IsoscelesTriangle(int x, int y):Shape(x, y){}
float IsoscelesTriangle::area() const
{
    return float(x*y)/2;
}