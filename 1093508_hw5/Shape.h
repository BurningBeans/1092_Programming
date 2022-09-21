#pragma once

class Shape{
public:
    Shape(int, int);
    virtual ~Shape(){};
    virtual float area()const = 0;
protected:
    int x;
    int y;
};