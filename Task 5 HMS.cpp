#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
};

Node* head = nullptr;

void addPatientEnd(int id) {
    Node* node = new Node();
    node->patientID = id;
    node->next = nullptr;

    if (!head) {
        head = node;
        cout << "Patient added at the end (first patient).\n";
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    cout << "Patient added at the end.\n";
}

void addPatientBeginning(int id) {
    Node* node = new Node();
    node->patientID = id;
    node->next = head;
    head = node;
    cout << "Emergency patient added at the beginning.\n";
}

void showPatients() {
    if (!head) {
        cout << "No patients currently checked in.\n";
        return;
    }

    Node* temp = head;
    cout << "Current Patients:\n";
    while (temp) {
        cout << "Patient ID: " << temp->patientID << endl;
        temp = temp->next;
    }
}

void findPatient(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->patientID == id) {
            cout << "Patient found: ID = " << id << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient with ID " << id << " not found.\n";
}

void deletePatient(int id) {
    if (!head) {
        cout << "No patients to remove.\n";
        return;
    }

    if (head->patientID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient removed successfully.\n";
        return;
    }

    Node* curr = head;
    while (curr->next && curr->next->patientID != id) curr = curr->next;

    if (!curr->next) {
        cout << "Patient not found.\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    cout << "Patient removed successfully.\n";
}

int main() {
    int choice, id;
    while (true) {
        cout << "\n--- Hospital Patient Management System ---\n";
        cout << "1. Add Patient (End)\n";
        cout << "2. Add Emergency Patient (Beginning)\n";
        cout << "3. Display All Patients\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Remove Patient (Treated)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                addPatientEnd(id);
                break;
            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                addPatientBeginning(id);
                break;
            case 3:
                showPatients();
                break;
            case 4:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                findPatient(id);
                break;
            case 5:
                cout << "Enter Patient ID to remove: ";
                cin >> id;
                deletePatient(id);
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
