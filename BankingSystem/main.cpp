#include <iostream>
#include "customer.h"
#include "customers_db.h"

using namespace std;

extern void signin();
extern Customer* login();
extern int admin();
extern int app(Customer* user);

int main() {

    loadCustomers("customers_DB.txt");
    cout << endl << "Welcome to Mihalakick's Bank\n";
    cout << "*******************************\n";
    bool state = true;
    Customer* user;
    while(state) {
        cout << "Type 1 to log-in or 2 to sign-in, in case you are new here. Else, type 3 to exit.\n";
        int option;
        cin >> option;

        cin.clear();
        fflush(stdin);

        switch(option) {
            case 1:
                user = login();
                if (user != nullptr) state = false;
                break;

            case 2:
                signin();
                break;
                
            case 3:
                saveCustomers("customers_DB.txt"); 
                return 0;

            case 1413914:
                admin();
                return 0;

            default:cout << "Invalid action!\n";
        }
    }

    app(user);

    return 0;

}