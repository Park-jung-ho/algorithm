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
    int a, b;
    cin >> a >> b;
    a += b;
    string c = to_string(a);
    cout << c.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}