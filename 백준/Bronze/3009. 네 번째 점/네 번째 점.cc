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
	int x, y, x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	if (x1 == x2) x = x3;
	else if (x1 == x3) x = x2;
	else x = x1;

	if (y1 == y2) y = y3;
	else if (y1 == y3) y = y2;
	else y = y1;

	cout << x << " " << y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}