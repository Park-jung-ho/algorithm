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
    string a;
    cin >> a;
    bool seven = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '7')
        {
            seven = true;
            break;
        }
    }
    int v = stoi(a);
    bool div = false;
    if (v%7==0)
    {
        div = true;
    }
    if (!seven && !div) 
    {
        cout << 0;
    }
    else if (!seven && div)
    {
        cout << 1;
    }
    else if (seven && !div)
    {
        cout << 2;
    }
    else if (seven && div)
    {
        cout << 3;
    }
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}