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
    string a;
    cin >> n >> a;
    if (a == "miss")
    {
        cout << 0;
    }
    if (a == "bad")
    {
        cout << n*200;
    }
    if (a == "cool")
    {
        cout << n*400;
    }
    if (a == "great")
    {
        cout << n*600;
    }
    if (a == "perfect")
    {
        cout << n*1000;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}