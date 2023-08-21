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

struct uv
{
	int u,v,d;
};

bool cmp(uv a, uv b){
	return a.d < b.d;
}
vector<string> nm;
vector<int> p;
vector<uv> tree;
int root(int x){
	if (p[x] == x)
	{
		return x;
	}
	return p[x] = root(p[x]);
}
void uroot(int x, int y){
	x = root(x);
	y = root(y);
	if (x != y)
	{
		p[y] = x;
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M;
	cin >> N >> M;
	nm.resize(N+1);
	p.resize(N+1);
	for (int i = 1; i < N+1; i++)
	{
		cin >> nm[i];
		p[i] = i;
	}
	
	for (int i = 0; i < M; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		if (nm[u] == "M" && nm[v] == "W")
		{
			tree.push_back({u,v,d});
		}
		else if (nm[u] == "W" && nm[v] == "M")
		{
			tree.push_back({u,v,d});
		}
	}

	if (tree.empty())
	{
		cout << -1;
	}
	else{
		sort(tree.begin(),tree.end(),cmp);
		int cnt = 0;
		int vs = 0;
		for (int i = 0; i < tree.size(); i++)
		{
			if (root(tree[i].u) == root(tree[i].v))
			{
				continue;
			}
			uroot(tree[i].u,tree[i].v);
			cnt += tree[i].d;
			vs++;
			if (vs == N-1)
			{
				break;
			}
		}
		if (vs == N-1)
		{
			cout << cnt;
		}
		else{
			cout << -1;
		}
		
	}
	
	
	
}
