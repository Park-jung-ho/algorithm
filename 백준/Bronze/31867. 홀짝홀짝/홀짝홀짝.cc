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
    string a;
    int b = 0;
    int d = 0;

    cin >> n >> a;
    for (auto c : a)
    {
        if ((c - '0') % 2 == 0) b++;
        else d++;
    }
    if (b > d) cout << 0;
    else if (b < d) cout << 1;
    else cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}