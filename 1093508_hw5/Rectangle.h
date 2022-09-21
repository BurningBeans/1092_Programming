#pragma once
#include "Shape.h"
class Rectangle : public Shape{
public:
    Rectangle(int, int);
    ~Rectangle(){};
    float area()const;
};