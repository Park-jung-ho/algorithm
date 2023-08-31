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

int N, M;

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = a[start];
	}
	else
	{
		init(a, tree, node*2, start, (start+end)/2);
		init(a, tree, node*2+1, (start+end)/2+1,end);
		tree[node] = min(tree[node*2], tree[node*2+1]);
	}
	
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int index, int val)
{
	if (index < start || index > end)
	{
		return;
	}
	if (start == end)
	{
		a[index] = val;
		tree[node] = val;
		return;
	}
	update(a, tree, node*2, start, (start+end)/2, index, val);
	update(a, tree, node*2+1, (start+end)/2+1, end, index, val);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return -1;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int lmin = query(tree, node*2, start, (start+end)/2, left, right);
	int rmin = query(tree, node*2+1, (start+end)/2+1, end, left, right);
	if (lmin == -1)
	{
		return rmin;
	}
	else if (rmin == -1)
	{
		return lmin;
	}
	else
	{
		return min(lmin,rmin);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int h = (int)ceil(log2(N));
	int s = (1 << (h+1));
	vector<int> tree(s);
	init(arr,tree,1,0,N-1);
	cin >> M;
	while (M--)
	{
		int w;
		cin >> w;
		if (w == 1)
		{
			int idx, val;
			cin >> idx >> val;
			update(arr,tree,1,0,N-1,idx-1,val);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(tree,1,0,N-1,l-1,r-1) << "\n";
		}
		
	}
	
}
