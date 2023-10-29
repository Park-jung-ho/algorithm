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

struct trie
{
    map<string, trie*> child;

    void insert(int idx, vector<string>& a)
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
    }

    void print(int idx)
    {
        for (auto& t : child)
        {
            for (int k = 0; k < idx; k++)
            {
                cout << " ";
            }
            cout << t.first << "\n";
            t.second->print(idx+1);
        }
    }
};

trie top;

void solve()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        vector<string> arr;
        istringstream a1(a);
        string c;
        while (getline(a1,c,'\\'))
        {
            arr.push_back(c);
        }
        top.insert(0,arr);
    }
    top.print(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}   