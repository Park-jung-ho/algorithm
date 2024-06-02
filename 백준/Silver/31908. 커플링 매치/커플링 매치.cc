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
    int N;
    cin >> N;
    string a, b;
    map<string,vector<string>> m;
    int cnt = 0;
    while (N--)
    {
        cin >> a >> b;
        if (b == "-") continue;
        if (m.find(b) == m.end()) m[b] = {};
        m[b].push_back(a);
        if (m[b].size() == 2) cnt++;
        if (m[b].size() == 3) cnt--;
    }
    cout << cnt << "\n";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (m[it->first].size() == 2)
        {
            for (auto name : m[it->first]) cout << name << " ";
            cout << "\n";
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}