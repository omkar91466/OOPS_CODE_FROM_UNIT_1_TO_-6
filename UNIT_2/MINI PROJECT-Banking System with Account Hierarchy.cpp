#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: Rs. " << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    virtual double calculateInterest() const = 0;

    virtual void display() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest() const override
    {
        return balance * 0.04;
    }

    void display() const override
    {
        cout << "\n--- Savings Account ---" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest() const override
    {
        return 0;
    }

    void display() const override
    {
        cout << "\n--- Current Account ---" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class FixedDepositAccount : public Account
{
public:
    FixedDepositAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest() const override
    {
        return balance * 0.07;
    }

    void display() const override
    {
        cout << "\n--- Fixed Deposit Account ---" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

int main()
{
    SavingsAccount savings(101, "Amit", 50000);
    CurrentAccount current(102, "Sneha", 75000);
    FixedDepositAccount fixedDeposit(103, "Rohan", 100000);

    cout << "===== BANKING SYSTEM =====" << endl;

    savings.deposit(5000);
    savings.withdraw(2000);

    current.deposit(10000);
    current.withdraw(5000);

    fixedDeposit.deposit(20000);

    savings.display();
    current.display();
    fixedDeposit.display();

    return 0;
}