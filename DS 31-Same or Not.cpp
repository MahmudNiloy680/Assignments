#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> A;
    queue<int> B;

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
        while(!A.empty() && !B.empty())
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