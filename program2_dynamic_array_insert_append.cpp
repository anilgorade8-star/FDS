/*
 * Program 2: Dynamic Array Operations
 * Operations:
 *  1. Creation of Dynamic Array list
 *  2. Insert element in the list at a specified position
 *  3. Append element into the list (at the end)
 */

#include <iostream>
using namespace std;

class DynamicArrayList {
private:
    int* arr;       // Pointer to dynamically allocated array
    int capacity;   // Total capacity of the array
    int size;       // Number of current elements

    // Helper function to resize the array when full
    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        cout << "[Info] Array capacity resized to: " << capacity << "\n";
    }

public:
    // 1. Creation of Dynamic Array list
    DynamicArrayList(int initialCapacity = 4) {
        if (initialCapacity <= 0) {
            initialCapacity = 4;
        }
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
        cout << "Dynamic Array list created with capacity: " << capacity << "\n";
    }

    // Destructor to free allocated memory
    ~DynamicArrayList() {
        delete[] arr;
    }

    // 2. Insert element in the list at a specified index
    void insertAt(int index, int element) {
        if (index < 0 || index > size) {
            cout << "Error: Invalid index " << index << "! Valid range is 0 to " << size << ".\n";
            return;
        }

        if (size == capacity) {
            resize(capacity * 2);
        }

        // Shift elements to the right to make room
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        size++;
        cout << "Element " << element << " inserted at index " << index << ".\n";
    }

    // 3. Append element into the list (at the end)
    void append(int element) {
        if (size == capacity) {
            resize(capacity * 2);
        }

        arr[size] = element;
        size++;
        cout << "Element " << element << " appended at index " << (size - 1) << ".\n";
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
    cout << "=== Dynamic Array List: Insert & Append ===\n";
    cout << "Enter initial capacity of dynamic array: ";
    cin >> initialCap;

    DynamicArrayList list(initialCap);

    int choice;
    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. Insert Element at Specific Position\n";
        cout << "2. Append Element at End\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int index, value;
                cout << "Enter index (0 to " << list.getSize() << "): ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAt(index, value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to append: ";
                cin >> value;
                list.append(value);
                break;
            }
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

