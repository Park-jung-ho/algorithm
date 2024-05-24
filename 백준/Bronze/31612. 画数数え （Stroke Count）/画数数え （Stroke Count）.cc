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
    int cnt = 0;


    cin >> n >> a;
    for (auto c : a)
    {
        if (c == 'j') cnt += 2;
        if (c == 'o') cnt += 1;
        if (c == 'i') cnt += 2;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}