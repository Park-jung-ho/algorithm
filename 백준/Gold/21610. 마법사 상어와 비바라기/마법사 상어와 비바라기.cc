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
    int N, M, d, s;
    cin >> N >> M;
    vector<vector<int>> arr(N,vector<int>(N));
    vector<vector<int>> v(N,vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dx[] = {0,-1,-1,-1,0,1,1,1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};
    deque<ip> q = {{N-1,0},{N-1,1},{N-2,0},{N-2,1}};
    while (M--)
    {
        cin >> d >> s;
        d--;
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop_front();
            x = (x+dx[d]*s)%N;
            y = (y+dy[d]*s)%N;
            if (x < 0) x = N + x;
            if (y < 0) y = N + y;
            arr[x][y]++;
            v[x][y] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (v[i][j] == 1)
                {
                    for (int k = 1; k < 8; k+=2)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= N || y < 0 || y >= N || arr[x][y] < 1) continue;
                        arr[i][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (v[i][j] == 0 && arr[i][j] > 1)
                {
                    q.push_back({i,j});
                    arr[i][j] -= 2;
                }
                v[i][j] = 0;
            }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     debug(arr[i]);
        // }
    }
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res += arr[i][j];
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}