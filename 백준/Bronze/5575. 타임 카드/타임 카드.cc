#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int a[3] = {0,};
    int b[3] = {0,};
    for (int i = 0; i < 3; i++)
    {
        int v[3] = {0,};
        for (auto& c : b) cin >> c;
        for (auto& c : a) cin >> c;
        v[2] = a[2] - b[2];
        if (v[2] < 0) v[2] += 60, a[1]--;
        v[1] = a[1] - b[1];
        if (v[1] < 0) v[1] += 60, a[0]--;
        v[0] = a[0] - b[0];
        for (auto& c : v) cout << c << " ";
        cout << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(2);
    cout << fixed;
    solve();
}