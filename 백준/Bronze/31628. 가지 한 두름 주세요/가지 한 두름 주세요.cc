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
    vector<vector<string>> g(10,vector<string>(10));
    for (auto& a : g)
        for (auto& b : a)
            cin >> b;
    for (auto& a : g)
    {
        auto t = a[0];
        for (auto& b : a)
        {
            if (b != t)
            {
                t = b;
                break;
            }
        }
        if (t == a[0])
        {
            cout << 1;
            return;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        auto t = g[0][i];
        for (int j = 0; j < 10; j++)
        {
            if (g[j][i] != t)
            {
                t = g[j][i];
                break;
            }
        }
        if (t == g[0][i])
        {
            cout << 1;
            return;
        }
    }
    cout << 0;   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}