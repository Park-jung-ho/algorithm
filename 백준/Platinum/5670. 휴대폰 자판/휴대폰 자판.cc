#include <bits/stdc++.h>
#include <sstream>
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

int cnt = 0;

struct trie
{
    map<char, trie*> child;
    int c = 0;
    void insert(int idx, string a)
    {
        if (idx == a.size())
        {
            return;
        }
        if (child.find(a[idx]) == child.end())
        {
            trie* childtrie = new trie;
            child.insert({a[idx],childtrie});
            childtrie->insert(idx+1,a);
        }
        else{
            child[a[idx]]->insert(idx+1,a);
        }
        child[a[idx]]->c++;
    }

    void findc(int idx, string a)
    {
        
        if (idx == a.size())
        {
            return;
        }
        if (idx==0 || child[a[idx]]->c != c)
        {
            cnt++;
        }
        
        child[a[idx]]->findc(idx+1, a);
    }
};

void solve()
{
    int n;
    
    while (cin >> n)
    {
        trie top;
        vector<string> arr(n);
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            top.insert(0,arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            top.findc(0,arr[i]);
            
        }
        double res = (double)cnt/n;
        cout << res << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);
    solve();
}   