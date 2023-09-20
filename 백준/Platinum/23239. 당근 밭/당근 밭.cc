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

ll w, h, l;
ll dot(ll x)
{
    ll cnt = 0;
    ll m = x;
    for (ll i = 1; i < x; i++)
    {
        while (i*i+m*m > x*x)
        {
            m--;
        }
        cnt += m;
    }
    return cnt;
}
ll ddot(ll x)
{
    ll cnt = 0;
    ll m = x+w;
    for (ll i = h+1; i < h+x; i++)
    {
        while (m > 0)
        {
            if (m*m + (i-h)*(i-h) <= (w+x)*(w+x) && (m-w)*(m-w)+i*i <= (h+x)*(h+x))
            {
                break;
            }
            
            m--;
        }
        cnt += m-w;
    }
    return cnt;
}
void solve()
{
    cin >> w >> h >> l;
    ll ans = dot(l)*3 + l*2;
    if (l - w > 0)
    {
        ans += l-w;
        ans += dot(l-w);
    }
    if (l - h > 0)
    {
        ans += l-h;
        ans += dot(l-h);
    }
    // debug(ans);

    if (l > w + h)
    {
        ans -= ddot(l - (w+h));
    }
    // debug(ans);
    
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}