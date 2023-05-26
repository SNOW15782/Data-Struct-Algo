#include <iostream>
#include <string>
using namespace std;

//BOOK STRUCTURE 
// TITLE, ISBN, ID, AVAILABLE (BOOL)
struct Book {
	string id;
	int isbn; 
	bool available; 
	string title; 
	//linked list 
	Book* next; 
	
};

//ROOM STRUCTURE 
//NAME, CAPACITY, AVAILABLE (BOOL)
struct Room{
	string name; 
	bool available; 
	int capacity; 
	//linked list 
	Room* next;
	
};



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
    if (id == "1211206128" || password == "123456") {
        cout << "Login Successful! Welcome, " << name << ".\n\n";
        system ("cls"); 
		string choice; 
		
		while (true){
			cout << "Hi "<< name<< " Welcome to do?\n";
			cout << "1. Book a Room\n";
			cout << "2. Rent a Book\n";
			cout << "3. Timetable\n";
			cout << "4. Exit\n"; 
			cout << "Enter your choice: "; 
			cin >> choice; 
			
			//IF ELSE SELECTION 
			if (choice == "1"){
				//FUNCTION BOOK A ROOM
			}
			else if (choice == "2"){
				//FUNCTION RENT A BOOK
			}
			else if (choice == "3"){
				//FUCNTION TIMETABLE 
			}
			else if (choice == "4"){
				cout << "Goodbye!"<<endl;
				break; 
			}
			else{
				cout << "Invalid choice. Please try again" <<endl;
			}
		} 
	
	} else {
        cout << "Incorrect ID or Password. Please try again.\n";
        exit(0);
    }

    return 0;
}
