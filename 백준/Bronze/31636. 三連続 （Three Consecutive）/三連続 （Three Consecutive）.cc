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
    string a;
    cin >> n >> a;
    bool can = false;
    for (int i = 0; i < n-2; i++)
    {
        if (a.substr(i,3) == "ooo")
        {
            can = true;
            break;
        }
    }
    if (can) cout << "Yes";
    else cout << "No";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}