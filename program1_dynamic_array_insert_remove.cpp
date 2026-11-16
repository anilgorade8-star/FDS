/*
 * Program 1: Dynamic Array Operations
 * Operations:
 *  1. Creation of Dynamic Array list
 *  2. Insert element in the list at a specified position
 *  3. Remove element from the list at a specified position
 */

#include <iostream>
using namespace std;

class DynamicArrayList {
private:
    int* arr;       // Pointer to dynamic array
    int capacity;   // Current maximum capacity
    int size;       // Current number of elements

    // Helper function to resize the array when full
    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        cout << "[Info] Array resized to capacity: " << capacity << "\n";
    }

public:
    // 1. Creation of Dynamic Array list
    DynamicArrayList(int initialCapacity = 5) {
        if (initialCapacity <= 0) {
            initialCapacity = 5;
        }
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
        cout << "Dynamic Array created with initial capacity: " << capacity << "\n";
    }

    // Destructor to free dynamically allocated memory
    ~DynamicArrayList() {
        delete[] arr;
    }

    // 2. Insert element at a specific index/position (0-based)
    void insertAt(int index, int element) {
        if (index < 0 || index > size) {
            cout << "Error: Invalid index " << index << "! Valid range is 0 to " << size << ".\n";
            return;
        }

        // Resize if array is full
        if (size == capacity) {
            resize(capacity * 2);
        }

        // Shift elements to the right
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        size++;
        cout << "Element " << element << " successfully inserted at index " << index << ".\n";
    }

    // 3. Remove element from a specific index/position (0-based)
    void removeAt(int index) {
        if (size == 0) {
            cout << "Error: List is empty. Cannot remove element.\n";
            return;
        }

        if (index < 0 || index >= size) {
            cout << "Error: Invalid index " << index << "! Valid range is 0 to " << (size - 1) << ".\n";
            return;
        }

        int removedVal = arr[index];

        // Shift elements to the left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        cout << "Element " << removedVal << " successfully removed from index " << index << ".\n";
    }

    // Display elements of the list
    void display() const {
        if (size == 0) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Current List Elements (" << size << "/" << capacity << "): [ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }

    int getSize() const {
        return size;
    }
};

int main() {
    int initialCap;
    cout << "=== Dynamic Array List Implementation ===\n";
    cout << "Enter initial capacity for dynamic array: ";
    cin >> initialCap;

    DynamicArrayList list(initialCap);

    int choice;
    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. Insert Element at Position\n";
        cout << "2. Remove Element from Position\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int index, value;
                cout << "Enter index (0 to " << list.getSize() << "): ";
                cin >> index;
                cout << "Enter element value to insert: ";
                cin >> value;
                list.insertAt(index, value);
                break;
            }
            case 2: {
                int index;
                cout << "Enter index to remove (0 to " << (list.getSize() - 1) << "): ";
                cin >> index;
                list.removeAt(index);
                break;
            }
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please select 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}

