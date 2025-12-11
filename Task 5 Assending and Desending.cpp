#include <iostream>
using namespace std;

int searchAsc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int searchDesc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void sortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void duplicateArr(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    int n;
    cout << "     Student Roll Number Search System   " << endl;
    cout << "\nEnter total number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Positive number required!" << endl;
        return 1;
    }

    int rolls[100], asc[100], desc[100];
    cout << "Enter " << n << " roll numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Roll No. " << i + 1 << ": ";
        cin >> rolls[i];
    }

    duplicateArr(rolls, asc, n);
    duplicateArr(rolls, desc, n);

    sortAsc(asc, n);
    sortDesc(desc, n);

    cout << "\nAscending Order : ";
    for (int i = 0; i < n; i++) cout << asc[i] << " ";
    cout << "\nDescending Order: ";
    for (int i = 0; i < n; i++) cout << desc[i] << " ";
    cout << "\n\n";

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    int pos = -1;
    if (key % 2 == 0) {
        cout << "[Searching ASCENDING (Even Roll No)]" << endl;
        pos = searchAsc(asc, n, key);
    } else {
        cout << "[Searching DESCENDING (Odd Roll No)]" << endl;
        pos = searchDesc(desc, n, key);
    }

    if (pos != -1) cout << "FOUND: Roll number " << key << " at position " << (pos + 1) << "." << endl;
    else cout << "NOT FOUND: Roll number " << key << " is not in the list." << endl;

   
    return 0;
}
