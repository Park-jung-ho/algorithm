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
    int ta, tb, va, vb;
    cin >> ta >> tb >> va >> vb;
    int time = 0;
    int a = 0;
    int b = 0;
    while (1)
    {
        time++;
        if (b == 0)
        {
            if (vb > 0)
            {
                vb--;
                b = tb;
            }
            else if (va > 0)
            {
                va--;
                b = ta;
            }   
        }
        if (a == 0 && va > 0)
        {
            va--;
            a = ta;
        }
        a = max(0,a-1);
        b = max(0,b-1);
        if (va == 0 && vb == 0 && a == 0 && b == 0) break;
    }
    cout << time << "\n";
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