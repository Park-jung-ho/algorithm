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
    int n, l;
    cin >> n >> l;
    int cnt = 0;
    int swp = -1;
    vector<ip> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr));
    for (int i = 0; i < n; i++)
    {
        int a = arr[i].first;
        int b = arr[i].second-1;
        if (a <= swp)
        {
            if (b > swp)
            {
                int na = b - swp;
                int c = na/l;
                if (na%l != 0) c++;
                cnt += c;
                swp += c * l;
            }
        }
        else
        {
            int na = b - a + 1;
            int c = na/l;
            if (na%l != 0) c++;
            cnt += c;
            swp = a + c * l - 1;
        }
    }

    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}