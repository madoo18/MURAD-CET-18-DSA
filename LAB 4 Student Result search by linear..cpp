#include <iostream>
using namespace std;

int searchLinear(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int searchBinary(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

void duplicateArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void sortBubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int total;
    cout << "      Student Record Search System     " << endl;
    cout << "\nEnter total number of students: ";
    cin >> total;

    if (total <= 0) {
        cout << "Error: Number of students must be positive!" << endl;
        return 1;
    }

    int rolls[total], rollsSorted[total];

    cout << "Enter " << total << " roll numbers:" << endl;
    for (int i = 0; i < total; i++) {
        cout << "Roll No. " << i + 1 << ": ";
        cin >> rolls[i];
    }

    duplicateArray(rolls, rollsSorted, total);
    sortBubble(rollsSorted, total);

    cout << "\nUnsorted Records: ";
    for (int i = 0; i < total; i++) cout << rolls[i] << " ";
    cout << "\nSorted Records:   ";
    for (int i = 0; i < total; i++) cout << rollsSorted[i] << " ";
    cout << endl << endl;

    int method, searchKey, pos;
    cout << "Choose Search Method:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> method;

    cout << "Enter roll number to search: ";
    cin >> searchKey;

    if (method == 1) pos = searchLinear(rolls, total, searchKey);
    else if (method == 2) pos = searchBinary(rollsSorted, total, searchKey);
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << endl;
    if (pos != -1) cout << "SUCCESS: Roll number " << searchKey << " found at position " << (pos + 1) << "." << endl;
    else cout << "NOT FOUND: Roll number " << searchKey << " is not in the records." << endl;



    return 0;
}
