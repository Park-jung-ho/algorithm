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
double N, M;
void solve()
{
    cin >> N >> M;
    cout.setf(std::ios_base::fixed);
	cout.precision(1);
    cout << N * M / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}