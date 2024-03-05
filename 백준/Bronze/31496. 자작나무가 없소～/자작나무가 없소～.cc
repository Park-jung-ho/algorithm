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
    int n;
    string a;
    cin >> n >> a;
    int res = 0;
    while (n--)
    {
        string b;
        int c;
        cin >> b >> c;
        vector<string> ss;
        istringstream iss(b);
        string bf;
        while (getline(iss,bf,'_'))
        {
            ss.push_back(bf);
        }
        
        for (auto s : ss)
        {
            if (s == a)
            {
                res += c;
                break;
            }
        }
        
    }
    cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}