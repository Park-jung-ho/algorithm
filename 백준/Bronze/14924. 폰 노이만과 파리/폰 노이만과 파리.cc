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
	int A, B, C;
    cin >> A >> B >> C;
    cout << C/(A*2) * B;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}