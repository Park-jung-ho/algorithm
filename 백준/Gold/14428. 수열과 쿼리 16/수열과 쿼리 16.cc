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
vector<int> arr(100001);
vector<int> tree(400001);

int midx(int x,int y){
	if (x == -1)
	{
		return y;
	}
	if (y == -1)
	{
		return x;
	}
	if (arr[x] == arr[y])
	{
		return x < y ? x : y;
	}
	else{
		return arr[x] <= arr[y] ? x : y;
	}
}

int init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = start;
	}
	int mid = (start+end)/2;
	return tree[node] = midx(init(start,mid,node*2),init(mid+1,end,node*2+1));
	
}

int update(int start, int end, int node, int index)
{
	if (start > index || end < index)
	{
		return tree[node];
	}
	if (start == end)
	{
		return tree[node];
	}

	int mid = (start+end)/2;
	
	return tree[node] = midx(update(start,mid,node*2,index),update(mid+1,end,node*2+1,index));
}

int query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
	{
		return -1;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start+end)/2;

	return midx(query(start,mid,node*2,left,right),query(mid+1,end,node*2+1,left,right));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	
	cin >> M;
	init(1,N,1);
	while (M--)
	{
		int w;
		cin >> w;
		if (w == 1)
		{
			int idx, val;
			cin >> idx >> val;
			arr[idx] = val;
			update(1,N,1,idx);
		}
		else
		{
			int l, r;
			cin >> l >> r;

			cout << query(1,N,1,l,r) << "\n";
		}
		
	}
	
}
