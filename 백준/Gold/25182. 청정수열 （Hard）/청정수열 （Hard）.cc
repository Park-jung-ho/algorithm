#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

int mod = 1000000007;

int modp(int x, int n)
{
    if (n == 0) return 1;
    ll u = modp(x, n/2);
    u = (u*u)%mod;
    if (n%2 == 1) u = (u*x)%mod;
    return u;
}

void solve()
{
    int n;
    cin >> n;
    
    ll cnt = 0;
    ll acnt = 0;
    ll x = 1;
    for (int i = 1; i < n+1; i++)
    {
        acnt = (acnt+(i*2))%mod;
        cnt = (cnt + (acnt * i)%mod) % mod;
        x = (x*i)%mod;
    }
    int rescnt = modp(x,2);
    cout << cnt << " " << rescnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}