#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
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

    int val;
    while(true)
    {
        cin >> val;
        
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    for (Node* i = head; i != NULL; i = i->next)
    {
        Node* prev = i;
        for (Node* j = i->next; j != NULL;)
        {
            if (i->val == j->val)
            {
                Node* tmp = j;
                prev->next = j->next;
                j = j->next;
                if (tmp == tail)
                {
                    tail = prev;
                }
                delete tmp;
            }
            else
            {
                prev = j;
                j = j->next;
            }
        }
    }

    print_linked_list(head);
    
    return 0;
}
