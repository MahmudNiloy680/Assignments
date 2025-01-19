#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* input_tree()
{
    int val;
    cin >> val;

    Node* root = (val == -1) ? NULL : new Node(val);

    queue<Node*> q;
    if(root) 
        q.push(root);

    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *leftChild, *rightChild;

        leftChild = (l == -1) ? NULL : new Node(l);
        rightChild = (r == -1) ? NULL : new Node(r);

        parent->left = leftChild;
        parent->right = rightChild;

        if(parent->left)
            q.push(parent->left);
        
        if(parent->right)
            q.push(parent->right);

    }
    return root;
}

bool perfect_tree(Node* root)
{
    if(root == NULL)
        return true;
    
    if(root->left == NULL && root->right == NULL)
        return true;
    
    if(root->left == NULL || root->right == NULL)
        return false;
    
    return perfect_tree(root->left) && perfect_tree(root->right);
}

int main()
{
    Node* root = input_tree();
    (perfect_tree(root)) ? cout << "YES" : cout << "NO";
    return 0;
}