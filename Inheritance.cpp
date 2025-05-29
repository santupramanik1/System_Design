#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currSpeed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currSpeed = 0;
    }

    // Common method for all Cars
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " :Engine start with a roar" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currSpeed << " km/h" << endl;
    }

    void brake()
    {
        currSpeed -= 20;
        if (currSpeed < 0)
            currSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currSpeed << " km/h" << endl;
    }

    virtual ~Car() {}
};

// Inherits from Car
class ManualCar : public Car
{
private:
    int currentGear = 0; // Specific to ManualCar
public:
    ManualCar(string b, string m) : Car(b, m)
    {
        currentGear = 0;
    }

    // Specialized method for ManualCar
    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
};

// Inherits from Car
class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m)
    {
        batteryLevel = 100;
    }

    // Specialized method for ElectricCar
    void chargeBattery()
    {
        batteryLevel = 100;
        cout << brand << " " << model << "Battery Full charged" << endl;
    }
};

int main()
{
    ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // specific to manual car
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "----------------------" << endl;

    ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); // specific to electric car
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    return 0;
}