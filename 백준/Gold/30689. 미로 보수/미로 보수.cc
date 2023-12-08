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
    vector<vector<char>> arr(n,vector<char>(m));
    vector<vector<int>> aval(n,vector<int>(m));
    vector<vector<int>> v(n,vector<int>(m));
    
    map<char,ip> mv;
    map<int,ip> mn;
    mv['R'] = {0,1};
    mv['L'] = {0,-1};
    mv['U'] = {-1,0};
    mv['D'] = {1,0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> aval[i][j];
        }
    }
    int num = 1;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j] != 0) continue;
            deque<ip> q = {{i,j}};
            v[i][j] = num;
            while (!q.empty())
            {
                auto [x,y] = q.front();
                q.pop_front();
                int nx = x + mv[arr[x][y]].first;
                int ny = y + mv[arr[x][y]].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    break;
                }
                if (v[nx][ny] != 0)
                {
                    // debug(num,v[nx][ny]);
                    if (v[nx][ny] == num)
                    {
                        mn[v[nx][ny]] = {nx,ny};
                        s.insert(v[nx][ny]);
                    }
                    break;
                }
                v[nx][ny] = num;
                q.push_back({nx,ny});
            }
            num++;
        }
    }
    
    int res = 0;
    for (auto c : s)
    {
        deque<ip> q = {mn[c]};
        int k = aval[mn[c].first][mn[c].second];
        while (!q.empty())
        {
            auto [x,y] = q.front();
            // debug(x,y);
            q.pop_front();
            int nx = x + mv[arr[x][y]].first;
            int ny = y + mv[arr[x][y]].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                break;
            }
            if (mn[c] == make_pair(nx,ny)) break;
            k = min(k,aval[nx][ny]);
            q.push_back({nx,ny});
        }
        // debug(c,k);
        res += k;
    }
    cout << res << "\n"; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}