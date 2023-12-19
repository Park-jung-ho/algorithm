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

void solve()
{
    int n, a;
    cin >> n;
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            res = max(res,cnt);
        }
    }
    cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}