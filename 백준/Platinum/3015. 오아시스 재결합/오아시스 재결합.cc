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
    ll cnt = 0;
    while (n--)
    {
        cin >> a;
        if (st.empty())
        {
            st.push({a,1});
        }
        else if (st.top().first > a)
        {
            cnt++;
            st.push({a,1});
        }
        else if (st.top().first == a)
        {
            cnt+=st.top().second;
            st.top().second++;
            if (st.size()>1) cnt++;
        }
        else
        {
            while (1)
            {
                if (st.top().first < a)
                {
                    cnt+=st.top().second;
                    st.pop();
                }
                else if (st.top().first == a)
                {
                    cnt+=st.top().second;
                    st.top().second++;
                    if (st.size()>1) cnt++;
                    break;
                }
                else
                {
                    cnt++;
                    st.push({a,1});
                    break;
                }
                if (st.empty())
                {
                    st.push({a,1});
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}