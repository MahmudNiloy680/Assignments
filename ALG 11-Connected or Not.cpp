#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e, q;
    cin >> n >> e;
    int adj_mat [n][n];
    memset(adj_mat,0,sizeof(adj_mat));

    for(int i = 0; i < n ; i++)
    {
        adj_mat[i][i] = 1;
    }

    for(int i = 0; i < e; i++)
    {
        int a,b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (adj_mat[a][b] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}