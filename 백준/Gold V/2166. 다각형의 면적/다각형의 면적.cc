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
    cin >> n;
    vector<lp> arr(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    arr[n] = arr[0];
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i].first * arr[i+1].second;
        res -= arr[i+1].first * arr[i].second;
        debug(res);
    }
    cout << abs(res)*0.5;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    solve();
}