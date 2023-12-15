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
#include "DEBUG.h"
#else
#define debug(x...)
#endif

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> visited(n,vector<int>(m));
    vector<vector<int>> vc(n,vector<int>(m));
    ip st, ed;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if (a == 'S')
            {
                st = {i,j};
                arr[i][j] = 0;
            }
            else if (a == 'H')
            {
                ed = {i,j};
                arr[i][j] = 0;
            }
            else if (a == 'X')
            {
                arr[i][j] = -1;
            }
            else
            {
                arr[i][j] = a - '0';
            }
        }
    }
    deque<pair<ip,int>> q = {{st,-1}};
    vc[st.first][st.second] = 1;
    
    
    while (!q.empty())
    {
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << visited[i][j];
        //     }
        //     cout << "\n";
        // }
        auto [ij,mt] = q.front();
        auto [x,y] = ij;
        // debug(x,y,mt);
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            if (i == mt) continue;
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            // debug(i,nx,ny);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == -1) continue;
            if (vc[nx][ny] > 3) continue;
            if (mt == -1 && arr[x][y] + arr[nx][ny] > k) continue;
            if (mt != -1 && arr[x+dx[mt]][y+dy[mt]] + arr[x][y] + arr[nx][ny] > k) continue;
            
            vc[nx][ny]++;
            visited[nx][ny] = visited[x][y] + 1;
            // debug(i,(i+2)%4);
            q.push_back({{nx,ny},(i+2)%4});
        }
        if (visited[ed.first][ed.second] != 0) break;
    }
    int res = visited[ed.first][ed.second] == 0 ? -1 : visited[ed.first][ed.second];
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}