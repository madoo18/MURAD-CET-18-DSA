#include <iostream>
using namespace std;

// Function to sort array in ascending order
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                // Swap values
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                // Swap values
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Binary search for ascending order array
int binarySearchAscending(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // Not found
}

// Binary search for descending order array
int binarySearchDescending(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // Not found
}

int main() {
    int size;

    cout << "===== Student Roll Number Search Program =====" << endl;

    // Input number of students
    cout << "Enter the no of students: ";
    cin >> size;

    int rollNumbers[100]; // Assume max 100 students

    // Input roll numbers
    cout << "Enter roll numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Roll Number " << i + 1 << ": ";
        cin >> rollNumbers[i];
    }

    int key;
    cout << "\nEnter roll number to search: ";
    cin >> key;

    int result = -1;

    // If roll number is even ? ascending search
    if (key % 2 == 0) {
        sortAscending(rollNumbers, size);
        cout << "\nArray sorted in ascending order for even roll number search." << endl;
        result = binarySearchAscending(rollNumbers, size, key);
    } 
    // If roll number is odd ? descending search
    else {
        sortDescending(rollNumbers, size);
        cout << "\nArray sorted in descending order for odd roll number search." << endl;
        result = binarySearchDescending(rollNumbers, size, key);
    }

    // Display results
    cout << "\nSorted Roll Numbers: ";
    for (int i = 0; i < size; i++) {
        cout << rollNumbers[i] << " ";
    }
    cout << endl;

    if (result != -1)
        cout << "\n Roll Number " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "\n Roll Number " << key << " not found in records." << endl;

    cout << "\n===== Search Complete =====" << endl;

    return 0;
}
