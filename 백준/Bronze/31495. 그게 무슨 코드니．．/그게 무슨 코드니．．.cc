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
    string a;
    getline(cin,a);
    string b = a.substr(1,a.size()-2);
    bool z = true;
    for (auto c : b)
    {
        if (c != ' ') z = false;
    }
    if (a[0] != '\"' || a[a.size()-1] != '\"' || z) cout << "CE";
    else cout << b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}