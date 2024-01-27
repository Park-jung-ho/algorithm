#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int c = 1;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            if (st.top() != c) break;
            st.pop();
            c++;
        }
        if (arr[i] == c)
        {
            c++;
        }
        else
        {
            st.push(arr[i]);
        }
    }
    while (!st.empty())
    {
        if (st.top() != c) break;
        st.pop();
        c++;
    }
    if (c != n+1) cout << "Sad";
    else cout << "Nice";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}