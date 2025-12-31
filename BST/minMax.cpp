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

  cout << "\nLevel Order Traversal:" << endl;
  cout << "======================" << endl;

  int level = 0;

  while (!q.empty())
  {
    int levelSize = q.size(); // Number of nodes at current level
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

  cout << "======================" << endl;
  cout << "Total levels: " << level << endl
       << endl;
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

void preOrder(Node *root)
{
  // NLR.
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root)
{
  // LNR.
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node *root)
{
  // LRN.
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

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

int minVal(Node *root)
{
  Node *temp = root;
  if (temp == NULL)
  {
    return -1;
  }
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}

int maxVal(Node *root)
{
  Node *temp = root;
  if (temp == NULL)
  {
    return -1;
  }
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp->data;
}

int main()
{
  Node *root = NULL;
  cout << "Enter the data : " << endl;
  Node *newroot = takeInput(root);
  levelOrderTraversal(newroot);
  //   cout <<"in order traversal ....."<<endl;
  //   inOrder(newroot);
  //   cout<<endl;
  //   cout <<"preOrder traversal ...." <<endl;
  //   preOrder(newroot);
  //   cout<<endl;
  //   cout <<"Post order ..."<<endl;
  //   postOrder(newroot);

  //   cout <<endl;
  //   cout <<"=============================================="<<endl;
  cout << "Found or not : " << BSTSearch(newroot, 187) << endl;

  cout << "Min is : " << minVal(newroot) << endl;
  cout << "MAX is : " << maxVal(newroot);
  return 0;
}