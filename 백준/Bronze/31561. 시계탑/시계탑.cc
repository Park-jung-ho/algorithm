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
    if (n <= 30) cout << (double)n/2;
    else cout << (double)(n-30)*((double)45/30)+15;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    solve();
}