#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_id;
    int mark;
};

char getGrade(int mark) {
    if (mark >= 80)
        return 'A';
    else if (mark >= 60)
        return 'B';
    else if (mark >= 50)
        return 'C';
    else if (mark >= 40)
        return 'D';
    else
        return 'F';
}

Student searchStudent(Student students[], int size, string target_id) {
    for (int i = 0; i < size; i++) {
        if (students[i].student_id == target_id) {
            return students[i];
        }
    }
    return { "", 0 };
}

int main() {
    const int SIZE = 5;
    Student students[SIZE];

    cout << "Please enter students' ID and marks:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Student " << i + 1 << " ID: ";
        cin >> students[i].student_id;
        cout << "Student " << i + 1 << " mark: ";
        cin >> students[i].mark;
    }

    string target_id;
    cout << "Enter the student's ID that you want to search: ";
    cin >> target_id;

    Student target_student = searchStudent(students, SIZE, target_id);

    if (target_student.student_id != "") {
        char grade = getGrade(target_student.mark);
        cout << "Target found" << endl;
        cout << "The mark of student " << target_student.student_id << " is " << target_student.mark << ". The grade is " << grade << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}

