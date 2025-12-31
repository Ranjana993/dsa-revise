// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    
    Node(){
        this ->data = data;
        this->next = NULL;
    }
    Node(int data ){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp ->data << "  ";
        temp = temp ->next;
    }
}

void sorting(Node* &head){
    Node* temp = head;
    int zero = 0 , one = 0 , twos = 0;
    // count kr lia hai 0s, 1s or 2s ko
    while(temp != NULL){
        if(temp ->data == 0) zero ++;
        else if(temp ->data == 1) one++;
        else if(temp->data == 2) twos++;
        temp = temp->next;
    }
    
    // fill krna hai ab data..
    temp = head;
    while(temp != NULL){
        while(zero--) {
            temp ->data = 0;
            temp = temp ->next;
        }
        while(one--) {
            temp ->data = 1;
            temp = temp ->next;
        }
        while(twos--) {
            temp ->data = 2;
            temp = temp ->next;
        }
    }
    
}


Node* sorting2(Node* &head){
    Node* zeroHead  = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node*oneHead = new Node(-1);
    Node*oneTail = oneHead;
    
    Node*twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    // seperating...
    Node* curr = head;
    while(curr != NULL){
        if(curr ->data == 0){
            zeroTail ->next = curr;
            zeroTail = zeroTail->next;
        }
        else if(curr ->data == 1){
            oneTail ->next = curr ;
            oneTail= oneTail->next;
        }
        else if(curr->data == 2){
            twoTail ->next = curr;
            twoTail = twoTail ->next;
        }
        curr = curr->next;
    }
    // ab connect kiya jayega yha pe bhaio aur beheno..
    if(oneHead ->next != NULL){
        zeroTail ->next = oneHead ->next;
        oneTail ->next = twoHead->next;
    }
    else{
        zeroTail ->next = twoHead->next;
    }
    twoTail ->next = NULL;
    
    // ab delete kiya jayega aur naya nodeHead bna k return kiya jayega bhaio aur beheno...
    
    Node * newHead = zeroHead ->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}




int main() {
    Node* first = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(2);
    Node* fifth = new Node(2);

    first ->next = second;
    second ->next =third;
    third ->next = fourth;
    fourth ->next = fifth;
    fifth->next = NULL;
    
    Node *head = first;
    print(head);
    cout <<endl;
    Node* newHead = sorting2(head);
    print(newHead);
    
    return 0;
}