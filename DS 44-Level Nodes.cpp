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

void printing_level_node(Node* root, int level)
{
    if(root == NULL)
    {
        return;
    }
    
    if(level == 0)
    {
        cout << root->val << " ";
        return;
    }

    printing_level_node(root->left, level - 1);
    printing_level_node(root->right, level - 1);
}

int max_high(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 0;
    int l = max_high(root->left);
    int r = max_high(root->right);
    return max(l, r) + 1;
}

int main()
{
    Node* root = input_tree();
    int level;
    cin >> level;
    if (max_high(root) < level)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        printing_level_node(root, level);
    }
    return 0;
}