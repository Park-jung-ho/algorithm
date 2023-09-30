#include <bits/stdc++.h>
#include <deque>
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
#include "DEBUG.h"
#else
#define debug(x...)
#endif

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void solve()
{
    int N;
    cin >> N;
    vector<string> arr(N);
    vector<vector<int>> visit(N,vector<int>(N));
    vector<vector<int>> change(N,vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    deque<ip> q;
    q.push_back({0,0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                continue;
            }
            if (visit[nx][ny] == 0)
            {
                change[nx][ny] = change[x][y];
                visit[nx][ny] = 1;
                if (arr[nx][ny] == '1')
                {
                    q.push_front({nx,ny});
                }
                if (arr[nx][ny] == '0')
                {
                    q.push_back({nx,ny});
                    change[nx][ny]++;
                }
            }
            if (nx == N-1 && ny == N-1)
            {
                break;
            }
        }
        // cout << "===========\n";
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << change[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
    }
    cout << change[N-1][N-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}   