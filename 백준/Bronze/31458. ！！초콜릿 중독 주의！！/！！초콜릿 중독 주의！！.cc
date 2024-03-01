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
    string a;
    cin >> a;
    bool r = true;
    int res = 1;
    for (int i = a.size()-1; i >= 0; i--)
    {
        if (a[i] == '!')
        {
            if (r)
            {
                res = 1;
            }
            else
            {
                res = res == 0 ? 1 : 0;
            }
        }
        else
        {
            if (i == a.size()-1) res = a[i] - '0';
            r = false;
        }
    }
    cout << res << "\n";   
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