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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n+1);
    for (auto& c : a) cin >> c;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        b[a[i]] = b[a[i]-1] + 1;
        res = max(res,b[a[i]]);
    }
    cout << n - res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}   