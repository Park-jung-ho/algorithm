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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    vector<int> cnt(3);
    for (int i = 0; i < m; i++)
    {
        cnt[arr[i]]++;
    }
    int t = 0;
    int idx = m-1;
    while (1)
    {
        int out = 0;
        if (cnt[1] + cnt[2] == 0) break;
        if (cnt[1] > 0)
        {
            cnt[1]--;
            out++;
        }
        if (cnt[2] > 0)
        {
            cnt[2]--;
            out++;
        }
        while (1)
        {
            if (out == 0) break;
            if (idx + 1 >= n) break;
            idx++;
            out--;
            cnt[arr[idx]]++;
        }
        t++;
    }
    cout << t;
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}