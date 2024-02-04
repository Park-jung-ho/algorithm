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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    int last = 0;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > last) cnt++;
        else cnt = 1;
        last = arr[i];
        res += cnt;
    }
    cout << res;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}