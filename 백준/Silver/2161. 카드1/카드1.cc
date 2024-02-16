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
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push_back(i+1);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
        if (q.empty()) break;
        q.push_back(q.front());
        q.pop_front();
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}