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
    int q, a, b;
    cin >> q;
    stack<int> st;
    while (q--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            st.push(b);
        }
        if (a == 2)
        {
            if (st.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        if (a == 3)
        {
            cout << st.size() << "\n";
        }
        if (a == 4)
        {
            if (st.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        if (a == 5)
        {
            if (st.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << st.top() << "\n";
            }
        }
    }
    

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}