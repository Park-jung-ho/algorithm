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
    string a;
    cin >> a;
    int k = 0;
    int mx = 0;
    vector<int> kmp(a.size());
    for (int x = 0; x < a.size(); x++)
    {
        k = 0;
        for (int i = 0; i < a.size(); i++) kmp[i] = 0;
        for (int i = x+1; i < a.size(); i++)
        {
            if (a[i] == a[k+x])
            {
                kmp[i] = ++k;
                mx = max(mx,kmp[i]);
            }
            else if (k != 0)
            {
                k = kmp[k+x-1];
                i--;
            }
        }
    }
    
    cout << mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}