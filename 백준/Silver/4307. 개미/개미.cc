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
	
	int T; 
	cin >> T;
	while (T--)
	{
		int n, l; 
		cin >> n >> l;
		vector<int> arr(l);
		for (int i = 0; i < l; i++)
		{
			int a; 
			cin >> a;
			arr[i] = a;
		}
		
		vector<int>  amax(l);
		vector<int>  amin(l);
		for (int i = 0; i < l; i++)
		{
			amin[i] = min(arr[i],n-arr[i]);
			amax[i] = max(arr[i],n-arr[i]);
		}
		sort(amin.begin(),amin.end());
		sort(amax.begin(),amax.end());
		cout << amin[l-1] << " " << amax[l-1] << "\n";
	}
}