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
    this->data = -1;
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

Node *reverseLL(Node *&head)
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

int getLen(Node *&head)
{
  if (head == NULL)
  {
    return -1;
  }
  Node *temp = head;
  int len = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  return len;
}

Node *getMiddle(Node *&head)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->next == NULL)
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

Node *reverseLLInKGrp(Node *&head, int k)
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
  int len = getLen(head);
  if (k > len)
  {
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
    head->next = reverseLLInKGrp(nextNode, k);
  }
  return prev;
}

bool checkForCircular(Node *&head)
{
  if (head == NULL)
  {
    return false;
  }
  if (head->next == NULL)
  {
    return false;
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
    if (fast == slow)
    {
      return true;
    }
  }
  return false;
}

Node *startOfLoop(Node *&head)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->next == NULL)
  {
    return NULL;
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
    if (fast == slow)
    {
      slow = head;
      break;
    }
  }
  while (fast != slow)
  {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node *findLoopAndRemove(Node *&head)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->next == NULL)
  {
    return NULL;
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
    if (fast == slow)
    {
      slow = head;
      break;
    }
  }
  Node *temp = fast;
  while (fast != slow)
  {
    temp = fast;
    slow = slow->next;
    fast = fast->next;
  }
  fast->next = NULL;
  return slow;
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
  sixth->next = fourth;

  Node *head = first;
  Node *tail = fifth;

  // print(head);
  // cout <<endl;
  // Node* newHead = reverseLL(head);
  // print(newHead);
  // cout <<endl;
  // cout << getMiddle(head)->data;
  // Node* newHead = reverseLLInKGrp(head , 4);
  // print(newHead);

  cout << "ans :" << checkForCircular(head) << endl;
  cout << "Loop starts from : " << startOfLoop(head)->data << " ." << endl;
  cout << "Removing loops :" << findLoopAndRemove(head)->data << endl;
  cout << "ans :" << checkForCircular(head) << endl;
  return 0;
}