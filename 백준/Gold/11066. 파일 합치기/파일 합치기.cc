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
#include "DEBUG.h"
#else
#define debug(x...)
#endif
int sum[501];
int dp[501][501];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sum[i+1];
        sum[i+1] += sum[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            dp[j][j+i] = INT_MAX;
            for (int k = j; k < j+i; k++)
            {
                dp[j][j+i] = min(dp[j][j+i],dp[j][k] + dp[k+1][j+i] + sum[j+i] - sum[j-1]);
            }
            // debug(j,j+i,dp[j][j+i]);
        }
    }
    cout << dp[1][n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}