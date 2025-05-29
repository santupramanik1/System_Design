#include <iostream>
using namespace std;

// Separate Interface for 2D Shape
class TwoDimensionalShape
{
public:
    virtual double area() = 0;
};

// Separate Interface for 3D Shape
class ThreeDimensionalShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// Square implement only the 2D interface
class Square : public TwoDimensionalShape
{
private:
    double side;

public:
    // constructor
    Square(double s)
    {
        this->side = s;
    }

    double area() override
    {
        return side * side;
    }
};

//  Rectangle implement only the 2D interface
class Rectangle : public TwoDimensionalShape
{
private:
    double length, height;

public:
    // Constructor
    Rectangle(double l, double h)
    {
        this->length = l;
        this->height = h;
    }

    double area() override
    {
        return length * height;
    }
};

//  Cube implement only the 3D interface
class Cube : public ThreeDimensionalShape
{
private:
    double side;

public:
    // constructor
    Cube(double s)
    {
        this->side = s;
    }

    double area()
    {
        return 6 * side * side;
    }

    double volume()
    {
        return side * side * side;
    }
};

int main()
{
    TwoDimensionalShape *square=new Square(4);
    TwoDimensionalShape *rectangle=new Rectangle(2,3);

    ThreeDimensionalShape *cube=new Cube(5);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;
    return 0;
}