#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e;

    long long adj_mat[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        int a, b;
        long long w;
        
        cin >> a >> b >> w;
        adj_mat[a][b] = min(w, adj_mat[a][b]);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                    adj_mat[i][j] = min(adj_mat[i][k] + adj_mat[k][j], adj_mat[i][j]);
            }
        }
    }

    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (adj_mat[x][y] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << adj_mat[x][y] << "\n";
    }
    return 0;
}
