#include "customer.h"
#include "customers_db.h"
#include <iostream>
#include <string>

using namespace std;

int admin() {
    
    cout << "Welcome Mr Mihalakick! Chose your actions: \n";
    string first, last, iban;
    bool done;
    
    while(1) {

        cout << "1.View customers - 2.Remove customer - 3.Find Customer - 4.Exit\n";

        int option;
        cin >> option;

        cin.clear();
        fflush(stdin);

        switch(option) {
            case 1:
                cout << endl;
                printCustomers();
                cout << endl;
                break;

            case 2:
                do {
                    cout << "Type the first and last name along with the IBAN of the account you wish to delete.\n";
                    cin >> first >> last >> iban;
                    cin.clear();
                    fflush(stdin);
                    Customer* customer = findCustomer(first, last, iban);
                    if (customer == nullptr) {
                        done = false;
                        cout << "There is no such account, please try again.\n";
                    } else {
                        removeCustomer(first, last, iban);
                        done = true;
                        cout << "The selected account has been deleted.\n";
                    }
                } while(!done);
                saveCustomers("customers_DB.txt");
                break;
            
            case 3:
                do {
                    cout << "Type the first and last name along with the IBAN of the account you wish to find.\n";
                    cin >> first >> last >> iban;
                    cin.clear();
                    fflush(stdin);
                    Customer* customer = findCustomer(first, last, iban);
                    if (customer == nullptr) {
                        done = false;
                        cout << "There is no such account, please try again.\n";
                    } else {
                        findCustomer(first, last, iban);
                        done = true;
                        cout << "The selected account has $" << customer->getBalance() << " in its balance.\n";
                    }
                } while(!done);
                break;

            case 4:
                return 0;

            default:cout << "Invalid action!\n";
        }
    }
}