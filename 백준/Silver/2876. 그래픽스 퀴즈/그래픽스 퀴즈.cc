#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	

	int n;
	cin >> n;
	
	vector<pair<int,int>> arr(n);
	vector<int> c(6,0);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 1; i < 6; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j].first == i | arr[j].second == i)
			{
				cnt++;
			}
			else{
				c[i] = max(c[i],cnt);
				cnt = 0;
			}
		}
		c[i] = max(c[i],cnt);
	}
	vector<pair<int,int>> m;
	for (int i = 1; i < 6; i++)
	{
		m.push_back(pair<int,int>(c[i],i));
	}
	sort(m.begin(),m.end(),compare);
	cout << m[0].first << " " << m[0].second;
}