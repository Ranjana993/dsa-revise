#include <iostream>
#include <queue>
#include <map>
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

Node *buildTree()
{
  int data;
  cout << "Enter the data ..";
  cin >> data;

  if (data == -1)
    return NULL;
  Node *root = new Node(data);

  cout << "Enter left child of " << data << ": ";
  root->left = buildTree();

  cout << "Enter right child of " << data << ": ";
  root->right = buildTree();
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
      ;
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    cout << endl;
    level++;
  }
}

void printTopview(Node *root)
{
  if (root == NULL)
    return;
  map<int, int> topView;
  queue<pair<Node *, int>> q;
  q.push(make_pair(root, 0));
  while (!q.empty())
  {
    pair<Node *, int> temp = q.front();
    q.pop();

    Node *firstNode = temp.first;
    int hd = temp.second;
    if (topView.find(hd) == topView.end())
    {
      topView[hd] = firstNode->data;
    }
    if (firstNode->left)
    {
      q.push(make_pair(firstNode->left, hd - 1));
    }
    if (firstNode->right)
    {
      q.push(make_pair(firstNode->right, hd + 1));
    }
  }
  for (auto it : topView)
  {
    cout << it.first << "  " << it.second << "  " << endl;
  }
}

void printBottomview(Node *root)
{
  if (root == NULL)
    return;
  map<int, int> topView;
  queue<pair<Node *, int>> q;
  q.push(make_pair(root, 0));
  while (!q.empty())
  {
    pair<Node *, int> temp = q.front();
    q.pop();

    Node *firstNode = temp.first;
    int hd = temp.second;
    topView[hd] = firstNode->data;
    if (firstNode->left)
    {
      q.push(make_pair(firstNode->left, hd - 1));
    }
    if (firstNode->right)
    {
      q.push(make_pair(firstNode->right, hd + 1));
    }
  }
  for (auto it : topView)
  {
    cout << it.first << "  " << it.second << "  " << endl;
  }
}

void leftView(Node *root, vector<int> &ans, int lvl)
{
  if (root == NULL)
    return;
  if (lvl == ans.size())
  {
    ans.push_back(root->data);
  }
  leftView(root->left, ans, lvl + 1);
  leftView(root->right, ans, lvl + 1);
}

void leftView(Node *root, vector<int> &ans, int lvl)
{
  if (root == NULL)
    return;
  if (lvl == ans.size())
  {
    ans.push_back(root->data);
  }
  leftView(root->right, ans, lvl + 1);
  leftView(root->left, ans, lvl + 1);
}

void leftBoundary(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right->NULL)
    return;
  cout << root->data << " "'; leftBoundary(root->left);
  leftBoundary(root->right);
}

void leafBoundary(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right->NULL)
  {
    cout << root->data << " "';
  }
  leftBoundary(root->left);
  leftBoundary(root->right);
}

void rightBoundary(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right->NULL)
    return;
  rightBoundary(root->right);
  rightBoundary(root->left);
  cout << root->data << " "';
}

void bounaryNode(Node *root)
{
  if (root == NULL)
    return;
  // A left boundary.
  leftBoundary(root->left);
  // leaf.
  leafBoundary(root);
  // right
  rightBoundary(root->right);
}

int main()
{
  // build tree...
  Node *root = buildTree();
  levelOrderTraversal(root);
  printTopview(root);
  return 0;
}