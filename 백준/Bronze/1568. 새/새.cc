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
    cin >> n;
    int k = 1;
    int cnt = 0;
    while (n > 0)
    {
        if (k > n)
        {
            k = 1;
        }
        n -= k;
        k++;

        cnt++;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}