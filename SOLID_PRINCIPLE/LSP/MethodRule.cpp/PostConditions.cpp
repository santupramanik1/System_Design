#include <iostream>

using namespace std;

// A Postcondition must be statisfied after a method is executed.
// Sub classes can strengthen the Postcondition but cannot weaken it.

class Car
{
protected:
    int speed;

public:
    Car()
    {
        speed = 0;
    }

    void accelerate()
    {
        cout << "Accelerating" << endl;
        speed += 20;
    }

    // PostCondition : Speed must reduce after brake
    virtual void brake()
    {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car {
private:
    int charge;

public:

    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake
    // PostCondition : Charge must increase.
    void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;
    }
};

// main method
int main()
{
    Car *hybridCar=new HybridCar();
    hybridCar->brake();
    return 0;
}