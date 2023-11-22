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
    string a;
    int n;
    cin >> a >> n;
    int k = 0;
    vector<int> kmp(a.size());
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[k])
        {
            kmp[i] = ++k;
        }
        else if (k != 0)
        {
            k = kmp[k-1];
            i--;
        }
    }
    // debug(kmp[a.size()-1]);
    ll cnt = a.size() + (ll)(a.size()-kmp[a.size()-1])*(n-1);
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}