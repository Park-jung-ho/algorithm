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
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    vector<int> v(m);
    vector<int> plug(m+1,-1);
    for (auto& a : arr) cin >> a;
    for (int i = 0; i < m; i++)
    {
        int k = m;
        for (int j = i+1; j < m; j++)
        {
            if (arr[i] == arr[j])
            {
                k = j;
                break;
            }
        }
        v[i] = k;
    }
    
    int cnt = 0;
    auto pp = [&]()
    {
        for (int i = 1; i <= m; i++)
        {
            if (plug[i] == -1) cout << "x ";
            else cout << "o ";
        }
        cout << "\n";
    };

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int a = arr[i];
        // pp();
        if (plug[a] != -1)
        {
            plug[a] = v[i];
        }
        else if (cnt < n)
        {
            cnt++;
            plug[a] = v[i];
        }
        else
        {
            res++;
            // cout << "CHANGE " << res << "\n";
            int np = -1;
            int ni = 0;
            for (int j = 1; j <= m; j++)
            {
                if (plug[j] == -1) continue;
                if (max(0,plug[j] - i) > np)
                {
                    // debug(ni,np);
                    np = max(0,plug[j] - i);
                    ni = j;
                    // debug(ni,np);
                }
            }
            plug[a] = v[i];
            plug[ni] = -1;
        }
    } 
    // pp();
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}