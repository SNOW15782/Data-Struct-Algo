#include <iostream>
using namespace std;

// Structure to hold student record
struct StudentRecord {
    int id;
    string name;
    char grade;
};

// Function to perform insertion sort on student records based on grade
void insertionSort(StudentRecord arr[], int n) {
    for (int i = 1; i < n; i++) {
        StudentRecord key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key.grade, to one position ahead of their current position
        while (j >= 0 && arr[j].grade > key.grade) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

// Function to display the student records
void displayRecords(StudentRecord arr[], int n) {
    cout << "Rank\tID\tName\tGrade" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arr[i].id << "\t" << arr[i].name << "\t" << arr[i].grade << endl;
    }
}

int main() {
    StudentRecord records[5];
    
    // Input student records from the user
    cout << "Enter student records:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student #" << i + 1 << endl;
        cout << "--------------" << endl;
        cout << "ID: ";
        cin >> records[i].id;
        cout << "Name: ";
        cin >> records[i].name;
        cout << "Grade (A, B, C, D, or F): ";
        cin >> records[i].grade;
        cout << endl;
    }
    
    // Sort the student records based on grade using insertion sort
    insertionSort(records, 5);
    
    // Display the sorted student records
    cout << "Ranking of Students" << endl;
    cout << "-------------------" << endl;
    displayRecords(records, 5);
    
    return 0;
}

