#include "customer.h"
#include "customers_db.h"
#include "checks.h"
#include <iostream>
#include <string>

using namespace std;

int app(Customer* user) {

    cout << "Hello Mr/Ms " << user->getLastName() << ". Choose your action.\n";
    
    while(1) {

        cout << "1.Deposit - 2.Withdraw - 3.Transfer - 4.Exit\n";
        int option;
        cin >> option;

        cin.clear();
        fflush(stdin);

        string input;
        double money;
        double newBalance;
        string first, last, iban;

        switch(option) {
            case 1:
                do {
                    cout << "Type the amount of money you wish to deposit: ";
                    getline(cin, input);
                    if(isNumeric(input) && stod(input) > 0) break;
                    cout << "Invalid input!\n";
                } while(!isNumeric(input) || stod(input) <= 0);
                money = stod(input);
                user->deposit(money);
                cout << "Done, $" << money << " has been added to your balance.\n";
                saveCustomers("customers_DB.txt");
                break;

            case 2:
                bool done;
                do {
                    cout << "Type the amount of money you wish to withdraw: ";
                    getline(cin, input);
                    if(isNumeric(input) && stod(input) > 0) break;
                    cout << "Invalid input!\n";
                } while(!isNumeric(input) || stod(input) <= 0);
                money = stod(input);
                done = user->withdraw(money);
                if(done) {
                    cout << "Done, $" << money << " has been withdrawn from your balance.\n";
                } else {
                    cout << "You don't have enough money in your balance.\n";
                }
                saveCustomers("customers_DB.txt");
                break;

            case 3:
                Customer* user2;
                do {
                    cout << "Type the first and last name along with the iban of the account you wish to tranfer money to.\n";
                    cin >> first >> last >> iban;
                    cin.clear();
                    fflush(stdin);
                    user2 = findCustomer(first, last, iban);
                    if (user2 == nullptr) {
                        done = false;
                        cout << "There is no such account, please try again.\n";
                    } else {
                        done = true;
                    }
                } while(!done);
                if (user == user2) {
                    cout << "You can't tranfer money to your account.\n";
                    break;
                }
                do {
                    cout << "Type the amount of money you wish to tranfer: ";
                    getline(cin, input);
                    if(isNumeric(input) && stod(input) > 0 && stod(input) <= user->getBalance()) break;
                    cout << "Invalid input or not enough money!\n";
                } while(!isNumeric(input) || stod(input) <= 0 || stod(input) > user->getBalance());
                money = stod(input);
                user->withdraw(money);
                user2->deposit(money);
                cout << "Done, you tranfered $" << money << " to Mr/Ms " << user2->getLastName() << ".\n";
                saveCustomers("customers_DB.txt");
                break;

            case 4:
                saveCustomers("customers_DB.txt");
                return 0;

            default: cout <<"Invalid action!\n";

        }

    }

}