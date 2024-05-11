#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int a, b, c, d;
    cin >> a >> b;
    c = (a+b)/2;
    d = a - c;
    if (a < b || c + d != a || abs(c-d) != b) cout << -1;
    else cout << max(c,d) << " " << min(c,d);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}