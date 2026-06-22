#include <iostream>
using namespace std;

// =====================================================
// Node Class
// =====================================================
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// =====================================================
// Print Linked List
// =====================================================
void print(Node*& head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// =====================================================
// Insert At Head
// =====================================================
void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// =====================================================
// Insert At Tail
// =====================================================
void insertAtTail(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// =====================================================
// Get Length of Linked List
// =====================================================
int getLen(Node*& head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    return len;
}

// =====================================================
// Insert At Given Position
// =====================================================
void insertAtPosition(Node*& head, Node*& tail, int pos, int data) {

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Insert at Head
    if (pos == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // Insert at Tail
    int len = getLen(head);

    if (pos >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in Middle
    Node* temp = head;
    int count = 1;

    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    Node* newNode = new Node(data);

    newNode->next = temp->next;
    temp->next = newNode;
}

// =====================================================
// Delete Node
// =====================================================
void deleteNode(Node*& head, Node*& tail, int pos) {

    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    // Delete Head Node
    if (pos == 1) {
        Node* temp = head;

        head = head->next;
        temp->next = NULL;

        delete temp;
        return;
    }

    // Delete Tail Node
    int len = getLen(head);

    if (pos >= len) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        tail = prev;
        prev->next = NULL;

        delete curr;
    }

    // Delete Middle Node
    Node* prev = NULL;
    Node* curr = head;

    int count = 1;

    while (count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

// =====================================================
// Reverse Linked List (Iterative Approach)
// =====================================================
Node* reverseList(Node*& head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {

        Node* nextnode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextnode;
    }

    return prev;
}

// =====================================================
// Reverse Linked List (Recursive Approach)
// =====================================================
Node* reverseListReccursion(Node*& head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseListReccursion(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// =====================================================
// Find Middle Node Using Fast & Slow Pointer
// =====================================================
Node* getMidNode(Node*& head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL) {

        fast = fast->next;

        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

// =====================================================
// Reverse the linked list in k grps 
// // =====================================================

Node* reverseLLinKGrp(Node* &head, int k) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    int len = getLen(head);

    if(k > len){
        cout << "Please enter a valid number." << endl;
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    int count = 0;

    while(curr != NULL && count < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;     // ← FIX
        count++;
    }

    if(nextNode != NULL){
        head->next = reverseLLinKGrp(nextNode, k);
    }

    return prev;
}




// =====================================================
// Driver Code
// =====================================================
int main() {

    // Creating Nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);

    // Connecting Nodes
    first->next = second;
    second->next = third;
    third->next = forth;

    // Head & Tail
    Node* head = first;
    Node* tail = forth;

    // Print Initial Linked List
    print(head);
    cout << endl;

    // =================================================
    // Insert At Head
    // =================================================
    /*
    cout << "Inserting at head" << endl;
    insertAtHead(head, tail, 5);
    print(head);
    cout << endl;
    */

    // =================================================
    // Insert At Tail
    // =================================================
    /*
    cout << "Inserting at tail" << endl;
    insertAtTail(head, tail, 50);
    print(head);
    cout << endl;
    */

    // =================================================
    // Insert At Given Position
    // =================================================
    /*
    cout << "Inserting at given position" << endl;
    insertAtPosition(head, tail, 4, 100);
    print(head);
    cout << endl;
    */

    // =================================================
    // Reverse Linked List (Iterative)
    // =================================================
    /*
    cout << "Reversing Linked List using Loop" << endl;

    head = reverseList(head);

    print(head);
    cout << endl;
    */

    // =================================================
    // Reverse Linked List (Recursive)
    // =================================================
    /*
    cout << "Reversing Linked List using Recursion" << endl;

    head = reverseListReccursion(head);
    head = reverseListReccursion(head);

    print(head);
    cout << endl;
    */

    // =================================================
    // Find Middle Node
    // =================================================
    // cout << "The middle of the Linked List is:" << endl;

    // head = getMidNode(head);

    // cout << "The mid is: " << head->data;
    // cout <<endl;

    // =================================================
    // Reverse the LL in k groups
    // =================================================

    cout <<"Reversing the LL by k grp " <<endl;
    head = reverseLLinKGrp(head , 2);
    print(head);
    return 0;
}