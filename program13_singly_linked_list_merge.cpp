#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "=== Merge Two Singly Linked Lists ===\n\n";

    Node* head1 = NULL;
    Node* tail1 = NULL;
    int n1;
    cout << "Enter number of nodes for List 1: ";
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        Node* newNode = new Node();
        cout << "Enter data for List 1, Node " << (i + 1) << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;
    int n2;
    cout << "\nEnter number of nodes for List 2: ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        Node* newNode = new Node();
        cout << "Enter data for List 2, Node " << (i + 1) << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Display List 1
    cout << "\nList 1: ";
    Node* temp = head1;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Display List 2
    cout << "List 2: ";
    temp = head2;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Direct Merge: link tail of List 1 to head of List 2
    Node* mergedHead = NULL;
    if (head1 == NULL) {
        mergedHead = head2;
    } else {
        mergedHead = head1;
        tail1->next = head2;
    }

    // Display Merged List
    cout << "\nMerged List: ";
    temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Free memory
    temp = mergedHead;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
