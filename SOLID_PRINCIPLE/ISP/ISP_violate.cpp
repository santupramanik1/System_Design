#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// Square is a 2D shape but is forced to implement volume()
class Square : public Shape
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
    // Unnecessary method
    double volume() override
    {
        throw logic_error("Volume not applicable for Square");
    }
};

// Rectangle is also a 2D shape but is forced to implement volume()
class Rectangle : public Shape
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
    // Unnecessary method
    double volume() override
    {
        throw logic_error("Volume not applicable for Rectangle");
    }
};

// Cube is a 3D shape, so it actually has a volume
class Cube : public Shape
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

// main method
int main()
{

    Shape *square = new Square(6);
    Shape *rectangle = new Rectangle(4, 2);
    Shape *cube = new Cube(4);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try
    {
        cout << "Square Volume: " << square->volume() << endl;
    }
    catch (logic_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}