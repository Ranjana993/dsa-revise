#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len;
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    Node* newNode = new Node(data);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    Node* newNode = new Node(data);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node*& head, Node*& tail, int pos, int data) {

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    if (pos <= 1) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);

    if (pos > len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp = head;
    int i = 1;

    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    Node* curr = temp->next;

    Node* newNode = new Node(data);

    temp->next = newNode;
    newNode->prev = temp;

    newNode->next = curr;
    curr->prev = newNode;
}

void deleteNodeAtPosition(Node*& head, Node*& tail, int pos) {

    if (head == NULL) {
        cout << "Linked List is Empty" << endl;
        return;
    }

    int len = getLength(head);

    if (pos < 1 || pos > len) {
        cout << "Invalid Position" << endl;
        return;
    }

    // Delete first node
    if (pos == 1) {

        Node* temp = head;

        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        return;
    }

    Node* curr = head;
    int count = 1;

    while (count < pos) {
        curr = curr->next;
        count++;
    }

    // Delete last node
    if (curr == tail) {

        tail = curr->prev;
        tail->next = NULL;

        delete curr;
        return;
    }

    // Delete middle node
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
}

int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;

    Node* head = first;
    Node* tail = fourth;

    cout << "Original List: ";
    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 5);
    cout << "After Insert At Head: ";
    print(head);

    insertAtTail(head, tail, 50);
    cout << "After Insert At Tail: ";
    print(head);

    insertAtPosition(head, tail, 4, 25);
    cout << "After Insert At Position 4: ";
    print(head);

    deleteNodeAtPosition(head, tail, 4);
    cout << "After Delete Position 4: ";
    print(head);

    deleteNodeAtPosition(head, tail, 1);
    cout << "After Delete Head: ";
    print(head);

    deleteNodeAtPosition(head, tail, getLength(head));
    cout << "After Delete Tail: ";
    print(head);

    return 0;
}