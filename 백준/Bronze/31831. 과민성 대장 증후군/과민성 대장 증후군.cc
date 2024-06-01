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
    vector<int> a(n+1);
    int cnt = 0;
    for (int i = 1; i < n+1; i++)
    {
        cin >> a[i];
        a[i] = max(0,a[i]+a[i-1]);
        if (a[i] >= m) cnt++;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}