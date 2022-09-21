#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "IsoscelesTriangle.h"
using namespace std;
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
