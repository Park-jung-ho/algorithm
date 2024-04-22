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
    string a;
    cin >> a;
    int x = 0;
    int y = 0;
    char last = ' ';
    for (auto c : a)
    {
        if (c != last)
        {
            last = c;
            if (c == '0') x++;
            else y++;
        }
    }
    if (x == 0 || y == 0) cout << 0;
    else cout << min(x,y);
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}