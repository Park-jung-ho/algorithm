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
    int n, c;
    string a;
    cin >> n;
    vector<vector<string>> arr(201);
    while (n--)
    {
        cin >> c >> a;
        arr[c].push_back(a);
    }
    for (int i = 1; i < 201; i++)
    {
        for (auto s : arr[i])
        {
            cout << i << " " << s << "\n";
        }
    }
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}