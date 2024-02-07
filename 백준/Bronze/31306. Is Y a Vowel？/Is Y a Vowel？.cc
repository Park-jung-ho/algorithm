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
    string a, b;
    cin >> a;
    b = "aeiou";
    int cnt = 0;
    int y = 0;
    for (auto c : a)
    {
        if (c == 'y')
        {
            y++;
            continue;
        }
        for (auto k : b)
        {
            if (k == c) cnt++;
        }
    }
    cout << cnt << " " << cnt+y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}