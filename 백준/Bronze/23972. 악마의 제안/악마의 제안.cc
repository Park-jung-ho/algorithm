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
    ll k, n;
    cin >> k >> n;
    if (n == 1)
    {
        cout << -1;
        return;
    }
    
    if ((k*n)%(n-1) != 0)
    {
        cout << (k*n)/(n-1) + 1;
    }
    else{
        cout << (k*n)/(n-1);
    }
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}