#include <iostream>
using namespace std;

int main() {
    int capacity;
    cout << "Enter initial capacity of dynamic array: ";
    cin >> capacity;

    if (capacity <= 0) {
        capacity = 10;
    }

    // (1) Creation of Dynamic Array list
    int* arr = new int[capacity];
    int size = 0;

    int n;
    cout << "How many initial elements do you want to enter? ";
    cin >> n;

    if (n > capacity) {
        delete[] arr;
        capacity = n + 5;
        arr = new int[capacity];
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        size++;
    }

    int choice;
    do {
        cout << "\n--- Array Operations ---\n";
        cout << "1. Insert element at position\n";
        cout << "2. Append element at the end\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // (2) Insert element at specified position
                int pos, val;
                cout << "Enter position to insert (0 to " << size << "): ";
                cin >> pos;

                if (pos < 0 || pos > size) {
                    cout << "Invalid position!\n";
                    break;
                }

                cout << "Enter value to insert: ";
                cin >> val;

                // Resize if full
                if (size == capacity) {
                    capacity = capacity * 2;
                    int* temp = new int[capacity];
                    for (int i = 0; i < size; i++) {
                        temp[i] = arr[i];
                    }
                    delete[] arr;
                    arr = temp;
                }

                // Shift elements to the right
                for (int i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos] = val;
                size++;

                cout << "Element inserted successfully!\n";
                break;
            }

            case 2: {
                // (3) Append element into the list
                int val;
                cout << "Enter value to append at the end: ";
                cin >> val;

                // Resize if full
                if (size == capacity) {
                    capacity = capacity * 2;
                    int* temp = new int[capacity];
                    for (int i = 0; i < size; i++) {
                        temp[i] = arr[i];
                    }
                    delete[] arr;
                    arr = temp;
                }

                arr[size] = val;
                size++;

                cout << "Element appended successfully!\n";
                break;
            }

            case 3: {
                // Display
                if (size == 0) {
                    cout << "Array is empty.\n";
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < size; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    delete[] arr;
    return 0;
}
