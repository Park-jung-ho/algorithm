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
    int n;
    string a;
    cin >> n >> a;
    a += '1';
    ll cnt = 0;
    ll res = 0;
    for (auto c : a)
    {
        if (c == '2')
        {
            cnt++;
        }
        else
        {
            for (ll i = 0; i < cnt; i++)
            {
                res += (cnt-i)*(i+1);
            }
            cnt = 0;
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}