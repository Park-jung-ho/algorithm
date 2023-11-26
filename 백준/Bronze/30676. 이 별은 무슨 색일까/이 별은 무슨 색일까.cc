#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
	int N;
	cin >> N;
	if (N >= 620 && N <= 780)
	{
		cout << "Red";
	}
	if (N >= 590 && N < 620)
	{
		cout << "Orange";
	}
	if (N >= 570 && N < 590)
	{
		cout << "Yellow";
	}
	if (N >= 495 && N < 570)
	{
		cout << "Green";
	}
	if (N >= 450 && N < 495)
	{
		cout << "Blue";
	}
	if (N >= 425 && N < 450)
	{
		cout << "Indigo";
	}
	if (N >= 380 && N < 425)
	{
		cout << "Violet";
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}