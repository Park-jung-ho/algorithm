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
	
	int T; 
	cin >> T;
	map<int,vector<int>> m;
	m.insert({0,{7}});
	m.insert({1,{2,4}});
	m.insert({2,{1,3,5}});
	m.insert({3,{2,6}});
	m.insert({4,{1,5,7}});
	m.insert({5,{2,4,6,8}});
	m.insert({6,{3,5,9}});
	m.insert({7,{4,0,8}});
	m.insert({8,{5,7,9}});
	m.insert({9,{6,8}});
	while (T--)
	{
		int n; 
		cin >> n;
		int cnt = 0;
		vector<int> arr(10,1);
		n--;
		while (n--)
		{
			vector<int> tmp(10,0);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < m[i].size(); j++)
				{
					tmp[i] += arr[m[i][j]]%1234567;
				}
			}
			for (int i = 0; i < 10; i++){
				arr[i] = tmp[i]%1234567;
			}
		}
		
		
		for (int i = 0; i < 10; i++){
			cnt += arr[i]%1234567;
		}
		cout << cnt % 1234567 << "\n";
	}
	

}