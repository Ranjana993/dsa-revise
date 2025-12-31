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
};

void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "  ";
    temp = temp->next;
  }
}

Node *reverseNode(Node *&head)
{
  if (head == NULL)
  {
    cout << "LL is empty .";
    return NULL;
  }
  if (head->next == NULL)
  {
    return head;
  }
  Node *prev = NULL;
  Node *curr = head;
  Node *nextNode = curr->next;
  while (curr != NULL)
  {
    nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
}

Node *addTwoNumbes(Node *&head1, Node *&head2)
{
  // phle reverse kiya jayega...
  head1 = reverseNode(head1);
  head2 = reverseNode(head2);

  // uske baad add kiya jayega...
  Node *ansHead = NULL;
  Node *ansTail = NULL;
  int carry = 0;
  while (head1 != NULL && head2 != NULL)
  {
    int sum = carry + head1->data + head2->data;
    int digit = sum % 10;
    carry = sum / 10;
    Node *newNode = new Node(digit);
    if (ansHead == NULL)
    {
      ansHead = newNode;
      ansTail = newNode;
    }
    else
    {
      ansTail->next = newNode;
      ansTail = ansTail->next;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  while (head1 != NULL)
  {
    int sum = carry + head1->data;
    int digit = sum % 10;
    carry = sum / 10;
    Node *newNode = new Node(digit);
    ansTail->next = newNode;
    ansTail = ansTail->next;
    head1 = head1->next;
  }
  while (head2 != NULL)
  {
    int sum = carry + head2->data;
    int digit = sum % 10;
    carry = sum / 10;
    Node *newNode = new Node(digit);
    ansTail->next = newNode;
    ansTail = ansTail->next;
    head2 = head2->next;
  }
  if (carry != 0)
  {
    Node *newNode = new Node(carry);
    ansTail->next = newNode;
    ansTail = ansTail->next;
  }

  //  uske baad answer ko reverse kr k bhej dia jayega ...
  ansHead = reverseNode(ansHead);
  return ansHead;
}

int main()
{
  Node *first1 = new Node(2);
  Node *second1 = new Node(3);
  Node *third1 = new Node(4);
  Node *fourth1 = new Node(5);
  Node *fifth1 = new Node(7);

  first1->next = second1;
  second1->next = third1;
  third1->next = fourth1;
  fourth1->next = fifth1;
  fifth1->next = NULL;

  // SECOND NODE...
  Node *first2 = new Node(5);
  Node *second2 = new Node(6);
  Node *third2 = new Node(4);
  Node *fourth2 = new Node(3);
  Node *fifth2 = new Node(7);

  first2->next = second2;
  second2->next = third2;
  third2->next = fourth2;
  fourth2->next = fifth2;
  fifth2->next = NULL;

  Node *head1 = first1;
  Node *head2 = first2;
  print(head1);
  cout << endl;
  print(head2);
  cout << endl;
  Node *newHead = addTwoNumbes(head1, head2);
  print(newHead);

  return 0;
}