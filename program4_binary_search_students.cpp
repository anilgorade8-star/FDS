#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int rollNumbers[100];
    cout << "Enter " << n << " roll numbers in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> rollNumbers[i];
    }

    int searchRoll;
    cout << "Enter the roll number to search: ";
    cin >> searchRoll;

    // Direct Binary Search
    int low = 0;
    int high = n - 1;
    int found = 0;
    int position = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (rollNumbers[mid] == searchRoll) {
            found = 1;
            position = mid;
            break;
        } else if (rollNumbers[mid] < searchRoll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found == 1) {
        cout << "Roll number " << searchRoll << " found at position: " << (position + 1) << " (index " << position << ")\n";
    } else {
        cout << "Roll number " << searchRoll << " not found in the list.\n";
    }

    return 0;
}
