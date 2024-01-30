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

void solve()
{
    int x, y, x2, y2, r, r2;
    cin >> x >> y >> r >> x2 >> y2 >> r2;
    double l = sqrt(pow(x-x2,2) + pow(y-y2,2));
    if (x == x2 && y == y2 && r == r2) cout << "-1\n";
    else if (r + r2 == l || abs(r - r2) == l) cout << "1\n";
    else if (r + r2 > l && abs(r - r2) < l) cout << "2\n";
    else cout << "0\n";
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