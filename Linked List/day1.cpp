// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    this->data = data;
    this->next = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  ~Node()
  {
    cout << "Node with value : " << this->data << " deleted ." << endl;
  }
};

void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node *newNode = new Node(data);
  newNode->next = head;
  if (head == NULL)
  {
    tail = newNode;
  }
  head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node *newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;
}
// Getting length....
int getLength(Node *&head)
{
  Node *temp = head;
  int len = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  return len;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // IF WE TRY TO INSERT AT HEAD I.E FIRST POSTION:
  if (pos == 0)
  {
    insertAtHead(head, tail, data);
    return;
  }
  // IF WE TRY TO INSERT AT TAIL I.E LAST POSTION:
  int len = getLength(head);
  if (pos >= len)
  {
    insertAtTail(head, tail, data);
    return;
  }
  int i = 1;
  Node *prev = head;
  while (i < pos)
  {
    prev = prev->next;
    i++;
  }
  Node *curr = prev->next;

  //  creating new node to insert in middle...
  Node *newNode = new Node(data);
  newNode->next = curr;
  prev->next = newNode;
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
  if (head == NULL)
  {
    cout << "Cannot be deleted .";
    return;
  }
  // first node ko delete krna hai yha ...
  if (pos == 1)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete (temp);
    return;
  }

  // last node ko delete krna hai yha ...
  int len = getLength(head);
  if (pos >= len)
  {
    int i = 1;
    Node *prev = head;
    while (i < pos - 1)
    {
      prev = prev->next;
      i++;
    }
    prev->next = NULL;
    Node *temp = tail;
    tail = prev;
    delete (temp);
    return;
  }

  // middle node ko delete krna hai yhaa.....
  int i = 1;
  Node *prev = head;
  while (i < pos - 1)
  {
    prev = prev->next;
    i++;
  }
  Node *currNode = prev->next;
  prev->next = currNode->next;
  currNode->next = NULL;
  delete (currNode);
}

int main()
{
  // Node* first = new Node(10);
  // Node* second = new Node(20);
  // Node* third = new Node(30);
  // Node* fourth = new Node(40);
  // first->next = second;
  // second->next=third;
  // third->next = fourth;
  // fourth ->next = NULL;
  // print(first);

  // ----INSERT AT HEAD ...

  Node *head = NULL;
  Node *tail = NULL;
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 50);
  // insertAtTail(head , tail , 55);
  insertAtPosition(head, tail, 1002, 4);
  print(head);
  cout << endl;
  deleteNode(head, tail, 3);
  print(head);
  cout << endl;

  return 0;
}