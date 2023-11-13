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

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    vector<char> b(n);
    vector<int> kmp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[k])
        {
            kmp[i] = ++k;
        }
        else if (k!=0)
        {
            k = kmp[k-1];
            i--;
        }
    }
    // debug(kmp);
    int m = 1;
    if (n % (n-kmp[n-1]) == 0)
    {
        m = n/(n-kmp[n-1]);
    }
    int g = gcd(n,m);
    cout << m/g << "/" << n/g;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}