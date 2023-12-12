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

bool cmp(ip a, ip b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
struct cmpr
{
    bool operator()(ip a, ip b)
    {
        return a.first < b.first;
    }
};

void solve()
{
    int n, d;
    cin >> n;
    int a, b;
    vector<ip> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ip solab = a <= b ? mp(a,b) : mp(b,a);
        arr[i] = solab;
    }
    cin >> d;
    sort(all(arr),cmp);
    priority_queue<ip,vector<ip>,greater<ip>> q;
    
    int L, R;
    multiset<int> Rmx;
    int cnt = 0;
    
    
    for (auto [a,b] : arr)
    {
        if (b-a > d) continue;
        if (q.empty())
        {
            q.push({a,b});
            L = q.top().first;
            R = b;
            Rmx.insert(R);
        }
        else if(max(R,b) - L <= d)
        {
            q.push({a,b});
            L = q.top().first;
            R = max(R,b);
            Rmx.insert(b);
        }
        else
        {
            while (1)
            {
                auto it = Rmx.find(q.top().second);
                Rmx.erase(it);
                q.pop();
                if (q.empty())
                {
                    q.push({a,b});
                    L = q.top().first;
                    R = b;
                    Rmx.insert(b);
                    break;
                }
                L = q.top().first;
                it = Rmx.end();
                it--;
                R = *it;
                if (max(R,b) - L <= d)
                {
                    q.push({a,b});
                    L = q.top().first;
                    R = max(R,b);
                    Rmx.insert(b);
                    break;
                }
            }
        }
        cnt = max(cnt,(int)q.size());
        auto it = Rmx.end();
        it--;
    }
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}