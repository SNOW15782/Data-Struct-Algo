#include <iostream>
#include <string>
#include <stack>
using namespace std;

//BOOK STRUCTURE 
// TITLE, ISBN, ID, AVAILABLE (BOOL), QUANTITY
struct Book {
	string id;
	string isbn; 
	string title; 
	bool available; 
	int quantity; 
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

//LINKED LIST FOR BOOK DATABASE 
class BookList{
	private: 
	Book* head;
	
	public: 
	BookList () : head(nullptr){}
	
	//SEARCH FOR BOOK BY ID (address of id, make it constant so it cannot be manipulate), STORE ID
	Book* searchBookByID (const string& id){
		Book* current = head;
		//SEARCHING ALGORITHM
		while (current != nullptr){
			if (current ->id == id){
				return current; 
			}
			//ELSE, RETURN NULLPTR
			current = current->next;
		}
		return nullptr;
	}
	//SEARCH FOR BOOK BY TITLE
	Book* searchBookByTitle(const string& title){
		Book* current = head;
		//SEARCHING ALGORITHM
		while (current != nullptr){
			if (current ->id == title){
				return current; 
			}
			//ELSE, RETURN NULLPTR
			current = current->next;
		}
			return nullptr;
	}
	
	//SEARCH FOR BOOK BY ISBN
	Book* searchBookByISBN(const string& isbn){
		Book* current = head;
		//SEARCHING ALGORITHM
		while (current != nullptr){
			if (current ->id == isbn){
				return current; 
			}
			//ELSE, RETURN NULLPTR
			current = current->next;
		}
			return nullptr;
	}
	
	//FUNCTION TO ADD A BOOK TO THE DATABASE, (REFER BOOK STRUCTURE), STORE ID, ISBN, TITLE, QUANTITY
	void addBook (const string& id, const string& isbn, const string title, int quantity){
	
	Book* newBook = new Book;
	newBook->id = id;
	newBook->isbn = isbn;
	newBook->title = title;
	
	//BOOL PART FOR BOOK STRUCT GOES HERE 
	newBook->available = true;
	newBook->quantity = quantity;
	newBook->next = nullptr;	
	
	
	//IF ELSE HERE 
	if (head == nullptr){
		head == newBook;
	}
	else{
		Book* current = head;
		while (current->next != nullptr){
			current = current ->next; 
		}
		current->next = newBook; 
	}
}
}; 
//FUNCTION TO RENT A BOOK 
/*void reserveBook (const string& id){
	Book* book = searchBookByID (id);

	if (book == nullptr){
		cout << "Book not found"<<endl;
		return;
	}
	
	if (!book->available){
		cout << "Book is not avaialble."<<endl;
		
		
		return; 
	}
	
	if (book->quantity > 0){
		cout << "Book Found"<< book->title <<endl; 
		cout << "Would you like to reserve this book? (Yes/No):";
		//declare string reservation
		string reservationOption; 
		cin >> reservationOption;
		
		if (reservationOption == "Yes"){
			string name; 
			cout << "Enter your name:";
			cin.ignore();
			getline (cin,name);
			
			//update the quantity section, if someone taken decrement by 1
			book->quantity--;
			
			cout << "Book reserved. Thanks you," << name << "!"<<endl;
			//add for code for handling immediate or later reservation 
		}
		
	}
	//ADD CODE FOR HANDLING NO OPTION 
	else{
		cout <<"Book is out of stock"<<endl;
		//Add code showing what book available 
	}
}*/

class MeetingRoomList{
	private: 
	Room*head; 
	
	public: 
	MeetingRoomList():head(nullptr){}
	
	//FUNCTION TO SEARCH FOR A ROOM BY NAME
	Room* searchRoomByName (const string& name){
		Room* current = head; 
		while (current!= nullptr){
			if (current->name == name){
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
//FUCNTION TO ADD A ROOM TO THE DATABASE (DANIEL PART) 
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
        //CREATE BOOK LIST AND ADD BOOKS FROM BOOKLIST CLASS 
        BookList BookList;
        
        //Create book list and add  books (ID, ISBN, TITLE, QUANTITY)
        BookList.addBook ("1","ISBN1 ", "Book 1", 5);
        BookList.addBook ("2","ISBN2 ", "Book 2", 4);
        BookList.addBook ("3","ISBN3 ", "Book 3", 3);
        BookList.addBook ("4","ISBN4 ", "Book 4", 3);
        BookList.addBook ("5","ISBN5 ", "Book 5", 2);
        
		//Create Meeting room list 
		MeetingRoomList roomList;
		// NAME OF THE ROOM, CAPACITY, LATER ADD
		
		
		string choice; 
		
		while (true){
			cout << "Hi "<< name<< " Welcome to do?\n";
			cout << "1. Book a Room\n";
			cout << "2. Rent a Book\n";
			cout << "3. Timetable\n";
			cout << "4. Exit\n"; 
			cout << "Enter your choice: "; 
			cin >> choice; 
			system ("cls");
			
			//IF ELSE SELECTION 
			if (choice == "1"){ 
				string roomChoice; 
				//FUNCTION BOOK A ROOM
			}
			else if (choice == "2"){
				//BOOK OPTIONS GOES HERE
				string bookChoice;
				cout << "What would you like to do?\n"; 
				cout << "1. Search for a Book by Title\n";
				cout << "2. Search for a Book by ISBN\n";
				cout << "3. Search for a Book by ID\n"; 
				cout << "4. Go back to the main menu\n";
				cout << "Enter your choice: "; 
				cin >> bookChoice; 
				
				//IF ELSE 
				//SEARCHING PART MIGHT NOT WORK ATM (LATER FIX) - ARIF
				if (bookChoice == "1"){
					string title; 
					cout << "Enter the title of the book: "; 
					cin.ignore();
					getline (cin, title); 
					
					//FUNCTION SEARCHING BOOK TITLE 
					Book* book = BookList.searchBookByTitle(title);
					if (book != nullptr){
						cout << "Book Found: "<<book->title <<endl; 
					}
					else{
						cout  << "Book not found" <<endl; 
					}
				}
				else if (bookChoice == "2"){
					string isbn;
					cout << "Enter the ISBN of the book: ";
					cin.ignore();
					getline(cin, isbn);
					
					Book* book = BookList.searchBookByISBN(isbn);
					if (book != nullptr){
						cout << "Book Found: "<<book->title <<endl; 
					}
					else{
						cout  << "Book not found" <<endl; 
					}
				}
				else if (bookChoice == "3"){
					string isbn;
					cout << "Enter the ID of the book: ";
					cin.ignore();
					getline(cin, id);
					
					Book* book = BookList.searchBookByID(id);
					if (book != nullptr){
						cout << "Book Found: "<<book->title <<endl; 
					}
					else{
						cout  << "Book not found" <<endl; 
					}	
				}
				else if (bookChoice == "4")
				//GO BACK TO MAIN MENU 
				continue; 
				else {
					cout << "Invalid choice. Please try again." <<endl; 
					system ("cls"); 
				}
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
