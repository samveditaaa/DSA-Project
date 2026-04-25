#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    Student* next;
};

Student* head = NULL;

// 🔹 Add Student
void addStudent(int id, string name) {
    Student* newNode = new Student();
    newNode->id = id;
    newNode->name = name;
    newNode->next = head;
    head = newNode;

    cout << "Student Added\n";
}

// 🔹 Display Students
void display() {
    if (head == NULL) {
        cout << "No records\n";
        return;
    }

    Student* temp = head;
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// 🔹 Search Student
void search(int key) {
    Student* temp = head;

    while (temp != NULL) {
        if (temp->id == key) {
            cout << "Found: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Not Found\n";
}

// 🔹 Delete Student
void deleteStudent(int key) {
    if (head == NULL) return;

    if (head->id == key) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted\n";
        return;
    }

    Student* temp = head;
    while (temp->next != NULL && temp->next->id != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Not Found\n";
        return;
    }

    Student* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Deleted\n";
}

// 🔹 Main Menu
int main() {
    int choice, id;
    string name;

    do {
        cout << "\n--- STUDENT MANAGEMENT ---\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                addStudent(id, name);
                break;

            case 2:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteStudent(id);
                break;

            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                search(id);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}