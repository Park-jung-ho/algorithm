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
    int n, m;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i+1];
    }
    cin >> m;
    int res = 0;
    while (m--)
    {
        int a;
        cin >> a;
        res += arr[a];
    }
    cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}