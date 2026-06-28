#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data ){
        this->data = data ;
        this->next = NULL;
    }
};


// printing the linked list..
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp ->data << " ";
        temp = temp ->next;
    }
}
int getLen(Node* &head){
    int len = 0 ;
    Node* temp = head;
    while(temp != NULL){
        temp = temp ->next;
        len++;
    }
    return len;
}

// Insert at head of linked list ...
void insertAtHead(Node* &head ,Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return ;
    }
    Node* newNode = new Node(data);
    newNode ->next = head;
    head = newNode;
    return ;
}

// Inserting at the tail .
void insertAtTheTail(Node* &head , Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return ;
    }
    Node* newNode = new Node(data);
    tail ->next = newNode;
    tail = newNode;
    return ;
}

void insertAtPos(Node* &head , Node* &tail , int pos , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return ;
    }

    if(pos == 0 ){
        insertAtHead(head , tail , data);
        return ;
    }

    int len = getLen(head);
    if(pos > len){
        insertAtTheTail(head , tail , data);
        return ;
    }
    int count = 0;
    Node*temp = head ;
    while(count < pos-1){
        temp = temp ->next;
        count++;
    }
    Node* newNode = new Node(data);
    newNode ->next = temp ->next;
    temp ->next = newNode;
    return ;
}


void deleteNodeAtPos(Node* &head , Node* &tail , int pos){
    if(head == NULL){
        cout <<"Linked list is empty ";
        return ;
    }
    if(pos == 1){
        Node* temp = head ;
        head = head->next ;
        temp ->next = NULL;
        delete temp;
        return ;
    }
    Node * curr = head;
	Node* prev = NULL;
	int count = 1;
	while( count < pos){
		prev = curr ;
		curr = curr -> next;
		count++;
	}
	prev -> next = curr -> next;
	curr -> next = NULL;
	delete curr;
    return ;
}


Node* reverseLinkedList(Node* &head ) {
    if(head == NULL){
        cout << "The linked list is empty ." ;
        return head;
    }
    Node* prev = NULL;
    Node*curr = head ;
    Node* nextNode = curr ->next;
    while(curr != NULL){
        nextNode = curr ->next ;
        curr ->next  = prev;
        prev = curr ;
        curr = nextNode;
    }
    return prev;
}

Node* reverseLLbyKgrp(Node* &head , int k){
    if(head == NULL){
        cout <<"The linked list is empty .";
        return head;
    }
    int i = 0 ;
    Node* prev = NULL;
    Node* curr = head ;
    Node* nextNode = curr ->next;
    while(i < k ){
        nextNode = curr ->next ;
        curr ->next = prev ;
        prev = curr ;
        curr = nextNode;
        i++;
    }
    if(nextNode != NULL){
        head ->next = reverseLLbyKgrp(nextNode , k );
    }
    return prev;
}

Node* findMid(Node* &head ){
    if(head == NULL){
        cout <<"Head is empty ."<<endl;
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL) {
        fast = fast ->next;
        if(fast != NULL){
            fast = fast ->next ;
            slow = slow ->next;
        }
    }
    return slow;
}

bool checkCircular(Node* &head){
    if(head == NULL){
        cout <<"The linked list is empty .";
        return false ;
    }
    Node* fast = head;
    Node*slow = head;
    while(fast != NULL){
        fast = fast ->next ;
        if(fast != NULL){
            fast = fast ->next;
            slow = slow ->next;
        }
        if(fast == slow){
            return true;
        }
    }
    return false;
}


Node* firstNodeOfLoop(Node* &head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

void removeLoop(Node* &head){
    if(head == NULL){
        return;
    }
    Node* startLoop = firstNodeOfLoop(head);
    if(startLoop == NULL){
        return ;
    }
    Node* temp = startLoop;
    while(temp->next != startLoop) {
        temp = temp->next;
    }

    // Break the cycle
    temp->next = NULL;
}

//  check for the palindrom 
bool isPalindrome(Node* &head){
    if(head == NULL){
        return false;
    }
    if(head -> next == NULL){
        return true;
    }
    // find the mid 
    Node* fast = head ;
    Node* slow = head;
    while(fast != NULL){
        fast = fast ->next;
        if(fast != NULL){
            fast = fast ->next ;
            slow = slow ->next ;
        }
    }
    Node* midNode = slow ;
    // mid k aage ka linked list reverse ..
    Node * reversedNodeHead = reverseLinkedList(slow ->next);
    Node* temp1 = head;
    Node* temp2  = reversedNodeHead;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

Node* sort012(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head ;
    while(curr != NULL){
        if(curr -> data == 0 ){
            zeroTail ->next = curr;
            zeroTail = curr;
        }
        else if(curr -> data == 1 ){
            oneTail ->next = curr;
            oneTail = curr;
        }
        else{
            twoTail ->next = curr;
            twoTail = curr;
        }
        curr = curr ->next;
    }
    if(oneHead -> next != NULL){
        zeroTail ->next =  oneHead ->next ;
    }
    else{
        zeroTail ->next = twoHead ->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // New head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}

Node* removeDuplicateFromSortedLL(Node* &head){
    if(head == NULL){
        return head;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){

        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }

    return head;
}


int main(){
    //  creating linked list
    Node* first = new Node(0);
    Node* second = new Node(2);
    Node* third  = new Node(2);
    Node* fourth = new Node(1);
    Node* fifth = new Node(0);

    first -> next = second ;
    second ->next = third;
    third ->next = fourth;
    fourth ->next = fifth;
    fifth -> next = NULL;

    Node* head = first;
    Node* tail = fifth;


    // print Linked list
    cout <<"Printing the Linked list : " <<endl;
    print(head);
    cout <<endl;

    // insert at head 
    // insertAtHead(head , tail , 100);
    // cout <<"Inserting the data at head :"<<endl;
    // print(head);

    // insert at the tail 
    // cout <<"Inserting the data at tail :" <<endl;
    // insertAtTheTail(head , tail , 1000);
    // print(head);


    //  insert at a given position 
    // cout <<"Inserting at the given position : "<<endl;
    // insertAtPos(head , tail , 2, 1000);
    // print(head);
    // cout <<endl;

    //  delete node from the linked list 
    // deleteNodeAtPos(head , tail , 1);
    // print(head);


    // reverse a linked list .
    // head = reverseLinkedList(head);
    // cout << "Reverseing the Linked List : "<<endl;
    // print(head);


    // reversing the Linked list in K grp .
    // head = reverseLLbyKgrp(head , 2);
    // cout <<"Reversing the linked list in k grp :"<<endl;
    // print(head);

    // find the middle of linked list ...
    // cout << "The middle Node of the linked list is : " <<findMid(head)->data <<endl;

    // check if the LInked list is circular or not 
    // cout << "Circular or not : " << checkCircular(head);
    // cout <<"The first Node of circular LL :" <<firstNodeOfLoop(head)->data <<endl;
    // check if the LInked list is circular or not 
    // cout << "Circular or not : " << checkCircular(head) <<endl;
    // cout <<"Removed loops after printing :"<<endl;
    // removeLoop(head);
    // cout << "Circular or not : " << checkCircular(head);
     
    // checck palindrome...
    // cout << isPalindrome(head);

    // sort 0s , 1s and 2s ...
    // head = sort012(head);
    // print(head);

    head = removeDuplicateFromSortedLL(head);
    print(head);




    return 0;
}