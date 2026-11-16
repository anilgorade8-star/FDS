#include <iostream>
using namespace std;

int main() {
    int stack[100];
    int top = -1;
    int maxSize = 100;
    int choice;

    cout << "=== Stack Operations (PUSH, PEEK, DISPLAY) ===\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. PEEK\n";
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
                // (2) PEEK (View top element without removing)
                if (top == -1) {
                    cout << "Stack is empty! Nothing to peek.\n";
                } else {
                    cout << "Top element is: " << stack[top] << "\n";
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
                        cout << stack[i] << "\n";
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
