#include <iostream>
#include <string>
using namespace std;

// Component Interface: defines a common interface for Mario and all power-up decorators.
class Character
{
public:
    virtual string getAbilities() = 0;
    virtual ~Character() {}
};

// Concrete Component: Basic Mario character with no power-ups.
class Mario : public Character
{
public:
    string getAbilities() override
    {
        return "Mario";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Charatcer and "has-a" Character.
class CharacterDecorator : public Character
{
protected:
    Character *character; // wrapped component

public:
    CharacterDecorator(Character *c)
    {
        this->character = c;
    }
};

// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator
{
public:
    // constructor
    HeightUp(Character *c) : CharacterDecorator(c) {}
    string getAbilities() override
    {
        return character->getAbilities() + " with HeightUp";
    }
};

// Concrete Decorator: Gun Shooting Power-Up.
class GunPowerUp : public CharacterDecorator
{
public:
    // constructor
    GunPowerUp(Character *c) : CharacterDecorator(c) {}
    string getAbilities() override
    {
        return character->getAbilities() + " with GunPowerUp";
    }
};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator
{
public:
    StarPowerUp(Character *c) : CharacterDecorator(c) {}

    string getAbilities() override
    {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }

    ~StarPowerUp()
    {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

// main methdo
int main()
{
    // Create a basic Mario character.
    Character *mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // Decorate Mario with a HeightUp power-up.
    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    // Decorate Mario further with a GunPowerUp.
    mario = new GunPowerUp(mario);
    cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    // Finally, add a StarPowerUp decoration.
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    return 0;
}
