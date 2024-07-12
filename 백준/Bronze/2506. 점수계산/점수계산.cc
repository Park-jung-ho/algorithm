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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			cnt++;
			res += cnt;
		}
		else
		{
			cnt = 0;
		}
	}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}