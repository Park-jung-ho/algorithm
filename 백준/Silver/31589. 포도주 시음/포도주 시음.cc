#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto& c : arr) cin >> c;
    sort(all(arr));
    ll res = arr[n-1];
    int l = 0;
    int r = n-2;
    k--;
    while (k > 1 && l < r)
    {
        res += arr[r] - arr[l];
        l++;
        r--;
        k-=2;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}