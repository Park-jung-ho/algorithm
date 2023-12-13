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
    int n, a;
    cin >> n;
    stack<ip> st;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (st.empty())
        {
            st.push({a,1});
        }
        else if (st.top().first <= a)
        {
            if (st.top().first == a) st.top().second++;
            else st.push({a,1});
        }
        else
        {
            int cnt = 1;
            while (1)
            {
                if (st.empty())
                {
                    st.push({a,cnt});
                    break;
                }
                if (st.top().first <= a)
                {
                    if (st.top().first == a) st.top().second += cnt;
                    else st.push({a,cnt});
                    break;
                }
                cnt += st.top().second;
                res = max(res,(ll)st.top().first*(cnt-1));
                st.pop();
            }
        }
        res = max(res,(ll)st.top().first*st.top().second);
    }
    int cnt = 0;
    while (!st.empty())
    {
        a = st.top().first;
        cnt += st.top().second;
        res = max(res,(ll)a*cnt);
        st.pop();
        // debug(a,cnt,a*cnt);
    }
    
    
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}