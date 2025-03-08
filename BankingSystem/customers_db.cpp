#include "customers_db.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<Customer> customersDB;

void addCustomer(const Customer& customer) {
    customersDB.push_back(customer);
}

Customer* findCustomer(const string& firstName, const string& lastName, const string& iban) {
    for (auto& customer : customersDB) {
        if (customer.getFirstName() == firstName && customer.getLastName() == lastName && customer.getIban() == iban) {
            return &customer;
        }
    }
    return nullptr;
}

bool removeCustomer(const string& firstName, const string& lastName, const string& iban) {
    for (auto it = customersDB.begin(); it != customersDB.end(); ++it) {
        if (it->getFirstName() == firstName && it->getLastName() == lastName && it->getIban() == iban) {
            customersDB.erase(it);
            return true;
        }
    }
    return false;
}

void printCustomers() {
    if (customersDB.empty()) {
        cout << "No customers in database." << endl;
        return;
    }
    for (const auto& customer : customersDB) {
        cout << "Customer: " << customer.getFirstName() << " " 
                  << customer.getLastName() << " with IBAN " << customer.getIban() << " | Balance: $" 
                  << customer.getBalance() << endl;
    }
}

void saveCustomers(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& customer : customersDB) {
        outFile << customer.getFirstName() << " "
                << customer.getLastName() << " "
                << customer.getPassword() << " "
                << customer.getBalance() << " "
                << customer.getIban() << endl;
    }
    outFile.close();
}

void loadCustomers(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    
    customersDB.clear(); // διαγραφή παλαιών δεδομένων

    string first, last, pass, iban;
    double balance;
    while (inFile >> first >> last >> pass >> balance >> iban) {
        customersDB.push_back(Customer(first, last, pass, balance, iban));
    }
    inFile.close();
}