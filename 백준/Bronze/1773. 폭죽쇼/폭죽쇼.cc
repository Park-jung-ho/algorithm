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
    int n, c;

	cin >> n >> c;

	int *tmp = new int[n];

	for (int i = 0; i < n; i++) cin >> tmp[i];

	int f = 0;
    int cnt = 0;

	for (int i = 1; i <= c; i++) 
    {
		for (int j = 0; j < n; j++)
		{
			if (i%tmp[j] == 0)
			{
				f = 1;
				break;
			}
		}

		if (f == 1)
		{
			cnt++;
			f = 0;
		}
	}

	cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}