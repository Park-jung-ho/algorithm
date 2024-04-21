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

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                x = i;
                y = j;
            }
        }
    }
    deque<ip> q = {{x,y}};
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != 1) continue;
            arr[nx][ny] = arr[x][y] + 1;
            q.push_back({nx,ny});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << "0 ";
            }
            else if (arr[i][j] == 1)
            {
                cout << "-1 ";
            }
            else
            {
                cout << arr[i][j]-2 << " ";
            }
        }
        cout << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}