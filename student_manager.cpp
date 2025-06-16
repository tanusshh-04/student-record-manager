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
    Student s;
    ofstream outFile("students.txt", ios::app);

    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore(); // Clear newline character from buffer

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    outFile << s.rollNo << "," << s.name << "," << s.marks << endl;
    outFile.close();

    cout << "Student added successfully.\n";
}

void viewStudents() {
    ifstream inFile("students.txt");
    string line;

    cout << "\n--- Student Records ---\n";
    if (!inFile) {
        cout << "No records found.\n";
        return;
    }

    bool empty = true;
    while (getline(inFile, line)) {
        cout << line << endl;
        empty = false;
    }

    if (empty) {
        cout << "No student data available.\n";
    }

    inFile.close();
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int fileRoll = stoi(line.substr(0, line.find(',')));
        if (fileRoll != roll) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student deleted successfully.\n";
    else
        cout << "Roll No not found.\n";
}

void updateStudent() {
    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int fileRoll = stoi(line.substr(0, line.find(',')));

        if (fileRoll == roll) {
            Student s;
            s.rollNo = roll;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new marks: ";
            cin >> s.marks;

            tempFile << s.rollNo << "," << s.name << "," << s.marks << endl;
            found = true;
        } else {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student updated successfully.\n";
    else
        cout << "Roll No not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== Student Record Manager ======\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: deleteStudent(); break;
            case 4: updateStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

