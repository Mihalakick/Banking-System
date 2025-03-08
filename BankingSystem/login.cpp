#include "customer.h"
#include "customers_db.h"
#include "checks.h"
#include <iostream>

using namespace std;

Customer* login() {
    
    string firstname;
    string lastname;
    string iban;
    string pass;

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
        cout << "Type your iban: ";
        getline(cin, iban);
        if(isNumeric(iban)) break;
        cout << "Invalid iban! Must contain numbers only\n";
    } while (!isNumeric(iban));

    Customer* user = findCustomer(firstname, lastname, iban);

    if (user == nullptr) {
        cout << "There is no such account, either the name or the iban was wrong.\n";
        return user;
    }

    do {
        cout << "Type your password: ";
        pass = getPassword();
        if (pass == user->getPassword()) break;
        cout << "The password was incorrect.\n";
    } while (pass != user->getPassword());

    return user;

}