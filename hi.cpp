#include <iostream>
using namespace std;

// A node in the linked list.
struct Node {
    int data;
    Node* next;
};

// Insert a new node at the beginning of the list.
void insertStart(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert a new node at the end of the list.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert a new node at a given position.
void insertMiddle(Node*& head, int value, int position) {
    if (position == 1) {
        insertStart(head, value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove the first node from the list.
void deleteStart(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Remove the last node from the list.
void deleteEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Remove the node at a specific position.
void deleteMiddle(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        deleteStart(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}

// Display the entire list.
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int n;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertEnd(head, value);
    }

    cout << "\nOriginal Linked List: ";
    display(head);

    insertStart(head, 10);
    cout << "After inserting 10 at start: ";
    display(head);

    insertMiddle(head, 20, 3);
    cout << "After inserting 20 at position 3: ";
    display(head);

    insertEnd(head, 30);
    cout << "After inserting 30 at end: ";
    display(head);

    deleteStart(head);
    cout << "After deleting from start: ";
    display(head);

    deleteMiddle(head, 3);
    cout << "After deleting from position 3: ";
    display(head);

    deleteEnd(head);
    cout << "After deleting from end: ";
    display(head);

    return 0;
}
