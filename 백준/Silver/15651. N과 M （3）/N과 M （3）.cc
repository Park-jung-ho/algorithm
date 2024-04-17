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

int n, m;

void pp(vector<int>& a)
{
    if (a.size() == m)
    {
        for (auto& c : a) cout << c << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        a.push_back(i+1);
        pp(a);
        a.pop_back();
    }
    
}

void solve()
{
    cin >> n >> m;
    vector<int> a;
    pp(a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}