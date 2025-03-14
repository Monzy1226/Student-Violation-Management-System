#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string id; // Change from int to string
    string name;
    vector<string> violations;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "\nEnter Student ID: ";
    getline(cin, s.id); // Accept alphanumeric input
    cout << "Enter Student Name: ";
    getline(cin, s.name);
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void addViolation() {
    string id;
    cout << "\nEnter Student ID: ";
    getline(cin, id); // Accept alphanumeric input
    bool found = false;

    for (auto &s : students) {
        if (s.id == id) {
            found = true;
            cout << "Enter Violation: ";
            string violation;
            getline(cin, violation);
            s.violations.push_back(violation);
            cout << "Violation added!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

void displayStudents() {
    cout << "\nStudent List:\n";
    for (const auto &s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name << "\n";
        if (!s.violations.empty()) {
            cout << "Violations:\n";
            for (const auto &v : s.violations) {
                cout << "- " << v << "\n";
            }
        }
        cout << "---------------------\n";
    }
}

void searchStudent() {
    string id;
    cout << "\nEnter Student ID to Search: ";
    getline(cin, id);
    bool found = false;

    for (const auto &s : students) {
        if (s.id == id) {
            found = true;
            cout << "\nID: " << s.id << "\nName: " << s.name << "\n";
            if (!s.violations.empty()) {
                cout << "Violations:\n";
                for (const auto &v : s.violations) {
                    cout << "- " << v << "\n";
                }
            } else {
                cout << "No violations recorded.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Violation System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Violation\n";
        cout << "3. Display Students\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // To prevent input buffer issues

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addViolation(); break;
            case 3: displayStudents(); break;
            case 4: searchStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
