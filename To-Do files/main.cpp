#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Load tasks from file
void loadTasks() {
    ifstream file("tasks.txt");
    if (!file) return;

    string desc;
    bool status;

    while (getline(file, desc)) {
        file >> status;
        file.ignore();
        tasks.push_back({desc, status});
    }

    file.close();
}

// Save tasks to file
void saveTasks() {
    ofstream file("tasks.txt");

    for (auto &task : tasks) {
        file << task.description << endl;
        file << task.completed << endl;
    }

    file.close();
}

// Add task
void addTask() {
    string desc;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, desc);

    tasks.push_back({desc, false});
    saveTasks();
}

// View tasks
void viewTasks() {
    cout << "\n--- TO-DO LIST ---\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].description
             << (tasks[i].completed ? " [Done]" : " [Pending]") << endl;
    }
}

// Mark complete
void markComplete() {
    int index;
    cout << "Enter task number: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        saveTasks();
    } else {
        cout << "Invalid task!\n";
    }
}

// Delete task
void deleteTask() {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        saveTasks();
    } else {
        cout << "Invalid task!\n";
    }
}

int main() {
    loadTasks();

    int choice;

    do {
        cout << "\n===== TO-DO APP =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markComplete(); break;
            case 4: deleteTask(); break;
        }

    } while (choice != 5);

    return 0;
}
