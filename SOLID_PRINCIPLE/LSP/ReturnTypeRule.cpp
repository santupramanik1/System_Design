#include <iostream>
#include <string>
using namespace std;

class Animal
{
};
class Dog : public Animal
{
};

class Parent
{
public:
    virtual Animal *getAnimal()
    {
        cout << "Parent : Returning Animal instance" << endl;
        return new Animal();
    }
};
class Child : public Parent
{
    //  Can also have return type as Dog
    virtual Animal *getAnimal() override
    {
        cout << "Child : Returning Dog instance" << std::endl;
        return new Dog();
    }
};

class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }

    void takeAnimal()
    {
        p->getAnimal();
    }
};

// main function
int main()
{
    Parent *parent = new Parent();
    Child *child = new Child();

    Client *client = new Client(parent);
    client->takeAnimal();

    return 0;
}