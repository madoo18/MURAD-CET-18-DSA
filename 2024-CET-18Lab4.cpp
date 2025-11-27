#include <iostream>
using namespace std;

// Function for Linear Search (used for unsorted arrays)
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function for Binary Search (used for sorted arrays)
int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid; // Return index if found
        else if (arr[mid] < key)
            start = mid + 1; // Search right half
        else
            end = mid - 1; // Search left half
    }

    return -1; // Not found
}

int main() {
    int size;

    cout << "===== Student Record Search System =====" << endl;

    // Get number of students
    cout << "Enter Number Of Students:";
    cin >> size;

    int rollNumbers[100]; // Assuming maximum 100 students

    // Input roll numbers
    cout << "Enter roll numbers of students:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Rollno of Student No" << i + 1 << ": ";
        cin >> rollNumbers[i];
    }

    // Ask for search type
    int choice;
    cout << "\nSelect search method:" << endl;
    cout << "1. Linear Search (for unsorted data)" << endl;
    cout << "2. Binary Search (for sorted data)" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Get the roll number to search
    int key;
    cout << "\nEnter roll number to search: ";
    cin >> key;

    int result = -1; // To store search result index

    // Perform the chosen search
    if (choice == 1) {
        result = linearSearch(rollNumbers, size, key);
    } 
    else if (choice == 2) {
        result = binarySearch(rollNumbers, size, key);
    } 
    else {
        cout << "Invalid choice! Please restart the program." << endl;
        return 0;
    }

    // Display search result
    if (result != -1)
        cout << "\n Roll Number " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "\n Roll Number " << key << " not found in records." << endl;

    cout << "\n===== Search Complete =====" << endl;

    return 0;
}
