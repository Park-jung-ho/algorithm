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
    int n, m;
    cin >> n >> m;
    bool can = true;
    while (m--)
    {
        int t;
        cin >> t;
        int tmp = 99999999;
        while (t--)
        {
            int a;
            cin >> a;
            if (a > tmp)
            {
                can = false;
            }
            tmp = a;
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