#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int V,E,P;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> V >> E >> P;
	vector<vector<pair<int,int>>> arr(V+1);
	vector<int> dist(V+1,50000001);
	dist[1] = 0;
	for (int i = 0; i < E; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));
	}
	priority_queue<pair<int,int>> q;

	q.push(make_pair(0,1));
	while (q.empty() == 0)
	{
		int cnt = -q.top().first;
		int idx = q.top().second;
		q.pop();
		for (int i = 0; i < arr[idx].size(); i++)
		{
			int nc,ni;
			ni = arr[idx][i].first;
			nc = cnt + arr[idx][i].second;
			if (dist[ni] > nc)
			{
				dist[ni] = cnt + arr[idx][i].second;
				q.push((make_pair(-nc,ni)));
			}
		}
		
	}
	// for (int i = 1; i < V+1; i++)
	// {
	// 	cout << dist[i] << " ";
	// }
	vector<int> Pdist(V+1,50000001);
	Pdist[P] = 0;
	q.push(make_pair(0,P));
	while (q.empty() == 0)
	{
		int cnt = -q.top().first;
		int idx = q.top().second;
		q.pop();
		for (int i = 0; i < arr[idx].size(); i++)
		{
			int nc,ni;
			ni = arr[idx][i].first;
			nc = cnt + arr[idx][i].second;
			if (Pdist[ni] > nc)
			{
				Pdist[ni] = cnt + arr[idx][i].second;
				q.push((make_pair(-nc,ni)));
			}
		}
	}
	// cout << "\n";
	// for (int i = 1; i < V+1; i++)
	// {
	// 	cout << Pdist[i] << " ";
	// }
	if (dist[V] >= Pdist[1] + Pdist[V])
	{
		cout << "SAVE HIM";
	}
	else{
		cout << "GOOD BYE";
	}
	
	

}