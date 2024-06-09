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
	int t;
	cin >> t;
	deque<int> q;
	while (t--)
	{
		string a;
		int b;
		cin >> a;
		if (a == "push")
		{
			cin >> b;
			q.push_back(b);
		}
		if (a == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		if (a == "size")
		{
			cout << q.size() << "\n";
		}
		if (a == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		if (a == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		if (a == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}