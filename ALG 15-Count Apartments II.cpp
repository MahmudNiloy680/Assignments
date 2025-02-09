#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
char wall = '#';
bool vis[1005][1005];

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;
vector<int> room_size;

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;

    for(int i=0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj])
            if (grid[ci][cj] != wall)
                count += dfs(ci,cj);
    }
    return count;
}

int main()
{
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != wall && !vis[i][j])
            {
                int room_count = dfs(i,j);
                if (room_count > 0)
                {
                    room_size.push_back(room_count);
                }
            }
        }
    }

    if (!room_size.empty())
    {
        sort(room_size.begin(), room_size.end());
        
        for (int i : room_size)
        {
            cout << i << " ";
        }
    }
    else
        cout << 0;
    return 0;
}