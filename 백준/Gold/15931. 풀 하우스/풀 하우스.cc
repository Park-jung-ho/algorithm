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
    n = 52 - n;
    int a = 0;
    debug(n);
    if (n > 36)
    {
        if (n < 39) a = 5;
        else if (n < 44) a = 6;
        else if (n < 48) a = 7;
        else a = 8;
    }
    else if (n > 26)
    {
        a = min(8,(n-26)/2);
        if ((n-26) % 2 == 1) a++;
    }
    int b = min(8,n/5);
    cout << a << " " << b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}