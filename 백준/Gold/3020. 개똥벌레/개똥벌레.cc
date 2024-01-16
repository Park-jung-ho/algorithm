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
    int n, h, a;
    cin >> n >> h;
    vector<int> arr(h+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i % 2 == 0)
        {
            arr[0]++;
            arr[a]--;
        }
        else
        {
            arr[h-a]++;
            arr[h]--;
        }
    }
    for (int i = 1; i <= h; i++)
    {
        arr[i] += arr[i-1];
    }
    int res = 100000000;
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        if (res == arr[i]) cnt++;
        if (res > arr[i])
        {
            res = arr[i];
            cnt = 1;
        }
    }
    cout << res << " " << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}