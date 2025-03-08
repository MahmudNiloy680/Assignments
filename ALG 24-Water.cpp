#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            a[i] = h;
            b[i] = h;
        }

        sort(b, b + n);

        int h1 = b[n - 1], h2 = b[n - 2];

        for (int i = 0; i < n; i++)
        {
            if (a[i] == h1 || a[i] == h2)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}