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
	cout << (log2(n) - (int)log2(n) == 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}