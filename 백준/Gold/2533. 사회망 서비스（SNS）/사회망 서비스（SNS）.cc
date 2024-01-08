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

vector<vector<int>> tree;
vector<int> visited;
vector<vector<int>> dp;

void dfs(int c)
{
    visited[c] = 1;
    dp[c][0] = 1;
    for (auto v : tree[c])
    {
        if (visited[v] == 1) continue;
        dfs(v);
        dp[c][1] += dp[v][0];
        dp[c][0] += min(dp[v][0],dp[v][1]);
    }
}

void solve()
{
    int n;
    cin >> n;
    
    tree.resize(n+1);
    visited.resize(n+1);
    dp.resize(n+1,vector<int>(2));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1);
    cout << min(dp[1][0],dp[1][1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}