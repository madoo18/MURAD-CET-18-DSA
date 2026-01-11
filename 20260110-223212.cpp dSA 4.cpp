#include <iostream>
using namespace std;

#define MAX 10   // Maximum stack size

// Class representing a stack of books
class BookStack {
private:
    string books[MAX];  // Array to store book names
    int top;            // Index of the top book

public:
    // Constructor to initialize stack
    BookStack() {
        top = -1;
    }

    // Function to add a book (Push)
    void pushBook(string book) {
        if (top == MAX - 1) {
            cout << "Stack is full. Cannot add more books.\n";
        } else {
            top++;
            books[top] = book;
            cout << "Book added successfully.\n";
        }
    }

    // Function to remove the top book (Pop)
    void popBook() {
        if (top == -1) {
            cout << "Stack is empty. No book to remove.\n";
        } else {
            cout << "Removed Book: " << books[top] << endl;
            top--;
        }
    }

    // Function to view the top book (Peek)
    void peekBook() {
        if (top == -1) {
            cout << "Stack is empty. No book to view.\n";
        } else {
            cout << "Top Book: " << books[top] << endl;
        }
    }

    // Function to display all books
    void displayBooks() {
        if (top == -1) {
            cout << "No books in the stack.\n";
        } else {
            cout << "Books in Stack (Top to Bottom):\n";
            for (int i = top; i >= 0; i--) {
                cout << books[i] << endl;
            }
        }
    }

    // Function to check if stack is empty
    void isEmpty() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack is not empty.\n";
        }
    }
};

// Main function
int main() {
    BookStack library;  // Object of BookStack class
    int choice;
    string bookName;

    do {
        cout << "\n--- Book Management System ---\n";
        cout << "1. Add Book (Push)\n";
        cout << "2. Remove Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, bookName);
                library.pushBook(bookName);
                break;

            case 2:
                library.popBook();
                break;

            case 3:
                library.peekBook();
                break;

            case 4:
                library.displayBooks();
                break;

            case 5:
                library.isEmpty();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        
    