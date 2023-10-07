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
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            return;
        }
        cout << a+b << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    solve();
}