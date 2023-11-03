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

vector<int> chk(2001);

struct trie
{
    map<char, trie*> node;
    bool finish;
    
    trie()
    {
        finish = false;
    }

    void Insert(int idx, string& a)
    {
        if (idx == a.size())
        {
            finish = true;
        }
        else{
            if (node.find(a[idx]) == node.end())
            {
                node.insert({a[idx],new trie});
            }
            node[a[idx]]->Insert(idx+1,a);
        }
    }

    void findc(string& a, int idx)
    {
        if (finish)
        {
            chk[idx]++;
        }
        if (node.find(a[idx]) != node.end())
        {
            node[a[idx]]->findc(a,idx+1);
        }
    }

    void findn(string& a, int idx)
    {
        if (finish)
        {
            chk[idx+1]++;
        }
        if (node.find(a[idx]) != node.end())
        {
            node[a[idx]]->findn(a,idx-1);
        }
    }
};

trie color;
trie nick;



void solve()
{
    int c, n;
    cin >> c >> n;

    string a;
    string b;
    for (int i = 0; i < c; i++)
    {
        cin >> a;
        color.Insert(0,a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        reverse(all(a));
        nick.Insert(0,a);
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        cin >> a;
        for (int i = 0; i < a.size(); i++)
        {
            chk[i] = 0;
        }
        
        color.findc(a,0);
        // reverse(all(a));
        nick.findn(a,a.size()-1);
        bool yes = false;
        for (int i = 0; i < a.size(); i++)
        {
            // cout << chk[i] << " ";
            if (chk[i]==2)
            {
                yes = true;
                break;
            }
        }
        if (yes)
        {
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}