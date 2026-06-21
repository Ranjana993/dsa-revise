#include <iostream>
using namespace std;


class Node{
    public:
    int data ;
    Node* next;

    Node(){
        this->data = 0 ;
        this->next = NULL;
    }
    Node(int data){
        this->data = data ;
        this->next = NULL;
    }
};



void print(Node* &head){
    Node* temp = head ;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
}


void insertAtHead(Node* &head , Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode ;
        tail = newNode ;
        return ;
    }
    Node *newNode = new Node(data);
    newNode ->next = head;
    head = newNode;

}


void insertAtTail(Node* &head , Node* &tail , int data ){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode ;
        tail = newNode ;
        return ;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int getLen(Node* &head ){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp ->next;
        len++;
    }
    return len;
}

void insertAtPosition(Node* &head , Node* &tail , int pos , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return ;
    }

    //insertting at the head
    if(pos == 1){
        insertAtHead(head , tail , data);
        return ;
    }

    //insertting at the tail
    int len = getLen(head);
    if(pos >= len){
        insertAtTail(head , tail , data);
        return ;
    }

    //  Inserting at the middle;
    Node* temp = head;
    int count = 1;

    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    
}


void deleteNode(Node*&head , Node* &tail , int pos){
    if(head == NULL){
        cout <<"Linked list is empty " <<endl;
        return; 
    }
    //  deleting the head node 
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return ;
    }
    // deleting the tail node
    int len = getLen(head);
    if(pos >= len){
        Node * prev = NULL;
        Node* curr = head;
        while(curr -> next != NULL){
            prev =curr ;
            curr = curr -> next;
        }
        tail = prev ;
        prev -> next = NULL;
        delete curr;
    }
    // deleteing the middle node
    Node* prev = NULL;
    Node* curr = head;
    int count = 1;
    while(count < pos){
        prev = curr;
        curr = curr -> next;
        count++;
    }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;

}

// reverse a linked list through loop
Node* reverseList(Node* &head){
    if(head == NULL || head ->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

}

Node* reverseListReccursion(Node* &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* newHead = reverseListReccursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node*forth = new Node(40);

    first -> next = second;
    second -> next = third;
    third -> next = forth;

    Node *head = first;
    Node* tail = forth;
    print(head);
    cout <<endl;
    // cout <<"Inserting at head " <<endl;
    // insertAtHead(head , tail , 5);
    // print(head);
    // cout<<endl;
    // cout <<"Inserting at tail " <<endl;
    // insertAtTail(head , tail , 50);
    // print(head);
    // cout<<endl;
    // cout <<"Inserting at the given position " << endl;
    // insertAtPosition(head , tail , 4, 100);
    // print(head);
    // cout<<endl;

    // reverse a linked list through loop
    cout <<"Reversing a linked list through loop " <<endl;
    head = reverseList(head);
    print(head);
    cout <<endl;

    cout <<"Reversing a linked list throgh the recursive approach " <<endl;
    head = reverseListReccursion(head);
    print(head);

    return  0;
}