#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        long long val ;
        Node *next;
    Node(long long val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, long long val)
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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    long long val;
    while(true)
    {
        cin >> val;
        
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    long long maximum = head->val;
    long long minimum = head->val;

    for (Node* i = head; i != NULL; i = i->next)
    {
        maximum = max(maximum, i->val);
        minimum = min(minimum, i->val);
    }

    cout << maximum - minimum << endl; 
    return 0;
}