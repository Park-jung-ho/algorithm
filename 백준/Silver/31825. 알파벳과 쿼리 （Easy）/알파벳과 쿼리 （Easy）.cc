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
    int n, q;
    string a;
    cin >> n >> q >> a;
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            char c = ' ';
            int cnt = 0;
            for (int i = l-1; i < r; i++)
            {
                if (a[i] != c)
                {
                    c = a[i];
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
        if (t == 2)
        {
            int cnt = 0;
            for (int i = l-1; i < r; i++)
            {
                if (a[i] == 'Z') a[i] = 'A';
                else a[i]++;
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}