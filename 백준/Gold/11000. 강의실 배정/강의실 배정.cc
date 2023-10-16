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
    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    priority_queue<int, vector<int>, greater<int>> ends;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a,b});
    }
    while (!pq.empty())
    {
        int st = pq.top().first;
        int ed = pq.top().second;
        pq.pop();
        if (!ends.empty() && ends.top() <= st)
        {
            ends.pop();
        }
        ends.push(ed);
    }
    cout << ends.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}