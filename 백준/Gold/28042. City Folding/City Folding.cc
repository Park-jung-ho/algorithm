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
    ll n, p, h;
    cin >> n >> p >> h;
    n = pow(2,n);
    ll mh = h;
    
    vector<ll> res = {mh};
    while (mh > 1)
    {
        ll base = 2;
        while (base < mh)
        {
            base *= 2;
        }
        mh = base - mh + 1;
        res.push_back(mh);
    }
    // debug(res);
    ll now = 1;
    ll floor = 1;
    string ans = "";
    res.pop_back();
    while (!res.empty())
    {
        if (now == res.back())
        {
            if (p <= n/2)
            {
                ans += 'R';
            }
            else
            {
                ans += 'L';
                p -= n/2;
            }
            res.pop_back();
        }
        else
        {
            if (p <= n/2)
            {
                if (res.back() == floor*2-now+1)
                {
                    ans += 'L';
                    p = n/2-p+1;
                    now = res.back();
                    res.pop_back();
                }
                else
                {
                    ans += 'R';
                }
            }
            else
            {
                if (res.back() == floor*2-now+1)
                {
                    ans += 'R';
                    p = n-p+1;
                    now = res.back();
                    res.pop_back();
                }
                else
                {
                    ans += 'L';
                    p -= n/2;
                }
            }
        }
        n /= 2;
        floor *= 2;
        
        // debug(ans,n);
    }
    while (n > 1)
    {
        if (p <= n/2)
        {
            ans += 'R';
        }
        else
        {
            ans += 'L';
            p-= n/2;
        }
        n/=2;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}