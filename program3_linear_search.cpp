#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int item;
    cout << "Enter the item to search: ";
    cin >> item;

    // Direct Linear Search
    int found = 0;
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            found = 1;
            position = i;
            break;
        }
    }

    if (found == 1) {
        cout << "Item " << item << " found at index: " << position << "\n";
        cout << "Position: " << (position + 1) << "\n";
    } else {
        cout << "Item " << item << " not found in the array.\n";
    }

    return 0;
}
