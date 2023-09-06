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
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr(N,vector<int>(M));
    vector<vector<int>> visit(N,vector<int>(M,-1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
	if (arr[0][0] == -1 || arr[N-1][M-1] == -1)
    {
        cout << -1;
        return 0;
    }
    deque<pair<int,int>> q;
    q.push_back({0,0});
    visit[0][0] = arr[0][0];
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (arr[nx][ny] == -1)
            {
                continue;
            }
            if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + arr[nx][ny])
            {
                visit[nx][ny] = visit[x][y] + arr[nx][ny];
                if (arr[nx][ny] == 0)
                {
                    q.push_front({nx,ny});
                }
                else{
                    q.push_back({nx,ny});
                }
            }
        }
    }
    cout << visit[N-1][M-1];
    
    
	
	
	
}
