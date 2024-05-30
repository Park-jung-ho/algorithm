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
    int N, Q;
    cin >> N >> Q;
    if (N >= 3 && Q <= 4) cout << "TroyMartian\n";
    if (N <= 6 && Q >= 2) cout << "VladSaturnian\n";
    if (N <= 2 && Q <= 3) cout << "GraemeMercurian\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}