#include <iostream>
using namespace std;
//----------------------------------------------------------------
class Shape{
public:
    Shape(float height, float width):h(height), w(width){};
    virtual float area()const = 0;
protected:
    float h;
    float w;
};
class Rectangle: public Shape{
public:
    Rectangle(float height, float width):Shape(height, width){}
    float area() const
    {
        return h * w;
    }
};
class IsoscelesTriangle: public Shape{
public:
    IsoscelesTriangle(float height, float width):Shape(height, width){}
    float area() const 
    {
        return (h * w) / 2;
    }
};
//----------------------------------------------------------------
int main()
{
 const Shape *myShape = new Rectangle(5, 3);

 cout << myShape->area() << '\n'; // 15
 delete myShape;
 myShape = new IsoscelesTriangle(5, 3);
 cout << myShape->area() << '\n'; // 7.5
 delete myShape;
 myShape = nullptr;

 Rectangle herShape(6, 8);
 IsoscelesTriangle hisShape(5, 4);
 const Shape &yourShape = herShape;

 cout << yourShape.area() << '\n'; // 48

 const Shape &theirShape = hisShape;
 cout << theirShape.area() << '\n'; // 10
}
