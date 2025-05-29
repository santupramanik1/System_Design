#include <iostream>
#include <string>
using namespace std;

// Burger Abstact class
class Burger
{
public:
    virtual void prepare() = 0; // pure virtual method
    virtual ~Burger() {}        // Destructor
};

// Concreate class of Burger
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

// BurgerFactory
class BurgerFactory
{
public:
    Burger *createBurger(string &type)
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            return nullptr;
        }
    }
};

// main method
int main()
{
    string type;
    cout << "Enter the types of Burger you want." << endl;
    cout << "1.Basic Burger(type-basic)\n 2.Standard Burger(type-standard) \n 3.Premium Burger(type-premium)" << endl;
    cin >> type;

    BurgerFactory *myBurgerFactory = new BurgerFactory();
    Burger *burger = myBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}