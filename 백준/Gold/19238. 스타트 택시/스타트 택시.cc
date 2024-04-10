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
    int dx[] = {-1, 0,0,1};
    int dy[] = { 0,-1,1,0};
    int n, m, g, xi, yi, xa, ya, xb, yb;
    cin >> n >> m >> g;
    vector<vector<int>> arr(n,vector<int>(n));
    vector<vector<int>> v(n,vector<int>(n));
    map<ip,ip> p;
    for (auto& ar : arr) for (auto& a : ar) cin >> a;
    cin >> xi >> yi;
    xi--;
    yi--;
    for (int i = 0; i < m; i++)
    {
        cin >> xa >> ya >> xb >> yb;
        p[{xa-1,ya-1}] = {xb-1,yb-1};
        arr[xa-1][ya-1] = 2; 
    }

    
    while (m--)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     debug(arr[i]);
        // }
        bool find = false;
        deque<ip> q;
        vector<ip> cs;
        for (auto& va : v) for (auto& vaa : va) vaa = 0;
        if (arr[xi][yi] != 2) q.push_back({xi,yi});
        else find = true, arr[xi][yi] = 0, cs.push_back({xi,yi});
        v[xi][yi] = 1;
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (arr[nx][ny] == 1 || v[nx][ny] > 0) continue;
                v[nx][ny] = v[x][y] + 1;
                if (arr[nx][ny] == 2)
                {
                    find = true;
                    if (cs.empty() || v[nx][ny] == v[cs[0].first][cs[0].second]) cs.push_back({nx,ny});
                }
                else
                {
                    q.push_back({nx,ny});
                }
            }
            
        }
        if (!find)
        {
            cout << "-1";
            return;
        }
        sort(all(cs));
        xi = cs[0].first;
        yi = cs[0].second;
        arr[xi][yi] = 0;
        g -= v[xi][yi] - 1;
        // debug(xi,yi,v[xi][yi]-1,g);
        // for (int i = 0; i < n; i++)
        // {
        //     debug(v[i]);
        // }
        if (g <= 0)
        {
            cout << "-1";
            return;
        }
        find = false;
        for (auto& va : v) for (auto& vaa : va) vaa = 0;
        q = {{xi,yi}};
        v[xi][yi] = 1;
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (arr[nx][ny] == 1 || v[nx][ny] > 0) continue;
                v[nx][ny] = v[x][y] + 1;
                if (p[{xi,yi}] == make_pair(nx,ny))
                {
                    find = true;
                    xi = nx;
                    yi = ny;
                    break;
                }
                q.push_back({nx,ny});
            }
            if (find) break;
        }
        if (!find)
        {
            cout << "-1";
            return;
        }
        g -= v[xi][yi] - 1;
        if (g < 0)
        {
            cout << "-1";
            return;
        }
        g += (v[xi][yi] - 1)*2;
        // debug(xi,yi,v[xi][yi]-1,g);
        // for (int i = 0; i < n; i++)
        // {
        //     debug(v[i]);
        // }
    }
    cout << g;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}