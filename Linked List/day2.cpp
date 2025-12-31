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
    this->data = 0;
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

int getLen(Node *&head)
{
  int len = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  return len;
}

Node *revereLL(Node *&head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL)
  {
    Node *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
}

Node *revereLLRecursion(Node *&head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *newHead = revereLLRecursion(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

// middle of LL:
Node *middleOfLL(Node *&head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *fast = head;
  Node *slow = head;
  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      fast = fast->next;
      slow = slow->next;
    }
  }
  return slow;
}

Node *reverseLLinKGrp(Node *head, int k)
{
  if (head == NULL)
  {
    cout << "LL is empty .";
    return head;
  }
  int len = getLen(head);
  if (k > len)
  {
    cout << "Pls enter valid value of k .";
    return head;
  }
  int count = 0;
  Node *prev = NULL;
  Node *curr = head;
  Node *nextNode = curr->next;
  while (count < k)
  {
    nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    count++;
  }
  if (nextNode != NULL)
  {
    head->next = reverseLLinKGrp(nextNode, k);
  }
  return prev;
}

int main()
{
  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);
  Node *fourth = new Node(40);
  Node *fifth = new Node(50);
  Node *sixth = new Node(60);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = NULL;
  Node *head = first;
  print(head);
  cout << endl;
  // Node* newHead = revereLLRecursion(head);
  // print(newHead);
  // Node* newHead  = middleOfLL(head);
  // cout<< newHead->data<< " ";
  Node *newHead = reverseLLinKGrp(head, 2);
  print(newHead);
  return 0;
}