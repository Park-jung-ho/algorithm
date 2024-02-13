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
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int x, y, d, t;
    cin >> x >> y >> d >> t;
    double l = sqrt(pow(x,2)+pow(y,2));
    double jump = 0;
    double time = 0;
    while (1)
    {
        if (jump == l) break;
        if (jump < l)
        {
            jump += d;
            time += t;
        }
        else
        {
            double v1, v2;
            if (jump >= d*2)
            {
                v1 = time;
            }
            else
            {
                v1 = min((jump - l),(double)t) + time;
            } 
            v2 = l - (jump - d) + time - t;
            time = min(v1,v2);
            break;
        }
    }
    cout << min(l,time) << "\n";
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    solve();
}