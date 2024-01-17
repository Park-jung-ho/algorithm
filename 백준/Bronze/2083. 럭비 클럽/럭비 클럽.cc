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

string a;
int b, c;

void solve()
{
    if (b > 17 || c > 79) cout << a << " Senior\n";
    else cout << a << " Junior\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        cin >> a >> b >> c;
        if (a == "#" && b == 0 && c == 0) return 0;
        solve();
    }
    
}