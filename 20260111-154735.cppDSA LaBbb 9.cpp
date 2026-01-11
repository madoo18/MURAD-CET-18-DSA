#include <iostream>
using namespace std;

#define MAX 10  


class TicketQueue {
private:
    string tickets[MAX];
    int front, rear;

public:
   
    TicketQueue() {
        front = -1;
        rear = -1;
    }

   
    void addTicket(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more tickets.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        tickets[rear] = name;
        cout << "Ticket added successfully.\n";
    }

   
    void processTicket() {
        if (isEmpty()) {
            cout << "No tickets to process.\n";
            return;
        }

        cout << "Processing Ticket: " << tickets[front] << endl;
        front++;

       
        if (front > rear) {
            front = rear = -1;
        }
    }

   
    void displayTickets() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << tickets[i] << endl;
        }
    }

 
    bool isEmpty() {
        return (front == -1);
    }

    
    bool isFull() {
        return (rear == MAX - 1);
    }

    
    void cancelTicket(string name) {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to cancel.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (tickets[i] == name) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Ticket not found.\n";
            return;
        }

        for (int i = pos; i < rear; i++) {
            tickets[i] = tickets[i + 1];
        }

        rear--;
        cout << "Ticket cancelled successfully.\n";

        if (rear < front) {
            front = rear = -1;
        }
    }
};


int main() {
    TicketQueue support;
    int choice;
    string customerName;

    do {
        cout << "\n--- Customer Service Ticketing System ---\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display Tickets\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Cancel Ticket\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);
                support.addTicket(customerName);
                break;

            case 2:
                support.processTicket();
                break;

            case 3:
                support.displayTickets();
                break;

            case 4:
                if (support.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 5:
                if (support.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 6:
                cout << "Enter customer name to cancel ticket: ";
                cin.ignore();
                getline(cin, customerName);
                support.cancelTicket(customerName);
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
