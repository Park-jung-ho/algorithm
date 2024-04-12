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
    pair<char,int> si[] = {{'8',7},{'0',6},{'2',5},{'4',4},{'7',3},{'1',2}};
    int n;
    cin >> n;
    string a = "";
    string b = "";
    for (int i = 0; i < n/2; i++)
    {
        b += '1';
    }
    if (n%2==1) b[0] = '7';
    while (1)
    {
        if (n == 17) a += "002", n-=17;
        if (n == 11) a += "02", n-=11;
        if (n == 10) a += "22", n-=10;
        if (n == 0) break;
        for (auto [x,y] : si)
        {
            if (n-y == 0 || n-y > 1)
            {
                a += x;
                n -= y;
                break;
            }
        }
    }
    reverse(all(a));
    if (a[0] == '0') a[0] = '6';
    cout << a << " " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}