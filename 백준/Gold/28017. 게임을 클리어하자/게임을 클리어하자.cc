#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = arr[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (k == j) continue;
                if (dp[i][j] == 0) dp[i][j] = dp[i-1][k] + arr[i][j];
                dp[i][j] = min(dp[i][j],dp[i-1][k] + arr[i][j]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        if (res == 0) res = dp[n-1][i];
        res = min(res,dp[n-1][i]);
    }
    cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}