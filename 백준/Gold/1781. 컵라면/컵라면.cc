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

bool cmp(pair<int,int> a, pair<int,int> b){
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
	
}
struct compare
{
	bool operator()(pair<int,int> a, pair<int,int> b){
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
		
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N,a,b;
	cin >> N;
	vector<pair<int,int>> arr(N);
	vector<int> count(N+1);
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
	priority_queue<pair<int , int>> heap;
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		s = max(s,a);
		arr[i] = {a,b};
	}
	sort(arr.begin(),arr.end(),cmp);
	int t = 2;
	int dead, cup;
	int res = arr[0].second;
	pq.push(arr[0]);
	// cout << "===============" << "\n";
	for (int i = 1; i < N; i++)
	{
		// cout << arr[i].first << " " << arr[i].second << "\n";
		dead = arr[i].first;
		cup = arr[i].second;
		// cout << pq.top().second << "\n";

		if (dead >= t)
		{
			t++;
			res += cup;
			pq.push(arr[i]);
		}
		else if (cup > pq.top().second)
		{
			res -= pq.top().second;
			pq.pop();
			res += cup;
			pq.push(arr[i]);
		}
	}
	cout << res;
	
	
}
