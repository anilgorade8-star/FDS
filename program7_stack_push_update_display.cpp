#include <iostream>
using namespace std;

int main() {
    int stack[100];
    int top = -1;
    int maxSize = 100;
    int choice;

    cout << "=== Stack Operations (PUSH, UPDATE, DISPLAY) ===\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. UPDATE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // (1) PUSH
                if (top == maxSize - 1) {
                    cout << "Stack Overflow! Stack is full.\n";
                } else {
                    int val;
                    cout << "Enter value to push: ";
                    cin >> val;
                    top++;
                    stack[top] = val;
                    cout << val << " pushed into stack.\n";
                }
                break;
            }

            case 2: {
                // (2) UPDATE
                if (top == -1) {
                    cout << "Stack is empty! Nothing to update.\n";
                } else {
                    int pos, newVal;
                    cout << "Enter position from top (1 to " << (top + 1) << "): ";
                    cin >> pos;

                    int index = top - pos + 1;
                    if (index < 0 || index > top) {
                        cout << "Invalid position!\n";
                    } else {
                        cout << "Enter new value: ";
                        cin >> newVal;
                        stack[index] = newVal;
                        cout << "Element at position " << pos << " updated successfully to " << newVal << ".\n";
                    }
                }
                break;
            }

            case 3: {
                // (3) DISPLAY
                if (top == -1) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack elements (top to bottom):\n";
                    for (int i = top; i >= 0; i--) {
                        cout << "Position " << (top - i + 1) << ": " << stack[i] << "\n";
                    }
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

    return 0;
}
