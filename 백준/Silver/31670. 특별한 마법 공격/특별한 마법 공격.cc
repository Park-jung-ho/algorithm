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
    int n, v;
    cin >> n;
    vector<int> a(n);
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    for (auto& c : a) cin >> c;
    dp[1][1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0] + a[i-1],dp[i-2][1] + a[i-1]);
        dp[i][1] = min(dp[i][1],dp[i-1][1] + a[i-1]);
    }

    cout << min(dp[n][0],dp[n][1]);
    
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}   