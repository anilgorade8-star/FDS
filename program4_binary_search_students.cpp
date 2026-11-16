/*
 * Program 4: Binary Search for Student Roll Numbers
 * Objective: Accept n students, input roll numbers in sorted order,
 *            and search for a specified roll number using Binary Search.
 *            Display its position if found; otherwise, display an appropriate message.
 */

#include <iostream>
using namespace std;

// Function to perform Binary Search on a sorted array of roll numbers
// Returns index if found, otherwise returns -1
int binarySearch(const int rollNumbers[], int n, int targetRoll) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (rollNumbers[mid] == targetRoll) {
            return mid; // Target found
        }
        else if (rollNumbers[mid] < targetRoll) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cout << "=== Student Roll Number Search Using Binary Search ===\n";
    cout << "Enter the number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of students must be greater than 0.\n";
        return 1;
    }

    int* rollNumbers = new int[n];

    cout << "\nEnter " << n << " roll numbers in ASCENDING (sorted) order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << " Roll Number: ";
        cin >> rollNumbers[i];

        // Validation check for sorted order
        if (i > 0 && rollNumbers[i] < rollNumbers[i - 1]) {
            cout << "Warning: The entered roll number is smaller than previous. Please enter in sorted order!\n";
        }
    }

    int targetRoll;
    cout << "\nEnter the roll number to search: ";
    cin >> targetRoll;

    int position = binarySearch(rollNumbers, n, targetRoll);

    if (position != -1) {
        cout << "\n[RESULT] Roll number " << targetRoll << " found in the records!\n";
        cout << "-> Zero-based Index: " << position << "\n";
        cout << "-> Position (1-based student rank): " << (position + 1) << "\n";
    } else {
        cout << "\n[RESULT] Roll number " << targetRoll << " was NOT found in the student records.\n";
    }

    delete[] rollNumbers;
    return 0;
}

