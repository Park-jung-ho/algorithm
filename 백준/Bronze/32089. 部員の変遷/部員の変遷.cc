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
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (auto& c : a) cin >> c;
		int cnt = 0;
		for (int i = 2; i < n; i++)
		{
			cnt = max(cnt,a[i]+a[i-1]+a[i-2]);
		}
		cout << cnt << "\n";
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}