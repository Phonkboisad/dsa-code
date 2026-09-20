Code of linked lists: 
Using structure: 
#include <iostream> 
using namespace std; 
/* 
Node Structure 
-------------- 
Each node contains: 
1. data -> stores the value 
2. next -> stores the address of the next node 
*/ 
struct Node 
{ 
int data; 
Node* next; 
}; 
/* 
INSERT AT START 
---------------- 
A new node is created and placed before the current first node. Example: 
Before: 
10 -> 20 -> 30 -> NULL 
Insert 5 at start: 
After: 
5 -> 10 -> 20 -> 30 -> NULL 
*/ 
void insertStart(Node*& head, int value) 
{ 
// Create a new node dynamically 
Node* newNode = new Node(); 
// Store the value in the new node 
newNode->data = value;
// New node points to the current first node newNode->next = head; 
// Head is updated to point to the new node head = newNode; 
} 
/* 
INSERT AT END 
-------------- 
A new node is added after the last node. Example: 
Before: 
10 -> 20 -> 30 -> NULL 
Insert 40 at end: 
After: 
10 -> 20 -> 30 -> 40 -> NULL 
*/ 
void insertEnd(Node*& head, int value) { 
// Create a new node 
Node* newNode = new Node(); 
// Store the value 
newNode->data = value; 
// Since this will be the last node, 
// its next pointer will be NULL 
newNode->next = NULL; 
// If the list is empty, 
// the new node becomes the first node if (head == NULL) 
{ 
head = newNode; 
return; 
} 
// Start from the first node
Node* temp = head; 
// Move temp until it reaches the last node while (temp->next != NULL) 
{ 
temp = temp->next; 
} 
// Connect the last node to the new node temp->next = newNode; 
} 
/* 
INSERT AT MIDDLE / SPECIFIC POSITION ------------------------------------- 
Inserts a new node at the given position. Position starts from 1. 
Example: 
Before: 
10 -> 20 -> 30 -> 40 -> NULL 
Insert 25 at position 3: 
After: 
10 -> 20 -> 25 -> 30 -> 40 -> NULL 
*/ 
void insertMiddle(Node*& head, int value, int position) { 
// If position is 1, insert at the beginning 
if (position == 1) 
{ 
insertStart(head, value); 
return; 
} 
// Create a new node 
Node* newNode = new Node(); 
// Store the value 
newNode->data = value;
// Start from the first node 
Node* temp = head; 
/* 
Move temp to the node just before 
the required position. 
For position 3: 
temp will stop at position 2. 
*/ 
for (int i = 1; i < position - 1 && temp != NULL; i++) { 
temp = temp->next; 
} 
// If temp becomes NULL, 
// the position does not exist 
if (temp == NULL) 
{ 
cout << "Invalid position!" << endl; 
// Delete the unused node 
delete newNode; 
return; 
} 
/* 
Connect the new node between temp 
and the next node. 
Before: 
temp -> next 
After: 
temp -> newNode -> next 
*/ 
newNode->next = temp->next; 
temp->next = newNode; 
} 
/*
DELETE FROM START 
------------------ 
Removes the first node from the linked list. Example: 
Before: 
10 -> 20 -> 30 -> NULL 
After deleting from start: 
20 -> 30 -> NULL 
*/ 
void deleteStart(Node*& head) 
{ 
// Check if the list is empty 
if (head == NULL) 
{ 
cout << "List is empty!" << endl; 
return; 
} 
// Store the first node temporarily 
Node* temp = head; 
// Move head to the second node 
head = head->next; 
// Delete the old first node 
delete temp; 
} 
/* 
DELETE FROM END 
---------------- 
Removes the last node from the linked list. Example: 
Before: 
10 -> 20 -> 30 -> NULL 
After deleting from end: 
10 -> 20 -> NULL
*/ 
void deleteEnd(Node*& head) { 
// Check if the list is empty 
if (head == NULL) 
{ 
cout << "List is empty!" << endl; return; 
} 
// If there is only one node 
if (head->next == NULL) 
{ 
// Delete the only node 
delete head; 
// List becomes empty 
head = NULL; 
return; 
} 
// Start from the first node 
Node* temp = head; 
/* 
Move temp until it reaches 
the second-last node. 
Example: 
10 -> 20 -> 30 -> NULL 
^ 
last 
temp stops at 20. 
*/ 
while (temp->next->next != NULL) { 
temp = temp->next; 
} 
// Delete the last node 
delete temp->next;
// Make the second-last node the last node temp->next = NULL; 
} 
/* 
DELETE FROM MIDDLE / SPECIFIC POSITION --------------------------------------- 
Deletes a node from the given position. Example: 
Before: 
10 -> 20 -> 30 -> 40 -> NULL 
Delete position 3: 
After: 
10 -> 20 -> 40 -> NULL 
*/ 
void deleteMiddle(Node*& head, int position) { 
// Check if the list is empty 
if (head == NULL) 
{ 
cout << "List is empty!" << endl; 
return; 
} 
// If position is 1, 
// delete the first node 
if (position == 1) 
{ 
deleteStart(head); 
return; 
} 
// Start from the first node 
Node* temp = head; 
/* 
Move temp to the node just before 
the node that we want to delete.
For position 3: 
temp stops at position 2. 
*/ 
for (int i = 1; i < position - 1 && temp != NULL; i++) { 
temp = temp->next; 
} 
// Check whether the position is valid 
if (temp == NULL || temp->next == NULL) { 
cout << "Invalid position!" << endl; 
return; 
} 
// Store the node that needs to be deleted Node* deleteNode = temp->next; 
/* 
Skip the node to be deleted. 
Before: 
10 -> 20 -> 30 -> 40 
Delete 30: 
10 -> 20 ------> 40 
| 
X 
30 
*/ 
temp->next = deleteNode->next; 
// Free the memory of the deleted node 
delete deleteNode; 
} 
/* 
DISPLAY LINKED LIST 
------------------- 
Traverses the complete list and 
prints the value of every node.
*/ 
void display(Node* head) 
{ 
// Start from the first node 
Node* temp = head; 
// Continue until NULL is reached 
while (temp != NULL) 
{ 
cout << temp->data << " -> "; 
// Move to the next node 
temp = temp->next; 
} 
// NULL indicates the end of the linked list cout << "NULL" << endl; 
} 
/* 
MAIN FUNCTION 
------------- 
Demonstrates all linked-list operations. 
*/ 
int main() 
{ 
// Initially the linked list is empty 
Node* head = NULL; 
/* 
INSERT USING FOR LOOP 
--------------------- 
The user enters the number of nodes. 
A for loop is then used to insert 
each value at the end of the list. 
*/ 
int n; 
cout << "How many nodes do you want to insert? "; cin >> n; 
for (int i = 0; i < n; i++)
{ 
int value; 
cout << "Enter value " << i + 1 << ": "; cin >> value; 
// Insert each value at the end 
insertEnd(head, value); 
} 
// Display the original linked list 
cout << "\nOriginal Linked List: "; display(head); 
/* 
INSERT AT START 
---------------- 
Insert 10 before the current first node. */ 
insertStart(head, 10); 
cout << "After inserting 10 at start: "; display(head); 
/* 
INSERT AT MIDDLE 
----------------- 
Insert 20 at position 3. 
*/ 
insertMiddle(head, 20, 3); 
cout << "After inserting 20 at position 3: "; display(head); 
/* 
INSERT AT END 
-------------- 
Insert 30 after the current last node. */ 
insertEnd(head, 30);
cout << "After inserting 30 at end: "; display(head); 
/* 
DELETE FROM START 
------------------ 
Delete the first node. 
*/ 
deleteStart(head); 
cout << "After deleting from start: "; display(head); 
/* 
DELETE FROM MIDDLE 
------------------- 
Delete the node at position 3. 
*/ 
deleteMiddle(head, 3); 
cout << "After deleting from position 3: "; display(head); 
/* 
DELETE FROM END 
---------------- 
Delete the last node. 
*/ 
deleteEnd(head); 
cout << "After deleting from end: "; display(head); 
return 0; 
}
