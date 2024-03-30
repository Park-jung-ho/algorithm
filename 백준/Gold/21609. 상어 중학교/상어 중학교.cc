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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(n));
    vector<vector<int>> trr(n,vector<int>(n));
    vector<vector<int>> v(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    deque<ip> q;
    int rcnt = 0;
    int cnt = 0;
    ip pos = {n,n};
    ip tpos = {n,n};
    deque<ip> dq;
    deque<ip> tmp;
    deque<ip> rb;
    auto bfs = [&](int color)
    {
        cnt = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny] == 1) continue;
                if (arr[nx][ny] == color)
                {
                    v[nx][ny] = 1;
                    q.push_back({nx,ny});
                    tmp.push_back({nx,ny});
                    if (tpos > make_pair(nx,ny)) tpos = {nx,ny}; 
                }
                if (arr[nx][ny] == 0)
                {
                    v[nx][ny] = 1;
                    q.push_back({nx,ny});
                    tmp.push_back({nx,ny});
                    cnt++;
                    rb.push_back({nx,ny});
                }
            }
        }
    };
    auto down = [&]()
    {
        for (int j = n-1; j >= 0; j--)
        {
            for (int i = n-1; i >= 0; i--)
            {
                if (arr[i][j] < 0) continue;
                int tp = i;
                while (1)
                {
                    if (tp+1 >= n || arr[tp+1][j] != -2) break;
                    tp++;
                }
                if (tp == i) continue;
                arr[tp][j] = arr[i][j];
                arr[i][j] = -2;
            }
        }
    };
    auto rot = [&]()
    {
        for (int j = n-1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                trr[n-j-1][i] = arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = trr[i][j];
            }
        }
    };

    int res = 0;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = 0;
            }
        }
        // 1 start
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] < 1 || v[i][j] == 1) continue;
                v[i][j] = 1;
                tmp.clear();
                tmp = {{i,j}};
                q.push_back({i,j});
                tpos = {i,j};

                bfs(arr[i][j]);

                if (tmp.size() > dq.size() ||
                   (tmp.size() == dq.size() && cnt > rcnt) ||
                   (tmp.size() == dq.size() && cnt == rcnt && pos < tpos))
                {
                    rcnt = cnt;
                    dq = tmp;
                    pos = tpos;
                }

                while (!rb.empty())
                {
                    auto [x,y] = rb.front();
                    rb.pop_front();
                    v[x][y] = 0;
                }
            }           
        }
        // 1 end

        // 2 start
        if (dq.size() < 2) break;

        res += pow(dq.size(),2);
        while (!dq.empty())
        {
            auto [x,y] = dq.front();
            dq.pop_front();
            arr[x][y] = -2;
        }
        
        // 2 end

        // 3 start
        down();
        // 3 end

        // 4 start
        rot();
        // 4 end

        // 5 start
        down();
        // 5 end

    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}