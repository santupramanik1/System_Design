#include <iostream>
#include <string>
using namespace std;

// Abstract class :Coffee
class Coffee
{
public:
    virtual int getCost() = 0;
    virtual string getDescription() = 0;
};

// Concrete class for Coffee
class SimpleCoffee : public Coffee
{
private:
    int cost;
    string name;

public:
    // constructor
    SimpleCoffee(int cost, string name)
    {
        this->cost = cost;
        this->name = name;
    }
    int getCost()
    {
        return cost;
    }

    string getDescription()
    {
        return name;
    }
};

// Abstract class :Decorator class
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *c;

public:
    // constructor
    CoffeeDecorator(Coffee *c)
    {
        this->c = c;
    }
};

// concrete class for decorator class
class Milk : public CoffeeDecorator
{
public:
    // constructor
    Milk(Coffee *c) : CoffeeDecorator(c) {}
    int getCost()
    {
        return c->getCost() + 6;
    }

    string getDescription()
    {
        return c->getDescription() + " Milk";
    }
};

class Sugar : public CoffeeDecorator
{
public:
    // constructor
    Sugar(Coffee *c) : CoffeeDecorator(c) {}
    int getCost()
    {
        return c->getCost() + 2;
    }

    string getDescription()
    {
        return c->getDescription() + " Sugar";
    }
};

// main method
int main()
{
    Coffee *coffee = new SimpleCoffee(5, "Simple Coffee");
    // Simple Coffee
    cout << coffee->getDescription() << " :" << coffee->getCost() << endl;

    // Simple coffee with milk
    coffee = new Milk(coffee);
    cout << coffee->getDescription() << " :" << coffee->getCost() << endl;

    // Simple coffee with milk ,sugar
    coffee = new Sugar(coffee);
    cout << coffee->getDescription() << " :" << coffee->getCost() << endl;

    // Simple coffee with milk ,sugar,milk
    coffee = new Milk(coffee);
    cout << coffee->getDescription() << " :" << coffee->getCost() << endl;
    return 0;
}