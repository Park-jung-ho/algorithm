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
    int n, k;
    string a;
    cin >> n >> k >> a;

    deque<int> val;
    for (auto c : a)
    {
        int v = c - '0';
        while (1)
        {
            if (val.empty() || k == 0)
            {
                val.push_back(v);
                break;
            }
            if (val.back() >= v)
            {
                val.push_back(v);
                break;
            }
            val.pop_back();
            k--;
        }
    }
    while (k--)
    {
        val.pop_back();
    }
    
    while (!val.empty())
    {
        cout << val.front();
        val.pop_front();
    }
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}