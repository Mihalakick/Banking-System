#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
    string firstName;
    string lastName;
    string password;
    double balance;
    string iban;

public:

    Customer(string first, string last, string pass, double initialBalance, string iban);

    string getFirstName() const;
    string getLastName() const;
    string getPassword() const;
    double getBalance() const;
    string getIban() const;

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif
