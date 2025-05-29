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
        return instance;
    }
};

// Intialization static variable
Singleton *Singleton::instance = new Singleton();
// main method
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
    return 0;
}