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
    int cnt = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int v = a[i] - '0';
        if (v > 0)
        {
            cnt += v;
            x = i;
        }
    }
    sort(all(a),greater<char>());
    if (cnt%3 == 0 && a[a.size()-1] == '0')
    {
        cout << a;
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}