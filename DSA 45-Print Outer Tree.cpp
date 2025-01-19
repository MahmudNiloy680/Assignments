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

void left_outer_tree(Node* root)
{
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
        return;
    }
    if(root->left != NULL)
    {
        left_outer_tree(root->left);
        cout << root->val << " ";
    }
    if(root->right != NULL && root->left == NULL)
    {
        left_outer_tree(root->right);
        cout << root->val << " ";
    }
}

void right_outer_tree(Node* root)
{
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
        return;
    }

    if(root->right != NULL)
    {
        cout << root->val << " ";
        right_outer_tree(root->right);
    }
    if(root->left != NULL && root->right == NULL)
    {
        cout << root->val << " ";
        right_outer_tree(root->left);  
    }
}

int main()
{
    Node* root = input_tree();
    if(root->left && root->right)
    {
        left_outer_tree(root->left);
        cout << root->val << " ";
        right_outer_tree(root->right);
    }
    else if(root->left)
    {
        left_outer_tree(root);
    }
    else if(root->right)
    {
        right_outer_tree(root);
    }
    else
    {
        cout << root->val;
    }
    return 0;
}