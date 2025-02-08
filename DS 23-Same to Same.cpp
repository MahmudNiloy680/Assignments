#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int val;
    Node* next;

    Node(int val) 
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, int val) 
{
    Node* newnode = new Node(val);
    if (head == NULL) 
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

bool is_equal(Node* head_1, Node* head_2) 
{
    while (head_1 != NULL && head_2 != NULL) 
    {
        if (head_1->val != head_2->val) 
        {
            return false;
            break;
        }
        head_1 = head_1->next;
        head_2 = head_2->next;
    }

    return (head_1 == NULL && head_2 == NULL);
}

int main()
{
    Node* head_1 = NULL;
    Node* tail_1 = NULL;
    Node* head_2 = NULL;
    Node* tail_2 = NULL;

    int val;
    while (cin >> val && val != -1) 
    {
        insert_at_tail(head_1, tail_1, val);
    }

    while (cin >> val && val != -1) 
    {
        insert_at_tail(head_2, tail_2, val);
    }

    if (is_equal(head_1, head_2)) 
    {
        cout << "YES" << endl;
    } 
    
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
