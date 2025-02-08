#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    vector<long long> prefiex_sum;

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        prefiex_sum.push_back(sum);
    }

    for (int i = prefiex_sum.size() - 1; i >= 0; i--)
    {
        cout << prefiex_sum[i] << " ";
    }

    return 0;
}