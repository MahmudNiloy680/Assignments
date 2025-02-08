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

void insert_at_head(Node* &head, Node* &tail, long long val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

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

void delete_node(Node* &head, Node* &tail, int idx)
{
    if (head == NULL) 
    {
        return;
    }

    if (idx == 0) 
    {
        Node* delete_node = head;
        head = head->next;
        if (head == NULL) 
        {
            tail = NULL;
        }
        delete delete_node;
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < idx; i++) 
    {
        if (tmp->next == NULL) 
        {
            return;
        }
        tmp = tmp->next;
    }

    if (tmp->next == NULL) 
    {
        return;
    }

    Node* delete_node = tmp->next;
    tmp->next = tmp->next->next;

    if (tmp->next == NULL) 
    {
        tail = tmp;
    }

    delete delete_node;
}

void print_linked_list(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        long long val;
        cin >> x >> val;
        if (x == 0)
        {
            insert_at_head(head, tail, val);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, val);
        }
        else if (x == 2)
        {
            delete_node(head, tail, val);
        }

        print_linked_list(head);
        cout << endl;
    }
    return 0;
}
