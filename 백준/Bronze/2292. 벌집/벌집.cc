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
    int cnt = 1;
    int t = 1;
    while (n > cnt)
    {
        cnt += t*6;
        t++;
    }
    cout << t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}