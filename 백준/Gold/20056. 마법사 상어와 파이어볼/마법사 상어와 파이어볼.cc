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
struct fb
{
	int m,d,s;
};
struct info
{
	vector<fb> now;
	vector<fb> move;
};
int dx[] = {-1,-1,0,1,1, 1, 0,-1};
int dy[] = {0, 1, 1,1,0,-1,-1,-1};
vector<vector<info>> arr;
int N,M,K,r,c,m,s,d;

int check(int a){
	if (a < 0)
	{
		return N-1;
	}
	if (a >= N)
	{
		return 0;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	arr.resize(N,vector<info>(N));
	
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> m >> s >> d;
		arr[r-1][c-1].now.push_back({m,d,s});
	}

	while (K--)
	{
		//모든 파이어볼 이동
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int nows = arr[i][j].now.size();
				for (int k = 0; k < nows; k++)
				{
					int cnt = arr[i][j].now[k].s % N;
					
					int x = i;
					int y = j;
					int d = arr[i][j].now[k].d;
					int nx = x, ny = y;
					while (cnt--)
					{
						nx = check(x + dx[d]);
						ny = check(y + dy[d]);
						x = nx;
						y = ny;
					}
					// cout << i << "," << j << " " << nx << "," << ny << "\n";
					arr[nx][ny].move.push_back(arr[i][j].now[k]);
				}
				arr[i][j].now.clear();
			}
		}
		// 이동이 모두 끝난 뒤 정산
		// cout << "\n";
		// for (int i = 0; i < N; i++)
		// {
		// 	for (int j = 0; j < N; j++)
		// 	{
		// 		cout << arr[i][j].move.size() << " ";
		// 	}
		// 	cout << "\n";
		// }
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int moves = arr[i][j].move.size();
				if (moves > 1)
				{
					int ss = 0;
					int sm = 0;
					int h = 0;
					int z = 0;
					for (int k = 0; k < moves; k++)
					{
						ss += arr[i][j].move[k].s;
						sm += arr[i][j].move[k].m;
						if (arr[i][j].move[k].d%2==0)
						{
							z++;
						}
						else{
							h++;
						}
					}
					int ns = ss/moves;
					int nm = sm/5;
					if (nm > 0)
					{
						if (z==0 || h==0)
						{
							arr[i][j].now.push_back({nm,0,ns});
							arr[i][j].now.push_back({nm,2,ns});
							arr[i][j].now.push_back({nm,4,ns});
							arr[i][j].now.push_back({nm,6,ns});
						}
						else{
							arr[i][j].now.push_back({nm,1,ns});
							arr[i][j].now.push_back({nm,3,ns});
							arr[i][j].now.push_back({nm,5,ns});
							arr[i][j].now.push_back({nm,7,ns});
						}
					}
				}
				else{
					for (int k = 0; k < moves; k++)
					{
						arr[i][j].now.push_back(arr[i][j].move[k]);
					}
				}
				arr[i][j].move.clear();
			}
		}
		// cout << "\n";
		// for (int i = 0; i < N; i++)
		// {
		// 	for (int j = 0; j < N; j++)
		// 	{
		// 		cout << arr[i][j].move.size() << " ";
		// 	}
		// 	cout << "\n";
		// }
	}
	int sm = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nows = arr[i][j].now.size();
			for (int k = 0; k < nows; k++)
			{
				sm += arr[i][j].now[k].m;
			}
		}
	}
	cout << sm;
}
