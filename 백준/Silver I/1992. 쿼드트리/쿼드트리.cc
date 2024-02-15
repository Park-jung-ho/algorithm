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

string quad(vector<string>& arr, int x, int y, int l)
{
    
    ip st[] = {{x,y},{x,y+l/2},{x+l/2,y},{x+l/2,y+l/2}};
    ip ed[] = {{x+l/2,y+l/2},{x+l/2,y+l},{x+l,y+l/2},{x+l,y+l}};
    string a = "";
    for (int k = 0; k < 4; k++)
    {
        x = st[k].first;
        y = st[k].second;
        char r = arr[x][y];
        for (int i = st[k].first; i < ed[k].first; i++)
        {
            for (int j = st[k].second; j < ed[k].second; j++)
            {
                if (arr[i][j] != r)
                {
                    r = -1;
                    break;
                }
            }
            if (r == -1) break;
        }
        if (r == -1) a += quad(arr,x,y,l/2);
        else a += r;
    }
    bool can = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[0] != a[i]) can = false;
    }   
    string b = "";
    if (can) return b+a[0];
    else return "("+a+")";
}

void solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << quad(arr,0,0,n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    solve();
}