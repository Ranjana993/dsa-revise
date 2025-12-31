#include <iostream>
#include <queue>
using namespace std;

// Node creation
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

// Binary search tree  building...
Node *BST(Node *root, int data)
{
  if (root == NULL)
  {
    root = new Node(data);
    return root;
  }
  if (data > root->data)
  {
    root->right = BST(root->right, data);
  }
  else
  {
    root->left = BST(root->left, data);
  }
  return root;
}

// taking inputs..
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

// print level by level
void levelOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    cout << "Root is empty . " << endl;
    return;
  }
  queue<Node *> q;
  q.push(root);
  int level = 0;
  cout << "=======================================" << endl;
  while (!q.empty())
  {
    int n = q.size();
    cout << "Level " << level << ": ";
    for (int i = 0; i < n; i++)
    {
      Node *temp = q.front();
      q.pop();
      cout << temp->data;
      if (i < n - 1)
        cout << " -> ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    cout << endl;
    level++;
  }
  cout << "======================" << endl;
  cout << "Total levels: " << level << endl
       << endl;
}

// Binary search tree e.i searching element..
bool BSTSearch(Node *root, int target)
{
  if (root == NULL)
  {
    return false;
  }
  if (root->data == target)
  {
    return true;
  }
  else if (target > root->data)
  {
    return BSTSearch(root->right, target);
  }
  else
  {
    return BSTSearch(root->left, target);
  }
  return false;
}

// PRE ORDER TRAVERSAL ..
void preOrder(Node *root)
{
  // NLR
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// POST ORDER TRAVERSAL ..
void postOrder(Node *root)
{
  // LRN
  if (root == NULL)
    return;
  preOrder(root->left);
  preOrder(root->right);
  cout << root->data << " ";
}

// IN ORDER TRAVERSAL ..
void inOrder(Node *root)
{
  // LNR
  if (root == NULL)
    return;
  preOrder(root->left);
  cout << root->data << " ";
  preOrder(root->right);
}

// Finding minimum element..
int minElementBST(Node *root)
{
  Node *temp = root;
  if (temp == NULL)
    return 0;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}

// Finding maximum element..
int maxElementBST(Node *root)
{
  Node *temp = root;
  if (temp == NULL)
    return 0;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp->data;
}

Node *deleteNodeInBST(Node *root, int target)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->data == target)
  {
    // isi ko delete krna h
    // 4 cases
    if (root->left == NULL && root->right == NULL)
    {
      // leaf node delete root;
      return NULL;
    }
    else if (root->left == NULL && root->right != NULL)
    {
      Node *child = root->right;
      // delete root;
      return child;
    }
    else if (root->left != NULL && root->right == NULL)
    {
      Node *child = root->left;
      // delete root;
      return child;
    }
    else
    {
      // both child
      // find inorder predecessor inb left subtree
      int inorderPre = maxElementBST(root->left);
      // replace root->data value with inorder predecessor
      root->data = inorderPre;
      // delete inorder predecessor from left subtree
      root->left = deleteNodeInBST(root->left, inorderPre);
      return root;
    }
  }
  else if (target > root->data)
  {
    // right jana chahiye
    root->right = deleteNodeInBST(root->right, target);
  }
  else if (target < root->data)
  {
    // left jana chahioye
    root->left = deleteNodeInBST(root->left, target);
  }
  return root;
}

int main()
{
  cout << "Enter the data ";
  // 10 20 5 11 17 2 4 8 6 25 15 -1
  Node *root = NULL;
  Node *newroot = takeInput(root);
  levelOrderTraversal(newroot);
  if (BSTSearch(newroot, 25))
  {
    cout << "Found . " << endl;
  }
  else
  {
    cout << "Not found . " << endl;
  }
  cout << "IN order printing......." << endl;
  inOrder(newroot);
  cout << endl
       << endl;
  cout << "Pre order printing......." << endl;
  preOrder(newroot);
  cout << endl
       << endl;
  cout << "Post order printing......." << endl;
  postOrder(newroot);
  cout << endl
       << endl;
  cout << "The minimum element is : " << minElementBST(newroot) << endl
       << endl;
  cout << "The maximum element is : " << maxElementBST(newroot) << endl
       << endl;

  root = deleteNodeInBST(newroot, 11);
  levelOrderTraversal(root);

  return 0;
}