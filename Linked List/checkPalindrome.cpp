// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node*next;
    
    Node(){
        this->data = -1;
        this->next = NULL;
    }
    Node(int data ){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node * & head ){
    if (head == NULL){
        return ;
    }
    Node*  temp = head;
    while(temp != NULL){
        cout << temp ->data << "  ";
        temp = temp->next;
    }
}

int getLen(Node* head){
    int len = 0;
    Node* &temp = head;
    while(temp !=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

Node* reverInKGrp(Node* head , int k ){
    if(head == NULL){
        cout <<"LL is empty";
        return NULL;
    }
    if(head ->next == NULL){
        return head;
    }
    int len = getLen(head);
    if(k > len){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head ;
    Node* nextNode = curr ->next;
    int count = 0;
    while(count < k && curr != NULL){
        nextNode = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    if(nextNode != NULL){
        head->next = reverInKGrp(nextNode , k);    
    }
    
    return prev;
}

Node* reverseLL(Node* &head){
    if(head == NULL){
        return NULL;
    }
    if(head ->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr ->next;
    while(curr != NULL){
        nextNode = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


bool checkForPalindrome(Node* &head){
    if(head == NULL){
        return false;
    }
    if(head -> next == NULL){
        return true;
    }
    
    // geting middle node..
    Node* fast = head ;
    Node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast ->next;
            slow = slow ->next;
        }
    }
    
    // reversing from middle..
    Node* reverseLLKaHead = reverseLL(slow->next);
    slow ->next = reverseLLKaHead;
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
    
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(40);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);
    
    first->next = second;
    second->next = third;
    third ->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    Node* head = first ;
    print(head);
    cout << endl;
    // Node* newHead = reverInKGrp(head , 2);
    // print(newHead);
    // cout <<endl;
    cout << checkForPalindrome(head);
    

    return 0;
}