#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data <<" ";
        temp = temp->next;
    }
}

Node* addTwoNumber(Node* first , Node* second){
    Node* ansHead = NULL;
    Node*ansTail = NULL;
    int carry = 0 ;

    while(first != NULL || second != NULL || carry != 0){
        int sum = carry ;
        if(first != NULL){
            sum += first->data;
            first = first -> next;
        }
        if(second != NULL){
            sum += second -> data;
            second = second ->next ;
        }
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);

        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }
    return ansHead;
}


int main(){
    // first number 342
    Node* first = new Node(2);
    Node*second = new Node(4);
    Node* third = new Node(3);
    first ->next = second;
    second->next = third;
    third ->next = NULL;

    //  second number 465
    Node* first1 = new Node(5);
    Node*second1 = new Node(6);
    Node* third1 = new Node(4);
    first1->next = second1;
    second1 -> next = third1;
    third1 -> next = NULL;

    cout<<"The first number is : "<<endl; 
    print(first);

    cout <<endl;
    cout<<"The second number is : "<<endl;
    print(first1);


    Node* ans = addTwoNumber(first , first1);
    cout <<"The sum is : " << endl;
    print(ans);



    return 0;
}