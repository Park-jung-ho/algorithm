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
    int c = 0;
    int nc = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a==0)
        {
            nc++;
        }
        else{
            c++;
        }
        
    }
    if (c > nc)
    {
        cout << "Junhee is cute!";
    }
    else{
        cout << "Junhee is not cute!";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}