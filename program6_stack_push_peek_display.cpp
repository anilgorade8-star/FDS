/*
 * Program 6: Stack Implementation
 * Operations:
 *  1. PUSH
 *  2. PEEK
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

    // 1. PUSH: Add an element to the top of the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << "Successfully pushed " << value << " onto the stack.\n";
    }

    // 2. PEEK: Return/View the top element without removing it
    void peek() const {
        if (top < 0) {
            cout << "Stack is empty! No element to peek.\n";
            return;
        }
        cout << "Top element (PEEK): " << arr[top] << " at index " << top << ".\n";
    }

    // Optional: Peek at an arbitrary position from the top (1-based)
    void peekAtPosition(int position) const {
        int index = top - position + 1;
        if (index < 0 || index > top) {
            cout << "Invalid position!\n";
            return;
        }
        cout << "Element at position " << position << " from top is: " << arr[index] << "\n";
    }

    // 3. DISPLAY: Display all elements in the stack
    void display() const {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nStack elements (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            if (i == top) {
                cout << arr[i] << " <-- [TOP]\n";
            } else {
                cout << arr[i] << "\n";
            }
        }
    }
};

int main() {
    Stack s;
    int choice;

    cout << "=== Stack Operations: PUSH, PEEK, DISPLAY ===\n";

    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. PUSH\n";
        cout << "2. PEEK (Top Element)\n";
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
            case 2:
                s.peek();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting stack program.\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

