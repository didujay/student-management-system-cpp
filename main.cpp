#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

Student students[100];
int count = 0;

void addStudent() {
    cout << "\nEnter Student ID: ";
    cin >> students[count].id;

    cout << "Enter Name: ";
    cin >> students[count].name;

    cout << "Enter Age: ";
    cin >> students[count].age;

    cout << "Enter Course: ";
    cin >> students[count].course;

    count++;
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if(count == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\nStudent Records:\n";
    for(int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age
             << ", Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            cout << "Student Found:\n";
            cout << "ID: " << students[i].id
                 << ", Name: " << students[i].name
                 << ", Age: " << students[i].age
                 << ", Course: " << students[i].course << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void updateStudent() {
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            cout << "Enter New Name: ";
            cin >> students[i].name;

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cout << "Enter New Course: ";
            cin >> students[i].course;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 6);

    return 0;
}
