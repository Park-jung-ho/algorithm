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
bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}
void solve()
{
    int n;
    cin >> n;
    vector<string> a;
    set<string> v;
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        if (v.find(c) == v.end())
        {
            v.insert(c);
            a.push_back(c);
        }
        
    }
    sort(all(a),cmp);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\n"; 
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}