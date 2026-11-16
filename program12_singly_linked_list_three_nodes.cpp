#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "=== Singly Linked List: 3 Nodes Creation & Display ===\n";

    // 1. Create three nodes dynamically
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // 2. Accept data for each node
    cout << "Enter data for Node 1: ";
    cin >> first->data;

    cout << "Enter data for Node 2: ";
    cin >> second->data;

    cout << "Enter data for Node 3: ";
    cin >> third->data;

    // 3. Link the nodes together
    first->next = second;   // Node 1 points to Node 2
    second->next = third;   // Node 2 points to Node 3
    third->next = NULL;     // Node 3 points to NULL (end of list)

    Node* head = first;

    // 4. Display the data stored in each node directly in main
    cout << "\nDisplaying elements of the Linked List:\n";
    Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        cout << "Node " << count << " data: " << temp->data << "\n";
        temp = temp->next;
        count++;
    }

    cout << "\nList view: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Free memory
    delete first;
    delete second;
    delete third;

    return 0;
}
