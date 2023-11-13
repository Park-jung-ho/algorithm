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

void print(vector<vector<int>> v){
    cout << "=====MAP=====\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == -1)
            {
                cout << "x" << " ";
            }
            else{
                cout << v[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void solve()
{
    int N, M, K, sc, sr, ec, er;
    cin >> N >> M >> K;
    vector<vector<char>> arr(N,vector<char>(M));
    vector<vector<int>> visited(N,vector<int>(M,-1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> sc >> sr >> ec >> er;
    deque<vector<int>> q;
    q.push_back({sc-1,sr-1,-1});
    visited[sc-1][sr-1] = 0;
    while (!q.empty())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int m = q.front()[2];
        
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            
            for (int k = 0; k < K; k++)
            {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || nx >=N || ny < 0 || ny >= M || arr[nx][ny] == '#')
                {
                    break;
                }
                if (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y] + 1)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push_back({nx,ny,i});
                }
                else if (visited[nx][ny] == visited[x][y] + 1)
                {
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
    // print(visited);
    cout << visited[ec-1][er-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}