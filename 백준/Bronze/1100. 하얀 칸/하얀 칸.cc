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
    int res = 0;
    int c = 0;
    int cnt = 0;
    for (int i = 0; i < 64; i++)
    {
        char a;
        cin >> a;
        if (i%2==c && a == 'F') res++;
        cnt++;
        if (cnt == 8)
        {
            cnt = 0;
            c = c == 0 ? 1 : 0;
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}