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

int N, M, K;

void solve()
{
    cin >> N >> M;
    int cnt = 0;
    while (N != M)
    {
        N++;
        cnt++;
        if (N >= 24)
        {
            N -= 24;
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}