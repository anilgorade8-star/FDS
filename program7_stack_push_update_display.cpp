/*
 * Program 7: Stack Implementation
 * Operations:
 *  1. PUSH
 *  2. UPDATE (Modify an existing element in the stack)
 *  3. DISPLAY
 */

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Stack is initially empty
    }

    // 1. PUSH: Push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << "Successfully pushed " << value << " onto the stack.\n";
    }

    // 2. UPDATE: Change the value of an element at a given position from the top (1-based position)
    // Position 1 represents the top of the stack, Position 2 is the element below top, etc.
    void update(int position, int newValue) {
        if (top < 0) {
            cout << "Stack Underflow! Stack is empty, nothing to update.\n";
            return;
        }

        int targetIndex = top - position + 1;

        if (targetIndex < 0 || targetIndex > top) {
            cout << "Error: Invalid position " << position << "! Valid positions are 1 to " << (top + 1) << ".\n";
            return;
        }

        int oldValue = arr[targetIndex];
        arr[targetIndex] = newValue;
        cout << "Element at position " << position << " from top updated from " 
             << oldValue << " to " << newValue << " (at index " << targetIndex << ").\n";
    }

    // 3. DISPLAY: Display all stack elements from top to bottom
    void display() const {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nStack elements (Top to Bottom):\n";
        cout << "Position\tValue\n";
        cout << "-----------------------\n";
        for (int i = top; i >= 0; i--) {
            int pos = top - i + 1;
            cout << pos << "\t\t" << arr[i];
            if (i == top) cout << "  <-- [TOP]";
            cout << "\n";
        }
    }

    int getCount() const {
        return top + 1;
    }
};

int main() {
    Stack s;
    int choice;

    cout << "=== Stack Operations: PUSH, UPDATE, DISPLAY ===\n";

    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. PUSH\n";
        cout << "2. UPDATE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            }
            case 2: {
                if (s.getCount() == 0) {
                    cout << "Stack is empty! Cannot update.\n";
                    break;
                }
                int pos, newVal;
                cout << "Enter position from top to update (1 to " << s.getCount() << "): ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> newVal;
                s.update(pos, newVal);
                break;
            }
            case 3:
                s.display();
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

