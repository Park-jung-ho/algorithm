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
    int mx = 0;
    cin >> n >> k;
    vector<int> arr(1000001);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mx = max(mx,b);
        arr[a]++;
        arr[b]--;
    }
    for (int i = 1; i <= mx; i++)
    {
        arr[i] += arr[i-1];
    }
    int a = 0;
    int b = 1;
    ll len = arr[0];

    while (1)
    {
        if (b > mx) break;
        if (len == k) break;
        if (len < k) len += arr[b++];
        if (len > k) len -= arr[a++];
    }

    if (b <= mx && a < b && len == k) cout << a << " " << b;
    else cout << "0 0";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}