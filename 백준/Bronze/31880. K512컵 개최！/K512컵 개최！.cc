#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

void solve()
{
    int n, m, a;
    cin >> n >> m;
    ll res = 0;
    while (n--)
    {
        cin >> a;
        res += a;
    }
    while (m--)
    {
        cin >> a;
        if (a > 0) res *= a;
    }
    cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}