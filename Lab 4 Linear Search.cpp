#include <iostream>
using namespace std;

int findIndex(int arr[], int n, int target) {
    for (int idx = 0; idx < n; idx++) {
        if (arr[idx] == target) {
            return idx;
        }
    }
    return -1;
}

int main() {
    int data[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 47, 51, 20, 58, 96, 45, 21, 36, 50};
    int keyToFind;

    cout << "Enter a number to search: ";
    cin >> keyToFind;

    int indexFound = findIndex(data, 20, keyToFind);

    if (indexFound != -1) {
        cout << "Number found at index: " << indexFound << endl;
    } else {
        cout << "Number not found!" << endl;
    }

    return 0;
}
