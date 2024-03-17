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
    int dx[] = {1,0};
    int dy[] = {0,1};
    int n, m;
    cin >> m >> n;
    vector<vector<int>> arr(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    deque<ip> q = {{0,0}};
    arr[0][0] = 2;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop_front();

        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != 1) continue;
            
            arr[nx][ny] = 2;
            q.push_back({nx,ny});
        }       
    }
    if (arr[n-1][m-1] == 2) cout << "Yes";
    else cout << "No";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}