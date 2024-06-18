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
	int n;
    cin >> n;
    if (n <= 5)
	{
		cout << n << '\n';
	}
    else
    {
        if ((n - 5) / 4 % 2 == 0) cout << 5 - (n-5) % 4 << '\n';
        else cout << 1 + (n - 5) % 4 << '\n';
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}