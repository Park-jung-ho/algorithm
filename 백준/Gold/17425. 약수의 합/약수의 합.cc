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
	
	
	int T;
	cin >> T;
	vector<long long> arr(1000001,1);
	for (int i = 2; i < 1000001; i++)
	{
		long long n = i;
		for (int j = 1; j < 1000001; j++)
		{
			n = i*j;
			if (n > 1000000)
			{
				break;
			}
			arr[n] += i;
			
		}
		arr[i] += arr[i-1];
	}
	
	while (T--)
	{
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}
	
	
		
	
}
