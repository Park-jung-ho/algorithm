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
    int n, c, t;
    cin >> n;
    vector<int> a(n+1);
    int res = 0;
    t = n;
    while (t--)
    {
        cin >> c;
        a[c] = a[c-1] + 1;
        res = max(res,a[c]);
    }
    cout << n - res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}   