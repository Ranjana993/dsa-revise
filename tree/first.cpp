#include <iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node* right;
    
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* BuildTree(){
    int data;
    cout <<"Enter the root data "<<endl;
    cin>>data;
    
    if(data == -1) return NULL;
    
    Node* root = new Node(data);
    cout <<"Left side of "<< data <<" . ";
    root->left = BuildTree();
    
    cout <<"Right side of "<< data <<" . ";
    root->right = BuildTree();
    
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

int main() {
    Node * root = BuildTree();
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    return 0;
}