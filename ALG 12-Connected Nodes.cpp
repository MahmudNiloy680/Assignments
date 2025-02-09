#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e, q;
    cin >> n >> e;
    vector<int> adj_list[n];

    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;

        if (!adj_list[x].empty())
        {    
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            for (int i : adj_list[x])
            {
                cout << i << " ";
            }
        }
        else
            cout << "-1";
        cout << endl;
    }
    return 0;
}