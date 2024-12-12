#include <iostream>
using namespace std;

struct Node {
    int data;           // Data part of the node
    Node* next;         // Pointer to the next node
};

Node* head = NULL;      // Head pointer for the linked list

// Function to insert a node at the end of the list
void insertAtEnd(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL; // Last node points to NULL

    if (head == NULL) {   // If the list is empty
        head = newNode;   // Make the new node the head
    } else {
        Node* temp = head; // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
    cout << "Inserted " << item << " at the end of the list.\n";
}

// Function to delete the first node of the list
void deleteFirst() {
    if (head == NULL) { // Check if the list is empty
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = head;   // Store the current head
    head = head->next;   // Move the head to the next node
    cout << "Deleted node with data: " << temp->data << "\n";
    delete temp;         // Free the memory of the deleted node
}

// Function to delete the last node of the list
void deleteLast() {
    if (head == NULL) {  // Check if the list is empty
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (head->next == NULL) { // If there's only one node
        cout << "Deleted node with data: " << head->data << "\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;       // Pointer to traverse the list
    Node* prev = NULL;       // Pointer to track the previous node
    while (temp->next != NULL) { // Traverse to the last node
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;       // Disconnect the last node
    cout << "Deleted node with data: " << temp->data << "\n";
    delete temp;             // Free the memory of the last node
}

// Function to delete a node at a specific position
void deleteAtPosition(int pos) {
    if (head == NULL) { // Check if the list is empty
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (pos == 1) {     // If the first node needs to be deleted
        deleteFirst();
        return;
    }
    Node* temp = head;  // Pointer to traverse the list
    Node* prev = NULL;  // Pointer to track the previous node
    int count = 1;      // Position counter

    while (temp != NULL && count < pos) { // Traverse to the specified position
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL) { // If the position is out of range
        cout << "Invalid position. No node to delete.\n";
        return;
    }
    prev->next = temp->next; // Update the link to skip the node
    cout << "Deleted node with data: " << temp->data << "\n";
    delete temp;             // Free the memory of the node
}

// Function to display the linked list
void display() {
    if (head == NULL) { // Check if the list is empty
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;  // Pointer to traverse the list
    cout << "Linked list: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to count the number of nodes in the list
void countNodes() {
    int count = 0;
    Node* temp = head;  // Pointer to traverse the list
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Total number of nodes: " << count << "\n";
}

int main() {
    int choice, item, pos;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Delete first node\n";
        cout << "3. Delete last node\n";
        cout << "4. Delete node at specific position\n";
        cout << "5. Display linked list\n";
        cout << "6. Count nodes\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> item;
                insertAtEnd(item);
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                deleteLast();
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                countNodes();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
