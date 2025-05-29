#include <iostream>
#include <string>
using namespace std;

// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.

class User
{
public:
    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password)
    {
        if (password.length() < 8)
        {
            return throw invalid_argument("Password must be at least 8 characters long");
        }
        cout << "Password set successfully" << endl;
    }
};

class AdminUser:public User{
    public:
      // Precondition: Password must be at least 6 characters
     void setPassword(string password) override
    {
        if (password.length() < 6)
        {
            return throw invalid_argument("Password must be at least 6 characters");
        }
        cout << "Password set successfully" << endl;
    }
};

//main method
int main()
{
    User *user=new AdminUser();
    user->setPassword("54yddh5");

    
    return 0;
}