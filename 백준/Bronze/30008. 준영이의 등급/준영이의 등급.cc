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
    int n, m, a;
    cin >> n >> m;
    ip rank[] = {{-1,4},{4,11},{11,23},{23,40},{40,60},{60,77},{77,89},{89,96},{96,100}};
    while (m--)
    {
        cin >> a;
        a = (a*100)/n;
        for (int i = 0; i < 9; i++)
        {
            if (a > rank[i].first && a <= rank[i].second) cout << i+1 << " ";
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}