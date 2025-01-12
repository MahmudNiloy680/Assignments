#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val ;
        Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class myStack
{
    public:
        vector<int> v;

        void push(int val)
        {
            v.push_back(val);
        }
        void pop()
        {
            if (!v.empty())
                v.pop_back();
        }
        int top()
        {
            return v.back();
        }
        int size()
        {
            return v.size();
        }
        bool empty()
        {
            return v.empty();
        }
};

class myQueue
{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz = 0;

        void push(int val)
        {
            sz++;
            Node* newNode = new Node(val);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }
        void pop()
        {
            sz--;
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            if (head == NULL)
            {
                tail = NULL;
            }
        }
        int front()
        {
            return head->val;
        }
        int back()
        {
            return tail->val;
        }
        int size()
        {
            return sz;
        }
        bool empty()
        {
            return head == NULL;
        }

};

int main()
{
    myStack A;
    myQueue B;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        A.push(val);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        B.push(val);
    }

    if(n != m)
    {
        cout << "NO";
    }
    else
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (A.top() != B.front())
            {
                flag = false;
                break;
            }
            A.pop();
            B.pop();
        }
        flag ? cout << "YES" : cout << "NO";
    }

    return 0;
}