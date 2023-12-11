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
#include "DEBUG.h"
#else
#define debug(x...)
#endif

vector<int> fact(53);
vector<int> win(53);

ll pw(ll x, ll m)
{
    if(!m) return 1;
    ll tmp = pw(x,m/2);
    tmp = tmp*tmp%10007;
    if (m%2) return tmp*x%10007;
    return tmp;
}

ll com(ll x, ll r)
{
    return fact[x]*win[r]%10007*win[x-r]%10007;
}

void solve()
{
    int n;
    cin >> n;
    
    ll res = 0;
    win[4] = 13;
    fact[0] = 1;
    for (int i = 1; i < 53; i++)
    {
        fact[i] = fact[i-1]*i%10007;
    }
    win[52] = pw(fact[52],10005);
    for (int i = 51; i >= 0; i--)
    {
        win[i] = win[i+1]*(i+1)%10007;
    }

    if (n > 3 && n < 40)
    {
        res = 13*com(48,n-4)%10007;
        for (int i = 2; i <= n/4; i++)
        {
            if (i%2==0) res = (10007 + res - (com(13,i)*com(52-(4*i),n-(4*i)))%10007)%10007;
            if (i%2==1) res = (res + (com(13,i)*com(52-(4*i),n-(4*i)))%10007)%10007;
        }        
    }
    if (n > 39)
    {
        res = com(52,n);
    }
    
    
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}