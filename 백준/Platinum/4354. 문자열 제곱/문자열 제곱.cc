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

string a;

void solve()
{
    
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
    bool can = false;
    for (int i = a.size()-2; i >= 0; i--)
    {
        if (kmp[i] <= kmp[i+1])
        {
            if (kmp[i] == 1)
            {
                can = true;
                break;
            }
        }
        else{
            break;
        }
    }
    int n = a.size() - kmp[a.size()-1];
    if (can && a.size() % n == 0)
    {
        cout << a.size() / n << "\n";
    }
    else{
        cout << 1 << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> a;
        if (a == ".")
        {
            break;
        }
        solve();
        
    }
    
    
}