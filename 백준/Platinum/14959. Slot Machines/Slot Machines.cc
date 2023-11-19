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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> kmp(n);
    for (int i = n-1; i >= 0; i--)
    {
        cin >> arr[i];
    }
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[k])
        {
            kmp[i] = ++k;
        }
        else if (k != 0)
        {
            k = kmp[k-1];
            i--;
        }
    }
    // debug(kmp);
    ip res = {0,n};
    for (int i = n-1; i >= 0; i--)
    {
        if (res.first+res.second >= n-1-i + n-kmp[i]-(n-1-i))
        {
            res = {n-1-i,n-kmp[i]-(n-1-i)};
        }
        // debug(n-1-i,n-kmp[i]-(n-1-i));
    }
    cout << res.first << " " << res.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}