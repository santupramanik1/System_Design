
#include <iostream>
#include <string>
using namespace std;

class ManualCar
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    // This is a constructor that is used to intialized the variable the `this` keyword is used to to differentiate the class variable and the parameter variable
    ManualCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " :Engine start with a roar" << endl;
    }

    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void accelerate(int speed)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main()
{
    ManualCar *myManulaCar = new ManualCar("Ford", "Mustang");

    myManulaCar->startEngine();
    myManulaCar->shiftGear(1);
    myManulaCar->accelerate();
    myManulaCar->shiftGear(2);
    myManulaCar->accelerate(40);
    myManulaCar->brake();
    myManulaCar->stopEngine();

    delete myManulaCar;

    return 0;
}