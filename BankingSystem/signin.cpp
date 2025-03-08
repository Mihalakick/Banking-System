#include "customer.h"
#include "customers_db.h"
#include "checks.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

string formatIban(int id) {
    ostringstream oss;
    oss << setw(5) << setfill('0') << id;
    return oss.str();
}

void signin() {
    
    string firstname;
    string lastname;
    string pass;
    string balanceString;
    
    cout << "Thank you for chosing our bank! Let's create your account!\n";
    
    do {
        cout << "Type your first name: ";
        getline(cin, firstname);
        if(isValidName(firstname)) break;
        cout << "Invalid name! Must start with an uppercase with no spaces, numbers, or special characters.\n";
    } while (!isValidName(firstname));

    do {
        cout << "Type your last name: ";
        getline(cin, lastname);
        if(isValidName(lastname)) break;
        cout << "Invalid lastname! Must start with an uppercase with no spaces, numbers, or special characters.\n";
    } while (!isValidName(lastname));

    do {
        cout << "Type the desired password: ";
        getline(cin, pass);
        if(pass.size() > 3) break;
        cout << "Invalid password! Must contain more than 3 characters\n";
    } while (pass.size() <= 3);

    do {
        cout << "Make your first deposit (type 0 in case you don't want to) : ";
        getline(cin, balanceString);
        if(isNumeric(balanceString)) break;
        cout << "Invalid input!\n";
    } while(!isNumeric(balanceString));

    double balance = stod(balanceString);

    int customers = customersDB.size();
    int intIban;
    if(customers == 0) intIban = 1;
    else intIban = customers + 1;
    bool done;
    string iban;

    do {
        done = true;
        iban = formatIban(intIban);
        for (auto it = customersDB.begin(); it != customersDB.end(); ++it) {
            if (it->getIban() == iban) {
                intIban++;
                done = false;
            }
        }
    } while (done == false);
    cout << iban << endl;
    Customer current_customer = Customer(firstname, lastname, pass, balance, iban);
    addCustomer(current_customer);
    cout << "Congratulations! Thank you for chosing Mihalakick's bank!\n";
    cout << "Your IBAN is " << current_customer.getIban() << endl;
    saveCustomers("customers_DB.txt");

}