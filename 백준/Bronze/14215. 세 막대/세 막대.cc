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
	vector<int> a(3);
	for (auto&c : a) cin >> c;
	sort(all(a));
	if (a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];	
	else cout << (a[0] + a[1])* 2 - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}