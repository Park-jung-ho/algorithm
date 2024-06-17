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
	vector<vector<int>> v(101,vector<int>(101));
	int res = 0;
	for (int t = 0; t < 4; t++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				if (v[i][j] == 0)
				{
					v[i][j] = 1;
					res++;
				}
			}
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