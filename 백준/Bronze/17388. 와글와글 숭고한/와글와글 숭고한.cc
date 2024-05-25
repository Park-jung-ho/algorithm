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
    int a, b, c;
    int cnt = 0;
    cin >> a >> b >> c;
    if (a + b + c >= 100) cout << "OK";
    else if (a < b && a < c) cout << "Soongsil";
    else if (b < a && b < c) cout << "Korea";
    else if (c < a && c < b) cout << "Hanyang";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}