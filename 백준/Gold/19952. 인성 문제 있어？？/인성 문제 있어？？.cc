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

int T, H, W, O, F, Xs, Ys, Xe, Ye;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> O >> F >> Xs >> Ys >> Xe >> Ye;
		vector<vector<int>> arr(H,vector<int>(W));
		vector<vector<int>> visit(H,vector<int>(W,-1));
		visit[Xs-1][Ys-1] = F;
		for (int i = 0; i < O; i++)
		{
			int x,y,L;
			cin >> x >> y >> L;
			arr[x-1][y-1] = L;
		}
		deque<pair<int,int>> q;
		q.push_back({Xs-1,Ys-1});
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)
				{
					continue;
				}
				if (arr[x][y] - arr[nx][ny] >= 0 && visit[x][y] -1 > visit[nx][ny])
				{
					visit[nx][ny] = visit[x][y] -1;
					if (visit[nx][ny] > 0)
					{
						q.push_back({nx,ny});
					}
				}
				else
				{
					if (arr[nx][ny] - arr[x][y] <= visit[x][y] && visit[x][y] -1 > visit[nx][ny])
					{
						visit[nx][ny] = visit[x][y] -1;
						if (visit[nx][ny] > 0)
						{
							q.push_back({nx,ny});
						}
					}
				}
			}
		}
		// for (int i = 0; i < H; i++)
		// {
		// 	for (int j = 0; j < W; j++)
		// 	{
		// 		cout << arr[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// for (int i = 0; i < H; i++)
		// {
		// 	for (int j = 0; j < W; j++)
		// 	{
		// 		cout << visit[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		if (visit[Xe-1][Ye-1] > -1)
		{
			cout << "잘했어!!\n";
		}
		else{
			cout << "인성 문제있어??\n";
		}
		
	}
}
