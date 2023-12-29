#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int dx[] = {0,-1,1,0};
int dy[] = {1,0,0,-1};

void solve()
{
    int n, m, hx, hy, ex, ey;
    cin >> n >> m >> hx >> hy >> ex >> ey;
    hx--;
    hy--;
    ex--;
    ey--;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<vector<int>>> v(2,vector<vector<int>>(n,vector<int>(m)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    deque<tuple<int,int,int>> q = {{hx,hy,0}};
    v[0][hx][hy] = 0;
    while (!q.empty())
    {
        auto [x,y,c] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (v[c][nx][ny] != 0) continue;
            if (c == 1 && arr[nx][ny] != 0) continue;
            if (c == 0 && arr[nx][ny] != 0 && v[1][nx][ny] == 0)
            {
                v[1][nx][ny] = v[c][x][y] + 1;
                q.push_back({nx,ny,1});
            }
            if (arr[nx][ny] == 0)
            {
                v[c][nx][ny] = v[c][x][y] + 1;
                q.push_back({nx,ny,c});
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << v[0][i][j];
        //     }
        //     cout << " || ";
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << v[1][i][j];
        //     }
        //     cout << "\n";
        // }
        
        if (v[0][ex][ey] != 0 || v[1][ex][ey] != 0)
        {
            break;
        }
    }
    int res = v[0][ex][ey] != 0 ? v[0][ex][ey] : v[1][ex][ey];
    if (res == 0) cout << -1;
    else cout << res; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}