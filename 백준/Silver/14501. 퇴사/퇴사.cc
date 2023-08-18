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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	
	cin >> N;
	vector<pair<int,int>> arr(N);
	vector<int> dp(N,0);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a,b);
		if (arr[i].first+i <= N)
		{
			dp[i] = arr[i].second;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = arr[i].first+i; j < N; j++)
		{
			if (arr[j].first+j <= N)
			{
				dp[j] = max(dp[j],dp[i] + arr[j].second);
			}
			
		}
		
		
	}
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		res = max(res,dp[i]);
	}
	cout << res;
	
}
