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
    int cnt = 0;
    while (n--)
    {
        int a;
        cin >> a;
        cnt += a;
    }
    if (cnt == 0)
    {
        cout << "Stay";
    }
    else if (cnt > 0)
    {
        cout << "Right";
    }
    else if (cnt < 0)
    {
        cout << "Left";
    }
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}