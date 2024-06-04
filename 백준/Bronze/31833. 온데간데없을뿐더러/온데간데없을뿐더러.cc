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
    string a = "";
    string b = "";
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        a += c;
    }
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        b += c;
    }
    ll x = stoll(a);
    ll y = stoll(b);
    cout << min(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}