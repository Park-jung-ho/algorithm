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
    int n;
    cin >> n;
    int cnt = 0;
    int score = 0;
    int t = n;
    bool f = false;
    while (t--)
    {
        int a;
        cin >> a;
        if (a == 5) cnt++;
        if (a == 3) f = true;
        score += a;
    }
    double av = (double)score/n;
    if (cnt == n) cout << "Named";
    else if (f) cout << "None";
    else if (av >= 4.5) cout << "High";
    else cout << "Common";
    
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}