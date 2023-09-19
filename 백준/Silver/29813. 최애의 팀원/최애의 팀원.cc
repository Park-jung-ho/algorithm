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
int N;
void solve()
{
    cin >> N;
    deque<pair<string,int>> q;
    for (int i = 0; i < N; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        q.push_back({a,b});
    }
    while (q.size() > 1)
    {
        string a = q.front().first;
        int b = q.front().second-1;
        q.pop_front();
        while (b--)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        q.pop_front();
    }
    cout << q.front().first;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}