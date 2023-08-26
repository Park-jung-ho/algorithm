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


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<vector<int>> arr;
vector<vector<vector<int>>> visit;

int N,M,T;
void pr(){
	cout << "===========\n"; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visit[0][i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visit[1][i][j] << " ";
		}
		cout << "\n";
	}
	
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> T;
	arr.resize(N,vector<int>(M));
	visit.resize(2,vector<vector<int>>(N,vector<int>(M)));

	deque<vector<int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	q.push_back({0,0,0});
	bool fail = true;
	int gg;
	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int g = q.front()[2];
		q.pop_front();
		if (visit[g][x][y] > T)
		{
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ng = g;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}
			if (visit[g][nx][ny] != 0)
			{
				continue;
			}
			if (g == 0 && arr[nx][ny] == 1)
			{
				continue;
			}
			visit[g][nx][ny] = visit[g][x][y] + 1;
			if (arr[nx][ny] == 2)
			{
				ng = 1;
				visit[1][nx][ny] = visit[0][nx][ny];
			}
			if (nx == N-1 && ny == M-1 && visit[g][nx][ny] <= T)
			{
				gg = ng;
				fail = false;
				break;
			}
			
			q.push_back({nx,ny,ng});
		}
		// pr();
		if (!fail)
		{
			break;
		}
		
	}
	if (fail)
	{
		cout << "Fail";
	}
	else{
		cout << visit[gg][N-1][M-1];
	}
	
}
