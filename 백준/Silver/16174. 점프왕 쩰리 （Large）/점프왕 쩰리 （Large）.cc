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
int dx[] = {1,0};
int dy[] = {0,1};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<vector<int>> arr(N,vector<int>(N));
	vector<vector<int>> visit(N,vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	deque<pair<int,int>> q;
	q.push_back({0,0});
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i]*arr[x][y];
			int ny = y + dy[i]*arr[x][y];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}
			if (visit[nx][ny] == 1)
			{
				continue;
			}

			visit[nx][ny] = 1;
			q.push_back({nx,ny});
			
		}
		
	}
	if (visit[N-1][N-1] == 1)
	{
		cout << "HaruHaru";
	}
	else{
		cout << "Hing";
	}
	
}
