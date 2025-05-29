#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    Singleton()
    {
        cout << "Singleton Constructor Called new object created" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

// Intialization static variable
Singleton *Singleton::instance = nullptr;
// main method
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
    return 0;
}