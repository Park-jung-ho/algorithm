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
    int Q;
    cin >> Q;
    map<string,int> a;
    map<string,int> b;
    
    while (Q--)
    {
        string q, s;
        char setName;
        cin >> q;
        if (q == "add")
        {
            cin >> setName >> s;
            string tmp = "";
            if (setName == 'A')
            {
                for (auto c : s)
                {
                    tmp += c;
                    if (a.find(tmp) == a.end()) a[tmp] = 0;
                    a[tmp]++;
                }
            }
            else
            {
                reverse(all(s));
                for (auto c : s)
                {
                    tmp += c;
                    if (b.find(tmp) == b.end()) b[tmp] = 0;
                    b[tmp]++;
                }
            }
        }
        if (q == "delete")
        {
            cin >> setName >> s;
            string tmp = "";
            if (setName == 'A')
            {
                for (auto c : s)
                {
                    tmp += c;
                    a[tmp]--;
                }
            }
            else
            {
                reverse(all(s));
                for (auto c : s)
                {
                    tmp += c;
                    b[tmp]--;
                }
            }
        }
        if (q == "find")
        {
            cin >> s;
            string tmp = "";
            int res = 0;
            for (int i = 0; i < s.size()-1; i++)
            {
                tmp += s[i];
                string sub = s.substr(i+1,s.size()-i-1);
                reverse(all(sub));
                if (a.find(tmp) != a.end() && b.find(sub) != b.end())
                {
                    res += a[tmp] * b[sub];
                }
            }
            cout << res << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}