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

int urdl(char c){
	if (c == 'U')
	{
		return 0;
	}
	else if (c == 'D')
	{
		return 1;
	}
	else if (c == 'L')
	{
		return 2;
	}
	else{
		return 3;
	}
	
	
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M;
	
	cin >> N >> M;
	vector<string> maze(N);
	vector<vector<pair<int,int>>> visit(N,vector<pair<int,int>>(M,make_pair(-1,-1)));
	vector<vector<int>> out(N,vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == make_pair(-1,-1))
			{
				visit[i][j] = make_pair(i,j);
				int x = i;
				int y = j;
				while (1)
				{
					int nx = x + dx[urdl(maze[x][y])];
					int ny = y + dy[urdl(maze[x][y])];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						out[i][j] = 1;
						break;
					}
					if (visit[nx][ny] == make_pair(-1,-1))
					{
						visit[nx][ny] = make_pair(i,j);
						x = nx;
						y = ny;
					}
					else if (visit[nx][ny] == visit[i][j])
					{
						break;
					}
					else{
						out[i][j] = out[visit[nx][ny].first][visit[nx][ny].second];
						break;
					}
					
						
					
				}
			}
			cnt += out[visit[i][j].first][visit[i][j].second];
		}
	}
	
	cout << cnt;
	
}
