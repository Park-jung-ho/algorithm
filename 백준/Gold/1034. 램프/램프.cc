#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int n, m, k, b;
int MX = 0;
vector<pair<string,int>> arr;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		bool chk = true;
		
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j].first == a)
			{
				arr[j].second += 1;
				chk = false;
			}
		}
		if (chk)
		{
			arr.push_back(make_pair(a,1));
		}
	}
	// for (int i = 0; i < arr.size(); i++)
	// {
	// 	cout << arr[i].first << "," << arr[i].second << "\n";
	// }
	
	cin >> k;
	b = k%2;
	
	for (int i = 0; i < arr.size(); i++)
	{
		int z = 0;
		for (int j = 0; j < arr[i].first.size(); j++)
		{
			if (arr[i].first[j] == '0')
			{
				z++;
			}
		}
		// cout << arr[i].first << "," << arr[i].second << "| " << z << "\n";
		if (z <= k && z%2 == b)
		{
			MX = max(MX,arr[i].second);
		}
		
	}
	
	cout << MX;

}