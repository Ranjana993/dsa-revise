#include <iostream>
using namespace std;

// Node class for Singly Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Print Linked List
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Find Length of Linked List
int getLen(Node *&head)
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

// Reverse Complete Linked List
Node *reverseLL(Node *&head)
{

    // Empty List
    if (head == NULL)
    {
        return head;
    }

    // Single Node
    if (head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;

    while (curr != NULL)
    {

        // Store next node
        nextNode = curr->next;

        // Reverse link
        curr->next = prev;

        // Move pointers forward
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Reverse Linked List in Groups of K
Node *reverseLLinKgrp(Node *&head, int k)
{

    // Base Case
    if (head == NULL)
    {
        return head;
    }

    int len = getLen(head);

    // If k is greater than length, no reversal
    if (k > len)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;

    int count = 0;

    // Reverse first k nodes
    while (count < k && curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;

        count++;
    }

    // Recursive call for remaining nodes
    if (nextNode != NULL)
    {
        head->next = reverseLLinKgrp(nextNode, k);
    }

    return prev;
}

// Find Middle Node using Slow-Fast Pointer
Node *findMidNode(Node *&head)
{

    if (head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

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

// Detect Cycle using Floyd's Cycle Detection Algorithm
bool isCyclic(Node *head)
{

    // Empty List
    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        // Slow moves 1 step
        slow = slow->next;

        // Fast moves 2 steps
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast)
        {
            return true;
        }
    }

    // No cycle found
    return false;
}


Node* firstNodeOfLoop(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
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
void removeLoop(Node* head) {

    Node* startNode = firstNodeOfLoop(head);

    // No cycle present
    if(startNode == NULL) {
        return;
    }

    Node* temp = startNode;

    // Reach last node of cycle
    while(temp->next != startNode) {
        temp = temp->next;
    }

    // Break the cycle
    temp->next = NULL;
}

int main()
{

    // Creating Nodes
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    // Connecting Nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    // Print Linked List
    // print(first);

    // Reverse Complete Linked List
    // first = reverseLL(first);
    // print(first);

    // Reverse in K Groups
    // first = reverseLLinKgrp(first, 2);
    // print(first);

    // Find Middle Node
    // cout << "Middle Node: "
    //      << findMidNode(first)->data << endl;

    // Check Cycle
    cout << "Is Linked List Cyclic? " << isCyclic(first) << endl;
    cout << firstNodeOfLoop(first) ->data;
    removeLoop(first);
    cout <<endl;
    cout << "Is Linked List Cyclic? " << isCyclic(first) << endl;


    return 0;
}