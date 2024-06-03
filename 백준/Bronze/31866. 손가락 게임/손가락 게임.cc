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
    int a, b;
    cin >> a >> b;
    
    if (a == 0)
    {
        if (b == 5) cout << "<";
        else if (b == 0) cout << "=";
        else cout << ">";
    }
    else if (a == 2)
    {
        if (b == 0) cout << "<";
        else if (b == 2) cout << "=";
        else cout << ">";
    }
    else if (a == 5)
    {
        if (b == 2) cout << "<";
        else if (b == 5) cout << "=";
        else cout << ">";
    }
    else
    {
        if (b == 0 || b == 2 || b == 5) cout << "<";
        else cout << "=";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}