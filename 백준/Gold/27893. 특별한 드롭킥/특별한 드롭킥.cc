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
    string a;
    cin >> n >> m >> a;
    vector<ip> p;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'X')
        {
            if (start > -1)
            {
                p.push_back({start,i});
                start = i;
            }
            else
            {
                start = i;
            }
        }
    }
    auto cmp = [&](ip& x, ip& y)
    {
        return x.second - x.first - 1 < y.second - y.first - 1;
    };
    sort(all(p),cmp);
    for (int i = 0; i < p.size(); i++)
    {
        if (m == 0) break;
        int v = p[i].second - p[i].first - 1;
        v = min(m,v);
        m -= v;
        for (int j = p[i].first+1; j < p[i].first+1+v; j++)
        {
            a[j] = 'X';
        }
    }
    if (start != -1 && m > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'X')
            {
                int idx = i;
                while (1)
                {
                    idx--;
                    if (idx < 0 || m == 0) break;
                    if (a[idx] == 'X') continue;
                    a[idx] = 'X';
                    m--;
                }
                while (1)
                {
                    i++;
                    if (i >= n || m == 0) break;
                    if (a[i] == 'X') continue;
                    a[i] = 'X';
                    m--;
                }
            }
        }
    }
    if (m > 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'X') continue;
            a[i] = 'X';
            m--;
            if (m == 0) break;
        }
    }
    // debug(a);
    bool ontrap = false;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'X')
        {
            if (!ontrap)
            {
                ontrap = true;
                res += 2;
            }
        }
        else
        {
            res++;
            ontrap = false;
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