/*
 * Program 12: Singly Linked List (Three Nodes)
 * Objective: Create at least three nodes of a singly linked list,
 *            link them together, and display the data stored in each node.
 */

#include <iostream>
using namespace std;

// Definition of a Singly Linked List Node
struct Node {
    int data;
    Node* next;

    // Constructor for easy initialization
    Node(int val) : data(val), next(nullptr) {}
};

// Function to traverse and display all nodes in the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;
    int nodeIndex = 1;

    cout << "\n--- Linked List Node Details ---\n";
    while (temp != nullptr) {
        cout << "Node " << nodeIndex << ": [ Data: " << temp->data 
             << " | Next: " << temp->next << " ]\n";
        temp = temp->next;
        nodeIndex++;
    }

    // Visual representation
    cout << "\nVisual Representation:\nHead -> ";
    temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== Singly Linked List: Creation of At Least Three Nodes ===\n\n";

    int val1, val2, val3;
    cout << "Enter data value for Node 1: ";
    cin >> val1;
    cout << "Enter data value for Node 2: ";
    cin >> val2;
    cout << "Enter data value for Node 3: ";
    cin >> val3;

    // 1. Dynamic allocation of three nodes
    Node* first = new Node(val1);
    Node* second = new Node(val2);
    Node* third = new Node(val3);

    // 2. Linking the three nodes together
    first->next = second;  // Node 1 points to Node 2
    second->next = third;  // Node 2 points to Node 3
    third->next = nullptr; // Node 3 is the last node, pointing to NULL

    Node* head = first;    // Head points to the first node

    cout << "\nSuccessfully created and linked 3 nodes!\n";

    // 3. Display data stored in each node
    displayList(head);

    // Clean up allocated memory
    delete first;
    delete second;
    delete third;

    return 0;
}

