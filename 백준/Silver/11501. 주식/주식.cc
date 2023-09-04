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
#include <unordered_map>
using namespace std;



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		long long cnt = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		
		int mx = arr[N-1];
		for (int i = N-2; i >= 0; i--)
		{
			if (arr[i] < mx)
			{
				cnt += mx - arr[i];
			}
			else{
				mx = arr[i];
			}
			
		}
		cout << cnt << "\n";
	}
	
    
	
	
	
}
