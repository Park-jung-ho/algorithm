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
    cin >> n;
    stack<ip> st;
    int cnt = 0;
    while (n--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a, b;
            cin >> a >> b;
            if (b == 1) 
            {
                cnt += a;
            }
            else
            {
                st.push({a,b-1});
            }
        }
        else
        {
            if (st.empty()) continue;
            auto [x,y] = st.top();
            st.pop();
            y--;
            if (y == 0)
            {
                cnt += x;
            }
            else
            {
                st.push({x,y});
            }
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}