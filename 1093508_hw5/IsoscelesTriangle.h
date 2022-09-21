#pragma once
#include "Shape.h"
class IsoscelesTriangle: public Shape{
public:
    IsoscelesTriangle(int, int);
    ~IsoscelesTriangle(){};
    float area() const;
};