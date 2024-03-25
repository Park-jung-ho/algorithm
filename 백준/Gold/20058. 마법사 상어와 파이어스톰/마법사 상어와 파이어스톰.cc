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
    int N, Q, len, l;
    cin >> N >> Q;
    len = pow(2,N);
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    vector<vector<int>> arr(len,vector<int>(len));
    vector<vector<int>> visited(len,vector<int>(len));
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (Q--)
    {
        cin >> l;
        l = pow(2,l);
        vector<vector<int>> tmp(l,vector<int>(l));
        for (int i = 0; i < len; i+=l)
        {
            for (int j = 0; j < len; j+=l)
            {
                int t = j+l;
                for (int x = i; x < i+l; x++)
                {
                    t--;
                    for (int y = j; y < j+l; y++)
                    {
                        tmp[y-j][t-j] = arr[x][y];
                    }
                }
                for (int x = i; x < i+l; x++)
                {
                    for (int y = j; y < j+l; y++)
                    {
                        arr[x][y] = tmp[x-i][y-j];
                    }
                }
            }
        }
        deque<ip> q;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int cnt = 0;
                if (arr[i][j] == 0) continue;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (nx < 0 || nx >= len || ny < 0 || ny >= len || arr[nx][ny] <= 0) continue;
                    cnt++;
                }
                if (cnt < 3 && arr[i][j] > 0)
                {
                    q.push_back({i,j});
                }
            }
        }
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop_front();
            arr[x][y]--;
        }
    }
    // debug(arr);
    int res = 0;
    int big = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            res += arr[i][j];
            if (visited[i][j] > 0 || arr[i][j] == 0) continue;;
            int tmp = 1;
            visited[i][j] = 1;
            deque<ip> q = {{i,j}};
            while (!q.empty())
            {
                auto [x,y] = q.front();
                q.pop_front();
            
                for (int k = 0; k < 4; k++)
                {
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if (nx < 0 || nx >= len || ny < 0 || ny >= len || visited[nx][ny] > 0 || arr[nx][ny] == 0) continue;
                    tmp++;
                    visited[nx][ny] = 1;
                    q.push_back({nx,ny});
                }
            }
            big = max(big,tmp);
        }
    }
    cout << res << "\n" << big;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}