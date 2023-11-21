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
    string a;
    cin >> a;
    vector<int> kmp(a.size());
    int k = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[k])
        {
            kmp[i] = ++k;
        }
        else if (k != 0)
        {
            k = kmp[k-1];
            i--;
        }
    }
    k = kmp[a.size()-1];
    if (k == 0)
    {
        cout << -1;
        return;
    }
    bool can = false;
    bool rr = false;
    for (int i = a.size()-2; i >= 0; i--)
    {
        if (kmp[i] == k)
        {
            can = true;
            break;
        }
    }
    int z = 0;
    // while (kmp[k-1] != 0)
    // {
    //     k = kmp[k-1];
    // }
    
    
    // debug(kmp,k,can);
    if (can)
    {
        cout << a.substr(0,k);
    }
    else if (kmp[k-1] != 0)
    {
        k = kmp[k-1];
        cout << a.substr(0,k);
    }
    else{
        cout << -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}