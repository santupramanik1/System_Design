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

   

    virtual void accelerate() = 0; // Abstract method for dynamic polymorphism
    virtual void brake() = 0;      // Abstract method for dynamic polymorphism
    virtual ~Car() {}              // virtual Destructor
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

    // Implement virtual method as its own style
    void accelerate()
    {
        cout << "Accelerate() method is implemented in ManualCar class" << endl;
    }

     void brake()
    {
        cout<<"brake() method is implemented in ManualCar class" << endl;
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
    // Implement virtual method as its own style
    void accelerate()
    {
        cout << "Accelerate() method is implemented in ElectricCar class" << endl;
    }

     void brake()
    {
        cout<<"brake() method is implemented in ElectricCar class" << endl;
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