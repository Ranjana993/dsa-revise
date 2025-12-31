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
  if (head == NULL)
  {
    return;
  }
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "  ";
    temp = temp->next;
  }
}

int getLen(Node *head)
{
  int len = 0;
  Node *&temp = head;
  while (temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  return len;
}

Node *removeDuplicates(Node *&head)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->next == NULL)
  {
    return head;
  }
  Node *curr = head;
  while (curr != NULL && curr->next != NULL)
  {
    if (curr->data == curr->next->data)
    {
      // Remove duplicate node
      Node *nodeToDelete = curr->next;
      curr->next = curr->next->next;
      delete nodeToDelete;
    }
    else
    {
      curr = curr->next;
    }
  }

  return head;
}

int main()
{
  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(40);
  Node *fourth = new Node(40);
  Node *fifth = new Node(60);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;
  Node *head = first;
  print(head);
  cout << endl;

  Node *newHead = removeDuplicates(head);
  print(newHead);

  return 0;
}