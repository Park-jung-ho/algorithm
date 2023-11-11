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
    int n;
    string a;
    cin >> n >> a;
    vector<int> kmp(n);
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[k])
        {
            kmp[i] = ++k;
        }
        else if (k != 0)
        {
            if (kmp[k-1] != 0)
            {
                k = kmp[k-1];
            }
            else{
                k = 0;
            }
            i--;
        }
        
    }
    // debug(kmp);
    cout << n - kmp[n-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}