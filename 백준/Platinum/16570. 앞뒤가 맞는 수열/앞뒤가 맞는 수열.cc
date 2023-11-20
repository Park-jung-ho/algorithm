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
	vector<int> arr(N);
	vector<int> kmp(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[N-i-1];
	}
	int k = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[i] == arr[k])
		{
			kmp[i] = ++k;
		}
		else if (k != 0)
		{
			k = kmp[k-1];
			i--;
		}
	}
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < N; i++)
	{
		if (mx == kmp[i])
		{
			cnt++;
		}
		if (mx < kmp[i])
		{
			mx = kmp[i];
			cnt = 1;
		}
	}
	if (mx == 0)
	{
		cout << -1;
	}
	else{
		cout << mx << " " << cnt;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}