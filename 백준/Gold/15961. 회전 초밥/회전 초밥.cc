#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;
#pragma GCC optimize("O3")
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> arr(n);
    vector<int> cnt(d+1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    set<int> eat;
    for (int i = 0; i < k; i++)
    {
        eat.insert(arr[i]);
        cnt[arr[i]]++;
    }
    
    int p = k;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int ns = eat.size();
        if (eat.find(c) == eat.end())
        {
            ns++;
        }
        mx = max(mx,ns);
        if (mx == k+1)
        {
            break;
        }
        cnt[arr[i]]--;
        if (cnt[arr[i]] == 0)
        {
            eat.erase(arr[i]);
        }
        eat.insert(arr[(i+k)%n]);
        cnt[arr[(i+k)%n]]++;
    }
    cout << mx;
    

    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}