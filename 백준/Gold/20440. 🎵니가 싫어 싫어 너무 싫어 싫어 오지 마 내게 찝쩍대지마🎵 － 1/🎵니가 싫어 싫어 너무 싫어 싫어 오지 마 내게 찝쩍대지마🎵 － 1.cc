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

int T;
bool cmp(pair<int,int> a, pair<int,int> b){
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	vector<pair<int,int>> arr;
	vector<pair<int,int>> res;
	unordered_map<int,int> um;
	for (int i = 0; i < T; i++)
	{
		int e, x;
		cin >> e >> x;
		if (um.find(e) == um.end())
		{
			um.insert({e,1});
		}
		else{
			um[e]++;
		}
		if (um.find(x) == um.end())
		{
			um.insert({x,-1});
		}
		else{
			um[x]--;
		}
	}
	vector<int> t;
	for (auto e : um)
	{
		t.push_back(e.first);
	}
	sort(t.begin(),t.end());
	int mx = 0;
	int cnt = 0;
	int em = 0;
	int xm = 0;
	bool b = false;
	for (int i = 0; i < t.size(); i++)
	{
		cnt += um[t[i]];
		if (cnt > mx)
		{
			mx = cnt;
			em = t[i];
			b = true;
		}
		else if (cnt < mx && cnt - um[t[i]] == mx && b)
		{
			xm = t[i];
			b = false;
		}
	}
	cout << mx << "\n" << em << " " << xm;
	
}
