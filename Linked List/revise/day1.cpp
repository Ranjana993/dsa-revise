#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;

	Node(){
		this->data = 0;
		this->next = NULL;
	}
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};


void print(Node* &head){
	Node* temp = head;
	while(temp !=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insertAtHead (Node* &head , Node* &tail , int data){
	if(head == NULL){
		Node* newNode = new Node(data);
		head = newNode;
		tail = newNode;
		return;
	}
	Node* newNode = new Node(data);
	newNode -> next = head;
	head = newNode;
	return;
}

void insertAtTail(Node* &head , Node* &tail , int data){
	if(head == NULL){
		Node* newNode = new Node(data);
		head = newNode;
		tail = newNode;
		return;
	}
	Node* newNode = new Node(data);
	tail->next = newNode;
	tail = newNode;
	return;
}


//  inserting at position
void insertAtPosition(Node* &head , Node* &tail , int position, int data){
	if(position == 1){
		insertAtHead(head , tail , data);
		return;
	}
	Node* temp = head;
	int count = 1;
	while(count < position-1){
		temp = temp->next;
		count++;
	}
	if(temp ->next == NULL){
		insertAtTail(head , tail , data);
		return;
	}
	Node* newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;

}

void deleteNode(Node* &head , Node* &tail , int position){
	if(position == 1){
		Node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
		return;
	}
	Node * curr = head;
	Node* prev = NULL;
	int count = 1;
	while( count < position){
		prev = curr ;
		curr = curr -> next;
		count++;
	}
	prev -> next = curr -> next;
	curr -> next = NULL;
	delete curr;

}


int main(){
	Node* first = new Node(10);
	Node* second = new Node(20);
	Node*third = new Node(30);
	Node* fourth = new Node(40);
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	cout << "Before Insertion : " << endl;
	print(first);
	cout <<"Inserting at head : " <<endl;
	insertAtHead(first , fourth , 90);
	cout <<endl;
	print(first);
	cout <<"Inserting at tail : " <<endl;
	insertAtTail(first , fourth , 100);
	cout <<endl;
	print(first);
	cout <<endl;
	cout <<"Inserting at position : " <<endl;
	insertAtPosition(first , fourth , 3 , 50);
	print(first);

	deleteNode(first , fourth , 3);
	cout <<endl;
	print(first);
	return  0;
}