#include <iostream>
using namespace std;

int main() {
    string name, id, password;

    // LOGIN PAGE
    cout << "Login Page\n";
    cout << "Name: ";
    getline(cin, name);

    while (true) {
        cout << "ID: ";
        getline(cin, id);

        // Check if ID is equal to 10 characters
        if (id.length() == 10) {
            break;
        } else {
            cout << "Invalid ID! Please make sure you enter the correct ID.\n";
        }
    }

    cout << "Password: ";
    getline(cin, password);

    // Check both ID and password
    if (id == "correctID" || password == "123456") {
        cout << "Login Successful! Welcome, " << name << ".\n";
    } else {
        cout << "Incorrect ID or Password. Please try again.\n";
        exit(0);
    }

    return 0;
}

