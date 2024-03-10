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
    auto op = [&](pair<string,int> x, pair<string,int> y)
    {
        if (x.second == y.second) return x.first < y.first;
        return x.second > y.second;
    };
    int n;
    cin >> n;
    map<string,int> m;
    
    while (n--)
    {
        string a;
        cin >> a;
        if (m.find(a) == m.end()) m[a] = 0;
        m[a]++;
    }
    vector<pair<string,int>> maps = {all(m)};
    sort(all(maps),op);
    cout << maps.begin()->first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}