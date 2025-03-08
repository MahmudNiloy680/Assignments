#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long w;
    Edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

long long dis[1005];
vector<Edge> edge_list;
int n, e;

bool cycle;

void bellman_ford()
{
    cycle = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b;
            long long w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
            if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }
    }

    for (auto ed : edge_list)
    {
        int a, b;
        long long w;
        a = ed.a;
        b = ed.b;
        w = ed.w;
        if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
        {
            cycle = true;
            return;
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;

    int s, t;
    cin >> s >> t;
    dis[s] = 0;

    bellman_ford();

    if (cycle)
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    while (t--)
    {
        int d;
        cin >> d;
        if (dis[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[d] << endl;
    }

    return 0;
}