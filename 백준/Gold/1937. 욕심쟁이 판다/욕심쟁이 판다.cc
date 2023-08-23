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

vector<vector<int>> arr;
vector<vector<int>> visit;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N;

void dfs(int x, int y){
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			continue;
		}
		if (arr[nx][ny] <= arr[x][y])
		{
			continue;
		}
		if (visit[nx][ny] == -1)
		{
			visit[nx][ny] = -2;
			dfs(nx,ny);
			visit[x][y] = max(visit[x][y],visit[nx][ny] + 1);
		}
		if (visit[nx][ny] > -1)
		{
			visit[x][y] = max(visit[x][y],visit[nx][ny] + 1);
		}
	}
	if (visit[x][y] < 0)
	{
		visit[x][y] = 1;
	}
		
}
	
void printmap(){
	cout << "=============\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	arr.resize(N,vector<int>(N));
	visit.resize(N,vector<int>(N,-1));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int res = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == -1)
			{
				visit[i][j] = -2;
				dfs(i,j);
			}
			
			res = max(res,visit[i][j]);
			
			// printmap();
		}
	}
	cout << res;
}
