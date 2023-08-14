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

int dx[] = {1,0};
int dy[] = {0,1};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M, H;
	cin >> N >> M;
	vector<vector<int>> arr(N,vector<int>(M));
	vector<vector<long long>> visit(N,vector<long long>(M,-1));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> H;
	deque<pair<int,int>> q;
	visit[0][0] = arr[0][0];
	q.push_back({0,0});
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop_front();
		if (visit[x][y] > H)
		{
			continue;
		}
		
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}
			long long cnt = visit[x][y] + arr[nx][ny];
			if (visit[N-1][M-1] != -1 && cnt > visit[N-1][M-1])
			{
				continue;
			}
			
			if (cnt > H)
			{
				continue;
			}
			if (visit[nx][ny] == -1)
			{
				visit[nx][ny] = cnt;
				q.push_back({nx,ny});
			}
			else if (cnt < visit[nx][ny])
			{
				visit[nx][ny] = cnt;
				q.push_back({nx,ny});
			}
		}
	}
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < M; j++)
	// 	{
	// 		cout << visit[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	if (visit[N-1][M-1] != -1 && visit[N-1][M-1] <= H)
	{
		cout << "YES\n" << visit[N-1][M-1];
	}
	else{
		cout << "NO";
	}
}
