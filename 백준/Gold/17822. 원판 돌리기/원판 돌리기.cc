#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, m, t, x, D, k;
    cin >> n >> m >> t;
    vector<vector<int>> arr(n+1,vector<int>(m));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    while (t--)
    {
        cin >> x >> D >> k;

        if (D == 1) k = m - k;
        for (int i = x; i <= n; i+=x)
        {
            vector<int> tmp(m,0);
            for (int j = 0; j < m; j++)
            {
                int idx = (j + k)%m;
                tmp[idx] = arr[i][j];
            }
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = tmp[j];
            }
        }
        set<ip> rm;
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int v = arr[i][j];
                if (v == 0) continue;
                sum += v;
                cnt++;
                int l = j-1;
                int r = j+1;
                int u = i-1;
                int d = i+1;
                if (l < 0) l = m-1;
                if (r >= m) r = 0;
                if (arr[i][l] == v) rm.insert({i,j}), rm.insert({i,l});
                if (arr[i][r] == v) rm.insert({i,j}), rm.insert({i,r});
                if (u > 0 && arr[u][j] == v) rm.insert({i,j}), rm.insert({u,j});
                if (d <= n && arr[d][j] == v) rm.insert({i,j}), rm.insert({d,j});
            }
        }
        if (rm.empty())
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int v = arr[i][j];
                    if (v == 0) continue;
                    if (v > (double)sum/cnt) arr[i][j]--;
                    if (v < (double)sum/cnt) arr[i][j]++;
                }
            }
        }
        for (auto it = rm.begin(); it != rm.end(); it++)
        {
            arr[it->first][it->second] = 0;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res += arr[i][j];
        }
    }
    cout << res;
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}