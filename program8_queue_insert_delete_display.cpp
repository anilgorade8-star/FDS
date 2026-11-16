/*
 * Program 8: Linear Queue Implementation
 * Operations:
 *  1. INSERT (Enqueue)
 *  2. DELETE (Dequeue)
 *  3. DISPLAY
 */

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // 1. INSERT (Enqueue)
    void insert(int value) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue Overflow! Queue is full, cannot insert " << value << ".\n";
            return;
        }

        // If inserting the first element
        if (front == -1) {
            front = 0;
        }

        arr[++rear] = value;
        cout << "Successfully inserted " << value << " into the queue.\n";
    }

    // 2. DELETE (Dequeue)
    void deleteQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Queue is empty, nothing to delete.\n";
            return;
        }

        int deletedValue = arr[front++];
        cout << "Successfully deleted " << deletedValue << " from the queue.\n";

        // Reset pointers when all elements are deleted
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // 3. DISPLAY
    void display() const {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nQueue elements (Front to Rear):\n";
        cout << "[ ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i == front) cout << "(Front)";
            if (i == rear) cout << "(Rear)";
            if (i < rear) cout << ", ";
        }
        cout << " ]\n";
    }
};

int main() {
    Queue q;
    int choice;

    cout << "=== Queue Operations: INSERT, DELETE, DISPLAY ===\n";

    do {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                q.insert(val);
                break;
            }
            case 2:
                q.deleteQueue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting queue program.\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

