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

Node *buildTreeInorderPostorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd)
{
  // Base case
  if (postIndex < 0 || inorderStart > inorderEnd)
  {
    return NULL;
  }

  // Get the current element from postorder (starting from end)
  int element = postorder[postIndex];
  postIndex--;

  Node *root = new Node(element);

  // Find position in inorder array
  int position = findPos(inorder, size, element);
  if (position == -1)
    return NULL;

  root->right = buildTreeInorderPostorder(inorder, postorder, size, postIndex, position + 1, inorderEnd);

  root->left = buildTreeInorderPostorder(inorder, postorder, size, postIndex, inorderStart, position - 1);

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
  q.push(NULL); // Marker for end of level

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    { // Level complete
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL); // Add marker for next level
      }
    }
    else
    {
      cout << temp->data << " ";

      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
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

  // TREE BY USING INORDER AND POSTORDER.....
  //   int inorder[] ={40,20,10,50, 30 , 60};
  //   int postorder[]={40,20,50,60,30,10};
  //   int size = 6;
  //   int postIndex = size - 1;
  //   int inorderStart = 0;
  //   int inorderEnd = size-1;
  //   Node*root =  buildTreeInorderPostorder(inorder , postorder , size, postIndex, inorderStart ,inorderEnd );

  //   levelOrderTraversal(root );
  return 0;
}