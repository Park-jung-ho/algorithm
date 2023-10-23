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
    vector<ip> arr;
    vector<ip> ar;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ar.push_back({a,b});
    }
    sort(all(ar));
    for (int i = 0; i < n; i++)
    {
        int a = ar[i].first;
        int b = ar[i].second;
        if (arr.empty())
        {
            arr.push_back({a,b});
        }
        else{
            if (arr.back().second >= a)
            {
                arr.back().second = max(arr.back().second,b);
            }
            else{
                arr.push_back({a,b});
            }
        }
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res += abs(arr[i].first-arr[i].second);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}