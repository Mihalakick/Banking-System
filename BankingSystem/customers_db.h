#ifndef CUSTOMERS_DB_H
#define CUSTOMERS_DB_H

#include <vector>
#include "customer.h"

using namespace std;

// external declaration of the list
extern vector<Customer> customersDB;

void addCustomer(const Customer& customer);
Customer* findCustomer(const string& firstName, const string& lastName, const string& iban);
bool removeCustomer(const string& firstName, const string& lastName, const string& iban);
void printCustomers();

void saveCustomers(const string& filename);
void loadCustomers(const string& filename);

#endif