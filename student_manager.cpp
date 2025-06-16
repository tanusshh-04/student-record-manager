#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void addStudent() {
    ofstream outFile("students.txt", ios::app);
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    outFile << s.rollNo << "," << s.name << "," << s.marks << endl;
    outFile.close();
    cout << "Student added successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 2);
    return 0;
}
