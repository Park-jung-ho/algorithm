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
    vector<ip> arr(3);
    for (auto& a : arr) cin >> a.first >> a.second;
    int hp;
    cin >> hp;
    int t = 0;
    while (1)
    {
        for (auto& a : arr)
        {
            if (t % a.first == 0) hp -= a.second;
        }
        if (hp <= 0) break;
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