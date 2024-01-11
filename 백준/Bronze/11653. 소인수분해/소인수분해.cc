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
    int n, mx;
    cin >> n;
    if (n == 1) return;
    mx = n;
    int c = 2;
    while (1)
    {
        if (n % c == 0)
        {
            n /= c;
            cout << c << "\n";
        }
        else
        {
            c++;
        }
        if (c == mx) break;
    }
    if (n > 1) cout << n << "\n";

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}