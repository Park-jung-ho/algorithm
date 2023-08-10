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
	
	
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	vector<int> visit(F+1);
	visit[S] = 1;
	deque<pair<int,int>> q;
	q.push_back(make_pair(S,0));
	bool can = false;
	int res = 0;
	while (!q.empty())
	{
		int n = q.front().first;
		int cnt = q.front().second;
		// cout << n << "," << cnt << "\n";
		q.pop_front();
		if (n == G)
		{
			can = true;
			res = cnt;
			break;
		}
		int nu = n+U;
		if (nu <= F && visit[nu] == 0)
		{
			visit[nu] = 1;
			q.push_back(make_pair(nu,cnt+1));
		}
		int nd = n-D;
		if (nd > 0 && visit[nd] == 0)
		{
			visit[nd] = 1;
			q.push_back(make_pair(nd,cnt+1));
		}
	}
	if (can)
	{
		cout << res;
	}
	else{
		cout << "use the stairs";
	}
	
		
	
}
