/*
 * Program 5: Stack Implementation
 * Operations:
 *  1. PUSH
 *  2. POP
 *  3. DISPLAY
 */

#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Stack is initially empty
    }

    // 1. PUSH: Insert an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << " (Stack is full).\n";
            return;
        }
        arr[++top] = value;
        cout << "Successfully pushed " << value << " onto the stack.\n";
    }

    // 2. POP: Remove and return the top element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Stack is empty, nothing to pop.\n";
            return;
        }
        int poppedValue = arr[top--];
        cout << "Successfully popped " << poppedValue << " from the stack.\n";
    }

    // 3. DISPLAY: Display all elements in the stack from top to bottom
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

    cout << "=== Stack Operations: PUSH, POP, DISPLAY ===\n";

    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
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
                s.pop();
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

