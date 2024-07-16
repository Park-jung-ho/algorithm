#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()


void solve()
{
    int n;
    cin >> n;
    int a = 100;
    int b = 100;
    while (n--)
    {
        int c, d;
        cin >> c >> d;
        if (c < d) a -= d;
        if (c > d) b -= c;
    }
    cout << a << "\n" << b;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}