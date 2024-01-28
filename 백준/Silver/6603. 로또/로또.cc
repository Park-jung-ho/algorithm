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

int n;
vector<int> res;
vector<int> arr(13);

void print(int c)
{
    if (res.size() == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = c; i < n; i++)
    {
        res.push_back(arr[i]);
        print(i+1);
        res.pop_back();
    }
    
}

void solve()
{
    while (1)
    {
        cin >> n;
        if (n == 0) return;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        print(0);
        cout << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}