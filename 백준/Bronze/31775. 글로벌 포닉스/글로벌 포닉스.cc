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
    vector<string> s(3);
    for (auto& a : s) cin >> a;
    int v[] = {0,0,0};
    for (auto& a : s)
    {
        if (a[0] == 'l') v[0]++;
        if (a[0] == 'k') v[1]++;
        if (a[0] == 'p') v[2]++;
    }
    if (v[0] > 0 && v[1] > 0 && v[2] > 0) cout << "GLOBAL";
    else cout << "PONIX";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}