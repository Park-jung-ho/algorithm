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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << "\n";
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}