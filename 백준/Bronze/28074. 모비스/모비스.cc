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
    string a;
    cin >> a;
    set<char> mobis = {'M','O','B','I','S'};
    vector<char> m = {'M','O','B','I','S'};
    set<char> res;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i] == m[j])
            {
                res.insert(a[i]);
            }
        }
    }
    if (mobis==res)
    {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
        
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}