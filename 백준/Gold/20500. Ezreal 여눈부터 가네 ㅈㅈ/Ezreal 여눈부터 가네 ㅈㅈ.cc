#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<long long> dp(n+1,1);
	dp[1] = 0;
	
	for (int i = 4; i < n+1; i++)
	{
		if (i%2 == 0)
		{
			dp[i] = (dp[i-1] * 2)%1000000007 + 1;
		}
		else
		{
			dp[i] = (dp[i-1] * 2)%1000000007 - 1;
		}
	}
	
	
	cout << dp[n];

	
}