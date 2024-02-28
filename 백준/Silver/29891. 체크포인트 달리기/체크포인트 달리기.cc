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
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c < 0) b.push_back(-c);
        else a.push_back(c);
    }
    sort(all(a),greater<>());
    sort(all(b),greater<>());
    ll res = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (cnt == 0 || cnt == k)
        {
            cnt = 0;
            res += a[i]*2;
        }
        cnt++;
    }
    cnt = 0;
    for (int i = 0; i < b.size(); i++)
    {
         if (cnt == 0 || cnt == k)
        {
            cnt = 0;
            res += b[i]*2;
        }
        cnt++;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}