#include "customer.h"
#include <iostream>

Customer::Customer(string first, string last, string pass, double initialBalance, string iban)
    : firstName(first), lastName(last), password(pass), balance(initialBalance), iban(iban) {}

string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }
string Customer::getPassword() const { return password; }
double Customer::getBalance() const { return balance; }
string Customer::getIban() const { return iban; }

void Customer::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        cout << "Invalid amount of money" << endl;
    }
}

bool Customer::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        //cout << "Done" << endl;
        return true;
    } else {
        //cout << "Either the amout of money is invalid or your balance doesn't have the required amount of money" << endl;
        return false;
    }
}
