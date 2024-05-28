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
    int N, Q;
    cin >> N >> Q;
    set<int> a;
    while (Q--)
    {
        int t, x;
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            a.insert(x);
        }
        if (t == 2)
        {
            cin >> x;
            a.erase(x);
        }
        if (t == 3)
        {
            cout << N - a.size() << "\n";
        }
    }
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}