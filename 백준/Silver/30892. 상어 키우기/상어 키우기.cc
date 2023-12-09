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
    ll t;
    cin >> n >> k >> t;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(all(arr));
    stack<ll> s;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < t)
        {
            s.push(arr[i]);
            continue;
        }
        while (!s.empty() && k > 0 && arr[i] >= t)
        {
            t += s.top();
            s.pop();
            k--;
        }
        if (arr[i] < t)
        {
            s.push(arr[i]);
        }
        else
        {
            break;
        }
    }
    if (k > 0)
    {
        while (!s.empty() && k > 0)
        {
            t += s.top();
            s.pop();
            k--;
        }
    }
    cout << t << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}