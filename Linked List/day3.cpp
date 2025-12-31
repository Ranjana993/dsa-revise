// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
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

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && slow != NULL)
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

Node *reverseKNode(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "The LL is empty .";
        return NULL;
    }
    if (head->next == NULL)
    {
        cout << "There is only one data in LL";
        return head;
    }
    int len = getLen(head);
    if (k > len)
    {
        // cout <<"Pls enter a valid number for K .";
        return head;
    }
    int count = 0;
    Node *prevNode = NULL;
    Node *curr = head;
    Node *nextNode = curr->next;
    while (count < k)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
        count++;
    }
    if (nextNode != NULL)
    {
        head->next = reverseKNode(nextNode, k);
    }
    return prevNode;
}

//  check for loop in LL:
bool findLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
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
            if (fast == slow)
            {
                return true;
            }
        }
    }
    return false;
}

// using hashmap
bool findLoopUsingMap(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return false;
    }
    Node *temp = head;
    map<Node *, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp])
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// starting point of loop :
Node *findLoopStart(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
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
            if (fast == slow)
            {
                slow = head;
                break;
            }
        }
    }
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// removing loop from LL :
Node *findAndRemoveLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
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
            if (fast == slow)
            {
                slow = head;
                break;
            }
        }
    }
    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
    return slow;
}

int main()
{
    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);
    Node *fourth = new Node(50);
    Node *fifth = new Node(60);
    Node *sixth = new Node(70);
    Node *seventh = new Node(80);
    Node *eighth = new Node(90);
    Node *ninth = new Node(100);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fourth;

    // print(head);
    // cout <<endl;

    // cout<<"The middle data is : "<< getMiddle(head) ->data << " . ";
    // cout <<endl;

    // head = reverseKNode(head , 4);
    // print(head);

    cout << "Checking for loop : " << findLoopUsingMap(head) << endl;
    cout << "Start of loop LL: " << findLoopStart(head)->data << " " << endl;
    findAndRemoveLoop(head);
    cout << endl;
    print(head);
    cout << endl;
    cout << "Checking for loop : " << findLoopUsingMap(head) << endl;

    return 0;
}