#include "checks.h"
#include <iostream>
#include <conio.h>

using namespace std;

bool isValidName(const string& name) {

    if (name.empty()) return false;

    if (!isupper(name[0])) return false;

    for (size_t i = 1; i < name.size(); i++) {
        if (!islower(name[i])) return false;
    }

    return true;
    
}

bool isNumeric(const string& input) {

    for (char ch : input) {
        if (!isdigit(ch)) return false;
    }

    return true;

}

string getPassword() {

    string password;
    char ch;

    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
    }

    cout << endl;
    return password;

}