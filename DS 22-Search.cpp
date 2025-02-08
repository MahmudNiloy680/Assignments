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
    int t;
    cin >> t;

    while (t--)
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

        int x;
        cin >> x;

        int count = 0;

        bool chk = false; 

        for (Node* i = head; i != NULL; i = i->next)
        {
            if (i->val == x)
            {
                chk = true;
                break;
            }
            count ++;
        }

        (chk) ? cout << count << endl: cout << -1 << endl;
    }

    return 0;
}