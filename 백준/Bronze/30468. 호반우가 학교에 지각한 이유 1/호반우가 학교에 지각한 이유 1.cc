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
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int ss, d, i, l, n;
    cin >> ss >> d >> i >> l >> n;
    cout << max(0,n*4 - (ss+d+i+l));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}