#include <iostream>
using namespace std;

// --- Strategy Interface for Talk ---
class TalkableRobot
{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {} // Destructor
};

// --- Concrete Strategies for Talk ---
class NormalTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Talking normally..." << endl;
    }
};
class NoTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Cannot talk." << endl;
    }
};

// --- Strategy Interface for Walk ---
class WalkableRobot
{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {} // Destructor
};

// --- Concrete Strategies for Walk ---
class NormalWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Walking normally..." << endl;
    }
};
class NoWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Cannot Walk..." << endl;
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot
{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Flying normally..." << endl;
    }
};

class NoFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Cannot fly." << endl;
    }
};

// --- Robot Base Class ---
class Robot
{
private:
    TalkableRobot *t;
    WalkableRobot *w;
    FlyableRobot *f;

public:
    // Constructor
    Robot(TalkableRobot *t, WalkableRobot *w, FlyableRobot *f)
    {
        this->t = t;
        this->w = w;
        this->f = f;
    }
    void talk()
    {
        t->talk();
    }

    void walk()
    {
        w->walk();
    }

    void fly()
    {
        f->fly();
    }
    virtual void projection() = 0; // Abstract method for subclasses
};

// --- Concrete Robot Types ---
class CompanionRobot : public Robot
{
public:
    CompanionRobot(TalkableRobot *t, WalkableRobot *w, FlyableRobot *f) : Robot(t, w, f) {}
    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WrokerRobot : public Robot
{
public:
    WrokerRobot(TalkableRobot *t, WalkableRobot *w, FlyableRobot *f) : Robot(t, w, f) {}
    void projection() override
    {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

// main method
int main()
{
    Robot *robot1 = new CompanionRobot(new NormalTalk(), new NormalWalk(), new NoFly());
    robot1->talk();
    robot1->walk();
    robot1->fly();
    robot1->projection();

    cout<<"----------------------"<<endl;
    Robot *robot2 = new CompanionRobot(new NormalTalk(), new NormalWalk(), new NoFly());
    robot2->talk();
    robot2->walk();
    robot2->fly();
    robot2->projection();
    return 0;
}