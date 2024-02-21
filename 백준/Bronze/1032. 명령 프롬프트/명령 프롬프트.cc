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
    int n;
    string a;
    string res;
    cin >> n >> res;
    
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        for (int k = 0; k < a.size(); k++)
        {
            if (a[k] != res[k]) res[k] = '?';
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