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
    string a = " WelcomeToSMUPC";
    int idx;
    cin >> idx;
    while (idx > 14)
    {
        idx -= 14;
    }
    
    
    cout << a[idx];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}