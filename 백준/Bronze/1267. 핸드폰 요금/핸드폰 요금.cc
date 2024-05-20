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
    int N, Y = 0, M = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int T;
        cin >> T;
        Y += (T / 30 + 1) * 10;
        M += (T / 60 + 1) * 15;
    }
    
    if (Y == M)
        cout << "Y M " << Y << "\n";
    else if (Y > M)
        cout << "M " << M << "\n";
    else
        cout << "Y " << Y << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}