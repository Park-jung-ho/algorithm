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

struct album
{
    string name;
    album* parent;
    map<string,album*> child;
    set<string> photos;

    void del(int& p)
    {
        p += photos.size();
        photos.clear();
    }
    void rmalb(int& a, int& p)
    {
        a++;
        del(p);
        for (auto it = child.begin(); it != child.end(); it++)
        {
            it->second->rmalb(a,p);
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    string q, s;
    
    album root;
    root.name = "album";
    root.parent = &root;
    
    album* current = &root;

    while (n--)
    {
        cin >> q >> s;
        if (q == "mkalb")
        {
            if (current->child.find(s) == current->child.end())
            {
                album* alb = new album;
                alb->name = s;
                alb->parent = current;
                current->child[s] = alb;
            }
            else
            {
                cout << "duplicated album name\n";
            }
        }
        if (q == "rmalb")
        {
            int a = 0;
            int p = 0;
            if (s == "-1")
            {
                auto it = current->child.begin();
                if (it != current->child.end())
                {
                    it->second->rmalb(a,p);
                    current->child.erase(it->first);
                }
            }
            else if (s == "1")
            {
                auto it = current->child.rbegin();
                if (it != current->child.rend())
                {
                    it->second->rmalb(a,p);
                    current->child.erase(it->first);
                }
            }
            else if (s == "0")
            {
                for (auto it = current->child.begin(); it != current->child.end(); it++)
                {
                    it->second->rmalb(a,p);
                }
                current->child.clear();
            }
            else
            {
                if (current->child.find(s) != current->child.end())
                {
                    current->child[s]->rmalb(a,p);
                    current->child.erase(s);
                }
            }
            cout << a << " " << p << "\n";
        }
        if (q == "insert")
        {
            if (current->photos.find(s) == current->photos.end())
            {
                current->photos.insert(s);
            }
            else
            {
                cout << "duplicated photo name\n";
            }
        }
        if (q == "delete")
        {
            int p = 0;
            if (s == "-1")
            {
                auto it = current->photos.begin();
                if (it != current->photos.end())
                {
                    current->photos.erase(*it);
                    p++;
                }
            }
            else if (s == "1")
            {
                auto it = current->photos.rbegin();
                if (it != current->photos.rend())
                {
                    current->photos.erase(*it);
                    p++;
                }
            }
            else if (s == "0")
            {
                p += current->photos.size();
                current->photos.clear();
            }
            else
            {
                if (current->photos.find(s) != current->photos.end())
                {
                    current->photos.erase(s);
                    p++;
                }
            }
            cout << p << "\n";
        }
        if (q == "ca")
        {
            if (s == "..")
            {
                current = current->parent;
            }
            else if (s == "/")
            {
                current = &root;
            }
            else
            {
                if (current->child.find(s) != current->child.end())
                {
                    current = current->child[s];
                }
            }
            cout << current->name << "\n";
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}