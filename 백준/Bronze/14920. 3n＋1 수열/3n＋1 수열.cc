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
	ll n;
	cin >> n;
	int cnt = 1;
	while (n != 1)
	{
		cnt++;
		if (n%2==1) n = n*3+1;
		else n /= 2;
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}