#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int dx[] {-1,0,1,0};
int dy[] {0,1,0,-1};

void solve()
{
	int n, m;
	cin >> m >> n;
	int x = -1;
	int y = -1;
	int x2, y2;
	vector<vector<char>> arr(n,vector<char>(m));
	vector<vector<int>> visited(n,vector<int>(m));
	vector<vector<int>> mb(n,vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'C')
			{
				x2 = x;
				y2 = y;
				x = i;
				y = j;
			}
		}
	}
	deque<ip> q = {{x,y}};
	mb[x][y] = -1;
	while (!q.empty())
	{
		if (visited[x2][y2] != 0) break;
		x = q.front().first;
		y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == mb[x][y]) continue;
			int nx = x;
			int ny = y;
			while (1)
			{
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '*')
				{
					break;
				}
				if (visited[nx][ny] == 0 || visited[nx][ny] > visited[x][y]+1)
				{
					visited[nx][ny] = visited[x][y]+1;
					mb[nx][ny] = i%2;
					q.push_back({nx,ny});
				}
			}
		}
		
	}
	cout << visited[x2][y2]-1;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}