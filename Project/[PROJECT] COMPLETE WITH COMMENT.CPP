//GROUP 7 DATA STRUCTURE AND ALGORITHM
//DANIEL ISKANDAR BIN MIZAN
//MUHAMAD ARIF BIN SALLEHUDDIN
//FARHAN DARWISY BIN MOHD FAZLI 
//MUHAMMAD DANISH MIRZA BIN YUSOF

#include <iostream> //Header file 
#include <string>
#include <stack>
#include <algorithm>
using namespace std; //use the standard namespace 

// BOOK STRUCTURE
struct Book {
    string id;
    string isbn;
    string title;
    bool available;
    int quantity;
    Book* next;
};

// ROOM STRUCTURE
struct Room {
    string name;
    bool available;
    int capacity;
    Room* next;
};

// BOOK CLASS
class BookList {
private:
	Book* head;


public:
    BookList() : head(nullptr) {}
	//FUNCTION AND METHODS FOR MANAGING THE BOOK LIST 
    
	//SEARCH BOOK BY ID USING LINEAR SEARCH 
	Book* searchBookByID(const string& id) {
        Book* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

	//SEARCH BOOK BY TITLE USING CASE-INSENTITIVE SEARCH
	 //ENABLE TO SEARCH THE BOOK IGNORING UPPER CASE AND LOWER CASE 
    Book* searchBookByTitle(const string& title) {
        Book* current = head;
        while (current != nullptr) {
            string storedTitle = current->title;
            transform(storedTitle.begin(), storedTitle.end(), storedTitle.begin(), ::tolower);
            string searchTitle = title;
            transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

            if (storedTitle == searchTitle) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

	//SEARCH BOOK BY ISNB USING BINARY SEARCH
	//COMPARING THE ISBN VALUES 
    Book* searchBookByISBN(const string& isbn) {
        Book* start = head;
        Book* end = nullptr;

        while (start != end) {
            Book* mid = start;
            int count = 0;

            while (mid != end) {
                mid = mid->next;
                count++;
            }

            mid = start;
            for (int i = 0; i < count / 2; i++) {
                mid = mid->next;
            }

            if (mid->isbn == isbn) {
                return mid;
            }
            else if (mid->isbn < isbn) {
                start = mid->next;
            }
            else {
                end = mid;
            }
        }

        return nullptr;
    }

    void addBook(const string& id, const string& isbn, const string& title, int quantity) {
        //CREATE A NEW BOOK INSTANCE
		Book* newBook = new Book;
        
        //ASSIGN VALUES TO THE NEW BOOK'S PROPERTIES 
		newBook->id = id;
        newBook->isbn = isbn;
        newBook->title = title;
        newBook->available = true;
        newBook->quantity = quantity;
        newBook->next = nullptr;

		//Check if the book list is empty 
        if (head == nullptr) {
            //if the list im empty, make the new book the head of the list 
			head = newBook;
        }
        else {
            Book* current = head;
            //If the list is not empty, find the last book in the list 
            while (current->next != nullptr) {
                current = current->next;
            }
            //Append the new book to the end of the list 
            current->next = newBook;
        }
    }

    void rentBook(const string& id) {
    	//Search for the book with the given ID
        Book* book = searchBookByID(id);
        
        if (book != nullptr) {
        	//check if the book is available and has a quantity greater than 0
            if (book->available && book->quantity > 0) {
                //decrement the quantity of the book 
				book->quantity--;
                
				//Print Sucess 
				cout << "    Book rented successfully.\n";
            }
            else {
            	// Print not available 
                cout << "    Sorry, the book is currently unavailable.\n";
            }
        }
        else {
        	//Print book not found 
            cout << "    Book not found.\n";
        }
    }

	//FUNCTION TO DELETE A BOOK 
    void deleteBook(const string& id) {
        //INITIALIE CURRENT AND PREVIOUS POINTERS 
		Book* current = head;
        Book* previous = nullptr;

		//TRAVERSE THE LIST 
        while (current != nullptr) {
            if (current->id == id) {
                if (previous == nullptr) {
                    // Deleting the head node
                    head = current->next;
                }
                else {
                	//DELETE A NODE THAT IS NOT THE HEAD 
                    previous->next = current->next;
                }
				//DELETE THE CURRENT NODE 
                delete current;
                
                //PRINT MESSAGE 
                cout << "    Book deleted successfully.\n";
                return;
            }
			//MOVE THE POINTERS FORWARD
            previous = current;
            current = current->next;
        }
		//PRINT BOOK NOT FOUND
        cout << "    Book not found.\n";
    }

	//DISPLAY THE AVAILABLE BOOKS FUNCTION
    void displayAvailableBooks() {
        Book* current = head;
        //CHECK IF THE BOOK IS AVAILABLE AND HAS A QUANTITY GREATER THAN 0
        while (current != nullptr) {
        	
        	//PRINT BOOK INFORMATION 
            if (current->available && current->quantity > 0) {
                cout << "Title: " << current->title << endl;
                cout << "ISBN: " << current->isbn << endl;
                cout << "ID: " << current->id << endl;
                cout << "Quantity: " << current->quantity << endl;
                cout << "--------------------------\n";
            }
            current = current->next;
        }
    }
};

// MEETING ROOM CLASS
class MeetingRoomList {
private:
    Room* head;

public:
	
	//MEETING ROOM USING LINKED LIST 
    MeetingRoomList() : head(nullptr) {}
	//START THE SEARCH FROM THE HEAD OF THE LIST 
    Room* searchRoomByName(const string& name) {
        Room* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addRoom(const string& name, bool available, int capacity) {
    	//Create a new room node
        Room* newRoom = new Room;
        newRoom->name = name;
        newRoom->available = available;
        newRoom->capacity = capacity;
        newRoom->next = nullptr;

        if (head == nullptr) {
        	//If the list is empty, set the new room as the head 
            head = newRoom;
        }
        else {
        	//TRAVERSE THE LIST TO FIND THE LAST NODE 
            Room* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            //APPEND THE NEW ROOM TO THE END 
            current->next = newRoom;
        }
    }
};

int main() {
    string name, id, password;

    // LOGIN PAGE
    cout << " <--------------------------->" << endl;
    cout << "    Welcome to MMU Library!   " << endl;
    cout << " <--------------------------->" << endl;
    cout << "\n         Login Page         " << endl;
    cout << " <--------------------------->" << endl;
    cout << "   Enter your name: ";
    getline(cin, name);

    while (true) {
        cout << "   Enter ID: ";
        getline(cin, id);

        // Check if ID is equal to 10 characters
        if (id.length() == 4) {
            break;
        }
        else {
            cout << "   Invalid ID! Please make sure you enter the correct ID.\n";
        }
    }

    cout << "   Password: ";
    getline(cin, password);

    // Check both ID and password
    if (id == "1211" && password == "123") {
        cout << "\n  Login Successful! Welcome, " << name << endl;
        system ("pause");
		system ("cls");

        // Create a book list and add books to the database
        BookList bookList;
        bookList.addBook("1", "9780132350884", "Clean Code: A Handbook of Agile Software Craftsmanship", 5);
        bookList.addBook("2", "9780137081073", "Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14", 3);
        bookList.addBook("3", "9780134685991", "Cracking the Coding Interview: 189 Programming Questions and Solutions", 2);
        bookList.addBook("4", "9780135787791", "Data Structure and Algorithm Fundamentals", 10);
        bookList.addBook("5", "9780138534431", "C++ Fundamentals", 4);


        // CREATE MEETING ROOM LIST DATABASE 
        MeetingRoomList roomList;
        roomList.addRoom("Azure", true, 3);
        roomList.addRoom("Diamond", true, 2);
        roomList.addRoom("Sapphire", true, 1);

        string choice;

        while (true) {
            cout << "\n   What would you like to do?" << endl;
            cout << " <--------------------------->" << endl;
            cout << "   No.        Category      " << endl;
            cout << " <--------------------------->" << endl;
            cout << "   1.    Rent a Meeting Room\n";
            cout << "   2.    Rent a Book\n";
            cout << "   3.    Delete a Book\n";
            cout << "   4.    Quit\n";
            cout << "\n   Enter your choice: ";
            cin >> choice;
            system("cls");

            if (choice == "1") {
                // FUNCTION TO BOOK A ROOM
                string roomName;
                cout << "\n       List of the room     " << endl;
                cout << " <--------------------------->" << endl;
                cout << "      No.      Room Name      " << endl;
                cout << " <--------------------------->" << endl;
                cout << "      Note: Room is Valid for 1 day"<<endl;
                cout << " <--------------------------->" << endl;
                cout << "      1.       Azure          " << endl;
                cout << "      2.       Diamond        " << endl;
                cout << "      3.       Sapphire       " << endl;
                cout << "      4.       Return to main menu       " << endl;

                cout << "\n  Type the name of the room (case-sensitive): ";
                cin.ignore(); // Added this line to clear the input buffer
                getline(cin, roomName);

                Room* room = roomList.searchRoomByName(roomName);
                if (room != nullptr) {
                    if (room->available) {
                        cout << "\n  Room " << room->name << " booked successfully!\n";
                        room->available = false;
                    }
                    else {
                        cout << "\n  Room " << room->name << " is not available at the moment.\n";
                    }
                }
                else {
                    cout << "\n  Room not Found...Returning to main menu.\n";
                    system ("pause");
                    system ("cls");
                    
                }
            }
            else if (choice == "2") {
                string bookChoice;

                cout << "\n   What would you like to do?\n";
                cout << " <--------------------------->" << endl;
                cout << "     No.        Category      " << endl;
                cout << " <--------------------------->" << endl;
                cout << "     1.     Search for a book " << endl;
                cout << "     2.     Rent a book" << endl;
                cout << "     3.     Return to main menu"<<endl;
                cout << "\n    Enter your choice: ";
                cin >> bookChoice;
                system ("cls");

                if (bookChoice == "1") {
                    string searchChoice;
                    cout << "\n  What field would you like to search by?\n";
                    cout << " <--------------------------->" << endl;
                    cout << "     No.        Category      " << endl;
                    cout << " <--------------------------->" << endl;
                    cout << "   1.         ID            " << endl;
                    cout << "   2.         Title         " << endl;
                    cout << "   3.         ISBN          " << endl;
                    cout << "\n  Enter your choice: ";
                    cin >> searchChoice;

                    string searchTerm;
                    cout << "\n  Enter the search term: ";
                    cin.ignore();
                    getline(cin, searchTerm);

                    Book* foundBook = nullptr;

                    if (searchChoice == "1") {
                        foundBook = bookList.searchBookByID(searchTerm);
                    }
                    else if (searchChoice == "2") {
                        foundBook = bookList.searchBookByTitle(searchTerm);
                    }
                    else if (searchChoice == "3") {
                        foundBook = bookList.searchBookByISBN(searchTerm);
                    }
                    else if (searchChoice == "4"){
                    	cout << "\nReturning to the main menu...\n"; 
                    	break;
					}

                    if (foundBook != nullptr) {
                        cout << "\n    Book found!\n";
                        cout << "    Title: " << foundBook->title << endl;
                        cout << "    ISBN: " << foundBook->isbn << endl;
                        cout << "    ID: " << foundBook->id << endl;
                        cout << "    Quantity: " << foundBook->quantity << endl;
                        if (foundBook->available && foundBook->quantity > 0) {
                            cout << "    The book is currently available.\n";
                        }
                        else {
                            cout << "    The book is currently unavailable.\n";
                        }
                    }
                    else {
                        cout << "\n    Book not found.\n";
                    }
                }
                else if (bookChoice == "2") {
                    string bookID;
                    cout << "\n  Enter the ID of the book you want to rent: ";
                    cin.ignore();
                    getline(cin, bookID);
                    bookList.rentBook(bookID);
                }
            }
            else if (choice == "3") {
                string bookID;
                cout << "\n  Enter the ID of the book you want to delete: ";
                cin.ignore();
                getline(cin, bookID);
                bookList.deleteBook(bookID);
            }
            else if (choice == "4") {
				cout << "Thank you for Using MMU Library!\n";
				cout << "Exiting the terminal..."; 
				break;
				
            }
            else {
                cout << "\n  Invalid choice! Please enter a valid option.\n";
            }
        }
    }
    else {
        cout << "\n  Login Failed! Please check your ID and password.\n";
    }

    return 0;
}
