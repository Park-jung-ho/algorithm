#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    string a;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            char c;
            cin >> c;
            if (c == 'w')
            {
                a = "chunbae";
            }
            if (c == 'b')
            {
                a = "nabi";
            }
            if (c == 'g')
            {
                a = "yeongcheol";
            }
        }
    }
    cout << a;
    

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}