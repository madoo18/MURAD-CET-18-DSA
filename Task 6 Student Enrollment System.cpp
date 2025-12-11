#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int sem;
    float gpa;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

Node* createNode(int id, string name, int sem, float gpa) {
    Node* n = new Node();
    n->id = id;
    n->name = name;
    n->sem = sem;
    n->gpa = gpa;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}

void addAtStart(int id, string name, int sem, float gpa) {
    Node* n = createNode(id, name, sem, gpa);
    if (!head) head = n;
    else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    cout << "Inserted at start.\n";
}

void addAtEnd(int id, string name, int sem, float gpa) {
    Node* n = createNode(id, name, sem, gpa);
    if (!head) {
        head = n;
        cout << "Inserted at end.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
    cout << "Inserted at end.\n";
}

void addAtPos(int pos, int id, string name, int sem, float gpa) {
    if (pos < 0) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 0) {
        addAtStart(id, name, sem, gpa);
        return;
    }
    Node* temp = head;
    int index = 0;
    while (temp && index < pos - 1) {
        temp = temp->next;
        index++;
    }
    if (!temp) {
        cout << "Position out of range.\n";
        return;
    }
    Node* n = createNode(id, name, sem, gpa);
    n->next = temp->next;
    n->prev = temp;
    if (temp->next) temp->next->prev = n;
    temp->next = n;
    cout << "Inserted at position " << pos << ".\n";
}

void delAtStart() {
    if (!head) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    cout << "Deleted from start.\n";
}

void delAtEnd() {
    if (!head) {
        cout << "List empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        cout << "Deleted last node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
    cout << "Deleted from end.\n";
}

void delAtPos(int pos) {
    if (!head) {
        cout << "List empty.\n";
        return;
    }
    if (pos == 0) {
        delAtStart();
        return;
    }
    Node* temp = head;
    int index = 0;
    while (temp && index < pos) {
        temp = temp->next;
        index++;
    }
    if (!temp) {
        cout << "Position out of range.\n";
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    cout << "Deleted from position " << pos << ".\n";
}

void showForward() {
    if (!head) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    cout << "\n--- Students (Forward) ---\n";
    while (temp) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Sem: " << temp->sem
             << " | GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}

void showBackward() {
    if (!head) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    cout << "\n--- Students (Backward) ---\n";
    while (temp) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Sem: " << temp->sem
             << " | GPA: " << temp->gpa << endl;
        temp = temp->prev;
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Enrollment System =====\n";
        cout << "1. Add at Start\n2. Add at End\n3. Add at Position\n";
        cout << "4. Delete at Start\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Display Forward\n8. Display Backward\n9. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        int id, sem, pos;
        float gpa;
        string name;

        switch (choice) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Semester: "; cin >> sem;
                cout << "GPA: "; cin >> gpa;
                addAtStart(id, name, sem, gpa);
                break;
            case 2:
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Semester: "; cin >> sem;
                cout << "GPA: "; cin >> gpa;
                addAtEnd(id, name, sem, gpa);
                break;
            case 3:
                cout << "Position: "; cin >> pos;
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Semester: "; cin >> sem;
                cout << "GPA: "; cin >> gpa;
                addAtPos(pos, id, name, sem, gpa);
                break;
            case 4: delAtStart(); break;
            case 5: delAtEnd(); break;
            case 6:
                cout << "Position: "; cin >> pos;
                delAtPos(pos);
                break;
            case 7: showForward(); break;
            case 8: showBackward(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 9);
}
