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
    left = NULL;
    right = NULL;
  }
};

int findPos(int inorder[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (inorder[i] == element)
    {
      return i;
    }
  }
  return -1; // Element not found
}

Node *buildTreeInorderPreOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{
  if (preIndex >= size || inorderStart > inorderEnd)
  {
    return NULL;
  }

  int element = preorder[preIndex++];
  Node *root = new Node(element);
  int position = findPos(inorder, size, element);

  root->left = buildTreeInorderPreOrder(inorder, preorder, size, preIndex, inorderStart, position - 1);
  root->right = buildTreeInorderPreOrder(inorder, preorder, size, preIndex, position + 1, inorderEnd);
  return root;
}

void levelOrderTraversal(Node *root)
{
  if (root == NULL)
  { // Handle empty tree
    cout << "Tree is empty!" << endl;
    return;
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    cout << temp->data << " ";

    if (temp->left)
      q.push(temp->left);
    if (temp->right)
      q.push(temp->right);
  }
  cout << endl; // For better output formatting
}

int main()
{
  int inorder[] = {40, 20, 50, 10, 60, 30, 70};
  int preorder[] = {10, 20, 40, 50, 30, 60, 70};
  int size = 7;
  int preIndex = 0;
  int inorderStart = 0;
  int inorderEnd = size - 1;

  Node *root = buildTreeInorderPreOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);
  levelOrderTraversal(root);

  return 0;
}