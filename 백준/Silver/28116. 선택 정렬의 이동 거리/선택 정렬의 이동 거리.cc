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
    vector<int> arr(n+1);
    vector<int> chk(n+1);
    vector<int> cnt(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin >> arr[i];
        chk[arr[i]] = i;
    }
    for (int i = 1; i < n+1; i++)
    {
        int a = chk[arr[chk[i]]];
        int b = i;
        int c = a - b;
        if (c == 0) continue;
        cnt[a] += c;
        cnt[b] += c;
        swap(arr[a],arr[b]);
        swap(cnt[a],cnt[b]);
        swap(chk[arr[a]],chk[arr[b]]);
    }
    for (int i = 1; i < n+1; i++)
    {
        cout << cnt[i] << " ";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}