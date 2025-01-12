#include <bits/stdc++.h>
using namespace std;

bool eliminate(string s)
{
    stack<char> st;

    for (char c : s) 
    {
        if (!st.empty() && (st.top() == '0' && c == '1'))
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    return st.empty();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        eliminate(s) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}