#include <iostream>
using namespace std;

// Node class for creating nodes of linked list
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Linked List class for creating and manipulating linked list
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete the first node of the linked list
    void deleteFirstNode() {
        if (head != NULL) {
            head = head->next;
        }
    }

    // Function to search for a data in the linked list
    bool search(int data) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display the linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList linkedList;
    int data;
    for (int i = 1; i <= 5; i++) {
        cout << "Enter data " << i << ": ";
        cin >> data;
        linkedList.insertAtEnd(data);
    }

    // Display the original list
    cout << "The Current List:" << endl;
    linkedList.display();

    // Delete the first node and display the updated list
    cout << "\nDeleting the first node" << endl;
    linkedList.deleteFirstNode();
    cout << "The list after deletion:" << endl;
    linkedList.display();

    // Search for data in the list
    int searchData;
    cout << "Enter a data to search: ";
    cin >> searchData;
    if (linkedList.search(searchData)) {
        cout << "DATA FOUND!" << endl;
    }
    else {
        cout << "DATA NOT FOUND!" << endl;
    }

    return 0;
}

