#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

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

class BookList {
private:
    Book* head;

public:
    BookList() : head(nullptr) {}

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

    Book* searchBookByTitle(const string& title) {
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

            string storedTitle = mid->title;
            transform(storedTitle.begin(), storedTitle.end(), storedTitle.begin(), ::tolower);
            string searchTitle = title;
            transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

            if (storedTitle == searchTitle) {
                return mid;
            }
            else if (storedTitle < searchTitle) {
                start = mid->next;
            }
            else {
                end = mid;
            }
        }

        return nullptr;
    }

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

    void addBook(const string& id, const string& isbn, const string title, int quantity) {
        Book* newBook = new Book;
        newBook->id = id;
        newBook->isbn = isbn;
        newBook->title = title;
        newBook->available = true;
        newBook->quantity = quantity;
        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        }
        else {
            Book* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newBook;
        }
    }

    void rentBook(const string& id) {
        Book* book = searchBookByID(id);
        if (book != nullptr) {
            if (book->available && book->quantity > 0) {
                book->quantity--;
                cout << "Book rented successfully.\n";
            }
            else {
                cout << "Sorry, the book is currently unavailable.\n";
            }
        }
        else {
            cout << "Book not found.\n";
        }
    }

    void displayAvailableBooks() {
        Book* current = head;
        while (current != nullptr) {
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
// MEETING ROOM DATABASE
class MeetingRoomList {
private:
    Room* head;

public:
    MeetingRoomList() : head(nullptr) {}

    // SEARCH FOR A ROOM BY NAME
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

    // ADD A ROOM TO THE DATABASE
    void addRoom(const string& name, bool available, int capacity) {
        Room* newRoom = new Room;
        newRoom->name = name;
        newRoom->available = available;
        newRoom->capacity = capacity;
        newRoom->next = nullptr;

        if (head == nullptr) {
            head = newRoom;
        } else {
            Room* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newRoom;
        }
    }
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
    if (id == "1211206128" && password == "123456") {
        cout << "Login Successful! Welcome, " << name << ".\n\n";
        
        // Create a book list and add books to the database
        BookList bookList;
        bookList.addBook("1", "9780132350884", "Clean Code: A Handbook of Agile Software Craftsmanship", 5);
        bookList.addBook("2", "9780137081073", "Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14", 3);
        bookList.addBook("3", "9780134685991", "Cracking the Coding Interview: 189 Programming Questions and Solutions", 2);

         // CREATE MEETING ROOM LIST
        MeetingRoomList roomList;
        roomList.addRoom("Azure", true,3);
        roomList.addRoom("Diamond", true,2);
        roomList.addRoom("Sapphire", true,1);

        string choice;

        while (true) {
            cout << "What would you like to do?\n";
            cout << "Select Category\n";
            cout << "1. Rent a Meeting Room\n";
            cout << "2. Rent a Book\n";
            cout << "3. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == "1") {
                 // FUNCTION TO BOOK A ROOM
                string roomName;
                cout<<"List of the room"<<endl;
                cout<<"1.Azure"<<endl;
                cout<<"2.Diamond"<<endl;
                cout<<"3.Sapphire"<<endl;
        
                cout << "Enter the name of the room: ";
                 cin.ignore(); // Add this line to clear the input buffer
                getline(cin, roomName);

                Room* room = roomList.searchRoomByName(roomName);
                if (room != nullptr) {
                    if (room->available) {
                        cout << "Room " << room->name << " booked successfully!\n";
                        room->available = false;
                    } else {
                        cout << "Room " << room->name << " is not available at the moment.\n";
                    }
                } else {
                    cout << "Room not found.\n";
                }
            }
            else if (choice == "2") {
                string bookChoice;
                cout << "What would you like to do?\n";
                cout << "1. Search for a book\n";
                cout << "2. Rent a book or show available books\n";
                cout << "Enter your choice: ";
                cin >> bookChoice;

                if (bookChoice == "1") {
                    string searchChoice;
                    cout << "What field would you like to search by?\n";
                    cout << "1. ID\n";
                    cout << "2. Title\n";
                    cout << "3. ISBN\n";
                    cout << "Enter your choice: ";
                    cin >> searchChoice;

                    string searchTerm;
                    cout << "Enter the search term: ";
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

                    if (foundBook != nullptr) {
                        cout << "Book found:\n";
                        cout << "Title: " << foundBook->title << endl;
                        cout << "ISBN: " << foundBook->isbn << endl;
                        cout << "ID: " << foundBook->id << endl;
                        cout << "Quantity: " << foundBook->quantity << endl;
                    }
                    else {
                        cout << "Book not found.\n";
                    }
                }
                else if (bookChoice == "2") {
                    string id;
                    cout << "Enter the ID of the book you want to rent: ";
                    cin >> id;
                    bookList.rentBook(id);
                }
                else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
            else if (choice == "3") {
                cout << "Exiting the program...\n";
                break;
            }
            else {
                cout << "Invalid choice. Please try again.\n";
            }

            cout << "---------------------------------------------\n";
        }
    }
    else {
        cout << "Login failed. Please check your credentials.\n";
    }

    return 0;
}