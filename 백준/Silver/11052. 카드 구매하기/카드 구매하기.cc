#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int cnt = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N; 
	cin >> N;
	vector<int> arr(N+1);
	for (int i = 1; i < N+1; i++)
	{
		int a; 
		cin >> a;
		arr[i] = a;
	}
	for (int i = 2; i < N+1; i++)
	{
		for (int j = i-1; j >= 1; j--)
		{
			if (i - j > j)
			{
				continue;
			}
			arr[i] = max(arr[i],arr[j]+arr[i-j]);
			//cout << arr[i] << "\n";
		}
	}
	cout << arr[N];
	

}