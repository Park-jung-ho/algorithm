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
	int cnt = 0;
	while (n--)
	{
		string a;
		cin >> a;
		vector<int> v(26);
		bool can = true;
		v[a[0]-'a'] = 1;
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] == a[i-1]) continue;
			if (v[a[i]-'a'] == 1)
			{
				can = false;
				break;
			}
			v[a[i]-'a'] = 1;
		}
		if (can) cnt++;
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}