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
		vector<string> a(n);
		map<string,string> c;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			string t = a[i];
			for (int j = 0; j < a[i].size(); j++)
			{
				a[i][j] = tolower(a[i][j]);
			}	
			c[a[i]] = t;
		}
		sort(all(a));
		cout << c[a[0]] << "\n";
	}
	
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}