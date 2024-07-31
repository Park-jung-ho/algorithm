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
	int n, m;
	cin >> n;
	int a = 0;
	
	while (n--)
	{
		int c;
		cin >> c;
		a = max(a,c);
	}
	

	cout << a << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}