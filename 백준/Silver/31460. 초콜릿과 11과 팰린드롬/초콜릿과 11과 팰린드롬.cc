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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    string a = "";
    for (int i = 0; i < n; i++) a += '2';
    if (n % 2 == 1)
    {
        a[0] = '1';
        a[n-1] = '1';
    }
    a += "\n";
    cout << a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}