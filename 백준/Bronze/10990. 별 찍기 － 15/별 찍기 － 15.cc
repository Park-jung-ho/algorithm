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

    for (int i = 1; i < n + 1; i++) 
	{
        for (int j = n - i; j > 0; j--) 
		{
            cout << " ";
        }
        if (i == 1) 
		{
            cout << "*\n";
        } 
		else 
		{
            cout << "*";
            for (int j = 0; j < 2 * (i - 1) - 1; j++) 
			{
                cout << " ";
            }
            cout << "*\n";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}