#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(a);
        sort(a.begin(), a.end());
        if (a == b)
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}