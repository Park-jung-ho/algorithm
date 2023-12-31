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

int L, R, C, sl, si, sj;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dz[] = {-1,1};

void solve()
{
    vector<vector<string>> arr(L,vector<string>(R));
    vector<vector<vector<int>>> v(L,vector<vector<int>>(R,vector<int>(C)));
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> arr[i][j];
            for (int k = 0; k < C; k++)
            {
                if (arr[i][j][k] == 'S')
                {
                    sl = i;
                    si = j;
                    sj = k;
                }
            }
        }
    }
    deque<tuple<int,int,int>> q = {{sl,si,sj}};
    v[sl][si][sj] = 1;
    while (!q.empty())
    {
        auto [z,x,y] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || arr[z][nx][ny] == '#') continue;
            if (v[z][nx][ny] != 0) continue;
            v[z][nx][ny] = v[z][x][y] + 1;
            if (arr[z][nx][ny] == 'E')
            {
                cout << "Escaped in " << v[z][nx][ny] - 1 << " minute(s).\n";
                return;
            }
            q.push_back({z,nx,ny});
        }
        for (int i = 0; i < 2; i++)
        {
            int nz = z + dx[i];
            if (nz < 0 || nz >= L || arr[nz][x][y] == '#' || v[nz][x][y] != 0) continue;
            v[nz][x][y] = v[z][x][y] + 1;
            if (arr[nz][x][y] == 'E')
            {
                cout << "Escaped in " << v[nz][x][y] - 1 << " minute(s).\n";
                return;
            }
            q.push_back({nz,x,y});
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        solve();   
    }
}