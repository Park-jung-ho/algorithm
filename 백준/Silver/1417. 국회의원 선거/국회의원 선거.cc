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
    int n, a;
    cin >> n >> a;
    priority_queue<int> pq;
    n--;
    int cnt = 0;
    while (n--)
    {
        int c;
        cin >> c;
        pq.push(c);
    }
    while (!pq.empty())
    {
        if (a > pq.top()) break;
        int t = pq.top();
        pq.pop();
        pq.push(t-1);
        a++;
        cnt++;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}