/*
 * Program 13: Singly Linked List Merge
 * Objective: Create two singly linked lists and merge them into a single list.
 *            Display the result after merging.
 */

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to append a node at the end of a linked list
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head, const string& listName) {
    cout << listName << ": ";
    if (head == nullptr) {
        cout << "Empty List\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to merge two linked lists into a single list (Concatenation)
// Appends list2 to list1 and returns the head of merged list
Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Link the last node of list 1 to the first node of list 2
    temp->next = head2;

    return head1;
}

// Helper to free all nodes in a list
void freeList(Node* head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    cout << "=== Merge Two Singly Linked Lists ===\n\n";

    int n1, n2, val;

    // Input for List 1
    cout << "Enter number of nodes for List 1: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Enter value for List 1, Node " << (i + 1) << ": ";
        cin >> val;
        insertEnd(list1, val);
    }

    // Input for List 2
    cout << "\nEnter number of nodes for List 2: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Enter value for List 2, Node " << (i + 1) << ": ";
        cin >> val;
        insertEnd(list2, val);
    }

    // Display individual lists before merge
    cout << "\n--- Before Merging ---\n";
    displayList(list1, "List 1");
    displayList(list2, "List 2");

    // Merge List 1 and List 2
    Node* mergedList = mergeLists(list1, list2);

    // Display result after merging
    cout << "\n--- After Merging into a Single List ---\n";
    displayList(mergedList, "Merged List");

    // Free allocated memory
    freeList(mergedList);

    return 0;
}

