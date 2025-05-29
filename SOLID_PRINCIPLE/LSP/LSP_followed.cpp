#include <iostream>
#include <vector>
using namespace std;

// Abstract class
// Deposit only account
class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};

// Abstract class
// deposit as well as withdraw is possible
class WithdrwableAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

// Saving account
class SavingAccount : public WithdrwableAccount
{
private:
    double balance;

public:
    // constructor
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

// current account
class CurrentAccount : public WithdrwableAccount
{
private:
    double balance;

public:
    // constructor
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

// Fixed Deposit Account
class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    // constructor
    FixedTermAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }
};

// client
class BankClient
{
private:
    vector<WithdrwableAccount *> withdrwableAccounts;
    vector<DepositOnlyAccount *> depositOnlyAccounts;

    //  Constructor
public:
    BankClient(vector<WithdrwableAccount *> withdrwableAccounts,
               vector<DepositOnlyAccount *> depositOnlyAccounts)
    {
        this->withdrwableAccounts = withdrwableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransaction()
    {
        for(WithdrwableAccount *acc:withdrwableAccounts)
        {
          acc->deposit(1000);
          acc->withdraw(500);
        }

        for(DepositOnlyAccount *acc:depositOnlyAccounts)
        {
            acc->deposit(500);
        }
    }
};

int main()
{
    vector<WithdrwableAccount *> withdrwableAccounts;

    withdrwableAccounts.push_back(new SavingAccount());
    withdrwableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount *> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(withdrwableAccounts, depositOnlyAccounts);
    client->processTransaction();
    
    return 0;
}