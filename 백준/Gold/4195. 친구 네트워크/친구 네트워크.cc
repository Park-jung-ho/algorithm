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
    cin >> n;
    vector<stack<string>> arr;
    map<string,int> d;
    while (n--)
    {
        int c;
        string a, b;
        cin >> a >> b;
        int x = -1;
        int y = -1;
        if (d.find(a) != d.end()) x = d[a];
        if (d.find(b) != d.end()) y = d[b];
        if (x == -1 && y == -1)
        {
            c = arr.size();
            arr.push_back({});
            arr[c].push(a);
            arr[c].push(b);
            d[a] = c;
            d[b] = c;
        }
        else if (x == -1)
        {
            c = d[b];
            arr[c].push(a);
            d[a] = c;
        }
        else if (y == -1)
        {
            c = d[a];
            arr[c].push(b);
            d[b] = c;
        }
        else if (x == y)
        {
            c = d[a];
        }
        else
        {
            int t;
            if (arr[d[a]].size() < arr[d[b]].size())
            {
                c = d[b];
                t = d[a];
            }
            else
            {
                c = d[a];
                t = d[b];
            }
            while (!arr[t].empty())
            {
                string s = arr[t].top();
                arr[t].pop();
                arr[c].push(s);
                d[s] = c;
            }
        }
        cout << arr[c].size() << "\n";
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}