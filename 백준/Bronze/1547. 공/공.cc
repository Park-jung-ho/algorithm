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
    int n;
    cin >> n;
    vector<int> arr(3);
    arr[0] = 1;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        swap(arr[a-1],arr[b-1]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == 1) cout << i+1;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}