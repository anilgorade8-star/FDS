/*
 * Program 3: Linear Search Algorithm
 * Objective: Search an item in an array and display its position using Linear Search.
 */

#include <iostream>
using namespace std;

// Function to perform Linear Search
// Returns the index if found, otherwise returns -1
int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

int main() {
    int n;
    cout << "=== Linear Search Implementation ===\n";
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }

    int target;
    cout << "\nEnter the item to search: ";
    cin >> target;

    int resultIndex = linearSearch(arr, n, target);

    if (resultIndex != -1) {
        cout << "\n[SUCCESS] Item " << target << " found in the array!\n";
        cout << "-> Zero-based Index: " << resultIndex << "\n";
        cout << "-> One-based Position: " << (resultIndex + 1) << "\n";
    } else {
        cout << "\n[NOT FOUND] Item " << target << " is not present in the array.\n";
    }

    delete[] arr; // Free dynamic memory
    return 0;
}

