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
	int JOI = 0;
	int IOI = 0;

	string s; 
	cin >> s;

	int l = s.length();

	for (int i = 0; i < l - 2; i++) {
		if (s.substr(i, 3) == "JOI") JOI++;
		if (s.substr(i, 3) == "IOI") IOI++;
	}

	cout << JOI << '\n' << IOI;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}