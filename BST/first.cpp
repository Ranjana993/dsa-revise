#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *BST(Node *root, int data)
{
  // if root is null means first node to insert..
  if (root == NULL)
  {
    root = new Node(data);
    return root;
  }
  if (data > root->data)
  {
    // right call
    root->right = BST(root->right, data);
  }
  else
  {
    // left call
    root->left = BST(root->left, data);
  }
  return root;
}

void levelOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  queue<Node *> q;
  q.push(root);

  int level = 0;

  while (!q.empty())
  {
    int levelSize = q.size(); 
    cout << "Level " << level << ": ";

    for (int i = 0; i < levelSize; i++)
    {
      Node *temp = q.front();
      q.pop();

      cout << temp->data;

      // Add separator between nodes (not after last node)
      if (i < levelSize - 1)
        cout << " → ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }

    cout << endl;
    level++;
  }

  cout << "Total levels: " << level << endl;
}

Node *takeInput(Node *root)
{
  int data;
  cin >> data;
  while (data != -1)
  {
    root = BST(root, data);
    cin >> data;
  }
  return root;
}

int main()
{
  Node *root = NULL;
  cout << "Enter the data : " << endl;
  Node *newroot = takeInput(root);
  levelOrderTraversal(newroot);
  return 0;
}
