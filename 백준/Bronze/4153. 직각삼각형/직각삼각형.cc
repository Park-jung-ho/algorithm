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
    vector<int> abc(3);
    while (1)
    {
        int z = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> abc[i];
            if (abc[i] == 0) z++;
        }

        if (z == 3) break;
        sort(all(abc));

        if ((abc[0] * abc[0]) + (abc[1] * abc[1]) == (abc[2] * abc[2])) cout << "right\n";
        else cout << "wrong\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}