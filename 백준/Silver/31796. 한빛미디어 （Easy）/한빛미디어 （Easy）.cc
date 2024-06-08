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
	vector<int> a(n);
	for (auto& c : a) cin >> c;
	sort(all(a));
	int res = 1;
	int mx = a[0]*2;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < mx) continue;
		res++;
		mx = a[i]*2;
	}
	cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}