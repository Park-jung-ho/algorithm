#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    while (1)
    {
        double a;
        cin >> a;
        if (a == -1) break;
        cout << "Objects weighing " << a <<  " on Earth will weigh " << a*0.167 << " on the moon.\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(2);
    cout << fixed;
    solve();
}