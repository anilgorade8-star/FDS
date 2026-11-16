#include <iostream>
using namespace std;

int main() {
    int queue[100];
    int front = -1;
    int rear = -1;
    int maxSize = 100;
    int choice;

    cout << "=== Queue Operations (INSERT, DELETE, DISPLAY) ===\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // (1) INSERT
                if (rear == maxSize - 1) {
                    cout << "Queue Overflow! Queue is full.\n";
                } else {
                    int val;
                    cout << "Enter value to insert: ";
                    cin >> val;
                    if (front == -1) {
                        front = 0;
                    }
                    rear++;
                    queue[rear] = val;
                    cout << val << " inserted into queue.\n";
                }
                break;
            }

            case 2: {
                // (2) DELETE
                if (front == -1 || front > rear) {
                    cout << "Queue Underflow! Queue is empty.\n";
                } else {
                    int deletedVal = queue[front];
                    front++;
                    cout << "Deleted element: " << deletedVal << "\n";

                    // Reset when empty
                    if (front > rear) {
                        front = -1;
                        rear = -1;
                    }
                }
                break;
            }

            case 3: {
                // (3) DISPLAY
                if (front == -1 || front > rear) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue elements: ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
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

    return 0;
}
