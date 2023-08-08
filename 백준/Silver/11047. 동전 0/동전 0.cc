#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

int T;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	
	int n, coin;
	cin >> n >> coin;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (coin - a[i] >= 0)
		{
			int d = coin / a[i];
			coin -= a[i]*d;
			cnt += d;
		}
		if (coin == 0)
		{
			break;
		}
		
	}
	cout << cnt;

		
	
}
