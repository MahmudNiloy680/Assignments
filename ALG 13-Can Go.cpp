#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
char wall = '#', room = '.';
bool vis[1005][1005];

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;



bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int8_t dfs(int si, int sj)
{
    vis[si][sj] = true;
    if (grid[si][sj] == room)
    {      
        return 1;
    }
    for(int i=0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj])
            if (grid[ci][cj] != wall)
                return dfs(ci,cj);
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
            if (grid[i][j] == room)
            {    
                si = i;
                sj = j;
            }
        }
    }

    memset(vis,false,sizeof(vis));
    int count = dfs(si,sj);
    
    cout << count << endl;
    return 0;
}