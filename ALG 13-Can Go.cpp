#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
char wall = '#', flr = '.';
bool vis[1005][1005];

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;

bool swtch = false;

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    if (grid[si][sj] == 'B')
    {    
        swtch = true;    
        return;
    }
    for(int i=0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj])
            if (grid[ci][cj] != wall)
                dfs(ci,cj);
    }
}

int main()
{
    cin >> n >> m;

    int si = -1, sj = -1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {    
                si = i;
                sj = j;
            }
        }
    }

    memset(vis,false,sizeof(vis));
    dfs(si,sj);
    
    (swtch) ? cout << "YES" : cout << "NO";
    return 0;
}