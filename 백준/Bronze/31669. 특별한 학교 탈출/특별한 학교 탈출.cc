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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    for (int i = 0; i < m; i++)
    {
        bool can = true;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] == 'O') can = false;
        }
        if (can)
        {
            cout << i+1;
            return;
        }
    }
    cout << "ESCAPE FAILED";
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}