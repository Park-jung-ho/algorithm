#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, m, k, y, x;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n,vector<int>(m,-1));
    while (k--)
    {
        cin >> y >> x;
        arr[y][x] = -2;
    }
    deque<ip> q = {{0,0}};
    arr[0][0] = 0;
    int dx[2][6] = {{-1,1,0,0,-1,1},{-1,1,0,0,-1,1}};
    int dy[2][6] = {{0,0,-1,1,1,1},{0,0,-1,1,-1,-1}};
    while (!q.empty())
    {
        if (arr[n-1][m-1] != -1) break;
        auto [x, y] = q.front();
        q.pop_front();
        int k = x%2==0 ? 1 : 0;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[k][i];
            int ny = y + dy[k][i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != -1) continue;
            arr[nx][ny] = arr[x][y] + 1;
            q.push_back({nx,ny});
        }
    }
    
    cout << arr[n-1][m-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}