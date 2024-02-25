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
    int n;
    cin >> n;
    ip res[] = {{0,0},
                {12,1600},
                {11,894},
                {11,1327},
                {10,1311},
                {9,1004},
                {9,1178},
                {9,1357},
                {8,837},
                {7,1055},
                {6,556},
                {6,773}};
    cout << res[n].first << " " << res[n].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}